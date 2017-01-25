//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define min(a,b) ((a < b) ? a : b)

vector<int> in64,level64;
void levelorder(int start, int end, int index){ //完全二叉搜索树中序得前序
    if (start > end) return;
    int n = end - start + 1; //子树节点数
    int l = log(n+1) / log(2); //得到层数
    int leave = n - (pow(2,l)-1); // 最底层的结点数（包括左子树底层与右子树底层之和）
    int root = start + pow(2, l-1) -1 + min(pow(2, l-1),leave);
    level64[index] = in64[root];
    levelorder(start, root - 1, 2 * index + 1); // 左子递归
    levelorder(root + 1, end, 2 * index + 2); // 右子递归
}

int pat_1064(){
    int n;
    scanf("%d",&n);
    in64.resize(n);
    level64.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&in64[i]);
    }
    sort(in64.begin(),in64.end());//对于二叉搜索树，中序就是递增有序的
    levelorder(0,n-1,0);
    printf("%d",level64[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d",level64[i]);
    }
    return 0;
}