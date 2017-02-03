//
// Created by 胡文杰 on 2017/2/3.
//

#include "pat.h"
#include <iostream>
#include <map>
#include <queue>
using namespace std;

int pat_1084(){
    string str1;
    string str2;
    cin >> str1 >> str2;
    map<char,int> s;
    queue<char> q;
    int len = str1.length();
    int index = 0;
    for (int i = 0; i < len; ++i) {
        if (str1[i] != str2[index]) {
            char c = (char)toupper(str1[i]);
            if (s[c] != 1){
                s[c] = 1;
                q.push(c);
            }
        } else {
            index ++;
        }
    }
    while (!q.empty()){
        cout << q.front();
        q.pop();
    }
    return 0;
}