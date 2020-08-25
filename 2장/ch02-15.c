#include<stdio.h>
 void hanoi(int n, int start, int work, int target);

 int main()
 {
	int num;
	scanf("%d",&num);

	hanoi(num,'A','B','C');
	getchar();
	return 0;
 }

void hanoi(int n, int start, int work, int target)
{
	if (n==1)
		printf("%c���� ����%d�� %c�� �̵�\n",start,n,target);

	else
	{
		hanoi(n-1,start, target, work);
		printf("%c���� ����%d�� %c�� �̵�\n",start,n,target);
		hanoi(n-1,work, start, target);
	}
}