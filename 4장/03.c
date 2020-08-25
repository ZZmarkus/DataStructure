// 동적메모리할당
#include<stdio.h>
#include<string.h>
#include<stdlib.h> // malloc, calloc, realloc

typedef struct ListNode
{
	char data[4];
	struct ListNode* link;
} listNode;

// 리스트의 시작을 나타내는 head 노드를 구조체로 정의
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
	L->head = NULL;		// 공백 리스트이므로 NULL로 설정
	return L;
}
void insertFirstNode(linkedList_h *L, char *x) 
{
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));	// 삽입할 새 노드 할당
	strcpy(newNode->data,x);						// 새 노드의 데이터 필드에 x 저장  
	newNode->link = L->head;
	L->head = newNode;
}

void print(linkedList_h *L)
{
  listNode*	temp = L->head;

	while (temp != NULL)
	{
		printf("반복문 temp를 가지고 %s\n", temp->data);
		temp = temp->link;
	}
}
