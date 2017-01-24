//
// Created by 胡文杰 on 2017/1/24.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct richest_55{
    char name[10];
    int age;
    int net;
};
bool cmp_55(richest_55 a,richest_55 b){
    if (a.net != b.net) return a.net > b.net;
    else if (a.age != b.age) return a.age < b.age;
    else return (strcmp(a.name,b.name) < 0);
}

int pat_1055(){
    int n, k;
    scanf("%d %d",&n,&k);
    richest_55 *richestes = new richest_55[n];
    vector<richest_55> richests;
    vector<int> book(205,0); //标记每个年龄段不超过100个人进入统计
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d",richestes[i].name,&richestes[i].age,&richestes[i].net);
    }
    sort(richestes, richestes+n, cmp_55);
    for (int i = 0; i < n; i++) {
        if (book[richestes[i].age] < 100){
            richests.push_back(richestes[i]);
            book[richestes[i].age]++;
        }
    }
    for (int i = 0; i < k; i++) {
        vector<richest_55> con;
        int num, start, end;
        scanf("%d %d %d",&num,&start,&end);
        for (int j = 0; j < richests.size(); j++) {
            if (richests[j].age >= start && richests[j].age <= end) {
                con.push_back(richests[j]);
            }
        }
        printf("Case #%d:\n",i+1);
        int len = con.size();
        if (len == 0) printf("None\n");
        else {
            for (int j = 0; j < num && j < len; j++) {
                printf("%s %d %d\n",con[j].name,con[j].age,con[j].net);
            }
        }
    }
    return 0;
}