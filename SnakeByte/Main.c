#include<stdio.h>
#include"snake.h"

int main() {
	int ekey = 0;

	init();						// ������ �ʱ�ȭ �Լ�

	while (1) {

		if (_kbhit()) {			// Ű���� �Է��� ������ 1, ������ 0�� ����
			ekey = _getch();	// �Է¹��� Ű ���� ����
			_flushall();

			switch (ekey) {
			case L:	if (sn.dir.x == 1)
				winner = -1;
				sn.dir.x = -1;
				sn.dir.y = 0;
				break;
			case R:	if (sn.dir.x == -1)
				winner = -1;
				sn.dir.x = 1;
				sn.dir.y = 0;
				break;
			case U: if (sn.dir.y == 1)
				winner = -1;
				sn.dir.x = 0;
				sn.dir.y = -1;
				break;
			case D:	if (sn.dir.y == -1)
				winner = -1;
				sn.dir.x = 0;
				sn.dir.y = 1;
				break;

			}

		}

		for (int i = 0; i < numb; i++)
		{
			if (sn.head.x == sn.tail[i].x && sn.head.y == sn.tail[i].y)
				winner = -1;
		}

		if (winner == item)
		{
			printf("you win\n");
			break;
		}
		else if (winner == -1)
		{
			printf("you lose\n");
			break;
		}
		update();				// ���� ������Ʈ
		draw();					// ȭ�鿡 ���

		Sleep(50);
	}
	release();
	return 0;
}
