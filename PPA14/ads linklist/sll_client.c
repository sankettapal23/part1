#include<stdio.h>
#include<stdlib.h>
#include "sll.h"
#include <assert>

void main()
{
    data_t data;
    status_t status;
    sll_t* p_list =NULL;

    p_list = create_list();
    show_list(p_list,"After Creating List");

    status = insert_start(p_list, 10);
    show_list(p_list,"\nAfter Insert start");

    status = insert_start(p_list, 20);
    show_list(p_list,"\nAfter Insert start");

    status = insert_start(p_list, 30);
    show_list(p_list,"\nAfter Insert start");

    status = insert_start(p_list, 40);
    show_list(p_list,"\nAfter Insert start");

    status = insert_start(p_list, 50);
    show_list(p_list,"\nAfter Insert start");

    status = insert_start(p_list, 60);
    show_list(p_list,"\nAfter Insert start");

    status = insert_end(p_list, 70);
    show_list(p_list,"\nAfter Insert end");

    status = insert_after(p_list,30,-5000);
    show_list(p_list,"After insert_after");
    status = insert_before(p_list,60,-9000);
    show_list(p_list,"After insert_before");

    status=get_start(p_list, &data);
    assert(status==SUCCESS);
    printf("START data =%d\n", data);
    status= get_end(p_list,&data);
    assert(status==SUCCESS);
    printf("end data =%d\n", data);
}