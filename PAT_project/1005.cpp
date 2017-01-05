//
//  1005.cpp
//  PAT_project
//
//  Created by 胡文杰 on 2017/1/5.
//  Copyright © 2017年 胡文杰. All rights reserved.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

int pat_1005(){
    string s[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    string str;
    int sum=0;
    cin >> str;
    for (int i=0; i<str.length(); i++) {
        sum += (str[i] - '0');//字符转数字
    }
    
    vector<int> container;
    while (sum != 0) {
        container.push_back(sum % 10);
        sum = sum / 10;
    }
    
    int len = container.size();
    if (container.empty()) {
        cout << s[0];
    }else{
        cout << s[container[len-1]];
        for (int i=len-2; i>-1; i--) {
            cout << " " << s[container[i]];
        }
    }
    cout << endl;
    
    //释放内存
    vector<int>(container).swap(container);
    
    return 0;
}
