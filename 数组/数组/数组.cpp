#include<iostream>

using namespace std;

//˳�������
#if 0

class Array {
private:
	int* m_Arr;//����
	int m_lenth;//������ЧԪ�صĸ���
	int m_capacity;//����

	void  expand()//дΪ˽�з���  �ڲ���������
	{
		//��ԭ�л��������һ��
		int size = m_capacity * 2;
		
		int* p = new int[size];
		memcpy(p, m_Arr, sizeof(int) * m_lenth);//ʱ�临�Ӷ���O(n)
		delete[]m_Arr;
		m_Arr = p;
		m_capacity = size;

	}
public:
	Array(int size = 10)//ָ����С
	{
		m_capacity = size;
		m_lenth = 0;
		m_Arr = new int[size];//����һ���ռ�
	}
	~Array()
	{
		delete [] m_Arr;//ֻ��ɾȥ���ϵ����ڴ�
		m_Arr = nullptr;

		m_lenth = 0;
		m_capacity = 0;
	}
	void pushback(int val)
	{
		if (m_lenth == m_capacity)//��������
		{
			expand();
		}
			m_Arr[m_lenth++] = val;
	
	}
	void popback() 
	{
		if(m_lenth>0)
			m_lenth--;
	}
	
	//��λ������Ԫ��
	void insert(int pos, int val)
	{
		if (pos<0 || pos>m_lenth)
		{
			cout << "������Χ";
			throw "pos invalid";
			//return;
		}
		if (m_lenth == m_capacity)
		{
			expand();
			//��pos֮���λ��ͳһ����ƶ�
		}
		for (int i = m_lenth; i >pos; i--)
		{
			m_Arr[i] = m_Arr[i - 1];//O(n)
		}
		m_Arr[pos] = val;
		m_lenth++;

	}
	//��λ��ɾ��
	void erase(int pos)//Ҫ�Բ�������Ч�Խ����ж�
	{
		if (pos<0 || pos>m_lenth)
		{
			cout << "������Χ";
			throw "pos invalid";
			//return;
		}
		for (int i = pos; i < m_lenth-1; i++)
		{
			m_Arr[i] = m_Arr[i + 1];
		}
		m_lenth--;
	}

	int find(int val)
	{
		for (int i = 0; i < m_lenth; i++)
		{
			if (m_Arr[i] == val)
			{
				return i;
			}
		}
		return -1;
	}

	void print()
	{
		for (int i = 0; i < m_lenth; i++)
		{
			cout << m_Arr[i] << " ";
		}
		cout << endl;
	}
    // �滻ԭ�е� ostream operator<< ����Ϊ��Ԫ��������
    friend ostream& operator<<(ostream& os, const Array& arr)
    {
        for (int i = 0; i < arr.m_lenth; i++)
        {
            os << arr.m_Arr[i] << " ";
        }
        return os;
    }
};


int main()
{
	Array arr1;
	arr1.pushback(1);
	arr1.pushback(2);
	arr1.pushback(3);

	arr1.insert(1,20);
	//arr1.print();
	cout << arr1;
}
#endif


//�����ַ���
void Reverse(char arr[], int size)
{
	//ǰ������ָ�룬����λ��
	//��������left>=rigth
	char* left = arr;
	char* right = arr + size-1;
	while (left < right)
	{
		char tmp = *right;
		*right = *left;
		*left = tmp;
		right--;
		left++;
	}
}


//int���飬��ż���ŵ���࣬�����ŵ��Ҳ�
//ֻҪleft��ż���Ͳ����н��������left��������right��ż�����ͽ�������λ��
//ʱ�临�Ӷ���O(n)
void exchange(int arr[],int size)
{
	int* left = arr;
	int* right = arr + size - 1;
	while (left < right)
	{
		//if ((*left & 0x1) == 0)//λ����
		if ((*left) % 2 == 1 && (*right) % 2 == 0)//������������Ҳ���ż��
		{
			int tmp = *right;
			*right = *left;
			*left = tmp;
			right--;
			left++;
		}
		else 
		{//ֱ���ҵ�������ż��
			while (*left % 2 == 0)
			{
				left++;
			}
			while (*right % 2 == 1)
			{
				right--;
			}
		}
	}
}



int main()
{
	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr[10] = { 2,3,33,11,0,1,3,5,7,9 };
	exchange(arr, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
}