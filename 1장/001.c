
#pragma warning(disable:4996) //scanf_s() 또는 printf_s()를 사용하지 않아서 발생하는 오류를 무시하는 코드
#include<stdio.h>
int find_max_score(int n); // 함수의 선언1, 최고점을 찾는다.

#define MAX_ELEMENTS 5  // 5를 상수화(기호)
int score[MAX_ELEMENTS];  // 단순 자료구조, 전역배열

int main()  //테스트
{
	int k;
	int result;

	for(k=0; k<MAX_ELEMENTS; k++)
	{
		score[k]=k;
	}
	
	result = find_max_score(MAX_ELEMENTS);
	printf("최고점수: %d\n", result);

	return 0;

}

int find_max_score(int n) // 학생의 숫자는 n, 함수 정의부분
{  
	int i, tmp;
	tmp=score[0];

	for(i=1;i<n;i++)
	{ 
		// 알고리즘
		if( score[i] > tmp )
		{
			tmp = score[i];
		}
	}
	return tmp;
}
