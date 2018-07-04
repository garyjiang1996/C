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

status CreateBiTree(BiTree &T) //建立二叉树（递归）
{
	char ch;
	scanf("%c", &ch); //先序输入 
	if(ch=='#')       //输入#号*T指向空树 
		T=NULL;
	else
	{
		if(!(T=(BiTNode*)malloc(sizeof(BiTNode)))) ///当T为空树时
			exit(OVERFLOW);
		T->data=ch;               //生成根结点
		CreateBiTree(T->lchild); //递归调用创建左右子树 
		CreateBiTree(T->rchild);
	} 
	return OK;
}  

status PreOrderTraverse(BiTree T){    //递归先序遍历二叉树   
	if (T){
		printf("%c",T->data);  //输出元素 
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	return OK;
}

status InOrderTraverse(BiTree T){   //递归中序遍历二叉树
	if (T) {
		InOrderTraverse(T->lchild);
		printf("%c",T->data);
		InOrderTraverse(T->rchild);
	}
	return OK;
}

status PostOrderTraverse(BiTree T){  //递归后序遍历二叉树
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

int main()       //调用创建二叉树,先中后序的遍历函数 
{
	BiTree T; 
	CreateBiTree(T);
	PreOrderTraverse(T); putchar('\n');
	InOrderTraverse(T); putchar('\n');
	PostOrderTraverse(T);
	return 0;
}

