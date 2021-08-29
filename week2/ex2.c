#include <stdio.h>
#include <string.h>

int main() {
    char s[256], r[256];
    int begin, end, count = 0;

    printf("Enter a string:\n");
    fgets(s, 256, stdin);

    while (s[count] != '\0')
        count++;

    end = count - 1;

    for (begin = 0; begin < count; begin++) {
        r[begin] = s[end];
        end--;
    }

    r[begin] = '\0';
    
    printf("Your string in reverse:%s\n", r);
    return 0;
}
