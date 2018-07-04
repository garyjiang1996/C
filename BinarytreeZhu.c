#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef char ElementType; 

typedef struct BiTreeNode  {  
    ElementType data;  
    struct BiTreeNode* lchild;  
    struct BiTreeNode* rchild;  
}BiTreeNode, *BiTree; 


int main()
{
	void createBiTree(BiTree &T);
	void preOrderTraverse(const BiTree &T);
	void inOrderTraverse(const BiTree &T);
	void postOrderTraverse(const BiTree &T);


	BiTree T = NULL;
	createBiTree(T);
	preOrderTraverse(T);
	printf("\n");
	inOrderTraverse(T);
	printf("\n");
	postOrderTraverse(T);
	printf("\n");
	return 0;

} 
//建立二叉树（递归）
void createBiTree(BiTree &T)  
{  
	   char data;  
       data=getchar();  
       if(data=='#')  
	   {  
          T=NULL;  
	   }  
       else  
	   {  
		 T=(BiTreeNode *)malloc(sizeof(BiTreeNode));  
         T->data = data;  
         createBiTree(T->lchild);  
         createBiTree(T->rchild);  
	   }  
}  

//递归先序遍历二叉树   
void preOrderTraverse(const BiTree &T)  
{  
    if(T)  
    {  
        printf("%c",T->data);//输出根节点值   
        preOrderTraverse(T->lchild);//遍历左子树   
        preOrderTraverse(T->rchild);//遍历右子树   
    }  
}  

//递归中序遍历二叉树
void inOrderTraverse(const BiTree &T)  
{  
    if(T)  
    {  
        inOrderTraverse(T->lchild);//遍历左子树   
        printf("%c",T->data);//输出根节点值   
        inOrderTraverse(T->rchild);//遍历右子树   
    }  
}

//递归后序遍历二叉树  
void postOrderTraverse(const BiTree &T)  
{  
    if(T)  
    {  
        postOrderTraverse(T->lchild);//遍历左子树   
        postOrderTraverse(T->rchild);//遍历右子树   
        printf("%c",T->data);//输出根节点值   
    }   
}  

