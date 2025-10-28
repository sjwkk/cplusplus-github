#include<iostream>
using namespace std;

class SqQueue_ {
private :
	int* base;//����һ������
	int front;
	int rear;
	int capacity;//��¼�ռ�����
public:
	SqQueue_(int size=7)
	{
		capacity = size;
		base = new int[capacity];
		rear = front=0;
	}
	~SqQueue_()
	{
		capacity = 0;
		delete[] base;
		base = nullptr;
	}
private:
	void Expand(int cap)
	{
		
		//��������
		int* n = new  int[cap];
		int j = 0;
			//���α���
		for (int i = front; i != rear; i = (i + 1) % capacity) {
			n[j] = base[i]; j++;
		}
		delete[] base;
		front = 0;
		rear = j;
		base = n;
		capacity = cap;
	}
public:
	void Pop(int data)//���
	{
		if ((rear + 1) % capacity == front) {//�Ѿ�����
			Expand(2 * capacity);
		}
		base[rear] = data;
		rear = (rear + 1) % capacity;
	}
	void Pop()
	{
		if (front == rear)
			throw "�ѿ�";
		else {
			front = (front + 1) % capacity;
		}
	}

	int Top()const
	{
		if (front == rear)
			throw "�ѿ�";
		return base[front];
	}
	int Back()const
	{
		if (front == rear)
			throw "�ѿ�";
		
		return base[(rear - 1 + capacity) % capacity];
	}
	bool Empty()
	{
		return front == rear;
	}
	int Size()
	{
		int size_ = 0;
		
		for (int i = front; i != rear; i = (i + 1) % capacity)
		{
			size_++;
		}
		return size_;
	}
};

#if 0
int main()
{
	SqQueue_ sq(7); // ����Ϊ����������Ǻ�������
	for (int i = 0; i < 10; i++)
	{
		sq.Pop(i); // ��ȷ������ӷ���
	}
	cout << sq.Top() << endl;
	cout << sq.Size();
}

#endif 