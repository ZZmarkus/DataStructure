// 현재의 코드를 디버깅을 하여, 그림으로 분석, 완성하시오.

#pragma warning(disable:4996) //scanf_s() 또는 printf_s()를 사용하지 않아서 발생하는 오류를 무시하는 코드

#include<stdio.h>
int seq_search(int* list, int n, int key);

int main()
{
	int array[10]={5,9,10,17,21,29,33,37,38,43};
	int num;
	int result;

	printf("탐색할 숫자 입력: ");
	scanf("%d",&num);
	
	result = seq_search(array, 10, num);
	printf("배열의 요소 %d 번째\n",result);

	return 0;
}

int seq_search(int* list, int n, int key)//순차탐색함수
{
	int i;
		
	for(i=0; i<n; i++)
	{
		if(list[i]==key)
			return i;
	}
	return -1;
}

