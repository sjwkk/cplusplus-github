#include<iostream>
using namespace std;

class SqQueue_ {
private :
	int* base;//开辟一个数组
	int front;
	int rear;
	int capacity;//记录空间容量
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
		
		//扩容数组
		int* n = new  int[cap];
		int j = 0;
			//依次遍历
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
	void Pop(int data)//入队
	{
		if ((rear + 1) % capacity == front) {//已经满了
			Expand(2 * capacity);
		}
		base[rear] = data;
		rear = (rear + 1) % capacity;
	}
	void Pop()
	{
		if (front == rear)
			throw "已空";
		else {
			front = (front + 1) % capacity;
		}
	}

	int Top()const
	{
		if (front == rear)
			throw "已空";
		return base[front];
	}
	int Back()const
	{
		if (front == rear)
			throw "已空";
		
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
	SqQueue_ sq(7); // 修正为对象定义而不是函数声明
	for (int i = 0; i < 10; i++)
	{
		sq.Pop(i); // 正确调用入队方法
	}
	cout << sq.Top() << endl;
	cout << sq.Size();
}

#endif 