//
// Created by 胡文杰 on 2017/2/3.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

struct stu_83{
    string name;
    string id;
    int grade;
};
bool cmp_83(stu_83 a, stu_83 b){
    return a.grade > b.grade;
}
int pat_1083(){
    int n,low,high;
    cin >> n;
    vector<stu_83> students(n);
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].id >> students[i].grade;
    }
    cin >> low >> high;
    sort(students.begin(), students.end(),cmp_83);
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (students[i].grade >= low && students[i].grade <= high){
            cout << students[i].name << " " << students[i].id << endl;
            flag = true;
        }
    }
    if (!flag) cout << "NONE" << endl;
    return 0;
}