#include<stdio.h>
#include"snake.h"

int main() {
	int ekey = 0;

	init();						// 변수값 초기화 함수

	while (1) {

		if (_kbhit()) {			// 키보드 입력이 있으면 1, 없으면 0을 리턴
			ekey = _getch();	// 입력받은 키 값을 받음
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
		update();				// 변수 업데이트
		draw();					// 화면에 출력

		Sleep(50);
	}
	release();
	return 0;
}
