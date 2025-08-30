#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector <int> getvector()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	return v;
}

//find�㷨
#if 0
class Person {
public:
	string m_name;
	int m_age;
	Person() {}
	Person(string name, int age) : m_name(name), m_age(age) {}
	bool operator== (const Person p)
	{
		return p.m_age == m_age && p.m_name == m_name;
	}
};
void test03()
{
	vector<int > v = getvector();
	//�������в���5
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	cout << *it << endl;

	//�ڶ����÷�
	vector<Person> v1;//�����
	v1.push_back(Person("xb", 11));
	v1.push_back(Person("xa", 12));
	v1.push_back(Person("xc", 13));
	v1.push_back(Person("xd", 14));

	//
	auto it1 = find(v1.begin(), v1.end(), Person("xc", 13));
	if (it1 == v1.end())
	{
		cout << "û���ҵ�\n";
	}
	else
	{
		cout << "�ҵ���\n";
	}
}

#endif


//adjacent_find
#if 0
 class Person {
	public:
		string m_name;
		int m_age;
		Person() {}
		Person(string name, int age) : m_name(name), m_age(age) {}
		bool operator() (const Person p1,const Person p2)
		{
			return p1.m_age == p2.m_age && p1.m_name == p2.m_name;
		}
	};
void test04()
{
	int arr[10] = { 1,2,3,5,5,6,1,2 };
	vector<int> v(arr,arr+10);
	auto it=adjacent_find(v.begin(), v.end());
	cout << *it << endl;

	//�ڶ��� ����ν��
	vector<Person> v1;//�����
	v1.push_back(Person("xb", 11));
	v1.push_back(Person("xa", 12));
	v1.push_back(Person("xc", 13));//�����ظ�
	v1.push_back(Person("xc", 13));
	v1.push_back(Person("xd", 14));
	auto it1 = adjacent_find(v1.begin(), v1.end(),Person());
	if (it1 == v1.end())
	{
		cout << "û���ҵ�\n";
	}
	else {
		cout << "�ҵ��� " << it1->m_name << endl;
	}

}
#endif

//find_if
#if 0
class Com {
public:
	bool operator()(int m)
	{
		return m == 5;
	}
};
void test05()
{
	vector<int> v = getvector();
	auto it=find_if(v.begin(), v.end(), Com());
	
	cout << *it << endl;
}
#endif

//binary_search
#if 0
class Person {
public:
	string m_name;
	int m_age;
	Person() {}
	Person(string name, int age) : m_name(name), m_age(age) {}
	bool operator<(const Person o)
	{
		return m_name < o.m_name;
	}
	bool operator== (const Person p)//���������
	{
		return p.m_age == m_age && p.m_name == m_name;
	}
	
};

void test06()
{
	vector<int> v = getvector();
	auto it=binary_search(v.begin(), v.end(),3);
	cout << it << endl;

	//�ڶ����÷�
	vector<Person> v1;//�����
	v1.push_back(Person("xa", 11));
	v1.push_back(Person("xb", 12));
	v1.push_back(Person("xc", 13));
	v1.push_back(Person("xd", 14));
	auto it1 = binary_search(v1.begin(), v1.end(), Person("xc",13));
}
#endif

//count
#if 1
void test07() {
	int arr[] = {1,2,3,3,3,3,4,4,4};
	vector<int> v(arr , arr + (sizeof(arr) / sizeof(int)));
	//����3�����˶��ٴ�
	int i=count(v.begin(), v.end(), 3);
	cout << i;
}
#endif
int main()
{
	
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	return 0;
}

