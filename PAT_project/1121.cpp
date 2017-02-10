//
// Created by 胡文杰 on 2017/2/10.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int pat_1121(){
    int n,m;
    vector<int> marrier(100000,-1);
    vector<int> book(100000,0);
    vector<int> ans;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int a1,a2;
        scanf("%d %d",&a1,&a2);
        marrier[a1] = a2;
        marrier[a2] = a1;
    }
    scanf("%d",&m);
    vector<int> guest(m);
    for (int i = 0; i < m; ++i) {
        int a;
        scanf("%d",&a);
        guest[i] = a;
        if (marrier[a] != -1){
            book[a] ++;
            book[marrier[a]] ++;
        } else {
            book[a] ++;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (book[guest[i]] == 1) ans.push_back(guest[i]);
    }
    sort(ans.begin(),ans.end());
    printf("%lu\n",ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (i == 0) printf("%05d",ans[i]);
        else printf(" %05d",ans[i]);
    }
    return 0;
}