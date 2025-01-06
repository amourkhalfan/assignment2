#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};
bool search(struct node* root, int key) {
    if (root == NULL) {
        return false;
    }
    if (root->data == key) {
        return true;
    }
    if (key < root->data) {
        return search(root->left, key);
    } else {
        return search(root->right, key);
    }
}
int height(struct node* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
void iterativePreOrder(struct node* root) {
    if (root == NULL) {
        return;
    }

    struct node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct node* node = stack[top--];
        printf("%d ", node->data);

        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}
void iterativeInOrder(struct node* root) {
    struct node* current = root;
    struct node* stack[100];
    int top = -1;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);

        current = current->right;
    }
}
struct node* findMin(struct node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}


int main() {
    struct node* root = NULL;
    if (search(root, 30)) {
        printf("Found 30 in the tree.\n");
    } else {
        printf("30 not found in the tree.\n");
    }

    printf("Height of the tree: %d\n", height(root));

    printf("PreOrder Traversal: ");
    iterativePreOrder(root);
    printf("\n");

    printf("InOrder Traversal: ");
    iterativeInOrder(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("Deleted 30 from the tree.\n");

    return 0;
}
