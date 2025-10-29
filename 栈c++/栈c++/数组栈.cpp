#include <iostream>
using namespace std;
typedef char SElemType;

//顺序栈
struct SqStack {
	SElemType* base;
	SElemType* top;
	int stacksize;//栈的最大可用容量
};


//初始化
bool InitStack(SqStack& S)
{
	
	S.base = new SElemType[100];//开辟一个数组
	if (!S.base)exit(-1);

	S.stacksize = 100;
	S.top = S.base;

	return 1;
}

SElemType GetTop(SqStack S) {
	if (S.base&&S.base!=S.top) {//检查空栈和不存在
		return *(S.top-1);
	}
	return -1;
}

//入栈
bool Push(SqStack& S,SElemType data) {
	//不会插入到base位置
	if(S.base&&S.top-S.base<100)//确保栈存在,栈还有空间
	{
		*S.top = data;
		S.top = S.top + 1;
		return 1;
	}
	return 0;
}

//出栈
SElemType Pop(SqStack &S)
{
	if(S.base&&S.base!=S.top)
	{
		return *--S.top;//为什么不需要把栈顶的元素制空?
	}
	else {
		return -1;
	}
}


//销毁栈
void DestoryStack(SqStack& S) {
	//S.base=nullptr;
	//使用while循环
	if (S.base)
	{
		delete[] S.base;
	}
	S.base = nullptr;
	S.top = S.base;
	S.stacksize = 0;
}


void ClearStack(SqStack& S)
{
	S.top = S.base;
}



//检查是否为空栈
bool StackEmpty(SqStack& S)
{
	if (S.base && S.base == S.top)
		return true;
	else if (S.base)
		return false;
	else
		cout << "栈不存在\n";
		return false;
}

//获取栈的长度
int StackLengh(SqStack& S)
{
	if (S.base) {
		return S.top - S.base;
	}
	else {
		return -1;
	}
}



//从头到尾遍历
void StackReverse(SqStack S) {
	cout << "输出 ";
	//设定一个临时指针
	SElemType* p = S.base;
	while (p!= S.top)
	{
		cout << (*p)<<" ";
		p++;
	}
	cout << endl;
}



//表达式求值




int main()
{

	/*
	SqStack S;
	cout << "初始化" << InitStack(S) << endl;

	for (int i = 0; i < 10; i++)
	{
		Push(S, i + 1);
	}
	cout << "获取长度 " << StackLengh(S) << endl;//获取长度

	StackReverse(S);
	cout <<"获取栈顶的元素 " << GetTop(S) << endl;

	cout << "出栈 " << Pop(S) << endl;
	cout << "获取长度 " << StackLengh(S) << endl;//获取长度


	ClearStack(S);

	cout<<"清空栈之后: " << StackEmpty(S) << endl;

	DestoryStack(S);

	cout << "销毁后" << GetTop(S) << endl;

	cout << "销毁后" << StackEmpty(S) << endl;//销毁
	*/
	
}
