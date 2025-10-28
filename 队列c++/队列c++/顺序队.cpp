#include<iostream>
using namespace std;
#define MAXSIZE 7
typedef  int QElemType;
//ѭ������
//˳���Ҫ����һ�������ͷβָ��
struct SqQueue {
	QElemType* base;//����
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

//����г���
int QueueLength(SqQueue Q) {
	if (Q.base) {
		
		return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
	}
	return -1;
}

//���
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
//����
bool DeQueue(SqQueue &Q,QElemType& e)//����-1��ΪԪ��
{
	if (Q.front==Q.rear)//��Ϊ��
	{
		return false;
	}
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return  true;
}
//ȡ�Ӷ�Ԫ��
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
	cout <<"�Ӷ�Ԫ�� " << GetHead(Q) << endl;
	cout << "�ӵĳ��� " << QueueLength(Q) << endl;

	cout << "���г��� " << DeQueue(Q, e) <<" " << e << endl;
	cout <<"�ӵĳ��� " << QueueLength(Q) << endl;
	cout <<"������� "<<Clear(Q)<<endl;
	Destory(Q);
}
# endif