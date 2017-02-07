//
// Created by 胡文杰 on 2017/2/6.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tree90;
int cnt90 = 0,num90 = 0;
void DFS_90(int root, int depth){
    int len = tree90[root].size();
    if (len == 0){
        if (depth > cnt90) {
            cnt90 = depth;
            num90 = 1;
        } else if (depth == cnt90) {
            num90 ++;
        }
        return;
    }
    for (int i = 0; i < len; ++i) {
        DFS_90(tree90[root][i],depth+1);
    }
}

int pat_1090(){
    int n;
    double price,rate;
    scanf("%d %lf %lf",&n,&price,&rate);
    rate = 1.0 + rate / 100;
    tree90.resize(n);
    int root;
    for (int i = 0; i < n ; ++i) {
        int a;
        scanf("%d",&a);
        if (a == -1){
            root = i;
        } else {
            tree90[a].push_back(i);
        }
    }
//    dfs
    DFS_90(root,0);
    for (int i = 0; i < cnt90; ++i) {
        price = price * rate;
    }
    printf("%.2f %d",price,num90);
    return 0;
}