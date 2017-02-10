//
// Created by 胡文杰 on 2017/2/10.
//

#include "pat.h"
#include <iostream>
#include <queue>
#define max(a,b) ((a > b) ? a : b)
using namespace std;

struct node_123{
    int avl;
    struct node_123 *left, *right;
};
typedef node_123* nodepoint;
node_123 *rotateleft(node_123 *root){
    node_123 *temp = root->right;
    root->right = temp->left;
    temp->left = root;
    return temp;
}
node_123 *rotateright(node_123 *root){
    node_123 *temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}
node_123 *rotateleftright(node_123 *root){
    root->left = rotateleft(root->left);
    return rotateright(root);
}
node_123 *rotaterightleft(node_123 *root){
    root->right = rotateright(root->right);
    return rotateleft(root);
}
int getheight(node_123 *root){
    if (root == NULL) return 0;
    else return max(getheight(root->left),getheight(root->right))+1;
}
node_123 *insert(node_123 *root, int avl){
    if (root == NULL){
        root = new node_123;
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
int pat_1123(){
    int n, avl;
    scanf("%d",&n);
    node_123 *tree = NULL;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &avl);
        tree = insert(tree, avl);
    }
    queue<nodepoint > q;
    q.push(tree);
    int cnt = 0;
    bool flag = true;
    while (!q.empty()){
        nodepoint current = q.front();
        q.pop();
        if (current != NULL){
            if (cnt == 0) printf("%d",current->avl);
            else printf(" %d",current->avl);
            cnt++;
            q.push(current->left);
            q.push(current->right);
        } else {
            if (cnt != n)
                flag = false;
        }
    }
    printf("\n");
    if (flag) printf("YES");
    else printf("NO");
    return 0;
}