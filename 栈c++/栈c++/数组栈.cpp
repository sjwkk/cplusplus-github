#include <iostream>
using namespace std;
typedef char SElemType;

//˳��ջ
struct SqStack {
	SElemType* base;
	SElemType* top;
	int stacksize;//ջ������������
};


//��ʼ��
bool InitStack(SqStack& S)
{
	
	S.base = new SElemType[100];//����һ������
	if (!S.base)exit(-1);

	S.stacksize = 100;
	S.top = S.base;

	return 1;
}

SElemType GetTop(SqStack S) {
	if (S.base&&S.base!=S.top) {//����ջ�Ͳ�����
		return *(S.top-1);
	}
	return -1;
}

//��ջ
bool Push(SqStack& S,SElemType data) {
	//������뵽baseλ��
	if(S.base&&S.top-S.base<100)//ȷ��ջ����,ջ���пռ�
	{
		*S.top = data;
		S.top = S.top + 1;
		return 1;
	}
	return 0;
}

//��ջ
SElemType Pop(SqStack &S)
{
	if(S.base&&S.base!=S.top)
	{
		return *--S.top;//Ϊʲô����Ҫ��ջ����Ԫ���ƿ�?
	}
	else {
		return -1;
	}
}


//����ջ
void DestoryStack(SqStack& S) {
	//S.base=nullptr;
	//ʹ��whileѭ��
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



//����Ƿ�Ϊ��ջ
bool StackEmpty(SqStack& S)
{
	if (S.base && S.base == S.top)
		return true;
	else if (S.base)
		return false;
	else
		cout << "ջ������\n";
		return false;
}

//��ȡջ�ĳ���
int StackLengh(SqStack& S)
{
	if (S.base) {
		return S.top - S.base;
	}
	else {
		return -1;
	}
}



//��ͷ��β����
void StackReverse(SqStack S) {
	cout << "��� ";
	//�趨һ����ʱָ��
	SElemType* p = S.base;
	while (p!= S.top)
	{
		cout << (*p)<<" ";
		p++;
	}
	cout << endl;
}



//���ʽ��ֵ




int main()
{

	/*
	SqStack S;
	cout << "��ʼ��" << InitStack(S) << endl;

	for (int i = 0; i < 10; i++)
	{
		Push(S, i + 1);
	}
	cout << "��ȡ���� " << StackLengh(S) << endl;//��ȡ����

	StackReverse(S);
	cout <<"��ȡջ����Ԫ�� " << GetTop(S) << endl;

	cout << "��ջ " << Pop(S) << endl;
	cout << "��ȡ���� " << StackLengh(S) << endl;//��ȡ����


	ClearStack(S);

	cout<<"���ջ֮��: " << StackEmpty(S) << endl;

	DestoryStack(S);

	cout << "���ٺ�" << GetTop(S) << endl;

	cout << "���ٺ�" << StackEmpty(S) << endl;//����
	*/
	
}
