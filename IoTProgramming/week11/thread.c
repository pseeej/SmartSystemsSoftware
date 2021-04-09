#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

int result;

void *thread_main(void *arg){

    int n= *(int *)arg;
    int i;

    for(i=0;i<n;i++){
	sleep(1);
	printf("Running...\n");
    }
    result = i;
    pthread_exit((void *)&result);
    return NULL;
//    return (void *)&result;
}

int main(){

    pthread_t t_id;
    int arg = 10;
    int ret;
    int *a;


    ret = pthread_create(&t_id, NULL, thread_main, (void *)&arg);
    if(ret != 0){
	errno = ret;
	perror("thread_create");
	return 0;
    }
    pthread_detach(t_id);
    sleep(5);
    /*
    ret = pthread_join(t_id, (void **)&a);
    if(ret != 0){
	errno=ret;
	perror("thread_join");
	return 0;
    }
    printf("result : %d\n", *a);
    */
    
    printf("End\n");

    return 0;
}
