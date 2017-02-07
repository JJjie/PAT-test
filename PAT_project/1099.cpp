//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct tree_99{
    int key;
    int left;
    int right;
};
vector<tree_99> tree99;
vector<int> num99;
int tag99 = 0;
void inorder_99(int root){ //中序，将数据写入树中
    if (tree99[root].left == -1 && tree99[root].right == -1){
        tree99[root].key = num99[tag99++];
        return;
    }
    if (tree99[root].left != -1){
        inorder_99(tree99[root].left);
    }
    tree99[root].key = num99[tag99++];
    if (tree99[root].right != -1){
        inorder_99(tree99[root].right);
    }
}
int pat_1099(){
    int n;
    scanf("%d",&n);
    tree99.resize(n);
    num99.resize(n);
    for (int i = 0; i < n; ++i) {
        int left,right;
        scanf("%d %d",&left,&right);
        tree99[i].left = left;
        tree99[i].right = right;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&num99[i]);
    }
    sort(num99.begin(),num99.end());
    inorder_99(0);
//    层序遍历
    queue<int> q;
    q.push(0);
    printf("%d",tree99[0].key);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        if (node != 0) printf(" %d",tree99[node].key);
        if (tree99[node].left != -1) q.push(tree99[node].left);
        if (tree99[node].right != -1) q.push(tree99[node].right);
    }
    return 0;
}