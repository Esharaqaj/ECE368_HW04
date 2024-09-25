#include "hw04.h"

#define MAX_ORD 8


int main()
{
    int id = 0;
    char order[MAX_ORD];
    node* windows = NULL;


    while(scanf("%s %d", order, &id)!= EOF)
    {
        if(!(strcmp(order,"open")))
        {
           windows = order_open(id, &windows);
        }

        else if(!(strcmp(order,"switch")))
        {
            windows = order_switch(id, &windows);
        }

        else if(!(strcmp(order,"close")))
        {
            windows = order_close(id, &windows);
        }

        if(windows == NULL)
        {
            return EXIT_SUCCESS;
        }

        else{
            printf("%d\n",windows->data);
        }
    }
    
    //freeList(&windows);
    return EXIT_SUCCESS;
}

node* createNewNode(int id)
{
    node* newNode = (node *)malloc(sizeof(node));
    newNode->data = id;
    newNode->next = NULL;
return(newNode);
}

node* order_open(int id, node **windows) {
    node* cur = *windows;
    *windows = createNewNode(id);
    (*windows)->next = cur;
    return *windows;
}

node* order_close(int id, node **windows)
{
    node* temp;
    node* cur = *windows;

    if((cur->data) == id)
    {
        if(cur->next == NULL)
        {
            free(cur);
            *windows = NULL;
            return(*windows);
        }
        else 
        {
        temp = cur;
        (*windows) = (*windows)->next;
        free(temp);
        }
    }
  
    else {   
        while((cur->next->data) != id)
        {
            cur = cur->next;
        }

        if((cur->next->next)!=NULL)
        {
            temp = cur->next;
            cur->next = cur->next->next;
            free(temp);
        }

        else
        {
            free(cur->next);
            cur->next = NULL;
        }
    }

    return(*windows);
}

node* order_switch(int id, node **windows)
{
 node* temp = *windows;
 node* found;
 node* cur = *windows;

 if((cur->data) == id)
 {
    return *windows;
 }

 while((cur->next->data) != id)
 {
    cur = cur->next;
 }

    found = cur->next;
    cur->next = cur->next->next;
    found->next = temp;
    *windows = found;
    return *windows;

}

void freeList(node** windows)
{
    node* temp;
    while((*windows) != NULL)
    {
        temp = *windows;
        *windows = (*windows)-> next;
        free(temp);
    }
}