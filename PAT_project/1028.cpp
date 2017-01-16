//
// Created by 胡文杰 on 2017/1/16.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
using namespace std;

struct student_28{
    int ID;
    string name;
    int grade;
};
bool up_id(student_28 &a, student_28 &b){
    return a.ID < b.ID;
}
bool down_name(student_28 &a, student_28 &b){
    if (a.name == b.name){
        return a.ID < b.ID;
    }else{
        return a.name <= b.name;
    }
}
bool down_grade(student_28 &a, student_28 &b){
    if (a.grade == b.grade){
        return a.ID < b.ID;
    }else{
        return a.grade <= b.grade;
    }

}
int pat_1028(){
    int N,C;
    cin >> N >> C;
    student_28 *stus = new student_28[N];
    for (int i = 0; i < N; i++) {
        cin >> stus[i].ID >> stus[i].name >> stus[i].grade;
    }

    if (C == 1){
        sort(stus, stus+N, up_id);
    }else if (C == 2){
        sort(stus, stus+N, down_name);
    }else if (C == 3){
        sort(stus, stus+N, down_grade);
    }
    for (int i = 0; i < N; i++) {
        cout << setfill('0') << setw(6) << stus[i].ID << " "
             << stus[i].name << " "
             << stus[i].grade << endl;
    }
    delete[] stus;
    return 0;
}