typedef struct node {
	char name;
	struct node *next;
}node;
typedef node *queue;
void qinit(queue *);
void enqueue(queue *, char);
char dequeue(queue *);
int qempty(queue *);
int qfull(queue *);
void qprint(queue *);

