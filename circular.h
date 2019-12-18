#pragma once
#include <iostream>

using namespace std;
typedef char CLDataType;
typedef struct CircleLinkList{
	CLDataType data;
	struct CircleLinkList* _next;
} CircleLinkList;

//初始化
void initCircleLinkList(CircleLinkList* pHead)
{
	//初始化为一个空表，仅有一个头节点
	pHead->_next = pHead;
	cout << "初始化成功!" << endl;
}

//申请新的节点
CircleLinkList* buyNewNode()
{
	CircleLinkList* newNode = new CircleLinkList();
	return newNode;
}

//尾插新节点
void pushBackData(CircleLinkList* pHead,CLDataType data)
{
	//先申请新的节点
	CircleLinkList* newNode = buyNewNode();
	//若链表为空，则直接尾插
	if (pHead->_next == pHead)
	{
		newNode->data = data;
		newNode->_next = pHead;
		pHead->_next = newNode;
	}
	//若链表不为空，则需要遍历找到最后的节点
	if (pHead->_next != pHead)
	{
		CircleLinkList* pCur = pHead->_next;
		while (pCur->_next != pHead)
		{
			pCur = pCur->_next;
		}
		newNode->data = data;
		pCur->_next = newNode;
		newNode->_next = pHead;
	}
}

//头插新节点
void pushFrontData(CircleLinkList* pHead, CLDataType data)
{
	//先申请新的节点
	CircleLinkList* newNode = buyNewNode();
	//若链表为空，则直接尾插
	if (pHead->_next == pHead)
	{
		newNode->data = data;
		newNode->_next = pHead;
		pHead->_next = newNode;
	}
	//若链表还有其他元素
	if (pHead->_next != pHead)
	{
		newNode->data = data;
		newNode->_next = pHead->_next;
		pHead->_next = newNode;
	}
}

//尾删链表
void popBackData(CircleLinkList* pHead)
{
	//若链表本身就为空
	if (pHead->_next == nullptr)
	{
		cout << "链表为空，尾删失败!" << endl;
		return;
	}
	//若链表仅有一个有效元素
	if (pHead->_next->_next == pHead)
	{
		delete pHead->_next;
		pHead->_next = pHead;
		return;
	}
	//若链表有若干个有效元素
	CircleLinkList* pPrev = pHead;
	CircleLinkList* pCur = pHead->_next;

	while (pCur->_next != pHead)
	{
		pPrev = pCur;
		pCur = pCur->_next;
	}
	delete pCur;
	pCur = nullptr;
	pPrev->_next = pHead;
}

//头删链表
void popFrontData(CircleLinkList* pHead)
{
	//若链表本身就为空
	if (pHead->_next == nullptr)
	{
		cout << "链表为空，尾删失败!" << endl;
		return;
	}
	//若链表仅有一个有效元素
	if (pHead->_next->_next == pHead)
	{
		CircleLinkList* pFirst = pHead->_next;
		delete pFirst;
		pFirst = nullptr;
		pHead->_next = pHead;
		return;
	}

	//若链表有若干个有效元素
	CircleLinkList* pFirst = pHead->_next;
	pHead->_next = pFirst->_next;
	delete pFirst;
	pFirst = nullptr;
}
//销毁链表
void destroyCircleLinkList(CircleLinkList* pHead)
{
	//若链表为空（仅有一个头节点）
	if (pHead->_next == pHead)
	{
		cout << "链表没有元素，删除失败!" << endl;
		return;
	}
	//若链表只有一个有效元素
	if (pHead->_next->_next == pHead)
	{
		delete pHead->_next;
		pHead->_next = pHead;
		cout << "销毁成功!" << endl;
		return;
	}
	//若链表有若干个有效元素，则依次遍历链表，释放每一个元素
	CircleLinkList* pCur = pHead->_next;
	while (pCur != pHead)
	{
		CircleLinkList* pTmp = pCur;
		pCur = pTmp->_next;
		delete pTmp;
		pTmp = nullptr;
	}
	//最后再处理头节点
	pHead->_next = pHead;
	cout << "销毁成功!" << endl;
}

//获取元素个数（仅有头节点，个数记为0）
void getLen(CircleLinkList* pHead)
{
	if (pHead->_next == pHead)
	{
		cout << "有效个数：0" << endl;
		return;
	}
	int count = 0;
	CircleLinkList* pCur = pHead->_next;
	while (pCur != pHead)
	{
		++count;
		pCur = pCur->_next;
	}
	cout << "有效个数: " << count << endl;
}

//打印链表
void printCircleLinkList(CircleLinkList* pHead)
{
	//若链表只有一个头，没有其他元素
	if (pHead->_next == pHead)
	{
		cout << "NULL" << endl;
	}
	CircleLinkList* pCur = pHead->_next;
	while (pCur != pHead)
	{
		cout << pCur->data << "-->";
		pCur = pCur->_next;
	}
	cout << endl;
}