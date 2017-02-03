//
// Created by 胡文杰 on 2017/2/3.
//

#include "pat.h"
#include <iostream>
using namespace std;

char unit_82[6][5] = {"Shi","Bai","Qian","Wan","Yi"};
char num_82[11][5] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
bool flag_82 = 0;

void read_82(int num){
    bool flag1 = 0, flag2 = 0, flag3 = 0;
    if (num / 1000){
        printf("%s %s",num_82[num/1000],unit_82[2]);
        flag1 = 1;
    }
    if (flag_82 && !flag1) printf("ling ");
    if (num / 100 % 10){
        if (flag1) printf(" ");
        printf("%s %s",num_82[num/100%10],unit_82[1]);
        flag2 = 1;
    }
    if (flag1 && !flag2 && num/100 != 0) printf(" ling");
    if (num / 10 % 10){
        if (flag1 || flag2) printf(" ");
        printf("%s %s",num_82[num/10%10],unit_82[0]);
        flag3 = 1;
    }
    if (flag2 && !flag3 && num%10 != 0) printf(" ling");
    if (num % 10){
        if (flag1 || flag2 || flag3) printf(" ");
        printf("%s",num_82[num%10]);
    }

}

int pat_1082(){
    int n;
    bool flag1 = 0, flag2 = 0;
    scanf("%d",&n);
    if (n < 0) {
        printf("Fu ");
        n = abs(n);
    }
    if (n == 0) printf("ling\n");
    if (n > 99999999){
        int temp = n / 100000000;
        read_82(temp);
        printf(" %s",unit_82[4]);
        n = n % 100000000;
        flag1 = 1;
    }
    if (n > 9999){
        int temp = n / 9999;
        if (flag1){
            printf(" ");
            flag_82 = 1;
        }
        read_82(temp);
        printf(" %s",unit_82[3]);
        n = n % 10000;
        flag2 = 1;
    }
    flag_82 = 0;
    if ((flag1 || flag2) && n != 0){
        printf(" ");
        flag_82 = 1;
    }
    read_82(n);

    return 0;
}