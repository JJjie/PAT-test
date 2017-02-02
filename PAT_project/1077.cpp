//
// Created by 胡文杰 on 2017/2/2.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1077(){
    int n;
    scanf("%d",&n);
    getchar();
    string ans;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin,s);
        int len = s.length();
        for (int j = 0; j < len/2; ++j) {
            swap(s[j],s[len-1-j]);
        }
        if (i == 0){
            ans = s;
            continue;
        } else {
            int lens = ans.length();
            int minlen = min(len,lens);
            for (int j = 0; j < minlen; ++j) {
                if (ans[j] != s[j]){
                    ans = ans.substr(0,j);
                    break;
                }
            }
        }
    }
    if(ans.length() == 0) {
        printf("nai");
    } else {
        for(int i = ans.length() - 1; i >= 0; i--) {
            printf("%c", ans[i]);
        }
    }
    return 0;
}