#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void reHeapUp (struct queue_t * q , uint8_t pos )
{
	if (pos>0){
		int8_t par = (pos-1)/2 ;
		if (q->proc[pos]->priority>q->proc[par]->priority){
			struct pcb_t *temp = q->proc[par]; 
			q->proc[par] = q-> proc[pos];
			q->proc[pos]= temp;
			reHeapUp(q,par);
		}
	}
}

void reHeapDown(struct queue_t * q, uint8_t pos, uint8_t last){
	uint8_t left = pos*2 +1 ;
	uint8_t  right = pos*2+2 ;
	uint8_t large ; 
	if ( left <= last ){
		if (right < last && q->proc[left]->priority < q->proc[right]->priority){
				large = right ;
		} else large=left ; 
		if (q->proc[large]->priority>q->proc[pos]->priority){
			pcb_t *temp = q->proc[large]; 
			q->proc[pos]= q->proc[large];
			q->proc[large] = q-> proc[pos];
			reHeapDown(q,large,last);
		}
	}
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (size== MAX_QUEUE_SIZE) return ; 
	q-> proc[q->size++] = proc ; 
	reHeapUp(q->proc,q->size-1 );
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	if (q->size==0)
	return NULL;
	struct pcb_t * ret = q->proc[0];
	q->size --;
	q->proc[0]= q->proc[q->size];
	reHeapDown(q,0,q->size-1);
	return ret; 
}

