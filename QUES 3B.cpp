
#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    int data;
    struct StackNode* next;
};
void push(struct StackNode** top, int data) {
    struct StackNode* new_node = (struct StackNode*) malloc(sizeof(struct StackNode));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}
void printStack(struct StackNode* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    struct StackNode* stack = NULL;
    
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    
    printf("Stack contents: ");
    printStack(stack);
    
    return 0;
}
