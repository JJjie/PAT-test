//
// Created by 胡文杰 on 2017/1/19.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>;
using namespace std;

struct student_36{
    string name;
    char gender;
    string ID;
    int grade;
};
bool cmpM(student_36 &A, student_36 &B){
    return A.grade < B.grade;
}
bool cmpF(student_36 &A, student_36 &B){
    return A.grade > B.grade;
}

int pat_1036(){
    int n;
    cin >> n;
    vector<student_36> Mstudents ;
    vector<student_36> Fstudents ;
    for (int i = 0; i < n; i++) {
        student_36 temp;
        char g;
        cin >> temp.name >> g >> temp.ID >> temp.grade;
        temp.gender = g;
        if (g == 'F'){
            Fstudents.push_back(temp);
        }else if (g == 'M'){
            Mstudents.push_back(temp);
        }
    }
    sort(Mstudents.begin(), Mstudents.end(), cmpM);
    sort(Fstudents.begin(), Fstudents.end(), cmpF);

    if (Mstudents.empty() && Fstudents.empty()){
        cout << "Absent\nAbsent\nNA" << endl;
    }else if (!Mstudents.empty() && Fstudents.empty()){
        cout << "Absent\n" << Mstudents[0].name << " " << Mstudents[0].ID << "\nNA" << endl;
    }else if (Mstudents.empty() && !Fstudents.empty()){
        cout << Fstudents[0].name << " " << Fstudents[0].ID << "\nAbsent\nNA" << endl;
    } else{
        int diff = Mstudents[0].grade - Fstudents[0].grade;
        diff = abs(diff);
        cout << Fstudents[0].name << " " << Fstudents[0].ID << '\n'
             << Mstudents[0].name << " " << Mstudents[0].ID << '\n'
             << diff << endl;
    }


    return 0;
}