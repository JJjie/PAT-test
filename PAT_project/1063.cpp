//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int pat_1063(){
    int n,m,k,t1,t2;
    scanf("%d",&n);
    vector<set<int>> v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&m);
        set<int> s;
        int temp;
        for (int j = 0; j < m; ++j) {
            scanf("%d",&temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d",&k);
    for (int i = 0; i < k; ++i) {
        scanf("%d %d",&t1,&t2);
        int nc = 0, nt = v[t2-1].size();
        for (/*auto*/set<int>::iterator it = v[t1-1].begin(); it != v[t1-1].end() ; it++) {
            if (v[t2-1].find(*it) == v[t2-1].end()) nt++;//找到v[t2]不存在的独立的元素
            else nc++;
        }
        float ans = (float)nc / nt * 100;
        printf("%.1f%%\n",ans);
    }
    return 0;
}