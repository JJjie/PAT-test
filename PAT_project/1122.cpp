//
// Created by 胡文杰 on 2017/2/10.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

int pat_1122(){
    int n,m,k,n1;
    scanf("%d %d",&n,&m);
    vector<vector<bool>> gragh(n+1);
    for (int i = 0; i <= n; ++i) {
        gragh[i].resize(n+1, false);
    }
    for (int i = 0; i < m; ++i) {
        int a,b;
        scanf("%d %d",&a,&b);
        gragh[a][b] = true;
        gragh[b][a] = true;
    }
    scanf("%d",&k);
    vector<int> query;
    for (int i = 0; i < k; ++i) {
        scanf("%d",&n1);
        query.resize(n1);
        for (int j = 0; j < n1; ++j) {
            scanf("%d",&query[j]);
        }
        if (n1 != n+1) {
            printf("NO\n");
        } else {
            if (query[0] != query[n1-1]){
                printf("NO\n");
            } else {
                vector<bool> visited(n+1, false);
                bool flag = true;
                int j;
                for (j = 0; j < n1-1; ++j) {
                    if (!gragh[query[j]][query[j+1]]) {
                        flag = false;
                    }
                    visited[query[j]] = true;
                }
                visited[query[j]] = true;
                for (j = 1; j <= n; ++j) {
                    if (!visited[j]) flag = false;
                }
                if (flag) printf("YES\n");
                else printf("NO\n");
            }
        }
        query.clear();
    }
    return 0;
}