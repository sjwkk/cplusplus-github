#include<iostream>
using namespace std;
typedef  int QElemType;

typedef struct QNode {//这是结点的结构体
	struct QNode* next; // 修正此处 Qode -> QNode
	QElemType data;
}QNode ,*QueuePtr;

struct LinkQueue//这是队列的头和尾
{
	QueuePtr front;
	QueuePtr rear;
};

void InitQueue(LinkQueue& Q) {
	//开辟一个头结点
	Q.front = Q.rear = new QNode();
	Q.front->next = nullptr;
}

void Destory(LinkQueue& Q) {
	//遍历
	QueuePtr p = Q.front;
	while (p)
	{
		QueuePtr cur = p->next;
		delete p;
		p = cur;
	}
}
//rear是有元素的
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

//求队列长度
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

//入队
bool EnQueue(LinkQueue& Q, QElemType e)//不会存在队满
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
//出队
bool DeQueue(LinkQueue& Q,QElemType & e)
{
	if (Q.front == Q.rear)//队为空
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
//取队顶元素
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
	cout << "队顶元素 " << GetHead(Q) << endl;
	cout << "队的长度 " << QueueLength(Q) << endl;

	cout << "进行出队 " << DeQueue(Q, e) << " " << e << endl;
	cout << "队的长度 " << QueueLength(Q) << endl;
	cout << "清空数组 " << Clear(Q) << endl;
	Destory(Q);
}
#endif