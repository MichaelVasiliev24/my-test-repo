#include "circleList.h"
#include <stdio.h>

void initCircleList(circleList* ptr)
{
    ptr->imNode.next = &(ptr->imNode);
    ptr->len = 0;
}

void pushBack(circleList* ptr, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = malloc(sizeof(int));
    if (newNode != NULL && newNode->data != NULL) {
        *(int*)newNode->data = value;
        Node* current = ptr->imNode.next;
        while (current->next != &(ptr->imNode)) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = &(ptr->imNode);
        ptr->len++;
    }
    else {
        printf("Ошибка выделения памяти для нового узла списка или для данных нового узла\n");
    }
}

int peekLast(circleList* ptr)
{
    if (ptr->len > 0) {
        Node* current = ptr->imNode.next;
        while (current->next != &(ptr->imNode)) {
            current = current->next;
        }
        int value = *(int*)current->data;
        return value;
    }
    else {
        printf("Ошибка: список пуст\n");
        // return 0;
    }
}

int pop(circleList* ptr)
{
    if (ptr->len > 0) {
        Node* current = ptr->imNode.next;
        while (current->next->next != &(ptr->imNode)) {
            current = current->next;
        }
        Node* temp = current->next;
        int value = *(int*)temp->data;
        current->next = &(ptr->imNode);
        ptr->len--;
        free(temp->data);
        free(temp);
        return value;
    }
    else {
        printf("Ошибка: список пуст\n");
        // return 0;
    }
}

Node* deleteNode(circleList* ptr, Node* current, int num)
{
    if (num > 0 && ptr->len > 0) {
        int ind;
        if (num != 1) {
            for (ind = 1; ind < num - 1; ind++) {
                if (current->next == &(ptr->imNode)) {
                    current = current->next->next;
                }
                else {
                    current = current->next;
                }
            }
        }

        if (current->next->next == &(ptr->imNode)) {
            Node* temp = current->next;
            current->next = &(ptr->imNode);
            ptr->len--;
            free(temp->data);
            free(temp);
            return ptr->imNode.next;
        }
        else if (current->next == &(ptr->imNode)) {
            current = ptr->imNode.next;
            ptr->imNode.next = current->next;
            ptr->len--;
            free(current->data);
            free(current);
            return ptr->imNode.next;
        }
        else {
            Node* temp = current->next;
            current->next = temp->next;
            ptr->len--;
            free(temp->data);
            free(temp);
            return current->next;
        }
    }
    else {
        printf("Ошибка: недопустимый номер/список пуст\n");
        return NULL;
    }
}

void destroyList(circleList* ptr)
{
    Node* current = ptr->imNode.next;
    while (ptr->len > 0) {
        Node* temp = current;
        current = current->next;
        ptr->len--;
        free(temp->data);
        free(temp);
    }
    ptr->imNode.next = &(ptr->imNode);
}