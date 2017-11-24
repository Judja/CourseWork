#include "sorting.h"
#include "header.h"

void QSort(int, int, int*, int);

clock_t QuickSort(){//�������, ��� ����������� ������� ���������� ��� ������� �������
    int j;//����� ��� ������ ������ �� �������� � ����
    int Sum[N];//���������� ������ ��� ���������� ���
    clock_t start, stop;//���� ��� �������� ������� � ���������� ������ ���������

    start = clock();
    for(j = 0; j < P; j++){
        sum(Sum, j);//inline-�������, ��� ������� ������ Sum
        QSort(0, N-1, Sum, j);
    }
    stop = clock();

    return stop - start;
}

void QSort(int L, int R, int* Sum, int l){//����� ���������� �23, ������ ����������
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
            //���� ���������� ���� �������� � ������, ���� ���������, ����� ���������� ����
            //�������� � ���������� ������ �������
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
