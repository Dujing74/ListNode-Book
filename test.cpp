#include"Mng.h"
void test()
{
	CBookMng m1;
	CBook book;
	bool success;
	m1.Insert(1, book, success);
	//cout << book;
	//cout << m1;
	cout << m1[1];
}

int main()
{
	test();
	return 0;
}