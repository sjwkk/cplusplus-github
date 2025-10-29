#include <iostream>
using namespace std;

using namespace std;
typedef int ElemType;//���ݵ�����


//ջ����
// ��ͷ�巨�����Ǻ��
//�ȳ�ʼ�����
typedef struct StackNode {
	ElemType data;//�������
	StackNode* next;//��һ�����
}*LinkStack;

bool InitStack(LinkStack& S)//��ʼ��
{
	//����Ҫ����ͷ���
	//S = new StackNode ();
	//S->next = nullptr;
	S = nullptr;
	return 1;
}
void DestoryStack(LinkStack& S) {//����ջ
	
	LinkStack p = S;
	while (p) {
		LinkStack cur = p->next;
		delete p;
		p = cur;
	}
	S = nullptr;//��ס��һ��
}
void ClearStack(LinkStack& S)//���ջ�������ͬ��
{
	LinkStack p = S;
	while (p) {
		LinkStack cur = p->next;
		delete p;
		p = cur;
	}
	S = nullptr;
}


bool StackEmpty(LinkStack S)//����Ƿ�Ϊ��ջ
{
	if (!S) {
		return true;
	}
	else {
		return false;
	}
}

int StackLengh(LinkStack& S)//��ȡջ�ĳ���
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
		return 0;//ջΪ��
	}
}

ElemType GetTop(LinkStack S) {//��ȡջ����Ԫ��
	if (S) {//����ջ�Ͳ�����
		return S->data;
	}
	return -1;
}

bool Push(LinkStack& S, ElemType data) {//��ջ
	//������뵽baseλ��
	
		//ͷ��
		LinkStack tmp = new StackNode();
		
		tmp->data = data;
		tmp->next = S;
		S = tmp;
		return 1;

}

ElemType Pop(LinkStack& S)//��ջ
{
	if (S) {
		//�ҵ�β����Ԫ��
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

void StackReverse(LinkStack S) {//��ͷ��β����
	cout << "��� ";
	//�趨һ����ʱָ��
	while (S) {
		cout << S->data<<" ";
		S = S->next;
	}
	cout << endl;
}
//�������ʽ����ֵ
void EvaluteExpression()
{

}


#if 0
int main()
{
	/*
	LinkStack S;
	cout << "��ʼ��" << InitStack(S) << endl;

	for (int i = 0; i < 10; i++)
	{
		Push(S, i + 1);
	}
	cout << "��ȡ���� " << StackLengh(S) << endl;//��ȡ����

	StackReverse(S);
	cout << "��ȡջ����Ԫ�� " << GetTop(S) << endl;

	cout << "��ջ " << Pop(S) << endl;
	cout << "��ȡ���� " << StackLengh(S) << endl;//��ȡ����


	//ClearStack(S);

	//cout << "���ջ֮��: " << StackEmpty(S) << endl;

	DestoryStack(S);

	cout << "���ٺ�" << GetTop(S) << endl;

	cout << "���ٺ�" << StackEmpty(S) << endl;//����
	*/



}
# endif