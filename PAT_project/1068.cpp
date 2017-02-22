//
// Created by 胡文杰 on 2017/1/30.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_68(int a,int b){
    return a > b;
}

int pat_1068(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> wallet; //纸币面值
    vector<vector<int> > dp;//能凑齐需求的组合(i-遍历的纸币数，j-剩余容量)
    vector<vector<bool> > included;//标记是否使用
    wallet.resize(n+1);
    for (int i = 1; i <= n ; ++i) {
        scanf("%d",&wallet[i]);
    }
    dp.resize(n+1);
    for (int i = 0; i <= n ; ++i) {
        dp[i].resize(m+1);
    }
    included.resize(m+1);
    for (int i = 0; i <= m ; ++i) {
        included[i].resize(n+1);
    }
    sort(wallet.begin()+1,wallet.end(),cmp_68);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m ; ++j) {
            if (j < wallet[i] || dp[i-1][j]>wallet[i] + dp[i-1][j-wallet[i]]){
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = wallet[i] + dp[i - 1][j - wallet[i]];
                included[j][i]=true;
            }
        }
    }
//    打印dp与include记录
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("/*****************/\n");
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            printf("%d ", (int)included[j][i]);
        }
        printf("\n");
    }

    if (dp[n][m] != m) {
        printf("No Solution\n");
    }
    else {
        bool first = true;
        for (int i = n; i >= 1 && m > 0; i--) {
            if (included[m][i]) {
                if (first) {
                    printf("%d", wallet[i]);
                    first = false;
                }
                else {
                    printf(" %d", wallet[i]);
                }
                m -= wallet[i];
            }
        }
        printf("\n");
    }
    return 0;
}