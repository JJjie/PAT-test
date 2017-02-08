//
// Created by 胡文杰 on 2017/2/8.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tree102_102{
    int left;
    int right;
};
vector<tree102_102> tree102;
vector<int> in102;
void inorder_102(int index){
    if (index == -1) return;
    inorder_102(tree102[index].left);
    in102.push_back(index);
    inorder_102(tree102[index].right);
}
int pat_1102(){
    int n;
    scanf("%d",&n);
    getchar();
    tree102.resize(n);
    vector<bool> book(n, false);
    for (int i = 0; i < n; ++i) {
        char left,right;
        int l,r;
        scanf("%c %c",&left,&right);
        getchar();
        l = (left == '-') ? -1 : (left - '0');
        r = (right == '-') ? -1 : (right - '0');
        tree102[i].left = r;
        tree102[i].right = l;
        if (tree102[i].left != -1) book[tree102[i].left] = true;
        if (tree102[i].right != -1) book[tree102[i].right] = true;
    }
    int root;
    for (int i = 0; i < n; ++i) {
        if (!book[i]) {
            root = i;
            break;
        }
    }
//    层序遍历
    queue<int> q;
    q.push(root);
    vector<int> level;
    while (!q.empty()){
        int current = q.front();
        q.pop();
        if (tree102[current].left != -1) q.push(tree102[current].left);
        if (tree102[current].right != -1) q.push(tree102[current].right);
        level.push_back(current);
    }
    for (int i = 0; i < level.size(); ++i) {
        if (i == 0) printf("%d",level[i]);
        else printf(" %d",level[i]);
    }
    printf("\n");
//    中序遍历
    inorder_102(root);
    for (int i = 0; i < in102.size(); ++i) {
        if (i == 0) printf("%d",in102[i]);
        else printf(" %d",in102[i]);
    }
    printf("\n");
    return 0;
}