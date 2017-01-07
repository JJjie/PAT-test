//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double round(double d,int n);//对n位长度小数的四舍五入

int pat_1011(){
    string flag[3] = {"W ","T ","F "};
    string result = "";
    double ans = 1.0;
    for (int i = 0; i < 3; i++) {
        double max = 0.0;
        int maxindex = 0;
        for (int j = 0; j < 3; j++) {
            double temp;
            cin >> temp;
            if (temp > max){
                max = temp;
                maxindex = j;
            }
        }
        ans *= max;
        result.append(flag[maxindex]);
    }
    double r = (ans * 0.65 - 1) * 2;
    cout << result << fixed << setprecision(2) << r << endl;

    return 0;
}

double round(double d,int n){
    int N = 1;
    for (int i = 0; i < n; ++i) {
        N *= 10;
    }
    d = d * N;
    double tag = (double)(int)(d);
    double temp = (d * N) - tag;
    if (temp > 0.4){
        d += 0.5;
    }
    d = d / N;
    return d;

}