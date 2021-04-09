#include "kvs.h"

char* get(kvs_t* kvs, const char* key)
{
    /* do program here */


    node_t* curr = (node_t*)malloc(sizeof(node_t));

    curr = kvs->db;

    while(curr!=NULL){
	if(!strcmp(key, curr->key))
	    return curr->value;
	curr = curr->next;
    }

    char* value = (char*)malloc(sizeof(char)*10);

    if(!value){
	printf("Failed to malloc\n");
	return NULL;
    }

    strcpy(value, "deadbeaf");  
    return value;

}
