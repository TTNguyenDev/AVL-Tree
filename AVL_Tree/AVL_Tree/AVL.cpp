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


NODE* Search(NODE* root, int x) {
    if (root == NULL)
        return NULL;
    if (root->key == x)
        return root;
    else if (root->key > x)
        return Search(root -> left, x);
    else if (root->key < x)
        return Search(root -> right, x);
    return NULL;
}

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
    
    root->bal = Height(root->left) - Height(root->right);
    
    if(root->bal >= 2 && x < root->left->key)
        rightRotate(root);
    if(root->bal >= 2 && x > root->left->key) {
        leftRotate(root->left);
        rightRotate(root);
    }
    
    if(root->bal <= -2 && x > root->right->key)
        leftRotate(root);
    
    if(root->bal <= -2 && x < root->right->key) {
        rightRotate(root->right);
        leftRotate(root);
    }
}

NODE* findMax(NODE* root) {
    if (root == NULL)
        return NULL;
    NODE* max = root;
    
    while (max != NULL) {
        if (max -> right == NULL)
            return max;
        max = max -> right;
    }
    return max;
}

int returnRoot(NODE* root) {
    return root->key;
} //check fuction


void Remove(NODE* &root, int x) {
    if (root==NULL)
        return;
    
    else if (root->key > x)
        Remove(root->left, x);
    else if (root->key < x)
        Remove(root->right, x);
    else {
        NODE *clone = root;
        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        else {
            NODE *parent = root;
            NODE *child = parent->left;
            
            while (child->right != NULL) {
                parent = child;
                child = child->right;
            }
            
            clone->key = child->key;
            parent->right = child->left;
            delete child;
        }
    }
}


bool isBST(NODE* root) {
    if (root == NULL)
        return true;
    
    if (root->left != NULL && root->left->key > root->key)
        return false;
    if (root->right != NULL && root->right->key < root->key)
        return false;
    if (isBST(root->left) == false || isBST(root->right) == false)
        return false;
    
    return true;
}

int countNODE(NODE* root) {
    int count = 0;
    
    if (root) {
        count ++;
        count += countNODE(root->left);
        count += countNODE(root->right);
    }
    return count;
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

void RemoveAVL(NODE* &root, int x) {
    if (root==NULL)
        return;
    
    else if (root->key > x)
        Remove(root->left, x);
    else if (root->key < x)
        Remove(root->right, x);
    else {
        NODE *clone = root;
        if (root->left == NULL)
            root = root->right;
        else if (root->right == NULL)
            root = root->left;
        else {
            NODE *parent = root;
            NODE *child = parent->left;
            
            while (child->right != NULL) {
                parent = child;
                child = child->right;
            }
            clone->key = child->key;
            parent->right = child->left;
            delete child;
        }
    }
    int balance = getBalance(root);
    
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    
    if (balance > 1 && getBalance(root->left) < 0)
    {
        leftRotate(root->left);
        rightRotate(root);
    }
    
    if (balance < -1 && getBalance(root->right) <= 0)
        leftRotate(root);
    
    if (balance < -1 && getBalance(root->right) > 0)
    {
        rightRotate(root->right);
        leftRotate(root);
    }
}

int getBalance(NODE* root) {
    return Height(root->left) - Height(root->right);
}
