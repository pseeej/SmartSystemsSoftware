#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

int count = 0;

void *thread_main(void *arg){

    int i;

    for(i=0;i<10000000;i++){
	count++;	
    }

    return NULL;
}

int main(){

    pthread_t t_id1, t_id2, t_id3;
    int ret;

    ret = pthread_create(&t_id1, NULL, thread_main,NULL);
    ret = pthread_create(&t_id2, NULL, thread_main,NULL);
    ret = pthread_create(&t_id3, NULL, thread_main,NULL);


    ret = pthread_join(t_id1, NULL);
    ret = pthread_join(t_id2, NULL);
    ret = pthread_join(t_id3, NULL);

    printf("count : %d\n", count);

    return 0;
}
