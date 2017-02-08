//
// Created by 胡文杰 on 2017/2/8.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp_105(int a, int b){
    return a > b;
}
int pat_1105(){
    int N,m,n;
    scanf("%d",&N);
    vector<int> num(N);
    for (int i = 0; i < N; ++i) {
        scanf("%d",&num[i]);
    }
    sort(num.begin(),num.end(),cmp_105);
    m = N,n = 1;
    while (m > n){
        n++;
        if (N % n == 0) m = N/n;
    }
    swap(n,m);
    int ans[m][n];
    int level = m / 2 + m % 2;
    int t = 0;
    for (int i = 0; i < level; i++) {
        for (int j = i; j <= n - 1 - i && t <= N - 1; j++)
            ans[i][j] = num[t++];
        for (int j = i + 1; j <= m - 2 - i && t <= N - 1; j++)
            ans[j][n - 1 - i] = num[t++];
        for (int j = n - i - 1; j >= i && t <= N - 1; j--)
            ans[m - 1 - i][j] = num[t++];
        for (int j = m - 2 - i; j >= i + 1 && t <= N - 1; j--)
            ans[j][i] = num[t++];
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0) printf("%d",ans[i][j]);
            else printf(" %d",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}