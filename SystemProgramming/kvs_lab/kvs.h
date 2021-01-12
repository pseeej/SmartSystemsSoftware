#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
	char key[100];
	char* value;
	struct node* next;
};	
typedef struct node node_t;


struct kvs{
	struct node* db; // database
	int items; // number of data 
};
typedef struct kvs kvs_t; 


kvs_t* open();
int close(kvs_t* kvs);
int put(kvs_t* kvs, const char* key, const char* value);
char* get(kvs_t* kvs, const char* key);
