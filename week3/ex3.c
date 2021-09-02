#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *next;
};

void print_list(struct node *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void insert_node(struct node *head, struct node *newnode, struct node *prevnode) {
    while (head != prevnode & head != NULL) {
        head = head->next;
    }
    if (head == NULL) { return; }
    struct node *temp = head->next;
    head->next = newnode;
    newnode->next = temp;
}

void delete_node(struct node *head, struct node *delnode) {
    while (head->next != delnode & head->next != NULL) {
        head = head->next;
    }
    if (head->next == NULL) { return; }
    head->next = head->next->next;
}

int main() {
    struct node *head = (struct node*) malloc(sizeof(struct node));
    head->val = 1;
    head->next = (struct node*) malloc(sizeof(struct node));
    head->next->val = 2;
    head->next->next = (struct node*) malloc(sizeof(struct node));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    printf("Inititial structure:\n");
    print_list(head);

    printf("Insert node after node2:\n");
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->val = 4;
    newnode->next = NULL;
    insert_node(head, newnode, head->next);
    print_list(head);

    printf("Delete node2:\n");
    delete_node(head, head->next);
    print_list(head);

    return 0;   
}
