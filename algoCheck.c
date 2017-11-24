#include "dialog.h"
#include "header.h"
#include <conio.h>
#include "sorting.h"
#include "arrayio.h"

//ці значення використовуються для позначення поточного способу заповнення масиву
#define SORTED 44
#define REVERSE 66
#define RANDOM 77
//ці значення використовуються функцією runAlgo для позначення того алгоритму, який потрібно запустити
#define INSERT 11
#define SELECT 445
#define SHAKER 667
#define QUICK 554

void init();//ініціалізує змінні занченнями за замовчуванням
void runAlgo(int);//запускає вибране сортування, параметр вказує на тип сортування
void Config();//діалог для вибору однієї з наступних опцій:
void changeFillType();//Діалог для зміни способу заповнення масиву
void changeSize();//Діалог для зміни розміру масиву
int changeValue();//допоміжна функція, яка перевіряє допустимість значень для розміру масиву


int fillType;//глобальна змінна, яка зберігає в  собі поточний спосіб заповнення масиву

void AlgoCheck()
{
    init();//ініціалізація змінних значеннями за замовчуванням
    char ch = '0';//сюди зчитується вибір користувача
    do{
        //Вивід діалогового меню:
        system("cls");
        printf("\n\tALGOCHECK\n\n");
        printf("1. Select\n");
        printf("2. Insert\n");
        printf("3. Shaker\n");
        printf("4. QuickSort\n");
        printf("\n5. Config\n");
        printf("\n9. Back\n");
        printf("\n0. EXIT");

        ch = getch();//вибір користувачем опції
        //опрацювання вибору
        switch(ch){
        //1-4:запуск відповідного алгоритму
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
        //5 - запуск діалогового меню налаштувань розміру і типу заповнення
        case '5':
            Config();
            break;
        //9 - повернутись назад, опрацювання на даному рівні не потрібне
        case '9':
            break;
        //негайний вихід з програми
        case '0':
            exit(0);
        }
    }
    while(ch!='9');//умова виходу з циклу - вибір опції "Back"
}

void runAlgo(int type){//функція запускає необхідний тип сортування для масиву, заповненого поточним способом заповнення
    system("cls");
    //залежно від типу заповнення заповнюємо масив:
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
    //після заповнення виводимо ще не відсортований алгоритмом масив
    arrOut();
    //відповідно до переданому в аргументі типу сортування сортуємо масив
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
    //виводимо відсортований масив
    printf("After sorting:\n\n");
    arrOut();
    getch();
}

void init()//функція присвоює розміру і типу заповнення масиву значення, обрані мною як значення за замовчуванням
{
    P = 2;//масив матиме два перерізи
    M = 2;//2 рядкм
    N = 5;//та 5 стовпців
    fillType = RANDOM;//заповнюється випадковими числами (10 - 99)
}

void Config(){//діалогове меню для переходу до меню зміни розміпу або типу заповнення
    char ch;//сюди записується вибір користувача
    do{
        //виводимо діалогове меню
        system("cls");
        printf("\n\tCONFIG\n\n");
        printf("1. Change Array Size\n");
        printf("2. Change Array FillType\n");
        printf("\n8. Restore Default Settings\n");
        printf("\n9. Back\n");
        printf("\nPlease, choose:");

        ch = getch();//вибір користувачем опції
        //опрацювання вибору
        switch(ch){
        //1 - діалог для зміни розмірів
        case '1':
            changeSize();
            break;
        //2 - діалог для зміни типу заповнення
        case '2':
            changeFillType();
            break;
        //8 - відновлення параметрів зв замовчуванням
        case '8':
            init();
            break;
        //9 - вихід в попереднє меню. обробка не потрібна
        case '9':
            break;
        default:
            break;
        }
    }while(ch != '9');//умова виходу з циклу - повернення в попереднє меню
}

void changeSize(){//діалогове меню для зміни розміру масиву
    char ch;//сюди записується вибір користувача
    do{
        //Виводимо пункти діалогового меню
        system("cls");
        printf("\n\tCHANGESIZE\n\n");
        printf("   ARRAY[ P ][ M ][ N ]\n");
        printf("CURRENT:[%3d][%3d][%3d]\n", P, M, N);
        printf("1. P\n");
        printf("2. M\n");
        printf("3. N\n");
        printf("\n9. Back\n");
        printf("\nPlease, choose:");

        ch = getch();//зчитування вибору користувача
        //обробка вибору користувача
        switch(ch){
        //1 - 3 - змінюється значення змінних P, M, N, коректність ввожу і ввід реалізує changeValue
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
        //9 - повернення до попереднього діалогу
        case '9':
            break;
        default:
            break;
        }
    }while(ch!='9');//умова виходу з циклу - вибій опції "BACK"
}

int changeValue(){//Функція для зміни значень P, N, M
    int input;//тут обраховується введене користувачем число
    char ch;//сюди записується введений користувачем символ
    while(1){//"вічний цикл"
        input = 0;
        ch = '0';
        do{
            //ввід числа реалізовується посимвольно, така схема більш стійка ніж просте зчитування за допомогою
            //scanf, оскільки дозволяє коректніше реагувати на некоректний ввід даних з клавіатури
            input *= 10;
            input += (int)(ch - '0');
            ch = getche();
        }while(ch<='9' && ch >= '0');//вихід з циклу - введення не-цифри. доки вводяться цифри, цикл обраховує кінцеве число
        //якщо ж одразу введена не-цифра, то результатом буде 0
        //перевіпка числа на відповідність допустимому діапазону значень
        if(input<1){
            printf("Please, input correct value!!! Minimum is 1!!!\n");
        }
        else if(input>700){
            printf("Please, input correct value!!! Maximum is 700!!!\n");
        }
        else{
            break;//вихід з "вічного" циклу, якщо введено правильно число
        }
    }
    return input;//повертаємо перевірене введене значення
}

void changeFillType(){//діалогове меню зміни типу заповнення масиву
    char ch;//сюди записується ввід користувача
    do{
        //виводимо пункти меню
        system("cls");
        printf("\n\tCHANGEFILLTYPE\n\n");
        printf("1. Sorted\n");
        printf("2. Reverse Sorted\n");
        printf("3. Random\n");
        printf("\n9. Back\n");

        ch = getch();//зчитуємо вибір
        //опрацьовуємо вибір
        switch(ch){
        //Змінюємо fillType у відповідності з вибором
        case '1':
            fillType = SORTED;
            break;
        case '2':
            fillType = REVERSE;
            break;
        case '3':
            fillType = RANDOM;
            break;
        //повернення в попереднє меню
        case '9':
            break;
        default:
            break;
        }
    }while(ch != '9');//умова виходу з циклу - вихід в попереднє меню
}
