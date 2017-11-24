#include "dialog.h"
#include "header.h"
#include "sorting.h"
#include "Measurement.h"

void Start();//������ ���������� ���������
void initShedule();//����������� ������ ������ ���������� �� �������������

Shedule(){
    initShedule();//����������� ������� �� �������������
    char ch;//���� ��������� ��� �����������
    do{
        //���� ���������� ����
        system("cls");
        printf("\n\tSHEDULE\n\n");
        printf("1. Start\n");
        printf("\n2. Config\n");
        printf("\n9. Back\n");
        printf("\n0. EXIT\n");
        printf("\nPlease, choose: ");
        ch = getch();//���������� ������
        //������� ������
        switch(ch){
        case '1':
            Start();//������ ���������� ���������
            break;
        case '2':
            changeSize();//������ ���� ���� ������ ������
        case '9':
            break;
        case '0':
            exit(0);//�����
        default:
            break;
        }
    }while(ch!='9');//����� ������ � ����� - ���� ����� ���������� � �������� ����
}

void Start(){//������ ���������� ���������
    int i;
    system("cls");
    //��������� ���������� ������� � ���������� ������䳿 ���������:
    printf("\n  ARRAY[%3d][%3d][%3d]\n\n", P, M, N);
    printf("\t|\tOrdered |  BackOrdered  | Random \n");
    printf(" SELECT\t");
    arrFillSorted();
    for(i = 0; i< measurements_number; i++){
        arrFillSorted();
        Res[i] = Select();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillReverse();
        Res[i] = Select();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillRandom();
        Res[i] = Select();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    printf("\n INSERT\t");
    for(i = 0; i< measurements_number; i++){
        arrFillSorted();
        Res[i] = Insert();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillReverse();
        Res[i] = Insert();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillRandom();
        Res[i] = Insert();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    printf("\n SHAKER\t");
    for(i = 0; i< measurements_number; i++){
        arrFillSorted();
        Res[i] = Shaker();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillReverse();
        Res[i] = Shaker();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillRandom();
        Res[i] = Shaker();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    printf("\n QSORT\t");
    for(i = 0; i< measurements_number; i++){
        arrFillSorted();
        Res[i] = QuickSort();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillReverse();
        Res[i] = QuickSort();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        arrFillRandom();
        Res[i] = QuickSort();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    getch();
}

void initShedule(){//�� �������� ������ �� �������� �� �������������
    M = 128;
    N = 128;
    P = 128;
}

void vecShedule(){
    int i;
    system("cls");
    //��������� ���������� ������� � ���������� ������䳿 ���������:
    printf("\n  ARRAY[%4d]\n\n", V);
    printf("\t|\tOrdered |  BackOrdered  | Random \n");
    printf(" SELECT\t");
    vecFillSorted();
    for(i = 0; i< measurements_number; i++){
        vecFillSorted();
        Res[i] = vecSelect();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillReverse();
        Res[i] = vecSelect();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillRandom();
        Res[i] = vecSelect();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    printf("\n INSERT\t");
    for(i = 0; i< measurements_number; i++){
        vecFillSorted();
        Res[i] = vecInsert();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillReverse();
        Res[i] = vecInsert();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillRandom();
        Res[i] = vecInsert();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    printf("\n SHAKER\t");
    for(i = 0; i< measurements_number; i++){
        vecFillSorted();
        Res[i] = vecShaker();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillReverse();
        Res[i] = vecShaker();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillRandom();
        Res[i] = vecShaker();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    printf("\n QSORT\t");
    for(i = 0; i< measurements_number; i++){
        vecFillSorted();
        Res[i] = vecQuickSort();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillReverse();
        Res[i] = vecQuickSort();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);
    for(i = 0; i< measurements_number; i++){
        vecFillRandom();
        Res[i] = vecQuickSort();
    }
    MeasurementProcessing();
    printf("|\t %6.1f ", (float)Res[0]/20);

    getch();
}
