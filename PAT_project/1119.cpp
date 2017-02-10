//
// Created by 胡文杰 on 2017/2/10.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;
int *pre119, *post119;
bool unique119 = true;
vector<int> ans119;

int findFromPre (int x, int l, int r) {
    for (int i = l; i <= r; i++) {
        if (x == pre119[i]) {
            return i;
        }
    }
    return -1;
}
void setIn(int prel,int prer,int postl,int postr){
    if (prel == prer){
        ans119.push_back(pre119[prel]);
        return;
    }
    if (pre119[prel] == post119[postr]){ //找到根节点
        int x = findFromPre(post119[postr-1], prel+1, prer);
        if (x - prel > 1){
            setIn(prel + 1, x - 1, postl, postl + x - prel - 2);
            ans119.push_back(post119[postr]);
            setIn(x, prer, postl + x - prel - 2 + 1, postr - 1);
        } else {
            unique119 = false;
            ans119.push_back(post119[postr]);
            setIn(x, prer, postl+x-prel-2+1, postr-1);
        }
    }
}
int pat_1119(){
    int n;
    scanf("%d",&n);
    pre119 = new int[n];
    post119 = new int[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&pre119[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d",&post119[i]);
    }
    setIn(0,n-1,0,n-1);
    printf("%s\n", (unique119) ? "Yes" : "No");
    for (int i = 0; i < ans119.size(); ++i) {
        if (i == 0) printf("%d",ans119[i]);
        else printf(" %d",ans119[i]);
    }
    printf("\n");
    return 0;
}