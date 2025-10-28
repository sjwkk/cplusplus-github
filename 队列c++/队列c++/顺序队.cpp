#include<iostream>
using namespace std;
#define MAXSIZE 7
typedef  int QElemType;
//循环队列
//顺序表，要包含一个数组和头尾指针
struct SqQueue {
	QElemType* base;//数组
	int front;
	int rear;
};
void InitQueue(SqQueue& Q) {
	Q.base = new QElemType[MAXSIZE];
	Q.front = Q.rear = 0;
}
void Destory(SqQueue& Q) {
	delete [] Q.base;
	Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
	{
		return 1;
	}
	return false;
}
bool Clear(SqQueue& Q) {
	if (!Q.base||Q.front==Q.rear) {
		return false;
	}
	Q.front = 0;
	Q.rear = 0;
	return true;
}

//求队列长度
int QueueLength(SqQueue Q) {
	if (Q.base) {
		
		return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
	}
	return -1;
}

//入队
bool EnQueue(SqQueue& Q,QElemType e)
{
	if (!Q.base||(Q.rear+1)%MAXSIZE==Q.front) 
	{
		return false;
	}
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return true;
}
//出队
bool DeQueue(SqQueue &Q,QElemType& e)//避免-1作为元素
{
	if (Q.front==Q.rear)//队为空
	{
		return false;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return  true;
}
//取队顶元素
QElemType GetHead(SqQueue Q)
{
	if (!Q.base||Q.front==Q.rear)
	{
		return -1;
	}
	return Q.base[Q.front];
}
#if 0
int main() {
	SqQueue Q;
	InitQueue(Q);
	for (int i = 0; i < 8; i++)
	{
		EnQueue(Q, i);
	}
	int e=0;
	cout <<"队顶元素 " << GetHead(Q) << endl;
	cout << "队的长度 " << QueueLength(Q) << endl;

	cout << "进行出队 " << DeQueue(Q, e) <<" " << e << endl;
	cout <<"队的长度 " << QueueLength(Q) << endl;
	cout <<"清空数组 "<<Clear(Q)<<endl;
	Destory(Q);
}
# endif