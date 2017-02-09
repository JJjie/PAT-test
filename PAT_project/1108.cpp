//
// Created by 胡文杰 on 2017/2/9.
//

#include "pat.h"
#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

bool judgestr(string s){
    int len = s.length();
    bool ans = true;
    int index = 0;
    for (int i = 0; i < len; ++i) {
        if (i == 0 && s[i] == '-') continue;
        if (s[i] == '.' && index == 0){
            index = i;
            if (len - index > 3) {
                ans = false;
                break;
            }
            continue;
        }
        if (!isdigit(s[i])) {
            ans = false;
            break;
        }
    }
    return ans;
}
int pat_1108(){
    int n;
    cin >> n;
    double sum = 0.0;
    int num = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        bool flag = judgestr(s);
        if (!flag) {
            cout << "ERROR: " << s << " is not a legal number" << endl;
        } else {
            int index=0;
            int t = 0;
            bool temp = (s[0] == '-');
            for (int j = 0; j < s.length(); ++j) {
                if (s[j] == '.'){
                    index = j;
                    continue;
                }
                if (isdigit(s[j])) {
                    t = t*10 + (int)(s[j] - '0');
                }
            }
            double ans;
            if (index != 0){
                ans = (double)t / (float)pow(10,s.length()-1-index);
            } else {
                ans = (double)t;
            }
            if (temp) {
                ans = -ans;
            }
            if (ans > 1000.0 || ans < -1000.0)
                cout << "ERROR: " << s << " is not a legal number" << endl;
            else {
                sum += ans;
                num++;
            }
        }
    }
    if (num == 0){
        printf("The average of 0 numbers is Undefined");
    } else {
        printf("The average of %d numbers is %.2f",num,sum/(double)num);
    }
    return 0;
}