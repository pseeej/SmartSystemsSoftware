#include <stdio.h>
#include <math.h>

typedef unsigned char *pointer;

void show_bytes(pointer start, size_t len){
	size_t i;
	for(i=0;i<len;i++){
		printf("%p\t0x%.2x\n", start+i, start[i]);
	}
	printf("\n");
}

int main(){

	printf("\n");

	//32bit ? 64bit
	if(sizeof(long)==8)
		printf("sizeof(long) == %ld\n\n64bit Computer\n\n", sizeof(long));
	else if(sizeof(long)==4)
		printf("sizeof(long) == %ld\n\n32bit Computer\n\n", sizeof(long));
	else;

	//little ? big
	int a = 15213;
	printf("int a = 15213;\n");
	show_bytes((pointer) &a, sizeof(int));

	int a_last16 = a%256;
	if(*((char*)&a) == a_last16)
		printf("Little Endian Computer\n");
	else
		printf("Big Endian Computer\n");



	printf("\n");

	return 0;
}
