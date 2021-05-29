#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>

#define MAX 1000

int buffer[MAX];
int fill_idx = 0;
int use = 0;
int count = 0;

int psum = 0;
int csum = 0;

pthread_cond_t empty, fill;
pthread_mutex_t mutex;

int loops;

int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int pthread_cond_signal(pthread_cond_t *cond);
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void put(int value){
    buffer[fill_idx] = value;
    fill_idx = (fill_idx + 1)%MAX;
    count++;
    psum += (value-fill_idx);
}

int get(){
    int temp = buffer[use];
    use = (use+1) % MAX;
    count--;
    csum += (temp-use);
    return temp;
}

void *producer(void *arg){
    int i;
    for(i = 0;i<loops;i++){
	    pthread_mutex_lock(&mutex);
    	while (count==MAX)
	        pthread_cond_wait(&empty, &mutex);
	    put(i);
    	pthread_cond_signal(&fill);
    	pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void *consumer(void *arg){
    int i;
    for (i=0;i<loops;i++){
	    pthread_mutex_lock(&mutex);
    	while(count==0)
	        pthread_cond_wait(&fill, &mutex);
    	int tmp = get();
    	pthread_cond_signal(&empty);
    	pthread_mutex_unlock(&mutex);
    	printf("%d\n", tmp);
    }
    return NULL;
}

int main(int argc, char *argv[]){
    if(argc!=2){
	    fprintf(stderr, "usage : threads <value> \n");
	    exit(1);
    }

    loops = atoi(argv[1]);
    pthread_t p1, p2, c1, c2;
    int rc = pthread_mutex_init(&lock, NULL);
    assert(rc==0);

    pthread_create(&p1, NULL, producer, NULL);
    pthread_create(&p2, NULL, producer, NULL);
    pthread_create(&c1, NULL, consumer, NULL);
    pthread_create(&c2, NULL, consumer, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_join(c1, NULL);
    pthread_join(c2, NULL);
    
    if(psum==csum)
        printf("Test OK\n");
    else
        printf("Wrong\n");

    return 0;
}
