#include "linkedlist.h"

int linked_list_init(linked_list_t** ll) 
{
	if(ll == NULL){
		printf("linked list pointer error \n");
		return -1;
	}

	/* do program */
	/* allocate linked list */
	/* initialize list head */
	/* initialize mutex lock for BLINKED_LIST version */

    *ll = (linked_list_t*)malloc(sizeof(linked_list_t));
    (*ll)->list_head = (node_t*)malloc(sizeof(node_t));

#ifdef BLINKED_LIST

    //ll->list_lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_init(&(*ll)->list_lock, NULL);

#endif

    (*ll)->list_head->next = NULL;
    (*ll)->list_head->key = 0;
    (*ll)->list_head->value = 0;

	srand((unsigned) time (NULL));

	return 0;
}


void linked_list_destroy(linked_list_t* ll)
{
	/* do program */ 
	/* free all nodes in the linked list */
	/* free the linked list */ 

    node_t* temp = ll->list_head;
    node_t* temp2 = temp;

    while(temp!=NULL){
        temp2 = temp2->next;
        free(temp);
        temp = temp2;
    }

	return;
}


long linked_list_get (long key, linked_list_t* ll) 
{
	/* do program */
	/* if key is found, return value */
	/* if key is not found, return -1 */

    node_t* temp = ll->list_head;

    while(temp!=NULL){
        if(temp->key == key)
            return temp->value;
        temp = temp->next;
    }

	return -1;
}

long linked_list_put (long key, long value, linked_list_t* ll)
{
	/* do program */
	/* if succeeds, return 0 */
	/* if fails, return -1 */

#ifdef BLINKED_LIST
    pthread_mutex_lock(&ll->list_lock);

    node_t* newNode = (node_t*)malloc(sizeof(node_t));
    newNode->key = key;
    newNode->value = value;
    newNode->next = ll->list_head->next;
    
    node_t* temp = ll->list_head; 

    temp->next = newNode;

    pthread_mutex_unlock(&ll->list_lock);

    return 0;
#endif

    node_t* temp2 = ll->list_head;

    node_t* newNode2 = (node_t*)malloc(sizeof(node_t));
    newNode2->key = key;
    newNode2->value = value;

    while(temp2){
        node_t* nextNode = temp2->next;
        int check = CAS(&temp2->next, temp2->next, newNode2);

        if(check==1){
            newNode2->next = nextNode;
            break;
        }
        else;
            //temp2 = temp2->next;
    }




	return 0;
}
