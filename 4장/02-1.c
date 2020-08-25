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
	//printf("p1의 데이터: %s \n", p1->data);
	//printf("p1의 링크:   %x \n", p1->link);

	//strcpy(p2->data, "DEF");
	//p2->link = NULL;
	//p1->link = p2;
	//printf("p2의 데이터: %s \n", p2->data);
	//printf("p2의 링크:   %x \n", p2->link);
	//printf("p1의 데이터: %s \n", p1->data);
	//printf("p1의 링크:   %x \n", p1->link);

	//strcpy(new->data, "XYZ");
	//new->link = p1->link; //new.link = &p2;
	//p1->link = new;

	//printf("p1의 데이터 %s \n", p1->data);
	//printf("new의 데이터 %s \n", new->data);
	//printf("p2의 데이터 %s \n", p2->data);

	while (temp != NULL)
	{
		printf("반복문 head를 가지고 %s\n", temp->data);
		temp = temp->link;
	}

	return 0;
}

linkedList_h* createLinkedList_h(void) {
	linkedList_h* L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;		// 공백 리스트이므로 NULL로 설정
	return L;
}

