//
// Created by 胡文杰 on 2017/2/10.
//

#include "pat.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int pat_1120(){
    int n;
    scanf("%d",&n);
    map<int,set<string>> mapp;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int num = 0;
        for (int j = 0; j < s.length(); ++j) {
            num += (int)(s[j] - '0');
        }
        mapp[num].insert(s);
    }
    vector<int> ans;
    for (auto it = mapp.begin(); it != mapp.end() ; it++) {
        int num = it->first;
        ans.push_back(num);
    }
    sort(ans.begin(),ans.end());
    printf("%lu\n",ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        if (i == 0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
    return 0;
}