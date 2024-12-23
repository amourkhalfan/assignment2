#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

struct student {
    char name[50];
    int age;
};

struct stack {
    struct student data[SIZE];
    int top;
} st = { .top = -1 };

void push(char* name, int age) {
    if (st.top >= SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    st.top++;
    strcpy(st.data[st.top].name, name);
    st.data[st.top].age = age;
    printf("Pushed student: %s, Age: %d\n", name, age);
}

struct student pop() {
    if (st.top == -1) {
        printf("Stack Underflow!\n");
        struct student empty = { "", -1 };
        return empty;
    }
    return st.data[st.top--];
}

void displayStack() {
    if (st.top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Students in stack:\n");
    for (int i = st.top; i >= 0; i--) {
        printf("%s (Age: %d)\n", st.data[i].name, st.data[i].age);
    }
}

int main() {
    push("Alice", 20);
    push("Bob", 22);
    displayStack();
    struct student s = pop();
    printf("Popped student: %s, Age: %d\n", s.name, s.age);
    displayStack();
    return 0;
}
