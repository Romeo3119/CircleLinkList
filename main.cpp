#include "circular.h"

int main()
{
	CircleLinkList circlelinklist;
	initCircleLinkList(&circlelinklist);

	cout << "β��" << endl;
	//pushBackData(&circlelinklist, 'A');
	pushBackData(&circlelinklist, 'B');
	pushBackData(&circlelinklist, 'C');
	pushBackData(&circlelinklist, 'D');
	pushBackData(&circlelinklist, 'E');
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "ͷ��" << endl;
	pushFrontData(&circlelinklist, 'A');
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "βɾ" << endl;
	popBackData(&circlelinklist);
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "ͷɾ" << endl;
	popFrontData(&circlelinklist);
	popFrontData(&circlelinklist);
	popFrontData(&circlelinklist);
	popFrontData(&circlelinklist);
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "����" << endl;
	destroyCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);
	system("pause");
	return 0;
}