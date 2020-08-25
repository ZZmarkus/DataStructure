#include <stdio.h>
#include <time.h>

#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {             // 구조체 polynomial 정의
	int degree;              // 다항식의 차수를 저장할 변수
	float coef[MAX_DEGREE];  // 다항식의 각 항의 계수를 저장할 1차원 배열
} polynomial;

polynomial addPoly(polynomial, polynomial);  // 함수의 선언부1
void printPoly(polynomial); // 함수의 선언부2

void main() 
{
	FILE* fp; // 파일입출력 공부
	clock_t start, finish;
	double duration;

	polynomial A = { 5,{ 6,7,3,1 } };    // 다항식 A의 초기화
	polynomial B = { 4,{ 2,31,0,2,1 } };  // 다항식 B의 초기화

	polynomial C;

	start = clock(); // 시간측정
	fp = fopen("report.txt", "at+");
	C = addPoly(A, B);   // 다항식 A, B에 대한 덧셈을 수행하기 위해 addPoly 함수 호출 

	printf("\n A(x) =");  printPoly(A);   // 다항식 A 출력
	printf("\n B(x) =");  printPoly(B);   // 다항식 B 출력
	printf("\n C(x) =");  printPoly(C);   // 다항식 C 출력

	finish = clock(); // 시간측정 완료
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	fprintf(fp,"수행시간: %lf초 \n", duration);
	fprintf(stdout, "수행시간: %lf초 \n",duration);

	fclose(fp);
	system("notepad.exe report.txt");  // 자동으로 메모장을 오픈
	system("cmd");
	getchar();
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;   // 다항식 덧셈의 결과 다항식을 저장할 polynomial 구조체 변수 선언
	int A_index = 0, B_index = 0, C_index = 0;
	int A_degree = A.degree, B_degree = B.degree;
	C.degree = MAX(A.degree, B.degree);

	while (A_index <= A.degree && B_index <= B.degree) {
		if (A_degree > B_degree) {
			C.coef[C_index++] = A.coef[A_index++];
			A_degree--;
		}
		else if (A_degree == B_degree) {
			C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
			A_degree--;
			B_degree--;
		}
		else {
			C.coef[C_index++] = B.coef[B_index++];
			B_degree--;
		}
	}
	return C;    // 다항식 덧셈의 결과 다항식 C를 반환
}

void printPoly(polynomial P) {
	int i, degree;
	degree = P.degree;

	for (i = 0; i <= P.degree; i++) {
		printf("%3.0fx^%d", P.coef[i], degree--);
		if (i < P.degree) printf(" +");
	}
	printf("\n");
}