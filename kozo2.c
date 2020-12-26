#include <stdio.h>
#include <string.h>

typedef struct
{
    int num;       
    int gas;
    struct Car *next;
} Car;

void printlist(Car car0, Car car1, Car car2, Car *pcar);

int main(void)
{
    Car car0;
    Car car1;
    Car car2;
    Car *pcar;

    car0.num = 1234;
    car0.gas = 25.5;
    car1.num = 4567;
    car1.gas = 52.2;
    car2.num = 7890;
    car2.gas = 20.5;

    car0.next = &car1;
    car1.next = &car2;
    car2.next = NULL;

    printlist(car0,car1,car2, pcar); /* 呼び出し */

    return 0;
}

void printlist(Car car0, Car car1, Car car2, Car *pcar)
{
    for (pcar = &car0; pcar != NULL; pcar = pcar->next)
    {
        printf("車のナンバーは%d:ガス量は%fです。\n", pcar->num, pcar->gas);
    }
    return;
}