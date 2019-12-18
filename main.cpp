#include "circular.h"

int main()
{
	CircleLinkList circlelinklist;
	initCircleLinkList(&circlelinklist);

	cout << "Î²²å" << endl;
	//pushBackData(&circlelinklist, 'A');
	pushBackData(&circlelinklist, 'B');
	pushBackData(&circlelinklist, 'C');
	pushBackData(&circlelinklist, 'D');
	pushBackData(&circlelinklist, 'E');
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "Í·²å" << endl;
	pushFrontData(&circlelinklist, 'A');
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "Î²É¾" << endl;
	popBackData(&circlelinklist);
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "Í·É¾" << endl;
	popFrontData(&circlelinklist);
	popFrontData(&circlelinklist);
	popFrontData(&circlelinklist);
	popFrontData(&circlelinklist);
	printCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);

	cout << "Ïú»Ù" << endl;
	destroyCircleLinkList(&circlelinklist);
	getLen(&circlelinklist);
	system("pause");
	return 0;
}