#include "sorting.h"
#include "header.h"

clock_t Select(){
    int Sum[N];//додатковий вектор для зберігання сум перерізів
    int i, j, L, R, max, min, imin, imax, k;
    clock_t start, stop;//змінні для фіксації початку і закінчення алгоритму

    start = clock();
    for(j = 0; j < P; j++){
        sum(Sum, j);//inline-функція, яка заповнбє вектор Sum

        L = 0;
        R = N-1;

        while(L<R){
            min = Sum[L];
            max = Sum[R];
            imin = L;
            imax = R;
            for(i = L; i<=R; i++){
                if(Sum[i]<min){
                    min = Sum[i];
                    imin = i;
                }
                else if(Sum[i]>max){
                    max = Sum[i];
                    imax = i;
                }
            }

            if(imin!=L){
                Sum[imin] = Sum[L];
                Sum[L] = min;
                //коли відбувається перестановка в векторі, також переставляємо елементи в відповідних стовпцях матриці
                for(k = 0; k<M; k++){
                    min = A[j][k][imin];
                    A[j][k][imin] = A[j][k][L];
                    A[j][k][L] = min;
                }
            }

            if(imax!=R){
                if(imax == L){
                    Sum[imin] = Sum[R];
                }
                else{
                    Sum[imax] = Sum[R];
                }
                Sum[R] = max;
                //коли відбувається перестановка в векторі, також переставляємо елементи в відповідних стовпцях матриці
                for(k = 0; k < M; k++){
                    if(imax == L){
                        max = A[j][k][imin];
                        A[j][k][imin] = A[j][k][R];
                    }
                    else{
                        max = A[j][j][imax];
                        A[j][k][imax] = A[j][k][R];
                    }
                    A[j][k][R] = max;
                }
            }
            L++;
            R--;
        }
    }
    stop = clock();

    return stop - start;
}
