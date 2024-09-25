#ifndef __HW04_H__
#define __HW04_H__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* order_open(int, node **);
node* order_switch(int, node **); 
node* order_close(int, node **);
node* createNewNode(int);
void freeList(node **);

#endif