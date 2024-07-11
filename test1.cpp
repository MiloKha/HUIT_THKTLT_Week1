#include<stdio.h>

void main()
{
	int a[10], n = 5, * pa;
	pa = a; // hoa c pa = &a[0];
	for (int i = 0; i < n; i++)
	{
		printf("% d" , a[i]); // printf(“%d”, pa[i]);
		printf("% d", *(a + i)); // printf(“%d”, *(pa + i));
	}
}
