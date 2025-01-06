#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct request {
    char device[20];
    int priority;
    struct request* next;
};
void insertRequest(struct request** head, char* device, int priority) {
    struct request* new_request = (struct request*) malloc(sizeof(struct request));
    strcpy(new_request->device, device);
    new_request->priority = priority;
    new_request->next = NULL;
    if (*head == NULL || (*head)->priority > priority) {
        new_request->next = *head;
        *head = new_request;
        return;
    }

    struct request* current = *head;
    while (current->next != NULL && current->next->priority <= priority) {
        current = current->next;
    }

    new_request->next = current->next;
    current->next = new_request;
}
void processRequests(struct request* head) {
    while (head != NULL) {
        printf("Processing request from: %s with priority %d\n", head->device, head->priority);
        head = head->next;
    }
}

int main() {
    struct request* requestList = NULL;

    insertRequest(&requestList, "Keyboard", 1);
    insertRequest(&requestList, "Mouse", 2);
    insertRequest(&requestList, "Scanner", 3);
    insertRequest(&requestList, "Printer", 4);

    printf("Request List (in order of priority):\n");
    processRequests(requestList);

    return 0;
}


