#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* createNode(int x) {
    struct node* t = (struct node*)malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    return t;
}

void insertEnd(struct node** head, int x) {
    struct node* t = createNode(x);
    if (*head == NULL) {
        *head = t;
        return;
    }
    struct node* p = *head;
    while (p->next != NULL)
        p = p->next;
    p->next = t;
}

int deleteKey(struct node** head, int key) {
    int count = 0;
    while (*head && (*head)->data == key) {
        struct node* temp = *head;
        *head = (*head)->next;
        free(temp);
        count++;
    }
    struct node* curr = *head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            struct node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            count++;
        } else {
            curr = curr->next;
        }
    }
    return count;
}

void display(struct node* head) {
    while (head) {
        printf("%d", head->data);
        if (head->next) printf("->");
        head = head->next;
    }
}

int main() {
    struct node* head = NULL;
    int arr[] = {1,2,1,2,1,3,1};
    int n = 7, key = 1;
    for (int i = 0; i < n; i++)
        insertEnd(&head, arr[i]);
    int cnt = deleteKey(&head, key);
    printf("Count: %d\nUpdated Linked List: ", cnt);
    display(head);
    return 0;
}
