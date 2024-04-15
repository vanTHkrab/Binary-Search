# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

struct tree* findMin(struct tree* node);
int delete(struct tree** root, int data);

struct tree* newnode(int data) {
    struct tree* tree = (struct tree*)malloc(sizeof(struct tree));
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

bool isEmpty(struct tree* root){
    return !root;
}

void print(struct tree* root) {
    if (root != NULL) {
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

struct tree* insert(struct tree* root, int data) {
    if (root == NULL) {
        return newnode(data);
    }
    if (root->data == data) {
        return root;
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

int delete(struct tree** root, int data) {
    if (*root == NULL) {
        return 0;
    }
    
    if (data < (*root)->data) {
        return delete(&((*root)->left), data);
    }
    else if (data > (*root)->data) {
        return delete(&((*root)->right), data);
    }
    else {
        if ((*root)->left == NULL && (*root)->right == NULL) {
            
            free(*root);
            *root = NULL;

        } else if ((*root)->left == NULL) {
            struct tree* temp = *root;
            *root = (*root)->right;
            free(temp);

        } else if ((*root)->right == NULL) {
            struct tree* temp = *root;
            *root = (*root)->left;
            free(temp);

        } else {
            struct tree* temp = findMin((*root)->right);
            (*root)->data = temp->data;
            delete(&((*root)->right), temp->data);
        }
        return 1; 
    }
}

struct tree* findMin(struct tree* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct tree* search(struct tree* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    }
    return search(root->right, data);
}

int main(void) {
    struct tree* root = NULL;
    struct tree* root2 = NULL;
    root = insert(root, 75);
    // root2 = insert(root2, 5);
    insert(root, 43);
    insert(root, 89);
    insert(root, 11);
    insert(root, 67);
    insert(root, 79);
    insert(root, 97);
    insert(root, 10);
    insert(root, 13);
    insert(root, 64);
    insert(root, 68);
    insert(root, 78);
    insert(root, 99);
    // insert(root, 40);
    print(root);
    delete(&root, 43);
    printf("\n");
    print(root);
    printf("\n");
    struct tree* result = search(root, 67);
    if (result != NULL) {
        printf("Data found: %d\n", result->data);
    } else {
        printf("Data not found.\n");
    }
    print(root);
}