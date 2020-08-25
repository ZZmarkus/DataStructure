#include<stdio.h>
#include<string.h>

typedef struct ListNode 
{
	char data[4];
	struct ListNode* link;
} listNode;

int main()
{
	listNode p1,p2,new; 
	listNode* head=&p1; // 1차원
	listNode* temp = head;

	strcpy(p1.data,"ABC"); //p1.data = 'A';
	p1.link = NULL;

	printf("p1의 데이터: %s \n",p1.data);
	printf("p1의 링크:   %x \n",p1.link);

	strcpy(p2.data, "DEF");//p2.data = "DEF";
	p2.link = NULL;

	p1.link = &p2;
	printf("p2의 데이터: %s \n", p2.data);
	printf("p2의 링크:   %x \n", p2.link);

	printf("p1의 데이터: %s \n", p1.data);
	printf("p1의 링크:   %x \n", p1.link);

	strcpy(new.data, "XYZ");
	new.link = p1.link; //new.link = &p2;
	p1.link = &new;

	printf("p1의 데이터 %s \n",p1.data);
	printf("new의 데이터 %s \n", new.data);
	printf("p2의 데이터 %s \n", p2.data);

	printf("p1가지고 %s \n", p1.data); // abc
	printf("p1가지고 %s \n", p1.link->data); // xyz
	printf("p1가지고 %s \n", p1.link->link->data); // def


	printf("head를 가지고 %s \n",head->data); // abc
	printf("head를 가지고 %s \n", head->link->data); // xyz
	printf("head를 가지고 %s \n", head->link->link->data); // def

	while (temp != NULL)
	{
		printf("반복문 head를 가지고 %s\n", temp->data);
		temp = temp->link;
	}


	return 0;
}