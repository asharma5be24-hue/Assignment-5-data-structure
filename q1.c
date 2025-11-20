#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* root = NULL;

struct node* createnode(int element) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = element;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insertnode(struct node *root, int key) {
    if (root == NULL) {
        return createnode(key);
    }

    if (key < root->data)
        root->left = insertnode(root->left, key);

    else if (key > root->data)
        root->right = insertnode(root->right, key);

    return root;
}

void preorder(struct node* temp) {
    if (temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(struct node* temp) {
    if (temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct node* temp) {
    if (temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

int main() {

    root = insertnode(root, 30);
    root = insertnode(root, 20);
    root = insertnode(root, 10);
    root = insertnode(root, 50);
    root = insertnode(root, 83);
    root = insertnode(root, 35);

    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    printf("\nPostorder: ");
    postorder(root);

    return 0;
}
