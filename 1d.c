#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct stack {
    int data[SIZE];
    int top;
};

int compareStacks(struct stack* s1, struct stack* s2) {
    if (s1->top != s2->top) return 0; 
    for (int i = 0; i <= s1->top; i++) {
        if (s1->data[i] != s2->data[i]) return 0;
    }
    return 1;
}

int main() {
    struct stack s1 = { .top = -1 };
    struct stack s2 = { .top = -1 };

    s1.data[++s1.top] = 1;
    s1.data[++s1.top] = 2;

    s2.data[++s2.top] = 1;
    s2.data[++s2.top] = 2;

    printf("Stacks are %s\n", compareStacks(&s1, &s2) ? "Equal" : "Not Equal");
    return 0;
}
