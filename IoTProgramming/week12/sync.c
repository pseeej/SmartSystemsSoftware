#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

int count = 0;
pthread_mutex_t mutex1, mutex2;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_main1(void *arg){

    int id = *(int *)arg;
    int i;

    for(i=1;i<=20;i+=2){
	pthread_mutex_lock(&mutex1);
	printf("id : %d %d\n", id, i);
	pthread_mutex_unlock(&mutex2);
    }

    return NULL;
}

void *thread_main2(void *arg){

    int id = *(int *)arg;
    int i;

    for(i=2;i<=20;i+=2){
	pthread_mutex_lock(&mutex2);
	printf("id : %d %d\n", id, i);
	pthread_mutex_unlock(&mutex1);
    }

    return NULL;
}


int main(){

    pthread_t t_id1, t_id2, t_id3;
    int ret;
    int a = 1, b=2, c=3;

    pthread_mutex_init(&mutex1, NULL);
    pthread_mutex_init(&mutex2, NULL);

    pthread_mutex_lock(&mutex2);
    ret = pthread_create(&t_id1, NULL, thread_main1,&a);
    ret = pthread_create(&t_id2, NULL, thread_main2,&b);
    //    ret = pthread_create(&t_id3, NULL, thread_main,&c);


    ret = pthread_join(t_id1, NULL);
    ret = pthread_join(t_id2, NULL);
    //    ret = pthread_join(t_id3, NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_mutex_destroy(&mutex2);

    return 0;
}
