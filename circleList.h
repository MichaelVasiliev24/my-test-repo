#pragma once
#include <stdlib.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct {
    Node imNode;
    size_t len;
} circleList;

void initCircleList(circleList* ptr);
void pushBack(circleList* ptr, int value);
int peekLast(circleList* ptr);
int pop(circleList* ptr);
Node* deleteNode(circleList* ptr, Node* current, int num);
void destroyList(circleList* ptr);
