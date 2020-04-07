#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define MAX(a,b) ((a>b)?a:b)


typedef int element;		// ���� Ž�� Ʈ�� element�� �ڷ����� int�� ����
typedef struct treenode {
	char key[10];	// ������ �ʵ�
	element num, age;
	double score;
	char my[100];
	struct treeNode* left;	// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;	// ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;

typedef struct ListNode {
	char key[10];
	element num, age;
	double score;
	char my[100];
	struct ListNode* link;
}listNode;

struct ListNode* p[1000];
int structCnt = 0;


treeNode* searchBSTTree(treeNode* root, element x);

treeNode* LL_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

treeNode* RR_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treeNode* LR_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(parent);
}

treeNode* RL_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(parent);
}

// ���� Ʈ���� ���̸� ���ϴ� ����
int getHeight(treeNode* p) {
	int height = 0;
	if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

// ���� Ʈ���� ���̸� �̿��� ���� �μ� BF�� ���ϴ� ����
int getBF(treeNode* p) {
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

// BF�� �˻��Ͽ� �ұ����� �߻��� ���, ȸ�� ���� ȣ��
treeNode* rebalance(treeNode** p) {
	int BF = getBF(*p);
	if (BF > 1) {
		if (getBF((*p)->left) > 0)
			*p = LL_rotate(*p);
		else    *p = LR_rotate(*p);
	}
	else if (BF < -1) {
		if (getBF((*p)->right) < 0)
			*p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}
	return *p;
}

// AVL Ʈ���� ��带 �����ϴ� ����: ���� Ž�� ����ó�� ������ �Ŀ�, rebalance() ȣ�� 
treeNode* insert_AVL_Node(treeNode** root, const char* x, const int num, const int age, const double score, const char* my) {
	if ((*root) == NULL) {
		(*root) = (treeNode*)malloc(sizeof(treeNode));
		strcpy((*root)->key, x);
		(*root)->num = num;
		(*root)->age = age;
		(*root)->score = score;
		strcpy((*root)->my, my);
		(*root)->left = NULL;
		(*root)->right = NULL;
		return (*root);
	}
	else if (num < (*root)->num) {
		(*root)->left = insert_AVL_Node(&((*root)->left), x, num, age, score, my);
		(*root) = rebalance(root);
	}
	else if (num > (*root)->num) {
		(*root)->right = insert_AVL_Node(&((*root)->right), x, num, age, score, my);
		(*root) = rebalance(root);
	}
	else {
		printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");
		exit(1);
	}
	return (*root);
}


treeNode* searchAVLTree(treeNode* root, element x) {
	treeNode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->num) p = p->left;
		else if (x == p->num) {
			printf("AVLƮ�� %d ã��--> %3d��°�� Ž�� ����\n", p->num,count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("AVL Ʈ�� %3d��°�� Ž�� ����! ã�� Ű�� �����ϴ�!\n", count);
	p = NULL;
	return p;
}


void displayInorder(treeNode* root, treeNode* AVL) {
	if (root) {
		displayInorder(root->left, AVL);
		searchAVLTree(AVL, root->num);
		searchBSTTree(AVL, root->num);
		displayInorder(root->right, AVL);
	}
}

treeNode* InputAVL(FILE* fp, treeNode* root_AVL);
treeNode* InputBST(FILE* fp, treeNode* root_BST);

int main() {
	FILE* fp;
	treeNode* root_AVL = NULL;
	treeNode* root_BST = NULL;
	clock_t start, finish;
	double AVLdura, BSTdura;
	int choice;
	int num;
	int AVLindex = 1, BSTindex = 1;

	fp = fopen("�й�.txt", "rt");
	root_AVL = InputAVL(fp, root_AVL);
	root_BST = InputBST(fp, root_BST);
	fclose(fp);
	
	while (1)
	{
		printf("1. �й� Ž��\n2. ȭ�� �����\n3. ��� �й� �� \n4. ����\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("�˻��� �й��� �Է��� �ּ���");
			scanf("%d", &num);

			start = clock();
			searchAVLTree(root_AVL, num);
			finish = clock();
			AVLdura = (double)(finish - start) / CLOCKS_PER_SEC;
			fp = fopen("AVL.txt", "at+");
			fprintf(fp, "%02d %d : %lf��\n", AVLindex, num, AVLdura);
			fclose(fp);
			AVLindex++;

			start = clock();
			searchBSTTree(root_BST, num);
			finish = clock();
			BSTdura = (double)(finish - start) / CLOCKS_PER_SEC;
			fp = fopen("BST.txt", "at+");
			fprintf(fp, "%02d %d : %lf��\n", BSTindex, num, BSTdura);
			fclose(fp);
			BSTindex++;

			if (AVLdura > BSTdura)
			{
				AVLdura -= BSTdura;
				printf("\n%d�� ã�� ��� : AVLƮ���� %lf�� ����\n", num, AVLdura);
			}
			else if (AVLdura == BSTdura)
			{
				printf("\n%d�� ã�°�� : ����\n", num);
			}
			else
			{
				BSTdura -= AVLdura;
				printf("\n%d�� ã�� ��� : BTSƮ���� %lf�� ����\n", num, BSTdura);
			}
			break;
		case 2:
			system("CLS");
			break;
		case 3:
			displayInorder(root_AVL, root_AVL);
		case 4:
			return 0;
		}
	}

	getchar();
}


treeNode* insert_BST_Node(treeNode *pt, const char* x, const int num, const int age, const double score, const char* my) {
	treeNode *newNode;
	if (pt == NULL) {
		newNode = (treeNode*)malloc(sizeof(treeNode));
		strcpy(newNode->key, x);
		newNode->num = num;
		newNode->age = age;
		newNode->score = score;
		strcpy(newNode->my, my);
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	else if (num < pt->num)  pt->left = insert_BST_Node(pt->left, x, num, age, score, my);
	else if (num > pt->num)  pt->right = insert_BST_Node(pt->right, x, num, age, score, my);
	else  printf("\n �̹� ���� Ű�� �ֽ��ϴ�! \n");

	return pt;
}


treeNode* searchBSTTree(treeNode* root, element x) {
	treeNode* p;
	int count = 0;
	p = root;
	while (p != NULL) {
		count++;
		if (x < p->num) p = p->left;
		else if (x == p->num) {
			printf("BSTƮ�� %d ã��--> %3d��°�� Ž�� ����\n", p->num, count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("BST Ʈ�� %3d��°�� Ž�� ����! ã�� Ű�� �����ϴ�!\n", count);
	p = NULL;
	return p;
}



treeNode* InputAVL(FILE* fp, treeNode* root_AVL)
{
	char name[10];
	int num, age;
	double score;
	char s[30];
	char my[100];

	while (!feof(fp))
	{
		p[structCnt] = (listNode*)malloc(sizeof(listNode));
		fscanf(fp, "%s %d %d %lf %s", name, &num, &age, &score, my);
		strcpy(p[structCnt]->key, name);
		p[structCnt]->num = num;
		p[structCnt]->age = age;
		p[structCnt]->score = score;
		strcpy(p[structCnt]->my, my);
		structCnt++;
	}

	for (int i = 0; i < structCnt; i++)
	{
		fprintf(stdout, "%s %d %d %.2lf %s\n", p[i]->key, p[i]->num, p[i]->age, p[i]->score, p[i]->my);
		if (root_AVL == NULL)
		{
			root_AVL = insert_AVL_Node(&root_AVL, p[i]->key, p[i]->num, p[i]->age, p[i]->score, p[i]->my);
		}
		else
		{
			insert_AVL_Node(&root_AVL, p[i]->key, p[i]->num, p[i]->age, p[i]->score, p[i]->my);
		}
	}
	return root_AVL;
}


treeNode* InputBST(FILE* fp, treeNode* root_BST)
{
	char name[10];
	int num, age;
	double score;
	char s[30];
	char my[100];

	while (!feof(fp))
	{
		p[structCnt] = (listNode*)malloc(sizeof(listNode));
		fscanf(fp, "%s %d %d %lf %s", name, &num, &age, &score, my);
		strcpy(p[structCnt]->key, name);
		p[structCnt]->num = num;
		p[structCnt]->age = age;
		p[structCnt]->score = score;
		strcpy(p[structCnt]->my, my);
		structCnt++;
	}

	for (int i = 0; i < structCnt; i++)
	{
		if (root_BST == NULL)
		{
			root_BST = insert_BST_Node( root_BST, p[i]->key, p[i]->num, p[i]->age, p[i]->score, p[i]->my);
		}
		else
		{
			insert_BST_Node(root_BST, p[i]->key, p[i]->num, p[i]->age, p[i]->score, p[i]->my);
		}
	}
	return root_BST;
}