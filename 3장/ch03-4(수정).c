#include <stdio.h>
#include <time.h>

#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct {             // ����ü polynomial ����
	int degree;              // ���׽��� ������ ������ ����
	float coef[MAX_DEGREE];  // ���׽��� �� ���� ����� ������ 1���� �迭
} polynomial;

polynomial addPoly(polynomial, polynomial);  // �Լ��� �����1
void printPoly(polynomial); // �Լ��� �����2

void main() 
{
	FILE* fp; // ��������� ����
	clock_t start, finish;
	double duration;

	polynomial A = { 5,{ 6,7,3,1 } };    // ���׽� A�� �ʱ�ȭ
	polynomial B = { 4,{ 2,31,0,2,1 } };  // ���׽� B�� �ʱ�ȭ

	polynomial C;

	start = clock(); // �ð�����
	fp = fopen("report.txt", "at+");
	C = addPoly(A, B);   // ���׽� A, B�� ���� ������ �����ϱ� ���� addPoly �Լ� ȣ�� 

	printf("\n A(x) =");  printPoly(A);   // ���׽� A ���
	printf("\n B(x) =");  printPoly(B);   // ���׽� B ���
	printf("\n C(x) =");  printPoly(C);   // ���׽� C ���

	finish = clock(); // �ð����� �Ϸ�
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	fprintf(fp,"����ð�: %lf�� \n", duration);
	fprintf(stdout, "����ð�: %lf�� \n",duration);

	fclose(fp);
	system("notepad.exe report.txt");  // �ڵ����� �޸����� ����
	system("cmd");
	getchar();
}

polynomial addPoly(polynomial A, polynomial B) {
	polynomial C;   // ���׽� ������ ��� ���׽��� ������ polynomial ����ü ���� ����
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
	return C;    // ���׽� ������ ��� ���׽� C�� ��ȯ
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