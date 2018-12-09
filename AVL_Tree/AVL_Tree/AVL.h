//
//  BTS.h
//  AVL_Tree
//
//  Created by TT Nguyen on 12/9/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#ifndef BTS_h
#define BTS_h

#include <iostream>

using namespace std;

struct NODE {
    int key;
    NODE* left;
    NODE* right;
    int bal;
};

NODE* createNode(int);
void NLR(NODE*);
void LNR(NODE*);
void LRN(NODE*);
NODE* Search(NODE*,int);
int Height(NODE*);
int getBalance(NODE* root);
NODE* findMax(NODE*);
void Remove(NODE* &,int);
bool isBST(NODE*);
int countNODE(NODE*);

//--------------
void Insert(NODE* &,int);

void rightRotate(NODE* &);
void leftRotate(NODE* &);

int returnRoot(NODE* root);
void RemoveAVL(NODE* &root, int x); 
#endif /* BTS_h */
