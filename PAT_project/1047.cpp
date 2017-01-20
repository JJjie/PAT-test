//
// Created by 胡文杰 on 2017/1/20.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct course_47{
    vector<string> stus;
};

int pat_1047(){
    int n, k;
    cin >> n >> k;
    course_47 * course = new course_47[k+1];
    for (int i = 0; i < n; i++) {
        int ans, temp;
        string name;
        cin >> name >> ans;
        for (int j = 0; j < ans; j++) {
            cin >> temp;
            course[temp].stus.push_back(name);
        }
    }
    for (int i = 1; i <= k; i++) {
        int len = course[i].stus.size();
        cout << i << " " << len << endl;
        sort(course[i].stus.begin(), course[i].stus.end());
        for (int j = 0; j < len; j++) {
            cout << course[i].stus[j] << endl;
        }
    }
    delete[] course;
    return 0;
}