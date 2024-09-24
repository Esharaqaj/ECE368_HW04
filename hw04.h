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

typedef struct header{
    node* head;
    node* tail;
}header;


node* order_open(int, node **);
node* order_switch(int, node **); 
node* order_close(int, node **);
node* createNewNode(int);
void freeList(node *);

#endif