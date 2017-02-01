//
// Created by 胡文杰 on 2017/2/1.
//

#include "pat.h"
#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

int pat_1071(){
    string s,t="";
    getline(cin, s);
    map<string, int> m;
    for (int i = 0; i < s.length(); ++i) {
        if (isalnum(s[i])){//判断字符是不是0-9，a-z,A-Z
            s[i] = tolower(s[i]);//单词不区分大小写
            t += s[i];
        } else{
            if (t.length())//说明是一个单词
                m[t] ++;
            t = "";
        }
    }
    if (t.length())m[t]++;
    int max = 0;
    for (auto it = m.begin(); it != m.end() ; it++) {
        if (it->second > max){
            max = it->second;
            t = it->first;
        }
    }
    cout << t << " " << max;
    return 0;
}