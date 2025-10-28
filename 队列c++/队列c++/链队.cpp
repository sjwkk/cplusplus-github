
#include<iostream>
using namespace std;

// ʹ��˫��ѭ������
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
//����
class LinkQueue {
public:
	Node* head;//ͷ���
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
	void Pop()//����
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
	void Push(int data)//���
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
	LinkQueue sq; // ����Ϊ����������Ǻ�������
	for (int i = 0; i < 10; i++)
	{
		sq.Push(i); // ��ȷ������ӷ���
	}
	cout << sq.Top() << endl;
	cout << sq.size;
}