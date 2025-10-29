#include<iostream>

#include<assert.h>
using namespace std;

//顺序表
//可扩容的
 template<typename T>
 //类型
class SeqStack {

private:
	T*  base;
	T*  top;//栈顶，指向最后一个元素的下一个位置
	int capicaty;//容量
	bool  Expand()
	{
		扩容
		初始化一个数组，然后进行把原来的数组替换成新的数组
		
		T* new_base = new T[2*capicaty];
		if (!new_base) {
			return false;
		}
		memcpy(new_base, base, capicaty * sizeof(T));//以b为单位
		delete[] base;
		base = new_base;
		top = base + capicaty;
		capicaty *= 2;

		return true;
	}
public:
	
	SeqStack(int size=10) //默认大小
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
	T GetPop() const//获取栈顶的元素,只读
	{
		if (top == base)
		{
			assert(top != base);
		}
		return *(top-1);
	}
	T Pop()
	{
		if (top == base) throw "栈为空";
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


//链式栈
struct Node {//栈的结点
	int data;
	Node* next;
	Node(int val=0) {//初始化,默认构造函数
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
		head = new Node();//开辟一个头结点
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
		//链表头结点后面的位置进行
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
	bool Empty()//判断是否为空
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
