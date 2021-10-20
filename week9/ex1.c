#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct page {
    int id;
    unsigned short counter;
} page_t;

unsigned char NUMBER_BITS = sizeof(((page_t *)0)->counter) * 8;

page_t *existing_page(page_t *pages, int id, size_t page_count) {
    for (int i = page_count - 1; i >= 0; i--) {
        if (pages[i].id == id)
            return pages + i;
    }
    return NULL;
}

page_t *free_space_page(page_t *pages, size_t page_count) {
    unsigned int lowest_counter = 1 << 31;
    int lowest_id = 0;
    for (int i = page_count - 1; i >= 0; i--) {
        if (pages[i].id == -1)
            return pages + i;

        if (pages[i].counter < lowest_counter) {
            lowest_counter = pages[i].counter;
            lowest_id = i;
        }
    }
    return pages + lowest_id;
}

int main(int argc, char *argv[]) {
    int page_count;
    printf("Print the number of pages ");
    fscanf(stdin, "%d", &page_count);

    page_t *pages = calloc(page_count, sizeof(page_t));
    for (int i = 0; i < page_count; ++i) {
        pages[i].id = -1;
    }
    FILE *input = fopen("input.txt", "r");

    int pageId;
    double hits = 0, misses = 0;
    while (fscanf(input, "%d", &pageId) == 1) {
        for (int i = 0; i < page_count; ++i) {
            printf("i = %d id = %d %d\n", i, pages[i].id, pages[i].counter);
        }

        page_t *page = existing_page(pages, pageId, page_count);
        if (page != NULL) {
            hits++;
        } else {
            page = free_space_page(pages, page_count);
            page->id = pageId;
            page->counter = 0;
            misses++;
        }

        for (int i = 0; i < page_count; ++i) {
            pages[i].counter >>= 1;
        }
        page->counter |= 1 << (NUMBER_BITS - 1);
        printf("current page number %d\n\n", pageId);
    }

    free(pages);
    fclose(input);

    printf("hit =  %f miss = %f ratio = %f\n", hits, misses, hits / misses);
    return 0;
}
