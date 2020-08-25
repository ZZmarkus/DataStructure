// 시험예상문제, 반복문 1조번을 실행시키고, 누적하여 결과를 출력하는 프로그램 개선
#pragma warning(disable:4996) //scanf_s() 또는 printf_s()를 사용하지 않아서 발생하는 오류를 무시하는 코드

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main(void)
{
	
	//수행시간 측정 코드
	clock_t start, finish;
	double  duration;
	int i, sum;

	start = clock(); // 시작시간

					 // 수행시간을 측정하고 하는 코드....
	for (i = 0, sum = 0; i < 100000000000; i++)
	{
		sum += i;  // sum = sum+i;
		printf("%d\n",sum);
	}

	finish = clock(); // 종료시간

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f 초입니다.\n", duration);

}