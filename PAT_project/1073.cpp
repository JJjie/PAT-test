//
// Created by 胡文杰 on 2017/2/1.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1073(){
    string str;
    cin >> str;
    if (str[0] == '-') cout << '-';
    int indexE = 0;
    for (int i = str.length(); i >= 0 ; i--) {
        if (str[i] == 'E') {
            indexE = i;
            break;
        }
    }
    int exponent = 0;
    for (int i = indexE+2; i < str.length() ; ++i) {
        exponent = (int)(str[i] - '0') + exponent*10;
    }
    if (str[indexE+1] == '-'){
        if (exponent > 0){
            cout << "0.";
            for (int i = 0; i < exponent-1; ++i) {
                cout << "0";
            }
            for (int i = 1; i < indexE; ++i) {
                if (str[i] != '.'){
                    cout << str[i];
                }
            }
        } else {
            for (int i = 1; i < indexE; ++i) {
                cout << str[i];
            }
        }
    } else {
        if (exponent > 0){
            int exp = exponent - indexE + 3;
            if (exp < 0){
                for (int i = 1; i < indexE; ++i) {
                    if (i == 3+exponent) cout << ".";
                    if (str[i] != '.' ){
                        cout << str[i];
                    }
                }
            } else {
                for (int i = 1; i < indexE; ++i) {
                    if (str[i] != '.' ){
                        cout << str[i];
                    }
                }
                for (int j = 1; j <= exp; ++j) {
                    cout << "0";
                }
            }
        } else {
            for (int i = 1; i < indexE; ++i) {
                cout << str[i];
            }
        }
    }
    return 0;
}