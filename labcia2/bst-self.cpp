#include <iostream>
using namespace std;

struct node {
    int data;
    node *left;
    node *right;
};

class bst {

public:
    node *insert (node *root, node *greenie) {
        if (root == NULL) {
            return greenie;
        }
        else if (greenie->data < root->data)
        {
            root->left = insert(root->left, greenie);
        } else if (greenie->data > root->data) {
            root->right = insert(root->right, greenie);
        }
        return root;
    }

    node *find_largest(node *root)
    {
        if (root->right == NULL)
            return root;
        else
            return find_largest(root->right);
    }

    node *find_smallest(node *root)
    {
        if (root->left == NULL)
            return root;
        else
            return find_smallest(root->left);
    }

    void preorder (node *root) {
        if (root != NULL) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    bool *del(node *root, int key)
};

int main () {
    bst b;
    node *root = NULL;
    node *l = NULL;
    node *s = NULL;
    node *temp = NULL;
}