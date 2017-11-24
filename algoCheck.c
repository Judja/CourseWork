#include "dialog.h"
#include "header.h"
#include <conio.h>
#include "sorting.h"
#include "arrayio.h"

//�� �������� ���������������� ��� ���������� ��������� ������� ���������� ������
#define SORTED 44
#define REVERSE 66
#define RANDOM 77
//�� �������� ���������������� �������� runAlgo ��� ���������� ���� ���������, ���� ������� ���������
#define INSERT 11
#define SELECT 445
#define SHAKER 667
#define QUICK 554

void init();//�������� ���� ���������� �� �������������
void runAlgo(int);//������� ������� ����������, �������� ����� �� ��� ����������
void Config();//����� ��� ������ ���� � ��������� �����:
void changeFillType();//ĳ���� ��� ���� ������� ���������� ������
void changeSize();//ĳ���� ��� ���� ������ ������
int changeValue();//�������� �������, ��� �������� ����������� ������� ��� ������ ������


int fillType;//��������� �����, ��� ������ �  ��� �������� ����� ���������� ������

void AlgoCheck()
{
    init();//����������� ������ ���������� �� �������������
    char ch = '0';//���� ��������� ���� �����������
    do{
        //���� ���������� ����:
        system("cls");
        printf("\n\tALGOCHECK\n\n");
        printf("1. Select\n");
        printf("2. Insert\n");
        printf("3. Shaker\n");
        printf("4. QuickSort\n");
        printf("\n5. Config\n");
        printf("\n9. Back\n");
        printf("\n0. EXIT");

        ch = getch();//���� ������������ �����
        //����������� ������
        switch(ch){
        //1-4:������ ���������� ���������
        case '1':
            runAlgo(SELECT);
            break;
        case '2':
            runAlgo(INSERT);
            break;
        case '3':
            runAlgo(SHAKER);
            break;
        case '4':
            runAlgo(QUICK);
            break;
        //5 - ������ ���������� ���� ����������� ������ � ���� ����������
        case '5':
            Config();
            break;
        //9 - ����������� �����, ����������� �� ������ ��� �� �������
        case '9':
            break;
        //�������� ����� � ��������
        case '0':
            exit(0);
        }
    }
    while(ch!='9');//����� ������ � ����� - ���� ����� "Back"
}

void runAlgo(int type){//������� ������� ���������� ��� ���������� ��� ������, ����������� �������� �������� ����������
    system("cls");
    //������� �� ���� ���������� ���������� �����:
    switch(fillType){
    case SORTED:
        arrFillSorted();
        break;
    case RANDOM:
        arrFillRandom();
        break;
    case REVERSE:
        arrFillReverse();
        break;
    default:
        arrFillRandom();
        break;
    }
    //���� ���������� �������� �� �� ������������ ���������� �����
    arrOut();
    //�������� �� ���������� � �������� ���� ���������� ������� �����
    switch(type){
    case SELECT:
        Select();
        break;
    case INSERT:
        Insert();
        break;
    case QUICK:
        QuickSort();
        break;
    case SHAKER:
        Shaker();
        break;
    }
    //�������� ������������ �����
    printf("After sorting:\n\n");
    arrOut();
    getch();
}

void init()//������� �������� ������ � ���� ���������� ������ ��������, ����� ���� �� �������� �� �������������
{
    P = 2;//����� ������ ��� �������
    M = 2;//2 �����
    N = 5;//�� 5 ��������
    fillType = RANDOM;//������������ ����������� ������� (10 - 99)
}

