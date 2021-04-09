#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void *thread_main(void *arg){
    int i;

    sem_wait(&sem);
    for(i = 0;i<3;i++){
	sleep(1);
	printf("Thread : %d %d\n", *(int *)arg, i);
    }
    sem_post(&sem);
    return NULL;
}

int main(int argc, char *argv[]){
    int i;
    pthread_t t_id[8];
    int thread_num[8] = {1,2,3,4,5,6,7,8};
    sem_init(&sem, 0, 3);

    for (i = 1;i<=8;i++){
	pthread_create(&t_id[i-1], NULL, thread_main, &thread_num[i-1]);
    }

    for(i = 0;i<8;i++){
	pthread_join(t_id[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}
