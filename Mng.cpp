#include"Mng.h"
#include<assert.h>
#include<stddef.h>
struct ListNode
{
	CBook cb;
	ptrType next;
};

ptrType CBookMng::PtrTo(int Position)const
{
	if ((Position < 1) || (Position > Length()))
		return NULL;
	else
	{
		ptrType cur = Head;
		for (int i = 1; i < Position; i++)
		{
			cur = cur->next;
		}
		return cur;
	}
}
CBookMng::CBookMng(const CBookMng& L):Size(L.Size)
{
	if (L.Head == NULL)
		Head = NULL;
	else
	{
		Head = new ListNode;
		assert(Head != NULL);
		Head->cb = L.Head->cb;
		ptrType NewPtr = Head;
		for (ptrType OrigPtr = L.Head->next; OrigPtr != NULL; OrigPtr = OrigPtr->next)
		{
			NewPtr->next = new ListNode;
			assert(NewPtr->next != NULL);
			NewPtr = NewPtr->next;
			NewPtr->cb = OrigPtr->cb;
		}
		NewPtr->next = NULL;
	}
}
CBookMng::~CBookMng()
{
	bool Success;
	while (!IsEmpty())
		Delete(1, Success);
}
bool CBookMng::IsEmpty()const
{
	return bool(Size == 0);
}
int CBookMng::Length()const
{
	return Size;
}
void CBookMng::Insert(int NewPosition, CBook NewBook, bool& Success)
{
	int NewLength = Length() + 1;
	Success = bool((NewPosition >= 1 && NewPosition <= NewLength));
	if (Success)
	{
		ptrType NewPtr = new ListNode;
		if (NewPtr != NULL)
		{
			Size = NewLength;
			NewPtr->cb = NewBook;
			if (NewPosition == 1)
			{
				NewPtr->next = Head;
				Head = NewPtr;
			}
			else
			{
				ptrType Prev = PtrTo(NewPosition - 1);
				NewPtr->next = Prev->next;
				Prev->next = NewPtr;
			}
		}
	}
}
void CBookMng::Delete(int Position, bool& Success)
{
	ptrType cur;
	Success = bool((Position >= 1) && (Position <= Size));
	if (Success)
	{
		Size--;
		if (Position == 1)
		{
			cur = Head;
			Head = Head->next;
		}
		else
		{
			ptrType prev = PtrTo(Position - 1);
			cur = prev->next;
			prev = cur->next;
		}
		delete cur;
		cur = NULL;
	}
}
CBook& CBookMng::operator[](int Position)
{
	ptrType temp = PtrTo(Position);
	return temp->cb;
}
CBookMng& operator+(CBookMng& cb1, CBookMng& cb2)
{
	CBookMng temp;
	temp.Size = cb1.Size + cb2.Size;
	bool Success;
	for (int i = 1; i <= cb1.Length(); i++)
	{
		temp.Insert(1, cb1.Head->cb, Success);
		cb1.Head = cb1.Head->next;
	}
	for (int j = 1; j <= cb2.Length(); j++)
	{
		temp.Insert(1, cb2.Head->cb, Success);
		cb2.Head = cb2.Head->next;
	}
	return temp;
}
ostream& operator<<(ostream& out, CBookMng& cb)
{
	for (int i = 1; i <= cb.Size; i++)
	{
		out << cb.Head->cb << endl;
		cb.Head = cb.Head->next;
	}
	out << cb.Size << endl;
	return out;
}