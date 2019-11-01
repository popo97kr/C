#include"snake.h"
numb = 5;

int outlier()
{
	for (int i = 0; i < numb; i++)
	{
		if (sn.tail[i].x > 78 || sn.tail[i].x < 2 || sn.tail[i].y > 18 || sn.tail[i].y < 1)
			return 1;

	}
}

int same(int a)
{
	for (int i = 0; i < a; i++)
	{
		if (obj[a].heart.x == obj[i].heart.x && obj[a].heart.y == obj[i].heart.y)
			return 1;
	}
	return 0;
}


void init() {

	printf("Enter the number of items: ");
	scanf_s("%d", &item);
	system("cls");
	obj = (object*)malloc(sizeof(object) * item);

	for (int i = 0; i < item; i++)
	{
		obj[i].heart.x = (rand() % 38 + 1) * 2;
		obj[i].heart.y = (rand() % 18 + 1);
		if (same(i) == 1)
		{
			i--;
			continue;
		}
	}

	do
	{
		sn.head.x = (rand() % 38 + 1) * 2;
		sn.head.y = (rand() % 18 + 1);

		switch (rand() % 4)
		{
		case LEFT: sn.dir.x = -1;
			sn.dir.y = 0;
			break;
		case RIGHT: sn.dir.x = 1;
			sn.dir.y = 0;
			break;
		case UP: sn.dir.x = 0;
			sn.dir.y = 1;
			break;
		case DOWN: sn.dir.x = 0;
			sn.dir.y = -1;
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			sn.tail[i].x = sn.head.x - (sn.dir.x * (i + 1) * 2);
			sn.tail[i].y = sn.head.y - (sn.dir.y * (i + 1));
		}
	} while (outlier() == 1);

	for (int i = 0; i < item; i++)
	{
		obj[i].yum = 0;
	}
	sInit();
}

void update() {
	//move
	if (!((sn.head.x + sn.dir.x * 2 == 78) || (sn.head.y + sn.dir.y == 19) || (sn.head.x + sn.dir.x * 2 == 0) || (sn.head.y + sn.dir.y == 0)))
	{
		sn.temp[0].x = sn.head.x;
		sn.temp[0].y = sn.head.y;

		sn.head.x = sn.head.x + sn.dir.x * 2;
		sn.head.y = sn.head.y + sn.dir.y;

		sn.temp[1].x = sn.tail[0].x;
		sn.temp[1].y = sn.tail[0].y;


		for (int i = 0; i < numb; i++)
		{
			if (i < numb)
			{
				sn.temp[i + 1].x = sn.tail[i].x;
				sn.temp[i + 1].y = sn.tail[i].y;
			}

			sn.tail[i].x = sn.temp[i].x;
			sn.tail[i].y = sn.temp[i].y;

		}
	}

	for (int i = 0; i < item; i++)
	{
		if (sn.head.x == obj[i].heart.x && sn.head.y == obj[i].heart.y && obj[i].yum == 0)
		{
			obj[i].yum = 1;
			numb++;
			winner++;
		}

	}

	for (int i = 0; i < numb; i++)
	{
		if (sn.head.x == sn.tail[i].x && sn.head.y == sn.tail[i].y)
			winner = -1;
	}

	//collision

}


void draw() {
	int i;

	sClear();

	for (i = 0; i < ROW; i++)
	{
		sPrint(i * 2, 0, "¡á");
		sPrint(i * 2, 19, "¡á");
	}
	for (i = 0; i < COL; i++)
	{
		sPrint(0, i, "¡á");
		sPrint(78, i, "¡á");
	}

	for (i = 0; i < item; i++)
	{
		if (obj[i].yum == 0)
			sPrint(obj[i].heart.x, obj[i].heart.y, "¢¾");
	}

	sPrint(sn.head.x, sn.head.y, "¡İ");
	for (i = 0; i < numb; i++)
	{
		sPrint(sn.tail[i].x, sn.tail[i].y, "¢Â");
	}

	sFlipping();

}

void release() {
	sRelease();
}
