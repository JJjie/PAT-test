//
// Created by 胡文杰 on 2017/1/17.
//

#include "pat.h"
#include <iostream>
#include <vector>
using namespace std;

struct customer_34{
    string name;
    string passwd;
};

int pat_1035(){
    int n;
    vector<customer_34> customers;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string name, passwd;
        cin >> name >> passwd;
        int len = passwd.length();
        bool flag = false;
        for (int j = 0; j < len; j++) {
            switch (passwd[j]) {
                case '1' : passwd[j] = '@'; flag = true; break;
                case '0' : passwd[j] = '%'; flag = true; break;
                case 'l' : passwd[j] = 'L'; flag = true; break;
                case 'O' : passwd[j] = 'o'; flag = true; break;
            }
        }
        customer_34 cus;
        cus.name = name;
        cus.passwd = passwd;
        if (flag) customers.push_back(cus);
    }

    int len = customers.size();
    if (n == 1 && len == 0){
        cout << "There is 1 account and no account is modified" << endl;
    }else if (n != 1 && len == 0 ){
        cout << "There are " << n << " account and no account is modified" << endl;
    }else{
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            cout << customers[i].name << " " << customers[i].passwd << endl;
        }
    }

    return 0;
}