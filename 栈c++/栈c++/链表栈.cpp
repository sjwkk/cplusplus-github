#include <iostream>
using namespace std;

using namespace std;
typedef int ElemType;//数据的类型


//栈队列
// 是头插法，不是后插
//先初始化结点
typedef struct StackNode {
	ElemType data;//存放数据
	StackNode* next;//下一个结点
}*LinkStack;

bool InitStack(LinkStack& S)//初始化
{
	//不需要设置头结点
	//S = new StackNode ();
	//S->next = nullptr;
	S = nullptr;
	return 1;
}
void DestoryStack(LinkStack& S) {//销毁栈
	
	LinkStack p = S;
	while (p) {
		LinkStack cur = p->next;
		delete p;
		p = cur;
	}
	S = nullptr;//记住这一步
}
void ClearStack(LinkStack& S)//清空栈这个是相同的
{
	LinkStack p = S;
	while (p) {
		LinkStack cur = p->next;
		delete p;
		p = cur;
	}
	S = nullptr;
}


bool StackEmpty(LinkStack S)//检查是否为空栈
{
	if (!S) {
		return true;
	}
	else {
		return false;
	}
}

int StackLengh(LinkStack& S)//获取栈的长度
{
	int len = 0;
	if (S)
	{
		LinkStack cur = S;
		while (cur)
		{
			len++;
			cur = cur->next;
		}
		return len;
	}
	else {
		return 0;//栈为空
	}
}

ElemType GetTop(LinkStack S) {//获取栈顶的元素
	if (S) {//检查空栈和不存在
		return S->data;
	}
	return -1;
}

bool Push(LinkStack& S, ElemType data) {//入栈
	//不会插入到base位置
	
		//头插
		LinkStack tmp = new StackNode();
		
		tmp->data = data;
		tmp->next = S;
		S = tmp;
		return 1;

}

ElemType Pop(LinkStack& S)//出栈
{
	if (S) {
		//找到尾部的元素
		LinkStack p=S->next;
		int ele = S->data;
		delete S;
		S = p;
		return ele;
	}
	else {
		return -1;
	}
}

void StackReverse(LinkStack S) {//从头到尾遍历
	cout << "输出 ";
	//设定一个临时指针
	while (S) {
		cout << S->data<<" ";
		S = S->next;
	}
	cout << endl;
}
//算数表达式求求值
void EvaluteExpression()
{

}


#if 0
int main()
{
	/*
	LinkStack S;
	cout << "初始化" << InitStack(S) << endl;

	for (int i = 0; i < 10; i++)
	{
		Push(S, i + 1);
	}
	cout << "获取长度 " << StackLengh(S) << endl;//获取长度

	StackReverse(S);
	cout << "获取栈顶的元素 " << GetTop(S) << endl;

	cout << "出栈 " << Pop(S) << endl;
	cout << "获取长度 " << StackLengh(S) << endl;//获取长度


	//ClearStack(S);

	//cout << "清空栈之后: " << StackEmpty(S) << endl;

	DestoryStack(S);

	cout << "销毁后" << GetTop(S) << endl;

	cout << "销毁后" << StackEmpty(S) << endl;//销毁
	*/



}
# endif