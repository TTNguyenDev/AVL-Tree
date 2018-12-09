#include "AVL.h"

NODE* createNode(int data) {
    NODE* root = new NODE;
    root -> key = data;
    root -> left = NULL;
    root -> right = NULL;
    
    return root;
}

void NLR(NODE* root)  {
    if (root == NULL)
        return;
    
    cout << root->key << " ";
    NLR(root->left);
    NLR(root->right);
} //preOrder

void LNR(NODE* root) {
    if (root == NULL)
        return;
    
    LNR(root->left);
    cout << root->key << " ";
    LNR(root->right);
} //inOrder

void LRN(NODE* root) {
    if (root == NULL)
        return;
    
    LRN(root->left);
    LRN(root->right);
    cout << root->key << " ";
} //postOrder

int Height(NODE* root) {
    if (root==NULL)
        return 0;
    
    else {
        int heightOfLeft = Height(root->left);
        int heightOfRight = Height(root->right);
        
        if (heightOfLeft > heightOfRight)
            return(heightOfLeft+1);
        else return(heightOfRight+1);
    }
}

void Insert(NODE* &root, int x) {
    if (root == NULL) {
        root = createNode(x);
        return;
    }
    if (root->key > x)
        Insert(root -> left, x);
    if (root->key < x)
        Insert(root -> right, x);
    
    int balance = getBalance(root);
    
    if(balance > 1 && x < root->left->key)
        rightRotate(root);
    
    if(balance > 1 && x > root->left->key) {
        leftRotate(root->left);
        rightRotate(root);
    }
    
    if(balance < -1 && x > root->right->key)
        leftRotate(root);
    
    if(balance < -1 && x < root->right->key) {
        rightRotate(root->right);
        leftRotate(root);
    }
}

NODE* findMinNode(NODE* &root) {
    NODE* min = root;
    while (min->left != NULL)
        min = min->left;
    return min;
}

void Remove(NODE* &root, int x) {
    if (root == NULL) return;
    else {
        if (root->key > x)
            Remove(root->left, x);
        
        else if (root->key < x)
            Remove(root->right, x);
        
        else {
            if (root->left == NULL) {
                NODE* temp = root->right;
                delete root;
                root = temp;
            }
            
            else if (root->right == NULL) {
                NODE*temp = root->left;
                delete root;
                root = temp;
            }
            
            else {
                NODE* min = findMinNode(root->right);
                root->key = min->key;
                Remove(root->right, min->key);
            }
        }
    }
    
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    
    if (balance > 1 && getBalance(root->left) < 0) {
        leftRotate(root->left);
        rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) <= 0)
        leftRotate(root);
    
    if (balance < -1 && getBalance(root->right) > 0) {
        rightRotate(root->right);
        leftRotate(root);
    }
}

void leftRotate(NODE* &root) {
    NODE *p;
    p=root->right;
    root->right=p->left;
    p->left=root;
    
    root=p;
}

void rightRotate(NODE* &root) {
    NODE *p;
    p=root->left;
    root->left=p->right;
    p->right=root;
    
    root=p;
}

int getBalance(NODE* root) {
    if (root == NULL)
        return 0;
    return Height(root->left) - Height(root->right);
}
