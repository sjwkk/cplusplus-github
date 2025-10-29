#include<iostream>

#include<assert.h>
using namespace std;

//˳���
//�����ݵ�
 template<typename T>
 //����
class SeqStack {

private:
	T*  base;
	T*  top;//ջ����ָ�����һ��Ԫ�ص���һ��λ��
	int capicaty;//����
	bool  Expand()
	{
		����
		��ʼ��һ�����飬Ȼ����а�ԭ���������滻���µ�����
		
		T* new_base = new T[2*capicaty];
		if (!new_base) {
			return false;
		}
		memcpy(new_base, base, capicaty * sizeof(T));//��bΪ��λ
		delete[] base;
		base = new_base;
		top = base + capicaty;
		capicaty *= 2;

		return true;
	}
public:
	
	SeqStack(int size=10) //Ĭ�ϴ�С
	{
		capicaty = size ;
		base = new T[capicaty];
		top = base;
	}

	~SeqStack()
	{
		capicaty = 0;
		
		delete[] base;
		top = base=nullptr;
	}
	T GetPop() const//��ȡջ����Ԫ��,ֻ��
	{
		if (top == base)
		{
			assert(top != base);
		}
		return *(top-1);
	}
	T Pop()
	{
		if (top == base) throw "ջΪ��";
		T tmp = *(top - 1);
		top--;
		return tmp;
	}
	void Push(T val)
	{
		if (top - base >= capicaty)
		{
			Expand();
		}
		*top++ = val;
	}
	bool Empty()
	{
		if (top == base)
		{
			return true;
		}
		return false;
	}

};


//��ʽջ
struct Node {//ջ�Ľ��
	int data;
	Node* next;
	Node(int val=0) {//��ʼ��,Ĭ�Ϲ��캯��
		data = val;
		next = new Node();
		next = nullptr;
	}

};
class LinkStack
{
private :
	Node* head;

	LinkStack()
	{
		head = new Node();//����һ��ͷ���
	}
	~LinkStack()
	{
		Node* p = head;
		while (p != nullptr)
		{
			Node* tmp = p->next;
			delete p;
			p = tmp;
		}
	}
public:
	void Push(int val)
	{
		Node* new_node=new Node(val);
		//����ͷ�������λ�ý���
		new_node->next = head->next;
		head->next = new_node;
	}
	void Pop()
	{
		if (!head->next)
			throw "this is empty";
		Node* p = head->next;
		head->next = p->next;
		delete p;
		p = nullptr;
	}
	int  GetTop()
	{
		if (!head->next)
			throw "this is empty";
		return head->next->data;
	}
	bool Empty()//�ж��Ƿ�Ϊ��
	{
		return head->next == nullptr;
	}
};



int main()
{
	SeqStack <int>  sq;
	cout << sq.GetPop() << endl;

	sq.Push(1);
	sq.Push(3);
	sq.Push(2);
	int i = 10;
	while (i)
	{
		sq.Push(i);
		i--;
	}
	cout << sq.GetPop() << endl;
	cout << sq.Empty() << endl;
}
