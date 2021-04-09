#include "kvs.h"

int main()
{
    kvs_t* kvs = open();

    if(!kvs) {
	printf("Failed to open kvs\n");
	return -1;
    }

    FILE *pFile = NULL;


    pFile = fopen("student.dat", "rb");
    if(pFile==NULL){
	perror("fileOpen");
	exit(1);
    }

    while(!feof(pFile)){
	char name[30];
	char place[30];

	int ret = fscanf(pFile, "%s %s\n", name, place);
	if(ret<0){
	    printf("fscanf\n");
	    exit(-1);
	}

	ret = put(kvs, name, place);

	if(ret < 0){
	    printf("Failed to put data\n");
	    exit(-1);
	}
	

    }

    fclose(pFile);


    // KVS created.  
    char key[100]; 
    char* value = (char*) malloc (sizeof(char)* 300);
    char* rvalue;

    pFile = fopen("student.dat", "rb");
    if(pFile==NULL){
	perror("fileOpen");
	exit(1);
    }

    while(!feof(pFile)){

	int ret = fscanf(pFile, "%s %s\n", key, value);
	if(ret<0){
	    printf("fscanf\n");
	    exit(-1);
	}

	if(!(rvalue = get(kvs, key))){
	    printf("Failed to get data\n");
	    exit(-1);
	}

	printf("get: %s, %s\n", key, rvalue);

    }

    fclose(pFile);

    close(kvs);

    return 0;
}
