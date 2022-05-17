#pragma once
#include<iostream>
#include<string>
using namespace std;
class Date
{
private:
	int year, month, day;
public:
	Date(int y = 2022, int m = 1, int d = 1) :year(y), month(m), day(d) {};
	Date(const Date& d1);
	~Date() {  };
	void setdate();
	void Output();
};
class CBook
{
private:
	string bookname;
	string author;
	string publishname;
	double price;
	Date d1;
	int n;
	static int number;
public:
	CBook(string bookname = "BookName", string author = "AuthorName", string publishname = "PressName",
		double price = 0.0, int n = 0) :bookname(bookname), author(author), publishname(publishname),
		price(price), d1(2015, 1, 1), n(n) {
		number++;
	};
	friend ostream& operator  <<(ostream& out, CBook& c1);
	friend istream& operator >>(istream& in, CBook& c1);
	static int booknumber();
	CBook& operator+(double i);

};