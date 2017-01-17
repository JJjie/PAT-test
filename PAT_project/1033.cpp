//
// Created by 胡文杰 on 2017/1/17.
//

#include "pat.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 99999999

struct station_33{
    float price, distance;
};
bool cmpdistance(station_33 &A, station_33 &B){
    return A.distance < B.distance;
}
int pat_1033(){
    float cmax, d, davg;
    int n;
//    cin >> cmax >> d >> davg >> n;
    scanf("%f%f%f%d", &cmax, &d, &davg, &n);
    vector<station_33> stations(n+1);//多出一个作为目的地
    stations[0].price = 0.0;
    stations[0].distance = d;
    for (int i = 1; i <= n; i++) {
//        cin >> stations[i].price >> stations[i].distance ;//注意：c++的输入比c的输入耗时要长
        scanf("%f%f",&stations[i].price,&stations[i].distance);
    }
    sort(stations.begin(), stations.end(), cmpdistance);

    float nowdis = 0.0, maxdis = 0.0, leftdis = 0.0;
    float nowprice = 0.0, totalprice = 0.0;
    if (stations[0].distance != 0){
        cout << "The maximum travel distance = 0.00" << endl;
        return 0;
    }else{
        nowprice = stations[0].price;
    }

//    贪心
    while (nowdis < d){
        maxdis = nowdis + cmax * davg;
        float minPriceDis = 0, minPrice = INF;
        int flag = 0;
        for(int i = 1; i <= n && stations[i].distance <= maxdis; i++) {
            if(stations[i].distance <= nowdis) continue;
            if(stations[i].price < nowprice) {
                totalprice += (stations[i].distance - nowdis - leftdis) * nowprice / davg;
                leftdis = 0.0;
                nowprice = stations[i].price;
                nowdis = stations[i].distance;
                flag = 1;
                break;
            }
            if(stations[i].price < minPrice) {
                minPrice = stations[i].price;
                minPriceDis = stations[i].distance;
            }
        }
        if(flag == 0 && minPrice != INF) {
            totalprice += (nowprice * (cmax - leftdis / davg));
            leftdis = cmax * davg - (minPriceDis - nowdis);
            nowprice = minPrice;
            nowdis = minPriceDis;

        }
        if(flag == 0 && minPrice == INF) {
            nowdis += cmax * davg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }

    }
    printf("%.2f", totalprice);

    return 0;
}