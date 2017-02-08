//
// Created by 胡文杰 on 2017/2/8.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pat_1101(){
    int n;
    scanf("%d",&n);
    vector<int> s(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&s[i]);
        b[i] = s[i];
    }
    vector<int> ans;
    sort(s.begin(),s.end());
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (b[i] == s[i] && b[i] > max){
            ans.push_back(b[i]);
        }
        if (b[i] > max){
            max = b[i];
        }
    }
    printf("%lu\n",ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (i == 0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
    printf("\n");
    return 0;
}