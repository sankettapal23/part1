#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

sll_t* create_list(void)
{
    return (get_node(0));
}

node_t* get_node(data_t new_data)
{
    node_t* new_node=NULL;

    new_node =(node_t*)xmalloc(sizeof(node_t));
    new_node->data = new_node->data;
    new_node->next = NULL;

    return (new_node);
}

void* xmalloc(size_t size_in_bytes)
{
    void* ptr = NULL;

    ptr = malloc(size_in_bytes);

    if(ptr == NULL)
    {
        fprintf(stderr, "Error in memory allocation");
        exit(EXIT_FAILURE);
    }

    return (ptr);
}

void show_list(sll_t* p_list, const char* msg)
{
    node_t* run = NULL;
    if(msg != NULL)
      puts(msg);

    run = p_list->next;
    printf("[start] ->");
    while(run!=NULL)
    {
        printf("[%d]->",run->data);
        run = run->next;
    }
    printf("[End]");

}

status_t insert_start(sll_t* p_list, data_t new_data)
{
    node_t* new_node=NULL;

    new_node = get_node(new_data);
    new_node ->next = p_list -> next;
    p_list->next = new_node;

    return (SUCCESS);
}

status_t insert_end(sll_t* p_list, data_t new_data)
{
    node_t* run=NULL;

    run=p_list ->next;

    while(run->next != NULL)
    {
        run=run->next;
    }
    run->next= get_node(new_data);

    return (SUCCESS);
}

status_t insert_after(sll_t* p_list, data_t e_data, data_t new_data)
{
    node_t* run=NULL;
    node_t* new_node=NULL;
    run=p_list -> next;
    while(run!=NULL)
    {
        if(run->data == e_data)
        {
            new_node = get_node(new_data);
            new_node->next = run->next;
            run->next=new_node;

            return(SUCCESS);
        }
        run=run->next;
    }
    return(LIST_DATA_NOT_FOUND);
}

status_t insert_before(sll_t* p_list, data_t e_data, data_t new_data)
{
    node_t* run=NULL;
    node_t* run_before=NULL;
    node_t* new_node=NULL;

    run=p_list->next;
    run_before=p_list;

    while(run != NULL)
    {
        if(run->data == e_data)
        {
            new_node=get_node(new_data);
            new_node -> next = run;
            run_before->next=new_node;

            return (SUCCESS);
        }
        run_before = run;
        run=run -> next;
    }
    return(LIST_DATA_NOT_FOUND);

}

status_t get_start(sll_t* p_list,data_t* p_start_data)
{
    if(p_list ->next ==NULL)
    {
        return (LIST_EMPTY);
    }
    *p_start_data = p_list ->next->data;
    return (SUCCESS);

}

status_t get_end(sll_t* p_list,data_t* p_end_data)
{
    
}