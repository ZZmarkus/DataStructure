// ������ �ڵ带 ������� �Ͽ�, �׸����� �м�, �ϼ��Ͻÿ�.

#pragma warning(disable:4996) //scanf_s() �Ǵ� printf_s()�� ������� �ʾƼ� �߻��ϴ� ������ �����ϴ� �ڵ�

#include<stdio.h>
int seq_search(int* list, int n, int key);

int main()
{
	int array[10]={5,9,10,17,21,29,33,37,38,43};
	int num;
	int result;

	printf("Ž���� ���� �Է�: ");
	scanf("%d",&num);
	
	result = seq_search(array, 10, num);
	printf("�迭�� ��� %d ��°\n",result);

	return 0;
}

int seq_search(int* list, int n, int key)//����Ž���Լ�
{
	int i;
		
	for(i=0; i<n; i++)
	{
		if(list[i]==key)
			return i;
	}
	return -1;
}

