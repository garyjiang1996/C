#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define OK 1
#define OVERFLOW -2
typedef int status;
typedef char TElemType;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

status CreateBiTree(BiTree &T) //�������������ݹ飩
{
	char ch;
	scanf("%c", &ch); //�������� 
	if(ch=='#')       //����#��*Tָ����� 
		T=NULL;
	else
	{
		if(!(T=(BiTNode*)malloc(sizeof(BiTNode)))) ///��TΪ����ʱ
			exit(OVERFLOW);
		T->data=ch;               //���ɸ����
		CreateBiTree(T->lchild); //�ݹ���ô����������� 
		CreateBiTree(T->rchild);
	} 
	return OK;
}  

status PreOrderTraverse(BiTree T){    //�ݹ��������������   
	if (T){
		printf("%c",T->data);  //���Ԫ�� 
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}

status InOrderTraverse(BiTree T){   //�ݹ��������������
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
	return OK;
}

status PostOrderTraverse(BiTree T){  //�ݹ�������������
	if (T) {
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%c",T->data);
	}
	return OK;
}

/*status PrintElement(TElemType e) 
{
	printf(e);
	return OK;
}*/

int main()       //���ô���������,���к���ı������� 
{
	BiTree T; 
	CreateBiTree(T);
	PreOrderTraverse(T); putchar('\n');
	InOrderTraverse(T); putchar('\n');
	PostOrderTraverse(T);
	return 0;
}

