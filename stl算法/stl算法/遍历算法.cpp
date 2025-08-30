#if	0
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector <int> getvector()
{
	vector<int> v;
	for (int i= 0; i < 10; i++)
	{
		v.push_back(i);
	}
	return v;
}

//for_each
void print(int i)
{
	cout << i << " ";
}
class MyPrint {
public:
	void operator ()(int i)
	{
		cout <<i << " ";
	}
};
void test01()
{
	//��ȡ��������
	vector <int> v=getvector();
    for_each(v.begin(), v.end(), MyPrint());
	cout << endl;
	for_each(v.begin(), v.end(), print);
}


//transform
//������������֮����п�������

class Number {
public:
	int operator() (int i)
	{
		return i + 100;
	}
};

struct transformTest02 {
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

void test02()
{
	vector<int> v1= getvector();
	vector <int> v2;
	v2.resize(v1.size());//�����С
	transform(v1.begin(), v1.end(), v2.begin(),Number());
	vector <int> vtarget;
	vtarget.resize(v1.size());

	//��������
	transform(v1.begin(), v1.end(), v2.begin(), vtarget.begin(), transformTest02());
	for (auto it : vtarget)
	{
		cout << it << " ";
	}
}

int main()
{
	//test01();
	//test02();

	return 0;
}


#endif