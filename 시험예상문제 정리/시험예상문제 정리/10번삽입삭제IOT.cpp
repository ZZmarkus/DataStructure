#pragma warning(disable :4996)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct ListNode
{
	char name[10];
	char num[10];
	struct ListNode* link;
}listNode;

typedef struct
{
	ListNode* head;
}LinkedList_h;

LinkedList_h* createLinkedList_h()
{
	LinkedList_h* L;
	L = (LinkedList_h*)malloc(sizeof(LinkedList_h));
	L->head = NULL;
	return L;
}

void insertFirstListNode(LinkedList_h* L, const char* x, const char* y)
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->name, x);
	strcpy(newNode->num, y);
	newNode->link = L->head;
	L->head = newNode;
}
void insertMiddleListNode(LinkedList_h* L, listNode* pre, const char* x, const char* y)
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->name, x);
	strcpy(newNode->num, y);
	if (L == NULL)
	{
		newNode->link = NULL;
		L->head = newNode;
	}
	else if (pre == NULL)
	{
		newNode->link = L->head;
		L->head = newNode;
	}
	else
	{
		newNode->link = pre->link;
		pre->link = newNode;
	}
}
void insertLastListNode(LinkedList_h* L, const char* x, const char* y)
{
	listNode* temp;
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->name, x);
	strcpy(newNode->num, y);
	newNode->link = NULL;
	if (L->head == NULL)
	{
		L->head = newNode;
		return;
	}
	temp = L->head;
	while (temp->link != NULL)
		temp = temp->link;
	temp->link = newNode;
}

void deleteNode(LinkedList_h* L, listNode* p)
{
	listNode* pre;
	if (L->head == NULL) return;
	if (L->head == p)
	{
		L->head = p->link;
		free(p);
	}
	else if (p == NULL) return;
	else
	{
		pre = L->head;
		while (pre->link != p)
			pre = pre->link;
		pre->link = p->link;
		free(p);
	}
}
void freeListNode(LinkedList_h* L)
{
	ListNode* pre;
	while (L->head != NULL)
	{
		pre = L->head;
		L->head = L->head->link;
		free(pre);
		pre = NULL;
	}
}

void printList(LinkedList_h* L, FILE* fp)
{
	listNode* p;
	p = L->head;
	fprintf(fp, "------현재 리스트 출력------\n");
	printf("------현재 리스트 출력------\n");
	while (p != NULL)
	{
		fprintf(fp, "%s\n", p->name);
		printf("%s\n", p->name);
		fprintf(fp, "%s\n", p->num);
		printf("%s\n", p->num);
		p = p->link;
		if (p != NULL)
		{
			fprintf(fp, "---------------------------\n");
			printf("---------------------------\n");
		}
	}
	printf("\n");
}
listNode* searchNode(LinkedList_h* L, const char* x)
{
	listNode* p;
	p = L->head;
	while (p != NULL)
	{
		if (strcmp(p->name, x) == 0 || strcmp(p->num, x) == 0) return p;
		else p = p->link;
	}
	p = 0;
	return p;
}

int main()
{
	FILE* fp;
	fp = fopen("listIOT.txt", "at+");
	LinkedList_h* L;
	ListNode* p;
	L = createLinkedList_h();
	clock_t start, finish;
	double duration;

	start = clock();
	insertFirstListNode(L, "a", "1");
	insertFirstListNode(L, "b", "2");
	insertFirstListNode(L, "c", "3");
	insertFirstListNode(L, "d", "4");
	insertFirstListNode(L, "e", "5");
	insertFirstListNode(L, "f", "6");
	insertFirstListNode(L, "g", "7");
	insertFirstListNode(L, "h", "8");
	insertFirstListNode(L, "i", "9");
	insertFirstListNode(L, "j", "10");
	printList(L, fp);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	fprintf(fp, "리스트 10개 First에 입력 걸린시간 : %lf\n", duration);
	printf("리스트 10개 First에 입력 걸린시간 : %lf\n", duration);
	freeListNode(L);

	p = searchNode(L, "d");
	start = clock();
	insertMiddleListNode(L, p, "a", "1");
	insertMiddleListNode(L, p, "b", "2");
	insertMiddleListNode(L, p, "c", "3");
	insertMiddleListNode(L, p, "d", "4");
	insertMiddleListNode(L, p, "e", "5");
	insertMiddleListNode(L, p, "f", "6");
	insertMiddleListNode(L, p, "g", "7");
	insertMiddleListNode(L, p, "h", "8");
	insertMiddleListNode(L, p, "i", "9");
	insertMiddleListNode(L, p, "j", "10");
	printList(L, fp);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	fprintf(fp, "리스트 10개 Middle에 입력 걸린시간 : %lf\n", duration);
	printf("리스트 10개 Middle에 입력 걸린시간 : %lf\n", duration);
	freeListNode(L);

	start = clock();
	insertLastListNode(L, "a", "1");
	insertLastListNode(L, "b", "2");
	insertLastListNode(L, "c", "3");
	insertLastListNode(L, "d", "4");
	insertLastListNode(L, "e", "5");
	insertLastListNode(L, "f", "6");
	insertLastListNode(L, "g", "7");
	insertLastListNode(L, "h", "8");
	insertLastListNode(L, "i", "9");
	insertLastListNode(L, "j", "10");
	printList(L, fp);
	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	fprintf(fp, "리스트 10개 last에 입력 걸린시간 : %lf\n", duration);
	printf("리스트 10개 last에 입력 걸린시간 : %lf\n", duration);
	freeListNode(L);

	system("notepade.exe listIOT.txt");
	system("pause");
}