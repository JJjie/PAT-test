//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct student {
    int ID, cs, math, en;
    int av;
    int crank, mrank, erank, arank;
};

int average(student &stu);
int findstu(student* &stu, int N, int target);
void stuRank(student* &stu, int N);
//sort函数cmp参数
bool up_cs(student &A, student&B);
bool up_math(student &A, student&B);
bool up_en(student &A, student&B);
bool up_av(student &A, student&B);
bool down_ID(student &A, student&B);

int pat_1012(){
    int N, M;
    int ID;
    cin >> N >> M;
    student * stu = new student[N];
    for (int i = 0; i < N; i++) {
        cin >> stu[i].ID >> stu[i].cs >> stu[i].math >> stu[i].en ;
        stu[i].av = average(stu[i]);
    }
    stuRank(stu, N);
    sort(stu, stu+N, down_ID);//回归按学号的升序排序
    for (int i = 0; i < M; i++) {
        cin >> ID;
        int p = findstu(stu, N, ID);
        if (p >= 0){
            int temp = stu[p].arank;
            char t = 'A';
            if (stu[p].crank < temp){
                temp = stu[p].crank;
                t = 'C';
            }else {
                if (stu[p].mrank < temp){
                    temp = stu[p].mrank;
                    t = 'M';
                }else {
                    if (stu[p].erank < temp){
                        temp = stu[p].erank;
                        t = 'E';
                    }
                }
            }
            cout << temp << " " << t << endl;
        }else{
            cout << "N/A" << endl;
        }
    }
//    释放内存
    delete[] stu;

    return 0;
}

int average(student &stu){
    int sum = stu.cs + stu.math + stu.en;
    return sum / 3;
}

//二分法搜索
int findstu(student* &stu, int N, int target){
    int low = 0,high = N-1;
    while (low <= high){
        int mid = (low + high) / 2;
        if (stu[mid].ID == target) return mid;
        else if (target > stu[mid].ID) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

bool up_cs(student &A, student&B){
    return A.cs > B.cs;
}
bool up_math(student &A, student&B){
    return A.math > B.math;
}
bool up_en(student &A, student&B){
    return A.en > B.en;
}
bool up_av(student &A, student&B){
    return A.av > B.av;
}
bool down_ID(student &A, student&B){
    return A.ID < B.ID;
}

void stuRank(student* &stu,int N){
    int i = 0;
    int tempscore = 0;
    int temprank = 0;//处理分数一样排名一样的情况
    int flag = 1;
    sort(stu, stu+N, up_cs);
    for ( i = 0; i < N; i++) {
        if (stu[i].cs == tempscore){
            stu[i].crank = temprank;
            flag++;
        } else{
            temprank += flag;
            flag = 1;
            stu[i].crank = temprank;
            tempscore = stu[i].cs;
        }
    }
    sort(stu, stu+N, up_math);
    tempscore = 0,temprank = 0,flag = 1;
    for ( i = 0; i < N; i++) {
        if (stu[i].math == tempscore){
            stu[i].mrank = temprank;
            flag++;
        } else{
            temprank += flag;
            flag = 1;
            stu[i].mrank = temprank;
            tempscore = stu[i].math;
        }
    }
    sort(stu, stu+N, up_en);
    tempscore = 0,temprank = 0,flag = 1;
    for ( i = 0; i < N; i++) {
        if (stu[i].en == tempscore){
            stu[i].erank = temprank;
            flag++;
        } else{
            temprank += flag;
            flag = 1;
            stu[i].erank = temprank;
            tempscore = stu[i].en;
        }
    }
    sort(stu, stu+N, up_av);
    tempscore = 0,temprank = 0,flag = 1;
    for ( i = 0; i < N; i++) {
        if (stu[i].av == tempscore){
            stu[i].arank = temprank;
            flag++;
        } else{
            temprank += flag;
            flag = 1;
            stu[i].arank = temprank;
            tempscore = stu[i].av;
        }
    }
}