#include "kvs.h"

int put(kvs_t* kvs, const char* key, const char* value)
{
    printf("put: %s, %s\n", key, value);
    /* do program here */

    node_t* newNode = (node_t *)malloc(sizeof(node_t));
    node_t* tempNode = (node_t *)malloc(sizeof(node_t));

    newNode->value = (char*)malloc(sizeof(value));

    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode -> next = NULL;

    int num = kvs->items;

    if(num==0)
	kvs->db = newNode;
    else{
	tempNode = kvs->db;
	for(int i=0;i<num-1;i++)
	    tempNode = tempNode->next;
	tempNode->next = newNode;
    } 


    kvs->items += 1;

    return 0;
}
