#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

#define MAX_DEGREE 10

typedef struct {
	float coef[MAX_DEGREE];
	int expon;
}polynomial;
polynomial poly1, poly2;

polynomial Zero()
{
	polynomial b;
	b.coef[0] = 0;
	b.expon = 0;
	return b;
}

bool IsZero(polynomial x)
{
	return (x.coef[0] == 0 && x.expon == 0);
}

float Coef(polynomial x, int exp)
{
	return (x.coef[exp] != 0 ? x.coef[exp] : 0);
}

int Leadexp(polynomial x)
{
	return x.expon;
}

polynomial Attach(polynomial x, float coef, int exp)
{
	if (exp > x.expon)
	{
		x.expon = exp;
		for (int i = exp; i > 0; i--)
		{
			x.coef[i] = x.coef[i - (exp - x.expon)];
		}
		x.coef[0] = coef;
	}
	else if (x.coef[x.expon - exp] == 0)
		x.coef[x.expon - exp] = coef;
	else
		exit(0);

	return x;
}

polynomial Remove(polynomial x, int exp)
{
	x.coef[x.expon - exp] = 0;
	return x;
}

polynomial SingleMut(polynomial x, float coef, int exp)
{
	polynomial y;
	for (int i = 0; i <= x.expon; i++)
	{
		y.coef[i]= x.coef[i] * coef;
	}
	y.expon =x.expon+ exp;
	return y;
}

polynomial Add(polynomial x, polynomial y)
{
	polynomial z;
	int availx = 0, availy = 0, availz = 0;
	int xexp = x.expon, yexp = y.expon;
	z.expon = max(x.expon, y.expon);

	while (availx <= x.expon && availy <= y.expon)
	{
		if (xexp > yexp)
		{
			z.coef[availz++] = x.coef[availx++];
			xexp--;
		}
		else if (xexp == yexp)
		{
			z.coef[availz++] = x.coef[availx++] + y.coef[availy++];
			xexp--;
			yexp--;
		}
		else
		{
			z.coef[availz++] = y.coef[availy++];
			yexp--;
		}
	}
	return z; 
}


polynomial Mult(polynomial x, polynomial y)
{
	polynomial z;
	z.expon = x.expon+y.expon;
	for (int i = 0; i < 10;i++)
		z.coef[i]=0;
	for (int i = 0; i <= x.expon; i++)
	{
		for (int j = 0; j <= y.expon; j++)
		{
			z.coef[z.expon - ((x.expon - i)+(y.expon - j))] += (x.coef[i] * y.coef[j]);
		}
	}
	return z;
}

void printpoly(polynomial x)
{
	int exp = x.expon;

	for (int i = 0; i <= x.expon; i++)
	{
		if (x.coef[i] == 0)
		{
			exp--;
			continue;
		}
		else
			printf("%3.fx^%d", x.coef[i], exp--);
	}
	printf("\n");

}
void main()
{
	polynomial poly1 = { { 1,4,0,0,1 },4 };
	polynomial poly2 = { { 1,0,1 },2 };

	printf("poly1: ");
	printpoly(poly1);
	printf("poly2: ");
	printpoly(poly2);
	printf("%.3fx^%d\n", Zero().coef[0], Zero().expon);
	printf("poly2가 zero항인가? : ");
	printf(IsZero(poly1) ? "TRUE\n" : "FALSE\n");
	printf("%.3f \n", Coef(poly1, 4));
	printf("%d \n", Leadexp(poly1));
	printf("2x^2를 붙였다:\n");
	printpoly(Attach(poly1, 2, 2));
	printf("지수가2인항을 지웠다:\n");
	printpoly(Remove(poly1, 2));
	printf("SingleMut(poly1에 3x^0를 곱함):\n");
	printpoly(SingleMut(poly1, 3, 0));
	printf("Addition:\n");
	printpoly(Add(poly1, poly2));
	printf("Multipication:\n");
	printpoly(Mult(poly1, poly2));

	return 0;
}