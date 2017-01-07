//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

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
    cout << result << fixed << setprecision(2) << (ans * 0.65 - 1) * 2 << endl;

    return 0;
}