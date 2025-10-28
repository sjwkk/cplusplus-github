
#include<iostream>
using namespace std;

// 使用双向循环链表
struct Node {
	int data;
	Node* next;
	Node* prev;
	Node()
	{
		data = 0;
		next = nullptr;
		prev = nullptr;
	}
};
//链队
class LinkQueue {
public:
	Node* head;//头结点
	int size;
public:
	LinkQueue()
	{
		head = new Node();//
		head->next = head;
		head->prev = head;
		size = 0;
	}
	~LinkQueue()
	{
		Node* cur = head->next;
		while (cur!=head)
		{
			Node* p = cur->next;
			delete cur;
			cur = p;
		}
		delete head;
		head = nullptr;
	}
	void Pop()//出队
	{
		
		Node* cur = head->next;
		if(cur!=head)
		{
			cur->next->prev = head;

			head->next = cur->next;
			delete cur;
			cur = nullptr;
			size--;
		}
	}
	void Push(int data)//入队
	{
		Node* n=new Node;
		n->data = data;
		n->next = head;
		n->prev = head->prev;
		head->prev->next = n;
		head->prev = n;
		size++;
	}
	int Top()
	{
		if (head->next != head)
		{
			return head->next->data;
		}
	}
	int Back()
	{
		if (head->next != head)
		{
			return head->prev->data;
		}
	}
	bool Empty()
	{
		
		if (head->next == head)
			return true;
		return false;
	} 
};

int main()
{
	LinkQueue sq; // 修正为对象定义而不是函数声明
	for (int i = 0; i < 10; i++)
	{
		sq.Push(i); // 正确调用入队方法
	}
	cout << sq.Top() << endl;
	cout << sq.size;
}