void Config(){//�������� ���� ��� �������� �� ���� ���� ������ ��� ���� ����������
    char ch;//���� ���������� ���� �����������
    do{
        //�������� �������� ����
        system("cls");
        printf("\n\tCONFIG\n\n");
        printf("1. Change Array Size\n");
        printf("2. Change Array FillType\n");
        printf("\n8. Restore Default Settings\n");
        printf("\n9. Back\n");
        printf("\nPlease, choose:");

        ch = getch();//���� ������������ �����
        //����������� ������
        switch(ch){
        //1 - ����� ��� ���� ������
        case '1':
            changeSize();
            break;
        //2 - ����� ��� ���� ���� ����������
        case '2':
            changeFillType();
            break;
        //8 - ���������� ��������� �� �������������
        case '8':
            init();
            break;
        //9 - ����� � �������� ����. ������� �� �������
        case '9':
            break;
        default:
            break;
        }
    }while(ch != '9');//����� ������ � ����� - ���������� � �������� ����
}

void changeSize(){//�������� ���� ��� ���� ������ ������
    char ch;//���� ���������� ���� �����������
    do{
        //�������� ������ ���������� ����
        system("cls");
        printf("\n\tCHANGESIZE\n\n");
        printf("   ARRAY[ P ][ M ][ N ]\n");
        printf("CURRENT:[%3d][%3d][%3d]\n", P, M, N);
        printf("1. P\n");
        printf("2. M\n");
        printf("3. N\n");
        printf("\n9. Back\n");
        printf("\nPlease, choose:");

        ch = getch();//���������� ������ �����������
        //������� ������ �����������
        switch(ch){
        //1 - 3 - ��������� �������� ������ P, M, N, ���������� ����� � ��� ������ changeValue
        case '1':
            printf("\nInput new Value for P (from 1 to 512): ");
            P = changeValue();
            break;
         case '2':
            printf("\nInput new Value for M (from 1 to 512): ");
            M = changeValue();
            break;
        case '3':
            printf("\nInput new Value for N (from 1 to 512): ");
            N = changeValue();
            break;
        //9 - ���������� �� ������������ ������
        case '9':
            break;
        default:
            break;
        }
    }while(ch!='9');//����� ������ � ����� - ���� ����� "BACK"
}

int changeValue(){//������� ��� ���� ������� P, N, M
    int input;//��� ������������ ������� ������������ �����
    char ch;//���� ���������� �������� ������������ ������
    while(1){//"����� ����"
        input = 0;
        ch = '0';
        do{
            //��� ����� ������������ �����������, ���� ����� ���� ����� �� ������ ���������� �� ���������
            //scanf, ������� �������� ��������� ��������� �� ����������� ��� ����� � ���������
            input *= 10;
            input += (int)(ch - '0');
            ch = getche();
        }while(ch<='9' && ch >= '0');//����� � ����� - �������� ��-�����. ���� ��������� �����, ���� �������� ������ �����
        //���� � ������ ������� ��-�����, �� ����������� ���� 0
        //�������� ����� �� ���������� ����������� �������� �������
        if(input<1){
            printf("Please, input correct value!!! Minimum is 1!!!\n");
        }
        else if(input>700){
            printf("Please, input correct value!!! Maximum is 700!!!\n");
        }
        else{
            break;//����� � "������" �����, ���� ������� ��������� �����
        }
    }
    return input;//��������� ��������� ������� ��������
}

void changeFillType(){//�������� ���� ���� ���� ���������� ������
    char ch;//���� ���������� ��� �����������
    do{
        //�������� ������ ����
        system("cls");
        printf("\n\tCHANGEFILLTYPE\n\n");
        printf("1. Sorted\n");
        printf("2. Reverse Sorted\n");
        printf("3. Random\n");
        printf("\n9. Back\n");

        ch = getch();//������� ����
        //����������� ����
        switch(ch){
        //������� fillType � ���������� � �������
        case '1':
            fillType = SORTED;
            break;
        case '2':
            fillType = REVERSE;
            break;
        case '3':
            fillType = RANDOM;
            break;
        //���������� � �������� ����
        case '9':
            break;
        default:
            break;
        }
    }while(ch != '9');//����� ������ � ����� - ����� � �������� ����
}
