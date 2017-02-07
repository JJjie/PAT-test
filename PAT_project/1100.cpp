//
// Created by 胡文杰 on 2017/2/7.
//

#include "pat.h"
#include <iostream>
#include <cctype>
using namespace std;
string a100[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct",
                "nov", "dec"};
string b100[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy",
                "lok", "mer", "jou"};
int pat_1100(){
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        if (isdigit(s[0])){
            int len = s.length();
            int num = 0;
            for (int j = 0; j < len; ++j) {
                num = num * 10 + (s[j] - '0');
            }
            cout << b100[num / 13];
            if ((num % 13) && (num / 13)) cout << " " << a100[num % 13];
            else if (num % 13 || num == 0) cout << a100[num % 13];
        } else {
            int len = s.length();
            int num = 0;
            if (len == 4){
                cout << "0";
            } else if (len == 3){
                for (int j = 1; j < 13; ++j) {
                    if (s == a100[j]){
                        cout << j;
                        break;
                    }
                    if (s == b100[j]){
                        cout << j*13;
                        break;
                    }
                }
            } else {
                string temp1 = s.substr(0, 3);
                string temp2 = s.substr(4, 3);
                for (int j = 1; j < 13; j++) {
                    if (temp1 == b100[j]) {
                        num += j * 13;
                    }
                    if (temp2 == a100[j]) {
                        num += j;
                    }
                }
                cout << num;
            }
        }
        cout << endl;
    }
    return 0;
}