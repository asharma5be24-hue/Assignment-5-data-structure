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

struct node* reverse(struct node* head) {
    struct node *prev = NULL, *curr = head, *next;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print(struct node* head) {
    while (head) {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL");
}

int main() {
    struct node* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head = reverse(head);
    print(head);
    return 0;
}
