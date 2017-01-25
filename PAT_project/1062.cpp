//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct people_62{
    int id;
    int virture;
    int talent;
};
bool cmp_62(people_62 a,people_62 b){
    if ((a.virture+a.talent) == (b.virture+b.talent)){
        if (a.virture == b.virture){
            return a.id < b.id;
        } else{
            return a.virture > b.virture;
        }

    }else {
        return (a.virture+a.talent) > (b.virture+b.talent);
    }
}
int pat_1062(){
    int n, lowgrade, highgrade;
    scanf("%d%d%d",&n,&lowgrade,&highgrade);
    vector<people_62> sage;
    vector<people_62> nobleman;
    vector<people_62> foolman;
    vector<people_62> smallman;
    for (int i = 0; i < n; ++i) {
        int id,v,t;
        scanf("%d%d%d",&id,&v,&t);
        if (v >= lowgrade && t >= lowgrade){
            if (v >= highgrade && t >= highgrade){
                people_62 p;
                p.id = id;
                p.virture = v;
                p.talent = t;
                sage.push_back(p);
            } else if (v >= highgrade && t < highgrade){
                people_62 p;
                p.id = id;
                p.virture = v;
                p.talent = t;
                nobleman.push_back(p);
            } else if (v<= highgrade && t <= highgrade && v>=t){
                people_62 p;
                p.id = id;
                p.virture = v;
                p.talent = t;
                foolman.push_back(p);
            } else {
                people_62 p;
                p.id = id;
                p.virture = v;
                p.talent = t;
                smallman.push_back(p);
            }
        }
    }
    sort(sage.begin(),sage.end(),cmp_62);
    sort(nobleman.begin(),nobleman.end(),cmp_62);
    sort(foolman.begin(),foolman.end(),cmp_62);
    sort(smallman.begin(),smallman.end(),cmp_62);
    int lens = sage.size();
    int lenn = nobleman.size();
    int lenf = foolman.size();
    int lensa = smallman.size();
    printf("%d\n",lens+lenn+lenf+lensa);
    for (int i = 0; i < lens; ++i) {
        printf("%d %d %d\n",sage[i].id,sage[i].virture,sage[i].talent);
    }
    for (int i = 0; i < lenn; ++i) {
        printf("%d %d %d\n",nobleman[i].id,nobleman[i].virture,nobleman[i].talent);
    }
    for (int i = 0; i < lenf; ++i) {
        printf("%d %d %d\n",foolman[i].id,foolman[i].virture,foolman[i].talent);
    }
    for (int i = 0; i < lensa; ++i) {
        printf("%d %d %d\n",smallman[i].id,smallman[i].virture,smallman[i].talent);
    }
    return 0;
}