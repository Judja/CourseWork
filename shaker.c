#include "sorting.h"
#include "header.h"

clock_t Shaker(){
    int Sum[N];//додатковий вектор для збереження сум елементів перерізів
    int L, R, k, i, j, l, B;
    clock_t start, stop;

    start = clock();

    for(j = 0; j < P; j++){
        sum(Sum, j);//inline-функція, яка заповнбє вектор Sum

        L = 0;
        R = N-1;
        l = 0;
        while(L<R){
            for(i = L; i < R; i++){
                if(Sum[i] > Sum[i+1]){
                    B = Sum[i];
                    Sum[i] = Sum[i+1];
                    Sum[i+1] = B;
                    l = i;
                    //коли відбувається перестановка елементів вектора що сортується,
                    //переставляємо елементів відповідних стовпців перерізу
                    for(k = 0; k < M; k++){
                        B = A[j][k][i];
                        A[j][k][i] = A[j][k][i+1];
                        A[j][k][i+1] = B;
                    }
                }
            }
            R = l;
            for(i = R-1; i >= L; i--){
                if(Sum[i] > Sum[i+1]){
                    B = Sum[i];
                    Sum[i] = Sum[i+1];
                    Sum[i+1] = B;
                    l = i;
                    //коли відбувається перестановка елементів вектора що сортується,
                    //переставляємо елементів відповідних стовпців перерізу
                    for(k = 0; k < M; k++){
                        B = A[j][k][i];
                        A[j][k][i] = A[j][k][i+1];
                        A[j][k][i+1] = B;
                    }
                }
            }
            L = l+1;
        }
    }
    stop = clock();

    return stop - start;
}
