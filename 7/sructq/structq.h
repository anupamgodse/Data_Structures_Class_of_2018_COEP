#define SIZE 128
typedef struct data {
	char name[16];
	int age;
}data;
typedef struct queue {
	data array[SIZE];
	int head, tail;
}queue;
void qinit(queue *);
void enqueue(queue *, data);
data dequeue(queue *);
int qempty(queue *);
int qfull(queue *);
void qprint(queue *);

