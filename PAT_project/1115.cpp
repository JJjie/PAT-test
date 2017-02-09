//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
using namespace std;

struct node115{
    int key;
    node115 *left, *right;
};
typedef node115* nodepoint;
int count115[1001] = {0};
nodepoint insertTotree(int a,nodepoint node){
    if (node == NULL) {
        node = new node115;
        node->left = NULL;
        node->right = NULL;
        node->key = a;
    } else if (a <= node->key){
        node->left = insertTotree(a,node->left);
    } else {
        node->right = insertTotree(a,node->right);
    }
    return node;
}
void readbst(nodepoint tree, int level){
    count115[level]++;
    if (tree->left != NULL){
        readbst(tree->left,level+1);
    }
    if (tree->right != NULL){
        readbst(tree->right,level+1);
    }
}
int pat_1115(){
    int n;
    scanf("%d",&n);
    nodepoint bst = NULL;
    for (int i = 0; i < n; ++i) {
        int a;
        scanf("%d",&a);
        bst = insertTotree(a,bst);
    }
    readbst(bst,1);
    int index = 0;
    for (int i = 0; i < 1001; ++i) {
        if (count115[i+1] == 0) {
            index = i;
            break;
        }
    }
    if (index == 0){
        printf("0 + 0 = 0\n");
    } else {
        printf("%d + %d = %d",count115[index],count115[index-1],count115[index]+count115[index-1]);
    }
    return 0;
}