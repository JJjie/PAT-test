//
// Created by 胡文杰 on 2017/2/8.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> v106;
double ans106 = 0.0;
int count106 = 1;
void DFS_106(int index, int depth, double r){
    if (v106[index].size() == 0){
        if (ans106 == 0.0){
            ans106 = pow(r,depth);
        } else {
            double p = pow(r,depth);
            if (ans106 == p) count106++;
            else if (ans106 > p) {
                count106 = 1;
                ans106 = p;
            }
        }
        return;
    }
    for (int i = 0; i < v106[index].size(); ++i) {
        DFS_106(v106[index][i],depth+1,r);
    }
}

int pat_1106(){
    int n,k,a;
    double price,r;
    scanf("%d %lf %lf",&n,&price,&r);
    r = 1.0 + r / 100;
    v106.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        for (int j = 0; j < k; ++j) {
            scanf("%d",&a);
            v106[i].push_back(a);
        }
    }
    DFS_106(0,0,r);
    printf("%.4f %d",ans106 * price,count106);
    return 0;
}