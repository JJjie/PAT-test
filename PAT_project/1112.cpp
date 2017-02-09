//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int pat_1112(){
    int k;
    cin >> k;
    string str;
    cin >> str;
    int len = str.length();
    map<char,int> mapp;
    for (int i = 0; i < len; ++i) {
        bool flag = true;
        for (int j = 0; j < k; ++j)
            if (str[i] != str[i+j])
                flag = false;
        if (flag){
            if (mapp[str[i]] != 2 ){
                mapp[str[i]] = 1;
                i = i+k-1;
            }
        } else {
            mapp[str[i]] = 2;
        }
    }
    set<char> printed;
    for (int i = 0; i < len; ++i) {
        if (mapp[str[i]] == 1 && printed.find(str[i])==printed.end()){
            cout << str[i];
            printed.insert(str[i]);
        }
    }
    cout << endl;
    string ans = "";
    for (int i = 0; i < len; ++i) {
        if (mapp[str[i]] == 2){
            ans += str[i];
        } else if (mapp[str[i]] == 1) {
            ans += str[i];
            i += k-1;
        }
    }
    cout << ans;
    return 0;
}