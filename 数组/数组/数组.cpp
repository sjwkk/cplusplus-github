#include<iostream>

using namespace std;

//顺序表，数组
#if 0

class Array {
private:
	int* m_Arr;//数组
	int m_lenth;//数组有效元素的个数
	int m_capacity;//容量

	void  expand()//写为私有方法  内部数组扩容
	{
		//在原有基础上添加一倍
		int size = m_capacity * 2;
		
		int* p = new int[size];
		memcpy(p, m_Arr, sizeof(int) * m_lenth);//时间复杂度是O(n)
		delete[]m_Arr;
		m_Arr = p;
		m_capacity = size;

	}
public:
	Array(int size = 10)//指定大小
	{
		m_capacity = size;
		m_lenth = 0;
		m_Arr = new int[size];//开辟一个空间
	}
	~Array()
	{
		delete [] m_Arr;//只会删去堆上到的内存
		m_Arr = nullptr;

		m_lenth = 0;
		m_capacity = 0;
	}
	void pushback(int val)
	{
		if (m_lenth == m_capacity)//进行扩容
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
	
	//按位置增加元素
	void insert(int pos, int val)
	{
		if (pos<0 || pos>m_lenth)
		{
			cout << "超出范围";
			throw "pos invalid";
			//return;
		}
		if (m_lenth == m_capacity)
		{
			expand();
			//把pos之后的位置统一向后移动
		}
		for (int i = m_lenth; i >pos; i--)
		{
			m_Arr[i] = m_Arr[i - 1];//O(n)
		}
		m_Arr[pos] = val;
		m_lenth++;

	}
	//按位置删除
	void erase(int pos)//要对参数的有效性进行判断
	{
		if (pos<0 || pos>m_lenth)
		{
			cout << "超出范围";
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
    // 替换原有的 ostream operator<< 方法为友元函数重载
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


//逆序字符串
void Reverse(char arr[], int size)
{
	//前后两个指针，交换位置
	//结束条件left>=rigth
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


//int数组，把偶数放到左侧，奇数放到右侧
//只要left是偶数就不进行交换，如果left是奇数、right是偶数、就交换两个位置
//时间复杂度是O(n)
void exchange(int arr[],int size)
{
	int* left = arr;
	int* right = arr + size - 1;
	while (left < right)
	{
		//if ((*left & 0x1) == 0)//位操作
		if ((*left) % 2 == 1 && (*right) % 2 == 0)//左侧是奇数，右侧是偶数
		{
			int tmp = *right;
			*right = *left;
			*left = tmp;
			right--;
			left++;
		}
		else 
		{//直接找到奇数和偶数
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