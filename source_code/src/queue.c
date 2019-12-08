#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
	return (q->size == 0);
}

void reHeapUp (struct queue_t * q , uint8_t pos )
{
	//printf("Heap up\n");
	if (pos>0){
		uint8_t par = (pos-1)/2 ;
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
		
		if (right <= last ){
			//printf("%d , %d\n",right , last );
			if( q->proc[left]->priority < q->proc[right]->priority){
				
				large = right ;
				
		} else large=left ; }
		else large =left;	
		if (q->proc[large]->priority>q->proc[pos]->priority){
			struct pcb_t *temp = q->proc[large]; 
			q->proc[large] = q->proc[pos];			
			q->proc[pos]= temp;
			reHeapDown(q,large,last);
		}
	}
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
	/* TODO: put a new process to queue [q] */	
	if (q->size== MAX_QUEUE_SIZE) return ; 
	q-> proc[q->size++] = proc ; 
	reHeapUp(q,q->size-1 );
	//printf("%d" , q->size);
}

struct pcb_t * dequeue(struct queue_t * q) {
	/* TODO: return a pcb whose prioprity is the highest
	 * in the queue [q] and remember to remove it from q
	 * */
	//printf("ec");	
	if (q->size==0) return NULL;
	struct pcb_t * ret = q->proc[0];
	
	q->proc[0]= q->proc[q->size-1];
	q->size --;	
	reHeapDown(q,0,q->size);
	
	return ret; 
}

