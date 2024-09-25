#include "hw04.h"
#define MAX_ORD 25

static void print_windows(node** windows){
    node* temp = *windows;
    while(temp->next != NULL){
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main(){
    int id = 0;
    char order[MAX_ORD];

    node* windows = NULL;

    while(scanf("%s %d", order, &id)!= EOF){
        if(!(strcmp(order,"open"))){
           createNewNode(id, &windows);
        }
        else if(!(strcmp(order,"switch"))){
            order_switch(id, &windows);
        }
        else if(!(strcmp(order,"close"))){
            order_close(id, &windows);
        }
        else if(!(strcmp(order, "print"))){
            print_windows(&windows);
        }

        if(windows == NULL){
            return EXIT_SUCCESS;
        }
        else{
            printf("%d\n",windows->data);
        }
    }
    freeList(&windows);
    return EXIT_SUCCESS;
}

void createNewNode(int id, node** windows)
{
    if(*windows == NULL){
        *windows = malloc(sizeof(**windows));
        (*windows)->next = NULL;
        (*windows)->data = id;
    }

    else{
        node* newNode = malloc(sizeof(node));
        newNode->data = id;
        newNode->next = (*windows);
        *windows = newNode;
    }
}

void order_close(int id, node** windows){
    order_switch(id, windows);
    node* temp = *windows;
    if(temp->next == NULL){
        free(temp);
        *windows = NULL;
        return;
    }
    (*windows) = temp->next;
    free(temp);
    temp = NULL;
}

void order_switch(int id, node ** windows){
    if((*windows)->data == id){return;}
    node* temp = *windows;
    int id_index = 0;
    while(temp->data != id){
        temp = temp->next;
        id_index++;
    }
    node* before_temp = *windows;
    for(int i = id_index; i>1; i--){
        before_temp = before_temp->next;
    }
    if(temp->next == NULL){
        before_temp->next = NULL;
        temp->next = *windows;
        *windows = temp;
        return;
    }
    before_temp->next = temp->next;
    temp->next = *windows;
    (*windows) = temp;
}

static void freeList(node** windows){
    if((*windows)==NULL){return;}
    node* temp = *windows;
    while((temp)->next != NULL){
        *windows = (*windows)-> next;
        free(temp);
        temp = NULL;
        temp = *windows;
    }
    free(temp);
    temp = NULL;
}