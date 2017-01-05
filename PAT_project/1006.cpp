//
//  1006.cpp
//  PAT_project
//
//  Created by 胡文杰 on 2017/1/5.
//  Copyright © 2017年 胡文杰. All rights reserved.
//

#include "pat.h"
#include <iostream>
#include <cstring>
using namespace std;

int pat_1006(){
    int  records;
    char lockID[15] = "none", unlockID[15] = "none", tempID[15] = "none";
    char opentime[10] = "23:59:59", shuttime[10] = "00:00:00", temptime[10];
    
    cin >> records;
    while (records != 0) {
        cin >> tempID;
        cin >> temptime;
        if (strcmp(temptime, opentime) < 0) {
            strcpy(opentime, temptime);
            strcpy(unlockID, tempID);
        }
        cin >> temptime;
        if (strcmp(temptime, shuttime) > 0) {
            strcpy(shuttime, temptime);
            strcpy(lockID, tempID);
        }
        records--;
    }
    cout << unlockID << " " << lockID << endl;
    
    return 0;
}
