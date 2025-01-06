#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100000
struct node {
    int length;
    int count;
    int max_value;
    struct node* next;
};

struct node* createNewNode(int length, int max_value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->length = length;
    newNode->count = 1;
    newNode->max_value = max_value;
    newNode->next = NULL;
    return newNode;
}

void insertOrUpdateNode(struct node** head, int length, int max_value) {
    struct node* current = *head;
    struct node* previous = NULL;
    
    while (current != NULL && current->length < length) {
        previous = current;
        current = current->next;
    }

    if (current != NULL && current->length == length) {
        current->count++;
        if (current->max_value < max_value) {
            current->max_value = max_value;
        }
        return;
    }

    struct node* newNode = createNewNode(length, max_value);
    
    if (previous == NULL) {
        newNode->next = *head;
        *head = newNode;
    } else {
        newNode->next = previous->next;
        previous->next = newNode;
    }
}
int calculateCollatz(int n, int* max_value) {
    int length = 0;
    *max_value = n;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        if (n > *max_value) {
            *max_value = n;
        }
        length++;
    }
    return length + 1;
}

int main() {
    int limit;
    struct node* runStats = NULL;
    scanf("%d", &limit);
    for (int i = 1; i <= limit; i++) {
        int max_value;
        int length = calculateCollatz(i, &max_value);
        insertOrUpdateNode(&runStats, length, max_value);
    }
    struct node* current = runStats;
    while (current != NULL) {
        printf("%d %d %d\n", current->length, current->count, current->max_value);
        current = current->next;
    }
    return 0;
}

