#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#define MAX(a,b) ((a>b)?a:b)


typedef int element;		// 이진 탐색 트리 element의 자료형을 int로 정의
typedef struct treenode {
	char key[10];	// 데이터 필드
	element num, age;
	double score;
	char my[100];
	struct treeNode* left;	// 왼쪽 서브 트리 링크 필드
	struct treeNode* right;	// 오른쪽 서브 트리 링크 필드
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

// 서브 트리의 높이를 구하는 연산
int getHeight(treeNode* p) {
	int height = 0;
	if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

// 서브 트리의 높이를 이용해 균형 인수 BF를 구하는 연산
int getBF(treeNode* p) {
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

// BF를 검사하여 불균형이 발생한 경우, 회전 연산 호출
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

// AVL 트리에 노드를 삽입하는 연산: 이진 탐색 연산처럼 삽입한 후에, rebalance() 호출 
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
		printf("\n 이미 같은 키가 있습니다! \n");
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
			printf("AVL트리 %d 찾기--> %3d번째에 탐색 성공\n", p->num,count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("AVL 트리 %3d번째에 탐색 실패! 찾는 키가 없습니다!\n", count);
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

	fp = fopen("학번.txt", "rt");
	root_AVL = InputAVL(fp, root_AVL);
	root_BST = InputBST(fp, root_BST);
	fclose(fp);
	
	while (1)
	{
		printf("1. 학번 탐색\n2. 화면 지우기\n3. 모든 학번 비교 \n4. 종료\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("검색할 학번을 입력해 주세요");
			scanf("%d", &num);

			start = clock();
			searchAVLTree(root_AVL, num);
			finish = clock();
			AVLdura = (double)(finish - start) / CLOCKS_PER_SEC;
			fp = fopen("AVL.txt", "at+");
			fprintf(fp, "%02d %d : %lf초\n", AVLindex, num, AVLdura);
			fclose(fp);
			AVLindex++;

			start = clock();
			searchBSTTree(root_BST, num);
			finish = clock();
			BSTdura = (double)(finish - start) / CLOCKS_PER_SEC;
			fp = fopen("BST.txt", "at+");
			fprintf(fp, "%02d %d : %lf초\n", BSTindex, num, BSTdura);
			fclose(fp);
			BSTindex++;

			if (AVLdura > BSTdura)
			{
				AVLdura -= BSTdura;
				printf("\n%d를 찾는 경우 : AVL트리가 %lf초 빠름\n", num, AVLdura);
			}
			else if (AVLdura == BSTdura)
			{
				printf("\n%d를 찾는경우 : 동일\n", num);
			}
			else
			{
				BSTdura -= AVLdura;
				printf("\n%d를 찾는 경우 : BTS트리가 %lf초 빠름\n", num, BSTdura);
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
	else  printf("\n 이미 같은 키가 있습니다! \n");

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
			printf("BST트리 %d 찾기--> %3d번째에 탐색 성공\n", p->num, count);
			return p;
		}
		else p = p->right;
	}
	count++;
	printf("BST 트리 %3d번째에 탐색 실패! 찾는 키가 없습니다!\n", count);
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