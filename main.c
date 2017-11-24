#include "header.h"
#include "dialog.h"
#include <conio.h>

//глобальні масиви і змінні, які оголошені в файлі header.h:
int A[700][700][700];
int M = 1;
int N = 1;
int P = 1;
int Vec[1000000];
int V = 12000;

int main()
{
    printf("\n\n\tCursova robota, Fedorchenko Denys, KV - 61");
    printf("\n\tVariant: 43, Zadacha #4, algorytmy #1, 11, 16, 23");
    printf("\n\nPress any button to continue");
    getch();
    dialog();//запуск головного діалогу
    return 0;
}
