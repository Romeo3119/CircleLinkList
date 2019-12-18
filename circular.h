#pragma once
#include <iostream>

using namespace std;
typedef char CLDataType;
typedef struct CircleLinkList{
	CLDataType data;
	struct CircleLinkList* _next;
} CircleLinkList;

//��ʼ��
void initCircleLinkList(CircleLinkList* pHead)
{
	//��ʼ��Ϊһ���ձ�����һ��ͷ�ڵ�
	pHead->_next = pHead;
	cout << "��ʼ���ɹ�!" << endl;
}

//�����µĽڵ�
CircleLinkList* buyNewNode()
{
	CircleLinkList* newNode = new CircleLinkList();
	return newNode;
}

//β���½ڵ�
void pushBackData(CircleLinkList* pHead,CLDataType data)
{
	//�������µĽڵ�
	CircleLinkList* newNode = buyNewNode();
	//������Ϊ�գ���ֱ��β��
	if (pHead->_next == pHead)
	{
		newNode->data = data;
		newNode->_next = pHead;
		pHead->_next = newNode;
	}
	//������Ϊ�գ�����Ҫ�����ҵ����Ľڵ�
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

//ͷ���½ڵ�
void pushFrontData(CircleLinkList* pHead, CLDataType data)
{
	//�������µĽڵ�
	CircleLinkList* newNode = buyNewNode();
	//������Ϊ�գ���ֱ��β��
	if (pHead->_next == pHead)
	{
		newNode->data = data;
		newNode->_next = pHead;
		pHead->_next = newNode;
	}
	//������������Ԫ��
	if (pHead->_next != pHead)
	{
		newNode->data = data;
		newNode->_next = pHead->_next;
		pHead->_next = newNode;
	}
}

//βɾ����
void popBackData(CircleLinkList* pHead)
{
	//���������Ϊ��
	if (pHead->_next == nullptr)
	{
		cout << "����Ϊ�գ�βɾʧ��!" << endl;
		return;
	}
	//���������һ����ЧԪ��
	if (pHead->_next->_next == pHead)
	{
		delete pHead->_next;
		pHead->_next = pHead;
		return;
	}
	//�����������ɸ���ЧԪ��
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

//ͷɾ����
void popFrontData(CircleLinkList* pHead)
{
	//���������Ϊ��
	if (pHead->_next == nullptr)
	{
		cout << "����Ϊ�գ�βɾʧ��!" << endl;
		return;
	}
	//���������һ����ЧԪ��
	if (pHead->_next->_next == pHead)
	{
		CircleLinkList* pFirst = pHead->_next;
		delete pFirst;
		pFirst = nullptr;
		pHead->_next = pHead;
		return;
	}

	//�����������ɸ���ЧԪ��
	CircleLinkList* pFirst = pHead->_next;
	pHead->_next = pFirst->_next;
	delete pFirst;
	pFirst = nullptr;
}
//��������
void destroyCircleLinkList(CircleLinkList* pHead)
{
	//������Ϊ�գ�����һ��ͷ�ڵ㣩
	if (pHead->_next == pHead)
	{
		cout << "����û��Ԫ�أ�ɾ��ʧ��!" << endl;
		return;
	}
	//������ֻ��һ����ЧԪ��
	if (pHead->_next->_next == pHead)
	{
		delete pHead->_next;
		pHead->_next = pHead;
		cout << "���ٳɹ�!" << endl;
		return;
	}
	//�����������ɸ���ЧԪ�أ������α��������ͷ�ÿһ��Ԫ��
	CircleLinkList* pCur = pHead->_next;
	while (pCur != pHead)
	{
		CircleLinkList* pTmp = pCur;
		pCur = pTmp->_next;
		delete pTmp;
		pTmp = nullptr;
	}
	//����ٴ���ͷ�ڵ�
	pHead->_next = pHead;
	cout << "���ٳɹ�!" << endl;
}

//��ȡԪ�ظ���������ͷ�ڵ㣬������Ϊ0��
void getLen(CircleLinkList* pHead)
{
	if (pHead->_next == pHead)
	{
		cout << "��Ч������0" << endl;
		return;
	}
	int count = 0;
	CircleLinkList* pCur = pHead->_next;
	while (pCur != pHead)
	{
		++count;
		pCur = pCur->_next;
	}
	cout << "��Ч����: " << count << endl;
}

//��ӡ����
void printCircleLinkList(CircleLinkList* pHead)
{
	//������ֻ��һ��ͷ��û������Ԫ��
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