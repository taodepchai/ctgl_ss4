#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createLinkedList(int n) {
    Node* head = NULL;
    Node* temp = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        Node* newNode = createNode(value);
        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    return head;
}

void printLinkedList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        return;
    }
    if (position < 0) {
        return;
    }

    Node* temp = *head;

    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    for (int i = 0; i < position; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == NULL) {
            return;
        }
    }

    prev->next = temp->next;
    free(temp);
}

void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, position;
    scanf("%d", &n);
    Node* head = createLinkedList(n);

    scanf("%d", &position);

    deleteAtPosition(&head, position);
    printLinkedList(head);

    freeLinkedList(head);
    return 0;
}
