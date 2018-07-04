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
//�������������ݹ飩
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

//�ݹ��������������   
void preOrderTraverse(const BiTree &T)  
{  
    if(T)  
    {  
        printf("%c",T->data);//������ڵ�ֵ   
        preOrderTraverse(T->lchild);//����������   
        preOrderTraverse(T->rchild);//����������   
    }  
}  

//�ݹ��������������
void inOrderTraverse(const BiTree &T)  
{  
    if(T)  
    {  
        inOrderTraverse(T->lchild);//����������   
        printf("%c",T->data);//������ڵ�ֵ   
        inOrderTraverse(T->rchild);//����������   
    }  
}

//�ݹ�������������  
void postOrderTraverse(const BiTree &T)  
{  
    if(T)  
    {  
        postOrderTraverse(T->lchild);//����������   
        postOrderTraverse(T->rchild);//����������   
        printf("%c",T->data);//������ڵ�ֵ   
    }   
}  

