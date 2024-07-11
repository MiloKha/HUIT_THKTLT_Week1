#include<stdio.h>
#include<conio.h>


void main()
{
	int a = 0, b = 0;
	printf("Nhap a va b: ");
	scanf_s("%d%d", &a, &b);
	try
	{
		if (b == 0)
			throw "So chia khong duoc la 0";
		else {
			int t = a / b;
			printf("%d", t);
		}
	}
	catch (const char* st)
	{
		printf("Loi: %s", st);
	}
	
	_getch();
}