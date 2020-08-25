
#pragma warning(disable:4996) //scanf_s() 또는 printf_s()를 사용하지 않아서 발생하는 오류를 무시하는 코드

#include <stdio.h>
#include <time.h>

int Factorial(int n);
int i=0;             // 전역변수 i가 무엇을 의미할까? 생각해보기... 

int main(void)
{
	clock_t start, finish;
	double duration;
	int num, result;
	
	FILE* fp; // 4바이트 파일포인터 선언...4바이트로 파일의 내용을 참조하는 변수...파일입출력 공부할 것


	while (1)
	{
		i++;
		fprintf(stdout, "팩토리얼 입력: ");  // (stdout의 의미: '모니터에 출력하라'는 뜻), 같은의미 코드: printf("팩토리얼 입력: ");
		fscanf(stdin,"%d",&num);             // (stdin의 의미: '키보드'로 입력받자'는 뜻), 같은의미 코드: scanf("%d",&num);
		start = clock();                    // 시간측정 시작

		if (num < 0)
			break;

		///////////////////////////////////////////////////////////////////////////////////////////////////////
		fp = fopen("report.txt", "at+");  // 파일을 만들어 오픈, 현재 프로젝트 폴더에 생성...
		result = Factorial(num);          // 팩토리얼 수행시간
		finish = clock();                 // 시간측정 완료
		
		duration = (double)(finish - start) / CLOCKS_PER_SEC; 
		
		fprintf(fp,"%03d--%d!=%d --> 수행시간 %lf초 \n", i, num, result, duration);    // 파일(fp)에 데이터를 출력
		fprintf(stdout,"%03d--%d!=%d --> 수행시간 %lf초 \n", num, result, duration);  // 모니터(stdout)에 데이터를 출력
		fclose(fp);                      // 파일 닫음
		///////////////////////////////////////////////////////////////////////////////////////////////////////
	 }
	    system("notepad.exe report.txt");  // 자동으로 메모장을 오픈
		system("cmd");                     // 메모장이 저장된 경로
	
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* 팩토리얼 함수
  1. 입          력: int n 
  2. 처리(알고리즘): 입력이 0이면 1을, 입력이 0이 아니면 재귀함수 호출
  3. 출          력: int 값 반환
*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
int Factorial(int n)  
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}