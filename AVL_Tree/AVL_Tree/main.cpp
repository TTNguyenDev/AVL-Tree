//
//  main.cpp
//  AVL_Tree
//
//  Created by TT Nguyen on 12/9/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "AVL.h"

int main() {
//    NODE *root = createNode(9);
//
//    Insert(root, 5);
//    Insert(root, 10);
//    Insert(root, 0);
//    Insert(root, 6);
//    Insert(root, 11);
//    Insert(root, -1);
//    Insert(root, 1);
//    Insert(root, 2);
    
    
    NODE *root = createNode(40);
    Insert(root, 36);
    Insert(root, 50);
    Insert(root, 18);
    Insert(root, 37);
    Insert(root, 8);
    Insert(root, 20);
    Insert(root, 45);
    Insert(root, 55);
    Insert(root, 65);
    
    NLR(root);
    RemoveAVL(root, 45);
    cout << endl;
    NLR(root);
}
