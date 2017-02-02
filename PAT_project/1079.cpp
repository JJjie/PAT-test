//
// Created by 胡文杰 on 2017/2/2.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node_79{
    double data;
    vector<int> child;
};
vector<node_79> v79;
double ans79 = 0.0;

void DFS_79(int index, int depth, double r){
    if (v79[index].child.size() == 0){
        ans79 += v79[index].data * pow(r+1,depth);
        return;
    }
    for (int i = 0; i < v79[index].child.size(); ++i) {
        DFS_79(v79[index].child[i],depth+1,r);
    }
}

int pat_1079(){
    int n,k,a;
    double price,r;
    scanf("%d %lf %lf",&n,&price,&r);
    r = r / 100;
    v79.resize(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        if (k == 0){
            scanf("%lf",&v79[i].data);
        } else {
            for (int j = 0; j < k; ++j) {
                scanf("%d",&a);
                v79[i].child.push_back(a);
            }
        }
    }
    DFS_79(0,0,r);
    printf("%.1f",ans79 * price);
    return 0;
}