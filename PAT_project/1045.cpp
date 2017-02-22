//
// Created by 胡文杰 on 2017/1/20.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

vector<int> favs_45;
vector<int> stripe_45;
vector<vector<int>> dp_45;

int lcs(int m, int n) { // 博客参考：http://www.aichengxu.com/other/8952954.htm
    if (m == 0 || n == 0) return 0;
    if (dp_45[m][n] != -1) return dp_45[m][n];
    if (favs_45[m - 1] == stripe_45[n - 1]) {
        dp_45[m][n - 1] = lcs(m, n - 1);
        dp_45[m][n] = dp_45[m][n - 1] + 1;
        return dp_45[m][n];
    }
    else {
        dp_45[m][n - 1] = lcs(m, n - 1);
        dp_45[m - 1][n] = lcs(m - 1, n);
        dp_45[m][n] = dp_45[m][n - 1] > dp_45[m - 1][n] ? dp_45[m][n - 1] : dp_45[m - 1][n];
        return dp_45[m][n];
    }
}

int pat_1045(){
    int n, m, l;
    cin >> n >> m;
    favs_45.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> favs_45[i];
    }
    cin >> l;
    stripe_45.resize(l);
    for (int i = 0; i < l; i++) {
        cin >> stripe_45[i];
    }
    dp_45.resize(m+1);
    for (int i = 0; i < m+1; i++) {
        dp_45[i].resize(l+1, -1);
    }
    cout << lcs(m,l) << endl;

    for (int i = 0; i < m + 1; i++) {
        for (int j = 0; j < l + 1; j++) {
            printf("%d ",dp_45[i][j]);
        }
        printf("\n");
    }

    return 0;
}

//// 采用lis的做法
//int book[201], a[10001], dp[10001];
//int main() {
//    int n, m, x, l, num = 0, maxn = 0;
//    scanf("%d %d", &n, &m);
//    for(int i = 1; i <= m; i++) {
//        scanf("%d", &x);
//        book[x] = i;
//    }
//    scanf("%d", &l);
//    for(int i = 0; i < l; i++) {
//        scanf("%d", &x);
//        if(book[x] >= 1)
//            a[num++] = book[x];
//    }
//    for (int i = 0; i < l; ++i) {
//        printf("%d ",a[i]);
//    }
//    printf("\n");
//    for(int i = 0; i < num; i++) {
//        dp[i] = 1;
//        for(int j = 0; j < i; j++)
//            if(a[i] >= a[j]) {
//                dp[i] = max(dp[i], dp[j] + 1);
//                printf("%d ",dp[i]);
//            }
//        printf("\n");
//        maxn = max(dp[i], maxn);
//    }
//    printf("%d", maxn);
//    return 0;
//}