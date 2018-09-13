#include "stack.h"
typedef stack *queue; 
void qinit(queue *);
void enqueue(queue *, int);
int dequeue(queue *);
int qempty(queue *);
int qfull(queue *);
void qprint(queue *);

