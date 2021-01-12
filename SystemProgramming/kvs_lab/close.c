#include "kvs.h"
#include <stdlib.h>

int close(kvs_t* kvs)
{
    /* do program */

    struct node *head;
    head = kvs->db;
    struct node *navi_node = head->next;
    struct node *free_node = NULL;

    while(navi_node->next!=NULL){
	free_node = navi_node;
	navi_node = navi_node->next;
	free(free_node);
    }

    head->next = navi_node;

    return 0;
}
