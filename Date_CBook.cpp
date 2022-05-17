#include "Date_CBook.h"
int CBook::number = 0;
ostream& operator  <<(ostream& out, CBook& c1)
{
	out << "书名:" << c1.bookname << "\n" << "作者名:" << c1.author << "\n" << "出版社名:" << c1.publishname << endl;
	out << "价格：" << c1.price << endl;
	c1.d1.Output();
	out << "出版书的数量：" << c1.n << endl;
	return out;
}
istream& operator >>(istream& in, CBook& c1)
{
	cout << "请依次输入：书名 作者名 出版社名 书本价格 出版日期 图书数量" << endl;
	in >> c1.bookname >> c1.author >> c1.publishname >> c1.price;
	c1.d1.setdate();
	in >> c1.n;
	return in;
}
CBook& CBook::operator+(double i)
{
	this->price += i;
	return *this;
}
int  CBook::booknumber()
{
	int i;
	cin >> i;
	CBook::number = i;
	return i;
}

void Date::setdate()
{
	cin >> year >> month >> day;
}
void Date::Output()
{
	cout << "出版日期：" << year << "." << month << "." << day << endl;
}
Date::Date(const Date& d1)
{
	year = d1.year;
	month = d1.month;
	day = d1.day;
}
