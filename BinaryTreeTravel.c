#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
typedef char TElemType;
typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild;
} BiNode , *BiTree;


Status CreatBiTree(BiTree *T)
{
    char ch;
    scanf("%c", &ch);
 
    //�����ǰ������ַ�Ϊ�ո���(*T)ָ�������
    if (ch == ' ')
    {
        (*T) = NULL;
    }
    else
    {
        if (!((*T) = (BiTree)malloc(sizeof(BiNode))))
            exit(OVERFLOW);
        (*T)->data = ch;             //���ɸ����
        CreatBiTree(&((*T)->lchild));    //����������
        CreatBiTree(&((*T)->rchild));    //����������
    }
    return OK;
}
 
/*
 * ���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú�����
 * �������������T�ĵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
 */
Status PreOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e))
{
    if (T)
    {
        if (Visit(T->data))
            if (PreOrderTraverse_Recursive(T->lchild, Visit))
                if (PreOrderTraverse_Recursive(T->rchild, Visit))
                    return OK;
        return ERROR;   //��������ִ�е���һ�������᷵��Error������дֻ��Ϊ��û�б��뾯�档
    }
    else
        return OK;  //��TΪ����ʱ��ֹͣ�ݹ顣
}
 
Status InOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e))
{
    if (T)
    {
        if (InOrderTraverse_Recursive(T->lchild, Visit))
            if (Visit(T->data))
                if (InOrderTraverse_Recursive(T->rchild, Visit))
                    return OK;
        return ERROR;
    }
    else
        return OK;
}
 
Status PostOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e))
{
    if (T)
    {
        if (PostOrderTraverse_Recursive(T->lchild, Visit))
            if (PostOrderTraverse_Recursive(T->rchild, Visit))
                if (Visit(T->data))
                    return OK;
        return ERROR;
    }
    else
        return OK;
}
Status PrintElement(TElemType e)
{
    putchar(e);
    return OK;
}
/*Status InitStack(Stack *s)  //��ʼջ
{
    s->base = (BiTree*)malloc(sizeof(BiTree)*STACK_INIT_SIZE);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
} 
Status GetTop(Stack *s, BiTree *c) //���ջ��Ԫ��
{
    if (StackEmpty(s))
        return ERROR;
    *c = *(s->top - 1);
    return OK;
}
Status StackEmpty(Stack *s)  //�ж�ջ�Ƿ�Ϊ��
{
    if (s->base == s->top)
        return OK;
    return ERROR;
}
//��ջ
Status Push(Stack *s, BiTree c)
{
    //����ռ䲻�������ӿռ�ķ���
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (BiTree*)realloc(s->base, sizeof(BiTree)*(s->stacksize + STACKINCREMENT));
        s->stacksize = s->stacksize + STACKINCREMENT;
    }
 
    *(s->top++) = c;
    return OK;
}
Status Pop(Stack *s, BiTree *c) //�� 
{
    if (StackEmpty(s))
        return ERROR;
    *c = *(--s->top);
    return OK;
}*/ 
int main()
{
    BiTree T;
    CreatBiTree(&T);
    PreOrderTraverse_Recursive(T, PrintElement); putchar('\n');
    InOrderTraverse_Recursive(T, PrintElement); putchar('\n');
    PostOrderTraverse_Recursive(T, PrintElement); putchar('\n');
    return 0;
}
