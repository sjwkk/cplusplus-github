#include<iostream>
using namespace std;

//ð������,����������
void sort1(int* array, int len)
{
	for (int i = 0; i < len - 1; i++)//��������
	{
		for (int j = 0; j < len - i - 1; j++)//ÿһ�˵ıȽ���
		{
			if(array[j]>array[j+1])
			{
				int tmp = array[i];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
int main()
{
	int array[] = { 1,2,22,33,52,666 };
	int len = sizeof(array) / sizeof(int);
	sort1(array, len);
	for (int ele : array)
	{
		cout << ele << endl;
	}

}