#ifndef __HW02_H__
#define __HW02_H__
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    int data;
    struct node* next;
}node;

void order_switch(int, node **); 
void order_close(int, node **);
void createNewNode(int, node**);
void freeList(node **);

#endif