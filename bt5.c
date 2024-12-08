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

void insert(Node** head, int value, int p) {
    if (p < 0) {
        return;
    }
    Node* newNode = createNode(value);
    if (p == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* current = *head;
    for (int i = 0; i < p - 1; i++) {
        if (current == NULL) {
            free(newNode);
            return;
        }
        current = current->next;
    }

    if (current == NULL) {
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
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
    int n, value, p;
    scanf("%d", &n);
    Node* head = createLinkedList(n);
    printf("nhap gia tri can chen");
    scanf("%d", &value);
    printf("nhap vi tri can chen");
    scanf("%d", &p);

    insert(&head, value, p);
    printLinkedList(head);

    freeLinkedList(head);
    return 0;
}
