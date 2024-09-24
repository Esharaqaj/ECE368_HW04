#include "hw04.h"

#define MAX_ORD 25


int main()
{
    int id = 0;
    char order[MAX_ORD];
    //node* windows = (node *)malloc(sizeof(node));

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
    printf("%d\n", (*windows)->data);


    // if ((*windows)== NULL) {
    //     *windows = createNewNode(id);
    //     printf("%d\n", (*windows)->data);

    // }

    // else {
    // while (cur->next != NULL) {
    //     cur = cur->next;
    // }

    // cur->next = createNewNode(id);
    // printf("%d\n", cur->next->data);
    // }
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
            return(*windows);
        }
        else 
        {
        temp = cur;
        (*windows) = (*windows)->next;
        printf("%d\n", (*windows)->data);
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
            printf("%d\n", cur->data);
            cur->next = cur->next->next;
            free(temp);
        }

        else
        {
            free(cur->next);
            cur->next = NULL;
            printf("%d\n", cur->data);

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
    printf("%d\n", cur->data);
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

    printf("%d\n", (*windows)->data);

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