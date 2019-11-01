#pragma once
#pragma once
#ifndef _SNAKE_H
#define _SNAKE_H

#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

#include"screen.h"

#define ROW 40
#define COL 20

#define L 75
#define R 77
#define U 72
#define D 80

typedef enum _dir { LEFT, RIGHT, UP, DOWN } direction;

typedef struct _pos {
	int x;
	int y;
}pos;

typedef struct _object {
	pos heart;
	int yum;
}object;

typedef struct _snake {
	pos head;
	pos tail[1000];
	pos dir;
	pos temp[1000];
}snake;


snake sn;
object* obj;
int item;
int winner;
int numb;

void init();
void update();
void draw();
void release();


#endif