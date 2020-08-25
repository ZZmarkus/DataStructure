#pragma warning (disable : 4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sqlite3.h"
#define CL_SIZE 26;

// ���� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	int id;
	char data[15];
	int searchNum = 0;
	struct ListNode* link;
} listNode;

struct ListNode* p[1000];
int structCnt = 0;

// ����Ʈ�� ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
} linkedList_h;


// ���� ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h* CL;
	CL = (linkedList_h*)malloc(sizeof(linkedList_h));	// ��� ��� �Ҵ�
	CL->head = NULL;										// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return CL;
}

// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h* CL) {
	listNode* p;
	printf(" CL = (");
	p = CL->head;
	do {
		printf("%s", p->data);
		p = p->link;
		if (p != CL->head) printf(", ");
	} while (p != CL->head);
	printf(") \n");
}

// ù ��° ��� ���� ����
void insertFirstNode(linkedList_h *CL, char* x) {
	listNode* newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));	// ������ �� ��� �Ҵ�
	strcpy(newNode->data, x);
	if (CL->head == NULL) {		// ���� ���� ����Ʈ�� ������ ���	
		CL->head = newNode;		// �� ��带 ����Ʈ�� ���� ���� ����
		newNode->link = newNode;
	}
	else {						// ���� ���� ����Ʈ�� ������ �ƴ� ��� 	
		temp = CL->head;
		while (temp->link != CL->head)
			temp = temp->link;
		newNode->link = temp->link;
		temp->link = newNode;	// ������ ��带 ù ��° ����� new�� ���� ���� 
		CL->head = newNode;
	}
}

// pre �ڿ� ��带 �����ϴ� ����
void insertMiddleNode(linkedList_h* CL, listNode *pre, char* x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->data, x);
	if (CL == NULL) {
		CL->head = newNode;
		newNode->link = newNode;
	}
	else if (pre == NULL)		//Ž���� ���� ������ �� pre�� NULL�� ��쵵 �߰��Ͽ���
	{
		return;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

// ���� ���� ����Ʈ�� pre �ڿ� �ִ� ��� old�� �����ϴ� ����
void deleteNode(linkedList_h* CL, listNode* old) {
	listNode* pre;					// ������ ����� ������ ��带 ��Ÿ���� ������	
	if (CL->head == NULL) return;	// ���� ����Ʈ�� ���, ���� ���� �ߴ�	
	if (CL->head->link == NULL) {	// ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(CL->head);				// ù ��° ����� �޸𸮸� �����ϰ�
		CL->head = NULL;				// ����Ʈ ���� �����͸� NULL�� ����
		return;
	}
	else if (old == NULL) return;   // ������ ��尡 ���� ���, ���� ���� �ߴ�	
	else {
		pre = CL->head;				// ������ pre�� ����Ʈ�� ���� ��忡 ����		
		while (pre->link != old) {
			pre = pre->link;			// ������ ��带 ������ pre�� �̿��� ã��
		}
		pre->link = old->link;
		if (old == CL->head)
			CL->head = old->link;
		free(old);					// ���� ����� �޸𸮸� ����	 		
	}
}

// ���� ���� ����Ʈ���� x ��带 Ž���ϴ� ����
listNode* searchNode(linkedList_h* CL, char* x) {
	listNode *temp;
	temp = CL->head;

	if (strcmp(temp->data, x) == 0) //ó���� temp!=NULL�̾��µ� ���� ã�� ��尡 ���ٸ� ���ѹݺ��� �Ǳ⶧���� �ڵ带 ������
		return temp;
	else temp = temp->link;

	while (temp != CL->head) {
		if (strcmp(temp->data, x) == 0) return temp;
		else temp = temp->link;
	}
	temp = NULL;
	return temp;	//ã�°��� ������� NULL��ȯ
}

void Input(FILE* fp1);
void Input2(FILE* fp1);

int main()
{
	FILE* fp;
	linkedList_h* CL;
	CL = createLinkedList_h();
	ListNode* ptr;
	char alpha[10] = "a";
	insertFirstNode(CL, alpha);
	for (int i = 1; i < CL_SIZE i++)
	{
		ptr = searchNode(CL, alpha);
		alpha[0] = alpha[0] + 1;
		insertMiddleNode(CL, ptr, alpha);
	}
	int chose;
	printf("(����)1���� ���� �� ���� �޸����� ���ĺ��� �˻� �� �ּ���\n");
	while (true)
	{
		printf("1. �������� �ܾ��� ���� 2. �ܾ� �˻��ϱ�\n");
		scanf("%d", &chose);
		if (chose == 1)
		{
			srand((unsigned)time(NULL));
			int y;
			y = rand();
			y = rand() % CL_SIZE;
			char note[20] = "notepad.exe ";
			char txt[10] = ".txt";
			char alp1[2] = "a";
			char alp2[2] = "a";
			alp1[0] = alp1[0] + y;
			alp2[0] = alp2[0] + y;
			strcat(note, alp1);
			strcat(note, txt);
			system(note);

			strcat(alp2, ".txt");
			fp = fopen(alp2, "at+");
			Input(fp);
			fclose(fp);
		}
		else if (chose == 2)
		{
			int searchNum = 0;
			int id;
			int num;
			char tmp[15];
			char search[15];
			printf("�˻��� �ܾ �Է��� �ּ��� :");
			scanf("%s", search);
			char a[10];
			a[0] = search[0];
			a[1] = '\0';
			strcat(a, ".txt");
			fp = fopen(a, "at+");
			Input2(fp);
			for (int i = 0; i <=structCnt; i++)
			{
				fscanf(fp, "%d %s", &id, tmp);
				if (i == structCnt)
				{
					fprintf(fp, "\n%02d %s", structCnt+1, search);
				}
				else if (strcmp(tmp, search) == 0)
				{
					p[i]->searchNum += 1;
					printf("\n %s�� �ܾ �˻��� Ƚ�� : %d \n", search, p[i]->searchNum);
				}
			}
			
			fclose(fp);
		}
	}
	system("pause");
}

void Input(FILE* fp1)
{
	FILE* fp2;
	fp2 = fopen("allAlpha.txt", "at+");
	int id;
	char alphabet[15];
	structCnt = 0;

	while (!feof(fp1))
	{
		p[structCnt] = (ListNode*)malloc(sizeof(ListNode));
		fscanf(fp1, "%d %s", &id, alphabet);
		p[structCnt]->id = id;
		strcpy(p[structCnt]->data, alphabet);
		p[structCnt]->searchNum = 0;
		fprintf(fp2, "%d %s\n", p[structCnt]->id, p[structCnt]->data);
		fprintf(stdout, "%02d %s\n", p[structCnt]->id, p[structCnt]->data);
		structCnt++;
	}
	fprintf(fp2, "�ܾ��� ���� : %d\n", structCnt);
	fprintf(stdout, "�ܾ��� ���� : %d\n", structCnt);
	fprintf(fp2, "-----------------------\n");
	fclose(fp2);
	printf("---------------------------\n");
}

void Input2(FILE* fp1)
{
	int id;
	char alphabet[15];
	structCnt = 0;

	while (!feof(fp1))
	{
		p[structCnt] = (ListNode*)malloc(sizeof(ListNode));
		fscanf(fp1, "%d %s", &id, alphabet);
		p[structCnt]->id = id;
		strcpy(p[structCnt]->data, alphabet);
		p[structCnt]->searchNum = 0;
		structCnt++;
	}
}