// �����޸��Ҵ�
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // malloc, calloc, realloc

typedef struct ListNode
{
	char data[4];
	struct ListNode* link;
} listNode;

// ����Ʈ�� ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void); 
void insertFirstNode(linkedList_h *L, char *x);
void print(linkedList_h *L);

//void print(linkedList_h *L);

int main()
{
	linkedList_h * L = createLinkedList_h();
	insertFirstNode(L, "ABC");
	insertFirstNode(L, "DEF");
	insertFirstNode(L, "GHI");
	insertFirstNode(L, "JKL");
	print(L);
	
	return 0;
}

linkedList_h* createLinkedList_h(void) 
{
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;		// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return L;
}
void insertFirstNode(linkedList_h *L, char *x) 
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));	// ������ �� ��� �Ҵ�
	strcpy(newNode->data,x);						// �� ����� ������ �ʵ忡 x ����  
	newNode->link = L->head;
	L->head = newNode;
}

void print(linkedList_h *L)
{
  listNode*	temp = L->head;

	while (temp != NULL)
	{
		printf("�ݺ��� temp�� ������ %s\n", temp->data);
		temp = temp->link;
	}
}
