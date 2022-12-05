#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
    int height;
    Node(int x) {
        key = x;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int height(Node *x) {
    if (!x) return 0;
    return x->height;
}

int getBalanceFactor(Node *N) {
    if (!N) return 0;
    return height(N->left) - height(N->right);
}

// left rotate function

Node *leftRotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node *rightRotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return x;
}

Node *insert(Node *node, int key) {
    if (!node) return new Node(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    if (balanceFactor < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    if (balanceFactor > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balanceFactor < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(Node *node) {
    if (!node) return;
    cout << node->key << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    Node *root = NULL;
    root = insert(root, 10);

    root = insert(root, 20);

    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    cout << "Preorder traversal of the "
            "constructed AVL tree is \n";
    preOrder(root);
    return 0;
}
