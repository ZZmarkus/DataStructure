
#pragma warning(disable:4996) //scanf_s() �Ǵ� printf_s()�� ������� �ʾƼ� �߻��ϴ� ������ �����ϴ� �ڵ�
#include<stdio.h>
int find_max_score(int n); // �Լ��� ����1, �ְ����� ã�´�.

#define MAX_ELEMENTS 5  // 100�� ���ȭ(��ȣ)
int score[MAX_ELEMENTS];  // �ܼ� �ڷᱸ��, �����迭

int main()  // �׽�Ʈ
{
	int k;
	int result;

	for(k=0; k<MAX_ELEMENTS; k++)
	{
		score[k]=k;
	}
	
	result = find_max_score(MAX_ELEMENTS);
	printf("�ְ�����: %d\n", result);

	return 0;

}

int find_max_score(int n) // �л��� ���ڴ� n, �Լ� ���Ǻκ�
{  
	int i, tmp;
	tmp=score[0];

	for(i=1;i<n;i++)
	{ 
		// �˰���
		if( score[i] > tmp )
		{
			tmp = score[i];
		}
	}
	return tmp;
}