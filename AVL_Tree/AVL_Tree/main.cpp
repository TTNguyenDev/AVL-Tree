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
    
    NLR(root);
    
    Remove(root, 36);
    Remove(root, 50);
    Remove(root, 18);
    Remove(root, 37);
//    Remove(root, 8);
//    Remove(root, 20);
//    Remove(root, 45);
//    Remove(root, 55);
//    Remove(root, 65);
//    Remove(root, 40);
    
    cout << endl;
    NLR(root);
}
