#include "Date_CBook.h"
int CBook::number = 0;
ostream& operator  <<(ostream& out, CBook& c1)
{
	out << "����:" << c1.bookname << "\n" << "������:" << c1.author << "\n" << "��������:" << c1.publishname << endl;
	out << "�۸�" << c1.price << endl;
	c1.d1.Output();
	out << "�������������" << c1.n << endl;
	return out;
}
istream& operator >>(istream& in, CBook& c1)
{
	cout << "���������룺���� ������ �������� �鱾�۸� �������� ͼ������" << endl;
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
	cout << "�������ڣ�" << year << "." << month << "." << day << endl;
}
Date::Date(const Date& d1)
{
	year = d1.year;
	month = d1.month;
	day = d1.day;
}
