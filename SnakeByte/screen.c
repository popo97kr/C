#include"screen.h"

static int sIdx;
static HANDLE screen[2];

void sInit() {
	CONSOLE_CURSOR_INFO cci;
	screen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	screen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(screen[0], &cci);
	SetConsoleCursorInfo(screen[1], &cci);
}
void sFlipping() {
	SetConsoleActiveScreenBuffer(screen[sIdx]);
	sIdx = !sIdx;
}
void sClear() {
	COORD coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(screen[sIdx], ' ', 80 * 28, coor, &dw);
}
void sRelease() {
	CloseHandle(screen[0]);
	CloseHandle(screen[1]);
}
void sPrint(int x, int y, char* str) {
	DWORD dw;
	COORD cpos = { x, y };
	SetConsoleCursorPosition(screen[sIdx], cpos);
	WriteFile(screen[sIdx], str, strlen(str), &dw, NULL);
}