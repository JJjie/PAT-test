//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree94;
int book94[101];
void DFS_94(int root, int level){
    book94[level] += 1;
    if (tree94[root].size() == 0) return;
    for (int i = 0; i < tree94[root].size(); ++i) {
        DFS_94(tree94[root][i],level+1);
    }
}

int pat_1094(){
    int n,m;
    scanf("%d %d",&n,&m);
    tree94.resize(n+1);
    fill(book94,book94+101,0);
    for (int i = 0; i < m; ++i) {
        int index,num;
        scanf("%d %d",&index,&num);
        for (int j = 0; j < num; ++j) {
            int a;
            scanf("%d",&a);
            tree94[index].push_back(a);
        }
    }
    DFS_94(1,1);
    int num=0,index=1;
    for (int i = 1; i < 101; ++i) {
        if (book94[i] > num){
            num = book94[i];
            index = i;
        }
    }
    printf("%d %d\n",num,index);
    return 0;
}