//
//  main.c
//  Project1
//
//  Created by Anne Louise on 4/3/16.
//  Copyright © 2016 Anne Louise. All rights reserved.
//

#include <stdio.h>
#define MAXN 10000
#define MAXK 100
#include "COMPARE.c"
#include "doalg.c"
#include <time.h>

int main(){
    
    clock_t begin, end;
    double time_spent;
    
    begin = clock();

    
    int N[8] = {100,1000, 8000,10000,10000,8000,1000,100};
    int K[8] = {10,40,70,100,10,40,70,100};
    int Best[MAXK];
    int k,n,flag,round,ct,loop,biggest,total;
    
    for (round=0; round<8; round++) {
        total = 0;
        biggest = -1;
        for (loop=0; loop<1000; loop++) {
            n = N[round];
            k = K[round];
            COMPARE(0,n);   //initializes a random array of length n
            flag = doalg( n, k, Best);
            if (flag==0) {
                printf(" *** flagged error at loop=%d\n",loop);
                return(0);
            }
            ct = COMPARE(-1,k,Best);
            if (ct<=0) {
                printf(" *** error at loop=%d\n",loop);
                return(0);
            }
            if (ct>biggest) biggest=ct;
            total += ct;
        }
        printf("n=%5d,  k=%d:  maximum= %d,  avg=%8.2f\n",
               N[round],K[round],biggest,(1.0*total)/1000);
        fflush(stdout);
    }
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time_spent  : %f", time_spent);
    return 0;
}