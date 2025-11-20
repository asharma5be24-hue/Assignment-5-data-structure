#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* newNode(int x) {
    struct node* t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    return t;
}

void printMid(struct node* head) {
    struct node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    printf("Middle: %d", slow->data);
}

int main() {
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);
    printMid(head);
    return 0;
}
