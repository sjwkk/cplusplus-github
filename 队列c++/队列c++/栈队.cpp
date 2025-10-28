#include<iostream>
using namespace std;
typedef  int QElemType;

typedef struct QNode {//���ǽ��Ľṹ��
	struct QNode* next; // �����˴� Qode -> QNode
	QElemType data;
}QNode ,*QueuePtr;

struct LinkQueue//���Ƕ��е�ͷ��β
{
	QueuePtr front;
	QueuePtr rear;
};

void InitQueue(LinkQueue& Q) {
	//����һ��ͷ���
	Q.front = Q.rear = new QNode();
	Q.front->next = nullptr;
}

void Destory(LinkQueue& Q) {
	//����
	QueuePtr p = Q.front;
	while (p)
	{
		QueuePtr cur = p->next;
		delete p;
		p = cur;
	}
}
//rear����Ԫ�ص�
bool QueueEmpty(LinkQueue Q)
{
	if (Q.front== Q.rear)
	{
		return true;
	}
	return false;
}

bool Clear(LinkQueue& Q) {
	QueuePtr p = Q.front->next;
	while (p)
	{
		QueuePtr cur = p->next;
		delete p;
		p = cur;
	}
	Q.rear = Q.front;
	Q.front->next = nullptr;
	return true;
}

//����г���
int QueueLength(LinkQueue Q) {
	if (Q.front) {

		int len = 0;
		QueuePtr p = Q.front->next;
		while (p)
		{
			p = p->next;
			len++;
		}
		return len;
	}
	return -1;
}

//���
bool EnQueue(LinkQueue& Q, QElemType e)//������ڶ���
{
	if (!Q.front )
	{
		return false;
	}
	QueuePtr p = new QNode();
	p->data = e;

	p->next = nullptr;
	Q.rear->next = p;
	Q.rear = Q.rear->next;
	return true;
}
//����
bool DeQueue(LinkQueue& Q,QElemType & e)
{
	if (Q.front == Q.rear)//��Ϊ��
	{
		return false;
	}
	e = Q.front->next->data;
	QueuePtr q = Q.front->next;
	Q.front->next = q->next;
	if (q==Q.rear)
	{
		Q.rear = Q.front;
	}

	delete q;
	return  true;
}
//ȡ�Ӷ�Ԫ��
QElemType GetHead(LinkQueue Q)
{
	if (Q.front==Q.rear)
	{
		return -1;
	}
	return Q.front->next->data;
}
#if 0
int main() {
	LinkQueue Q;
	InitQueue(Q);
	for (int i = 0; i < 8; i++)
	{
		EnQueue(Q, i);
	}
	int e = 0;
	cout << "�Ӷ�Ԫ�� " << GetHead(Q) << endl;
	cout << "�ӵĳ��� " << QueueLength(Q) << endl;

	cout << "���г��� " << DeQueue(Q, e) << " " << e << endl;
	cout << "�ӵĳ��� " << QueueLength(Q) << endl;
	cout << "������� " << Clear(Q) << endl;
	Destory(Q);
}
#endif