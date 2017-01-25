//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int pat_1061(){
    string a,b,c,d;
    cin >> a >> b >> c >> d;
    char temp[2];//存星期与小时
    int pos; //存分钟
    int j;
    int lena = a.length();
    int lenb = b.length();
    int min1 = min(lena,lenb);
    int lenc = c.length();
    int lend = d.length();
    int min2 = min(lenc,lend);
    string weekday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    for (int i = 0; i < min1; i++) {
        if (a[i] == b[i] && ((a[i] >= 'A') && (a[i] <= 'G'))){
            temp[0] = a[i];
            a[i] = '#';
            j = i;
            break;
        }
    }
    for (int i = j; i < min1; i++) {
        if (a[i] == b[i] && (((a[i] >= 'A') && (a[i] <= 'N')) || ((a[i] >= '0') && a[i] <= '9'))){
            temp[1] = a[i];
            break;
        }
    }
    for (int i = 0; i < min2; ++i) {
        if (c[i] == d[i] && ((c[i] >= 'A' && c[i] <= 'Z')||(c[i] >= 'a' && c[i] <= 'z'))){
            pos = i;
            break;
        }
    }
    int hour;
    if (temp[1] >= '0' && temp[1] <= '9'){
        hour = temp[1] - '0';
    } else {
        hour = 10 + temp[1] - 'A';
    }
    cout << weekday[temp[0] - 'A'] << " "
         << setfill('0') << setw(2) << hour << ":"
         << setfill('0') << setw(2) << pos << endl;
    return 0;
}