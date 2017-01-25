//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
#define max(a,b) ((a > b) ? a : b)
using namespace std;

struct node_66{
    int avl;
    struct node_66 *left, *right;
};

node_66 *rotateleft(node_66 *root){
    node_66 *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
node_66 *rotateright(node_66 *root){
    node_66 *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
node_66 *rotateleftright(node_66 *root){
    root->left = rotateleft(root->left);
    return rotateright(root);
}
node_66 *rotaterightleft(node_66 *root){
    root->right = rotateright(root->right);
    return rotateleft(root);
}
int getheight(node_66 *root){
    if (root == NULL) return 0;
    else return max(getheight(root->left),getheight(root->right))+1;
}
node_66 *insert(node_66 *root, int avl){
    if (root == NULL){
        root = new node_66;
        root->avl = avl;
        root->left = root->right = NULL;
    } else if (avl < root->avl) {
        root->left = insert(root->left,avl);
        if (getheight(root->left) - getheight(root->right) == 2){
            root = (avl < root->left->avl) ? rotateright(root) : rotateleftright(root);
        }
    } else {
        root->right = insert(root->right,avl);
        if (getheight(root->left) - getheight(root->right) == -2){
            root = (avl > root->right->avl) ? rotateleft(root) : rotaterightleft(root);
        }
    }
    return root;
}
int pat_1066(){
    int n, avl;
    scanf("%d",&n);
    node_66 *tree = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &avl);
        tree = insert(tree, avl);
    }
    printf("%d",tree->avl);
    return 0;
}