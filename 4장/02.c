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
int main()
{
	/*listNode* p1 = (listNode*)malloc(sizeof(listNode));
	listNode* p2 = (listNode*)malloc(sizeof(listNode));
	listNode* new = (listNode*)malloc(sizeof(listNode));
	listNode* head = p1;
	listNode* temp = head;*/

	linkedList_h * L =createLinkedList_h();
	
	

	//strcpy(p1->data, "ABC"); 
	//p1->link = NULL;
	//printf("p1�� ������: %s \n", p1->data);
	//printf("p1�� ��ũ:   %x \n", p1->link);

	//strcpy(p2->data, "DEF");
	//p2->link = NULL;
	//p1->link = p2;
	//printf("p2�� ������: %s \n", p2->data);
	//printf("p2�� ��ũ:   %x \n", p2->link);
	//printf("p1�� ������: %s \n", p1->data);
	//printf("p1�� ��ũ:   %x \n", p1->link);

	//strcpy(new->data, "XYZ");
	//new->link = p1->link; //new.link = &p2;
	//p1->link = new;

	//printf("p1�� ������ %s \n", p1->data);
	//printf("new�� ������ %s \n", new->data);
	//printf("p2�� ������ %s \n", p2->data);

	while (temp != NULL)
	{
		printf("�ݺ��� head�� ������ %s\n", temp->data);
		temp = temp->link;
	}

	return 0;
}

linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;		// ���� ����Ʈ�̹Ƿ� NULL�� ����
	return L;
}

