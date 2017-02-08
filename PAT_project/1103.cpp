//
// Created by 胡文杰 on 2017/2/8.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> con103,ans,tempAns;
int maxFacSum = -1;
void dfs(int index, int tempSum, int tempK, int facSum, int n, int k) {
    if(tempSum == n && tempK == k) {
        if(facSum > maxFacSum) {
            ans = tempAns;
            maxFacSum = facSum;
        }
        return ;
    }
    if(tempSum > n || tempK > k) return ;
    if(index >= 1) {
        tempAns.push_back(index);
        dfs(index, tempSum + con103[index], tempK + 1, facSum + index, n, k);
        tempAns.pop_back();
        dfs(index - 1, tempSum, tempK, facSum, n, k);
    }
}
int pat_1103(){
    int n,k,p;
    scanf("%d %d %d",&n,&k,&p);
    int index = 1,temp = 0;
    while (temp < n){
        con103.push_back(temp);
        temp = pow(index,p);
        index++;
    }
    dfs(con103.size()-1,0,0,0,n,k);
    if(maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}