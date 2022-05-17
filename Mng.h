#pragma once
#include"Date_CBook.h"
using namespace std;

struct ListNode;
typedef ListNode* ptrType;

class CBookMng
{
private:
	int Size;//链表节点数
	ptrType Head;//头节点
	ptrType PtrTo(int Position)const;//遍历函数
public:
	CBookMng(int size=0,ptrType head=NULL):Size(size),Head(head){}
	CBookMng(const CBookMng& CB);//复制构造函数
	~CBookMng();
	bool IsEmpty()const;
	int Length()const;
	void Insert(int Newposition, CBook NewBook, bool& success);
	void Delete(int Position, bool& success);
	CBook& operator[](int Position);
	friend CBookMng& operator+(CBookMng& cb1, CBookMng& cb2);
	friend ostream& operator<<(ostream& out,  CBookMng& cb);
};
