#include "sorting.h"
#include "header.h"

void QSort(int, int, int*, int);

clock_t QuickSort(){//функція, яка викликатиме функцію сортування для кожного перерізу
    int j;//змінна для обходу масиву по перерізах в циклі
    int Sum[N];//додатковий вектор для збереження сум
    clock_t start, stop;//змінні для фіксації початку і завершення роботи алгоритму

    start = clock();
    for(j = 0; j < P; j++){
        sum(Sum, j);//inline-функція, яка заповнбє вектор Sum
        QSort(0, N-1, Sum, j);
    }
    stop = clock();

    return stop - start;
}

void QSort(int L, int R, int* Sum, int l){//Метод сортування №23, швидке сортування
    int B, i, j, Tmp, k;

    B = Sum[(L+R)/2];
    i = L;
    j = R;

    while(i<=j){
        while(Sum[i]<B) i++;
        while(Sum[j]>B) j--;
        if(i<=j){
            Tmp = Sum[i];
            Sum[i] = Sum[j];
            Sum[j] = Tmp;
            //коли відбувається обмін елементів в векторі, який сортується, також відбувається обмін
            //стовпців в відповідному перерізі матриці
            for(k = 0; k < M; k++){
                Tmp = A[l][k][i];
                A[l][k][i] = A[l][k][j];
                A[l][k][j] = Tmp;
            }
            i++;
            j--;
        }
    }
    if(L<j) QSort(L, j, Sum, l);
    if(i<R) QSort(i, R, Sum, l);
}
