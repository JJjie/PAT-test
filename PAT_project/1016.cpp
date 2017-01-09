//
// Created by 胡文杰 on 2017/1/7.
//

#include "pat.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int toll[24];//每个时段的费用
int tollhour[24];//从0点开始到整点的费用
int tollday;

struct item{
    int d, h, m;
    bool condition;
};
struct itempair{
    int bd, bh, bm;
    int ed, eh, em;
    int time;
    float cost;
};
struct person{
    string name;
    int mth;
    vector<item> records;
    vector<itempair> outs;
    float TotalToll=0;
};
bool less_name(person &A, person &B);
bool less_time(item &A, item &B);

int pat_1016(){
    vector<person> people;//每个人的容器
    for (int i = 0; i < 24; i++) {//费用明细
        cin >> toll[i];
    }
    tollhour[0] = 0;
    for (int i = 1; i < 24; i++) {
        tollhour[i] = tollhour[i-1] + 60 * toll[i-1];
    }
    tollday = tollhour[23] + 60*toll[23];

    int N;
    cin >> N;
    item t;
    person p;
    string name,on_off;
    int Nname = 0;//记录有多少个人
    for (int i = 0; i < N; i++) {
        cin >> name;
        string tempname = name;
        int index = 0;
        if (Nname == 0){
            p.name = name;
            people.push_back(p);
            index = 0;
            Nname ++;
        }else{
            int j;
            for (j = 0; j < Nname; j++) {
                if (people[j].name == name){
                    index = j;
                    break;
                }
            }
            if (j == Nname){//people中没有匹配到的人
                p.name = name;
                people.push_back(p);
                index = Nname;
                Nname ++;
            }
        }
        scanf("%d:%d:%d:%d", &people[index].mth, &t.d, &t.h, &t.m);
        cin >> on_off;
        t.condition = (on_off == "on-line");
        people[index].records.push_back(t);
    }

//    对统计的数据排序规范化
    sort(people.begin(),people.end(),less_name);
    for (int i = 0; i < Nname; i++) {
        sort(people[i].records.begin(), people[i].records.end(),less_time);
        for (int j = 0; j < people[i].records.size(); j++) {
            cout << people[i].name << " " << setfill('0') << setw(2) << people[i].mth << ":" << setfill('0') << setw(2) << people[i].records[j].d << ":" << setfill('0') << setw(2) << people[i].records[j].h << ":" << setfill('0') << setw(2) << people[i].records[j].m << " " << people[i].records[j].condition << endl;
        }
    }

    itempair tp;
    for (int i = 0; i < Nname; i++) {
        int start=-1,end=-1;
        for (int j = 0; j < people[i].records.size(); j++) {
            for (int k = end+1; k < people[i].records.size(); k++) {//找出最早挂电话
                if (!people[i].records[k].condition) {
                    end = j;
                    break;
                }
            }
            for (int k = start+1; k < people[i].records.size(); k++) {
                if (people[i].records[k].condition && less_time(people[i].records[k],people[i].records[end])) start = j;
            }
            //判断是否有头有尾
            if (people[i].records[start].condition && !people[i].records[end].condition){
                tp.bd = people[i].records[start].d;
                tp.bh = people[i].records[start].h;
                tp.bm = people[i].records[start].m;
                tp.ed = people[i].records[end].d;
                tp.eh = people[i].records[end].h;
                tp.em = people[i].records[end].m;
                //计算消费
                int cd = tp.ed - tp.bd;
                int ch = tp.eh - tp.bh;
                int cm = tp.em - tp.bm;
                tp.time = cd*24*60 + ch*60 + cm;
                int cost = cd*tollday + tollhour[tp.eh] - tollhour[tp.bh] - tp.bm*toll[tp.bh] + tp.em*toll[tp.eh];
                tp.cost = ((cost >= 0) ? (float)cost/100 : 0);
                people[i].outs.push_back(tp);
                people[i].TotalToll += tp.cost;
            }
        }
    }

    for (int i = 0; i < Nname; i++) {
        cout << people[i].name << " " << setfill('0') << setw(2) << people[i].mth << endl;
        for (int j = 0; j < people[i].outs.size(); j++) {
            cout << setfill('0') << setw(2) << people[i].outs[j].bd << ":"
                 << setfill('0') << setw(2) << people[i].outs[j].bh << ":"
                 << setfill('0') << setw(2) << people[i].outs[j].bm << " "
                 << setfill('0') << setw(2) << people[i].outs[j].ed << ":"
                 << setfill('0') << setw(2) << people[i].outs[j].eh << ":"
                 << setfill('0') << setw(2) << people[i].outs[j].em << " "
                 << people[i].outs[j].time << " $"
                 << fixed << setprecision(2) << people[i].outs[j].cost << endl;
        }
        cout << "Total amount: $" << fixed << setprecision(2) << people[i].TotalToll << endl;
    }

    return 0;
}

bool less_name(person &A, person &B){
    bool result = (A.name < B.name);
    return result;
}

bool less_time(item &A, item &B){
    if (A.d < B.d){
        return true;
    }else{
        if (A.d == B.d && A.h < B.h) {
            return true;
        }else{
            if ((A.d == B.d) && (A.h == B.h) && (A.m <= B.m)){
                return true;
            } else{
                return false;
            }
        }
    }
}