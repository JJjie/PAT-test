//
// Created by 胡文杰 on 2017/1/25.
//

#include "pat.h"
#include <iostream>
using namespace std;

int pat_1058(){
    int ga, sa, ka;
    int gb, sb, kb;
    int upk=0, ups=0; //进位符
    scanf("%d.%d.%d",&ga, &sa, &ka);
    scanf("%d.%d.%d",&gb, &sb, &kb);
    ka = ka+kb;
    while (ka >= 29){
        ka -= 29;
        upk += 1;
    }
    sa = sa + sb + upk;
    while (sa >= 17){
        sa -= 17;
        ups += 1;
    }
    ga = ga + gb + ups;
    printf("%d.%d.%d",ga,sa,ka);
    return 0;
}
