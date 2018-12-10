//
//  main.cpp
//  AVL_Tree
//
//  Created by TT Nguyen on 12/9/18.
//  Copyright © 2018 TT Nguyen. All rights reserved.
//

#include "AVL.h"

int main() {

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
    
    cout << "After Insert: ";
    NLR(root);
    
    Remove(root, 36);
    Remove(root, 50);
    Remove(root, 18);
    Remove(root, 37);

    cout << "\nAfter Remove Nodes: ";
    NLR(root);
    cout << endl;
}
