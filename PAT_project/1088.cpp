//
// Created by 胡文杰 on 2017/2/4.
//

#include "pat.h"
#include <iostream>
using namespace std;

long long gcd_88(long long a, long long b) {//求最大公约数
    return b == 0 ? abs(a) : gcd_88(b, a % b);
}

void printans(long long a,long long b){
    if (a == 0){
        printf("0");
        return;
    } else if (b == 0){
        printf("Inf");
        return;
    }
    long long integration = 0;
    bool temp = false;
    if (a < 0){
        temp = true;
        a = abs(a);
    }
    int gcdvalue = gcd_88(a,b);
    a = a / gcdvalue;
    b = b / gcdvalue;
    while (a >= b){
        integration ++;
        a = a - b;
    }
    if (temp){
        if (a == 0){
            printf("(-%lld)",integration);
        } else {
            if (integration != 0){
                printf("(-%lld %lld/%lld)",integration,a,b);
            } else {
                printf("(-%lld/%lld)",a,b);
            }

        }
    } else {
        if (a == 0){
            printf("%lld",integration);
        } else {
            if (integration != 0){
                printf("%lld %lld/%lld",integration,a,b);
            } else {
                printf("%lld/%lld",a,b);
            }
        }
    }
}

int pat_1088(){
    long long a1,a2,b1,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&a2,&b1,&b2);
    int gcdvalue = gcd_88(a1,a2); // 约分处理
    a1 = a1 / gcdvalue;
    a2 = a2 / gcdvalue;
    gcdvalue = gcd_88(b1,b2);
    b1 = b1 / gcdvalue;
    b2 = b2 / gcdvalue;

    long long suma,b,differencea,producta,productb,quotienta,quotientb;
    suma = a1 * b2 + a2 * b1;
    b = a2 * b2;
    differencea = a1 * b2 - a2 * b1;
    producta = a1 * b1;
    productb = a2 * b2;
    bool temp = false;
    if ((a1 < 0 && b1 > 0) || (a1 > 0 && b1 < 0)) temp = true;
    quotienta = abs(a1) * b2;
    quotientb = a2 * abs(b1);
    if (temp) quotienta = -quotienta;

    printans(a1,a2);
    printf(" + ");
    printans(b1,b2);
    printf(" = ");
    printans(suma,b);
    printf("\n");
    printans(a1,a2);
    printf(" - ");
    printans(b1,b2);
    printf(" = ");
    printans(differencea,b);
    printf("\n");
    printans(a1,a2);
    printf(" * ");
    printans(b1,b2);
    printf(" = ");
    printans(producta,productb);
    printf("\n");
    printans(a1,a2);
    printf(" / ");
    printans(b1,b2);
    printf(" = ");
    printans(quotienta,quotientb);
    printf("\n");
    return 0;
}