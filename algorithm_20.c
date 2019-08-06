#include<stdio.h>
#include<stdlib.h>
#define MAX_QUEUE_SIZE 20
typedef int element;
typedef struct { 	//큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear; 
} DequeType;

//오류함수;
void error (char *message){
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//초기화; 
void init_deque(DequeType *q){
	q->front = q->rear = 0;
}

//공백상태 검출 함수;
int is_empty(DequeType *q){
	return (q->front == q->rear);
} 

//포화 상태 검출 함수;
int is_full(DequeType *q){
	return ((q->rear+1) % MAX_QUEUE_SIZE == q->front);
} 

//원형큐 출력 함수;
void deque_print(DequeType *q){
	printf("DEQUE(front = %d rear = %d) = ", q->front, q->rear);
	if(!is_empty(q)){
		int i = q->front;
		do{
			i=(i+1)%(MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if(i==q->rear)
				break;
		} while(i!=q->front);
	}
	printf("\n");
} 

//삽입함수;
void add_rear(DequeType *q, element item){
	if(is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear+1)%MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
} 

//삭제함수;
element delete_front(DequeType *q){
	if(is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front+1)%MAX_QUEUE_SIZE;
	return q->data[q->front];
} 

void add_front(DequeType *q, element val){
	if(is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = val;
	q->front = (q->front - 1) % MAX_QUEUE_SIZE;
} 

element delete_rear(DequeType *q){
	int prev = q->rear;
	if(is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear-1 ) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_front(DequeType *q){
	if(is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front+1)%MAX_QUEUE_SIZE];
}

element get_rear(DequeType *q){
	if(is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}

main(){
	DequeType queue;
	
	init_deque(&queue);
	int i;
	for(i=0;i<3;i++){
		add_front(&queue, i);
		deque_print(&queue);
	}
	for(i=10;i<13;i++){
		add_rear(&queue, i);
		deque_print(&queue);
	}
	for(i=0;i<3;i++){
		delete_rear(&queue);
		deque_print(&queue);
	}
}

