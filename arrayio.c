#include "arrayio.h"
#include "header.h"
#include "time.h"

void arrFillSorted(){
    //заповнення масиву елемента впорядкованими за незменшенням
    int i, j, k;
    for(i=0; i<P; i++)
        for(j=0; j<M; j++)
            for(k=0; k<N; k++)
                A[i][j][k] = 20+2*i+2*j+2*k;
}

void arrFillReverse(){
    //заповнення масиву елементами, впорядкованими за незбільшенням
    int i, j, k;
    for(i=0; i<P; i++)
        for(j=0; j<M; j++)
            for(k=0; k<N; k++)
                A[i][j][k] = 10+2*(M+N+P-(i+j+k));
}

void arrFillRandom(){
    //заповнення масиву елментами, згенерованими випадковим чином
    srand(time(NULL));
    int i, j, k;
    for(i=0; i<P; i++)
        for(j=0; j<M; j++)
            for(k=0; k<N; k++)
                A[i][j][k] = rand()%1998-999;
}

void arrOut(){
    //виведення елементів масиву на екран
    int i, j, k;
    printf("Array A:\n");
    for(i=0; i<P; i++){
        for(j=0; j<M; j++){
            for(k=0; k<N; k++)
                printf("%4d", A[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }
}

void vecFillRandom(){
    srand(time(NULL));
    int i;
    for(i = 0; i < V; i++){
        Vec[i] = rand()%1998-999;
    }
}

void vecFillReverse(){
    int i;
    for(i = 0; i < V; i++){
        Vec[i] = V-i;
    }
}
void vecFillSorted(){
    int i;
    for(i = 0; i < V; i++){
        Vec[i] = i;
    }
}
