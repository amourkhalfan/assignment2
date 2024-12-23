#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack {
    char data[SIZE];
    int top;
} st = { .top = -1 };

void push(char c) {
    st.data[++st.top] = c;
}

char pop() {
    if (st.top == -1) return '\0';
    return st.data[st.top--];
}

int isBalanced(char* expr) {
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            char top = pop();
            if ((expr[i] == ')' && top != '(') || 
                (expr[i] == '}' && top != '{') || 
                (expr[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }
    return st.top == -1;
}

int main() {
    char expr[] = "{[()]}";
    printf("Parentheses are %s\n", isBalanced(expr) ? "Balanced" : "Not Balanced");
    return 0;
}
