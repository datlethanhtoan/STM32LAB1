
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int empty(struct queue_t * q) {
    if (q == NULL) return 1;
	    return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
    /* TODO: put a new process to queue [q] */
    if(q == NULL)
        exit(1);
    q->proc[q->size] = proc;
    ++q->size;
}

struct pcb_t * dequeue(struct queue_t * q) {
    /* TODO: return a pcb whose prioprity is the highest
     * in the queue [q] and remember to remove it from q
     * */
    if(empty(q)) 
        return NULL;
    struct pcb_t * proc = q->proc[0];
#ifdef MLQ_SCHED
    --q->size;
    for(int i = 0; i < q->size; ++i) {
        q->proc[i] = q->proc[i + 1];
    }
	return proc;
#else
    int index = 0;
    int size = q->size;
    for(int i = 1; i < size; ++i) {
        if(proc->priority < q->proc[i]->priority) {
            index = i;
            proc = q->proc[i];
        }
    }
    --q->size;
    for(int i = index; i < q->size; ++i) 
        q->proc[i] = q->proc[i + 1];
    return proc
#endif
}

