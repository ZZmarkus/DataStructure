// ���迹����, �ݺ��� 1������ �����Ű��, �����Ͽ� ����� ����ϴ� ���α׷� ����
#pragma warning(disable:4996) //scanf_s() �Ǵ� printf_s()�� ������� �ʾƼ� �߻��ϴ� ������ �����ϴ� �ڵ�

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
	
	//����ð� ���� �ڵ�
	clock_t start, finish;
	double  duration;
	int i, sum;

	start = clock(); // ���۽ð�

					 // ����ð��� �����ϰ� �ϴ� �ڵ�....
	for (i = 0, sum = 0; i < 100000000000; i++)
	{
		sum += i;  // sum = sum+i;
		printf("%d\n",sum);
	}

	finish = clock(); // ����ð�

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f ���Դϴ�.\n", duration);

}