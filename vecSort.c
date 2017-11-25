#include "sorting.h"
#include "header.h"

clock_t vecShaker(){//Метод сортування №16 методу прямого обміну, Шейкерне сортування для вектора
    int B, i, L, R, k;
    clock_t start, stop;

    start = clock();
    L = 0;
    R = V-1;
    k = 0;
    while(L<R){
        for(i = L; i<R; i++){
            if(Vec[i] > Vec[i+1]){
                B = Vec[i];
                Vec[i] = Vec[i+1];
                Vec[i+1] = B;
                k = i;
            }
        }
        R = k;
        for(i = R-1; i>=L; i--){
            if(Vec[i]>Vec[i+1]){
                B = Vec[i];
                Vec[i] = Vec[i+1];
                Vec[i+1] = B;
                k = i;
            }
        }
        L = k+1;
    }
    stop = clock();

    return stop - start;
}

clock_t vecInsert(){//Метод сортування вставкою №1, "вставка зліва" для вектора
    int B, i, j, k;
    clock_t start, stop;

    start = clock();
    for(i = 1; i < V; i++){
        B = Vec[i];
        j = 0;
        while(B>Vec[j])
            j++;
        for(k = i-1; k>=j; k--){
            Vec[k+1] = Vec[k];
        }
        Vec[j] = B;
    }
    stop = clock();

    return stop - start;
}

void vecQSort(int L, int R){//Метод сортування №23, швидке сортування для вектора
    int B, Tmp, i, j;
    B = Vec[(L+R)/2];
    i = L;
    j = R;
    while(i<=j){
        while(Vec[i] < B) i++;
        while(Vec[j] > B) j--;
        if(i<=j){
            Tmp = Vec[i];
            Vec[i] = Vec[j];
            Vec[j] = Tmp;
            i++;
            j--;
        }
    }
    if(L<j)
        vecQSort(L, j);
    if(i<R)
        vecQSort(i, R);
}

clock_t vecQuickSort(){//"Обгортка", яку використаємо для вимірювання часу роботи рекурсивної функції
    clock_t start, stop;
    start = clock();
    vecQSort(0, V-1);
    stop = clock();
    return stop - start;
}


clock_t vecSelect(){//Метод сортування №7 методом прямого вибору для вектора
    int Min, Max, L, R, i, imin, imax;
    clock_t start, stop;

    start = clock();
    L = 0;
    R = V-1;
    while(L<R){
        Min = Vec[L];
        imin = L;
        Max = Vec[L];
        imax = L;
        for(i = L+1; i <= R; i++){
            if(Vec[i] < Min){
                Min = Vec[i];
                imin = i;
            }
            else if(Vec[i] > Max){
                Max = Vec[i];
                imax = i;
            }
        }
            if(imin != L){
                Vec[imin] = Vec[L];
                Vec[L] = Min;
            }

            if(imax != R){
                if(imax == L){
                    Vec[imin] = Vec[R];
                }
                else{
                    Vec[imax] = Vec[R];
                }
                Vec[R] = Max;
            }
        L++;
        R--;
    }
    stop = clock();

    return stop - start;
}
