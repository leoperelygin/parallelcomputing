#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#define MAX 16

int a[] = { 1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220 };

int maxop = 0;
int sumOp = 0;

void SumArOpenMp (){
    #pragma omp parallel
        {
            #pragma omp for
            for (int i = 0; i < MAX; i++)
            sumOp += a[i];
        }
}

void FindMaxOpenMP(){
#pragma omp parallel
    {
    for (int i = 0; i < MAX; i++)
        if (a[i] > maxop)
        #pragma ompcritical
            if (a[i] > maxop)
            {
                maxop = a[i];
            }
    }
}

int main(){

clock_t time;
time = clock();

//OpenMP
    time = clock();
    SumArOpenMp();
    printf("SumOpenMP is %d ", sumOp);

    FindMaxOpenMP();
    printf("MaxOpenMP is %d ", maxop);
    time = time - clock();
    printf(" %f", (double) time/CLOCKS_PER_SEC);
    return 0;
}
