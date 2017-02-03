//
// Created by 胡文杰 on 2017/2/3.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu_80{
    int id;
    int ge;
    int gi;
    int grade;
    int rank;
    vector<int> select;
};

struct sch_80{
    int quota;
    vector<int> student;
    int lastrank = -1;
};
bool cmp_80(stu_80 a,stu_80 b){
    if (a.grade == b.grade){
        return a.ge > b.ge;
    } else{
        return a.grade > b.grade ;
    }
}

int pat_1080(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    vector<sch_80> school(m);
    vector<stu_80> students(n);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&school[i].quota);
    }
    for (int i = 0; i < n; ++i) {
        int ge,gi;
        scanf("%d %d",&ge,&gi);
        students[i].id = i;
        students[i].ge = ge;
        students[i].gi = gi;
        students[i].grade = (ge+gi)/2;
        for (int j = 0; j < k; ++j) {
            int a;
            scanf("%d",&a);
            students[i].select.push_back(a);
        }
    }
    sort(students.begin(),students.end(),cmp_80);
    int rank = 1,grade = students[0].grade,ge = students[0].ge;
    for (int i = 0; i < n; ++i) {
        if (students[i].grade == grade && students[i].ge == ge){
            students[i].rank = rank;
        } else {
            rank = i+1;
            grade = students[i].grade;
            ge = students[i].ge;
            students[i].rank = rank;
        }
    }
    for (int i = 0; i < n; ++i) {
        int len = students[i].select.size();
        for (int j = 0; j < len; ++j) {
            int index = students[i].select[j];
            if (school[index].quota > 0 ){
                school[index].student.push_back(students[i].id);
                school[index].quota--;
                school[index].lastrank = students[i].rank;
                break;
            } else if (school[index].quota == 0 && school[index].lastrank == students[i].rank){
                school[index].student.push_back(students[i].id);
                break;
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        int len = school[i].student.size();
        sort(school[i].student.begin(),school[i].student.end());
        for (int j = 0; j < len; ++j) {
            if (j == 0) printf("%d",school[i].student[j]);
            else printf(" %d",school[i].student[j]);
        }
        printf("\n");
    }
    return 0;
}