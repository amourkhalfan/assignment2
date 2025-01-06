#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct StackNode {
    char data;
    struct StackNode* next;
};
void push(struct StackNode** top, char data) {
    struct StackNode* new_node = (struct StackNode*) malloc(sizeof(struct StackNode));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}
char pop(struct StackNode** top) {
    if (*top == NULL) return -1;
    char popped = (*top)->data;
    struct StackNode* temp = *top;
    *top = (*top)->next;
    free(temp);
    return popped;
}
int precedence(char operator) {
    if (operator == '^') return 3;
    if (operator == '*' || operator == '/') return 2;
    if (operator == '+' || operator == '-') return 1;
    return 0;
}
void infixToPostfix(char* infix, char* postfix) {
    struct StackNode* stack = NULL;
    int i = 0, j = 0;

    while (infix[i]) {
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            push(&stack, infix[i]);
        } else if (infix[i] == ')') {
            while (stack != NULL && stack->data != '(') {
                postfix[j++] = pop(&stack);
            }
            pop(&stack);  // Remove '(' from stack
        } else {
            while (stack != NULL && precedence(stack->data) >= precedence(infix[i])) {
                postfix[j++] = pop(&stack);
            }
            push(&stack, infix[i]);
        }
        i++;
    }

    while (stack != NULL) {
        postfix[j++] = pop(&stack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[] = "((a+b)^((c/d)*e))";
    char postfix[100];
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
