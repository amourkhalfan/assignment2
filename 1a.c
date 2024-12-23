#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct stack {
    int data[SIZE];
    int top;
} st = { .top = -1 };

void push(int item) {
    if (st.top >= SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    st.data[++st.top] = item;
}

int pop() {
    if (st.top == -1) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return st.data[st.top--];
}

void reverseList(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }
    printf("Reversed List: ");
    while (st.top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverseList(arr, n);
    return 0;
}
