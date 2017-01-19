//
// Created by 胡文杰 on 2017/1/19.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp_38 (string a, string b){
    return a+b < b+a;
}
int pat_1038(){
    int n;
    cin >> n;
    string *strs = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
    }
    sort(strs, strs+n, cmp_38);
    string s;
    for (int i = 0; i < n; i++) {
        s += strs[i];
    }
    while (s.length() != 0 && s[0] == '0'){
        s.erase(s.begin());
    }
    if (s.length() == 0){
        cout << 0 << endl;
    }else{
        cout << s << endl;
    }
    return 0;
}