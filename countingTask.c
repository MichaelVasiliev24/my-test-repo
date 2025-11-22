#include "circleList.h"
#include <stdio.h>

void getData(int* ptr1, int* ptr2);
void freeData(int* ptr1, int* ptr2);
void addPosToList(circleList* ptr, int numbers);
int lastRemainingPos(circleList* ptr, int period);

int main(void)
{
    int* numbers = (int*)malloc(sizeof(int));
    int* period = (int*)malloc(sizeof(int));
    getData(numbers, period);

    circleList list;
    initCircleList(&list);
    addPosToList(&list, *numbers);

    if (*numbers > 1 && *period > 0) {
        printf("Номер начальной позиции воина, который останется последним: %d\n", lastRemainingPos(&list, *period));
        freeData(numbers, period);
        destroyList(&list);
        return 0;
    }
    else if (*numbers == 1 && *period > 0) {
        printf("Номер начальной позиции воина, который останется последним: %d\n", 1);
        freeData(numbers, period);
        destroyList(&list);
        return 0;
    }
    else {
        printf("Ошибка: некорректно введённые данные\n");
        freeData(numbers, period);
        return 1;
    }
}

void getData(int* ptr1, int* ptr2)
{
    printf("Введите количество воинов (n): \n");
    scanf("%d", ptr1);
    printf("Введите периодичность убийства (m): \n");
    scanf("%d", ptr2);
}

void freeData(int* ptr1, int* ptr2)
{
    free(ptr1);
    free(ptr2);
}

void addPosToList(circleList* ptr, int numbers)
{
    for (int i = 1; i <= numbers; i++) {
        pushBack(ptr, i);
    }
}

int lastRemainingPos(circleList* ptr, int period)
{
    Node* stNode = ptr->imNode.next;
    while (ptr->len != 1) {
        stNode = deleteNode(ptr, stNode, period);
    }
    int res = *(int*)ptr->imNode.next->data;
    return res;
}