#include "dialog.h"
#include "header.h"
#include "sorting.h"
#include "Measurement.h"

void Start();//запуск тестування алгоритмів
void initShedule();//ініціалізація розмірів масиву значеннями за замовчуванням

Shedule(){
    initShedule();//ініціалізація змінними за замовчуванням
    char ch;//сюди зчитується ввід користувача
    do{
        //вивід діалогового меню
        system("cls");
        printf("\n\tSHEDULE\n\n");
        printf("1. Start\n");
        printf("\n2. Config\n");
        printf("\n9. Back\n");
        printf("\n0. EXIT\n");
        printf("\nPlease, choose: ");
        ch = getch();//зчитування вибору
        //обробка вибору
        switch(ch){
        case '1':
            Start();//запуск тестування алгоритмів
            break;
        case '2':
            changeSize();//запуск вікна зміни розмірів масиву
        case '9':
            break;
        case '0':
            exit(0);//вихід
        default:
            break;
        }
    }while(ch!='9');//умова виходу з циклу - вибір опції повернення в попереднє меню
}

void Start(){//запуск тестування алгоритмів
    int i;
    system("cls");
    //одночасне формування таблиці і вимірювання швидкодії алгоритмів:
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

void initShedule(){//ці значення вибрані як значення за замовчуванням
    M = 128;
    N = 128;
    P = 128;
}

void vecShedule(){
    int i;
    system("cls");
    //одночасне формування таблиці і вимірювання швидкодії алгоритмів:
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
