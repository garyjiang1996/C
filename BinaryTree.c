/*
 * ���������ַ�Ϊ��ABC##DE#G##F###��ʵ������ʱ��#�ÿո���档
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
 
typedef int Status;
#define OK 1
#define ERROR 0
#define OVERFLOW -2
 
//�������Ķ�������洢��ʾ
typedef char TElemType;
typedef struct BiNode
{
    TElemType data;
    struct BiNode *lchild, *rchild;
} BiNode , *BiTree;
 
//ջ��˳��洢�ṹ
#define STACK_INIT_SIZE 100      //�洢�ռ��ʼ������
#define STACKINCREMENT 10       //�洢�ռ��������
 
typedef struct
{
    BiTree *base;
    BiTree *top;
    int stacksize;
} Stack;
 
//��������
Status InitStack(Stack *S);
Status Push(Stack *S, BiTree p);
Status Pop(Stack *S, BiTree *p);
Status GetTop(Stack *S, BiTree *p);
Status StackEmpty(Stack *S);
 
Status CreatBiTree(BiTree *T);
Status PreOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e));
Status InOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e));
Status PostOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e));
Status PreOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e));
Status InOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e));
Status InOrderTraverse_NonRecursive_2(BiTree T, Status(*Visit)(TElemType e));
Status PostOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e));
 
Status PrintElement(TElemType e);
 
int main()
{
    BiTree T;
    CreatBiTree(&T);
    //����
    PreOrderTraverse_Recursive(T, PrintElement); putchar('\n');
    PreOrderTraverse_NonRecursive(T, PrintElement); putchar('\n');
    //����
    InOrderTraverse_Recursive(T, PrintElement); putchar('\n');
    InOrderTraverse_NonRecursive(T, PrintElement); putchar('\n');
    InOrderTraverse_NonRecursive_2(T, PrintElement); putchar('\n');
    //����
    PostOrderTraverse_Recursive(T, PrintElement); putchar('\n');
    PostOrderTraverse_NonRecursive(T, PrintElement); putchar('\n');
    return 0;
}
 
/* 
 * �������������������н���ֵ(һ���ַ�)���ո��ַ���ʾ������������������ʾ�Ķ�����T��
 */
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
 
/*
 * ����������������ǵݹ��㷨��
 */
Status PreOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e))
{
    Stack *S;   //ջS�д洢ָ��������ָ�롣
    BiTree p;
    S = (Stack*)malloc(sizeof(Stack));
    InitStack(S);
    Push(S, T); //��ָ���ջ��
    while (!StackEmpty(S))
    {
        //��ȡջ��ָ�룬���ջ��ָ�벻Ϊ�գ����ʸý�㡣�����ý�����������ջ��
        if (GetTop(S, &p) && p)
        {
            if (!Visit(p->data))
                return ERROR;
            Push(S, p->lchild);
        }
        //ջ��ָ��Ϊ�գ�����֮ǰѹ�������������������Ϊ�ա�
        else
        {
            Pop(S, &p); //��ָ����ջ
            if (!StackEmpty(S))
            {
                Pop(S, &p); //�ѱ����ʹ��ĸ������ջ����ʱ������ջ�����������ѱ�ȫ�����ʹ���
                Push(S, p->rchild);  //��������ջ��
            }
        }
    }
    return OK;
}
 
/* 
 * ���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ؽ��в�����Ӧ�ú�����
 * ��������������ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
 */
Status InOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e))
{
    Stack *S;
    BiTree p;
    S = (Stack *)malloc(sizeof(Stack));
    InitStack(S);
    Push(S, T); //��ָ���ջ
    while (!StackEmpty(S))
    {
        //�����ߵ���ͷ
        while (GetTop(S, &p) && p)
        {
            Push(S, p->lchild);
        }
 
        //��ָ����ջ
        Pop(S, &p);
 
        //���ʽڵ㣬������һ��
        if (!StackEmpty(S))
        {
            Pop(S, &p);
            if (!Visit(p->data))
                return ERROR;
            Push(S, p->rchild);
        }
    }
    return OK;
}
 
/*
 * ���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ؽ��в�����Ӧ�ú�����
 * ��������������ķǵݹ��㷨����ÿ������Ԫ�ص��ú���Visit��
 */
Status InOrderTraverse_NonRecursive_2(BiTree T, Status(*Visit)(TElemType e))
{
    Stack *S;
    BiTree p = T;
    S = (Stack *)malloc(sizeof(Stack));
    InitStack(S);
 
    while (p || !StackEmpty(S))
    {
        //��ָ���ջ������������
        if (p)
        {
            Push(S, p);
            p = p->lchild;
        }
        //��ָ����ջ�����ʸ���㣬����������
        else
        {
            Pop(S, &p);
            if (!Visit(p->data))
                return ERROR;
            p = p->rchild;
        }
    }
    return OK;
}
 
/*
 * ����������������ǵݹ��㷨
 */
Status PostOrderTraverse_NonRecursive(BiTree T, Status(*Visit)(TElemType e))
{
    Stack *S;
    BiTree p, pre=NULL;//preָ���ѷ��ʹ������һ����㡣
    S = (Stack*)malloc(sizeof(Stack));
    InitStack(S);
    Push(S, T);//��ָ���ջ
 
    while (!StackEmpty(S))
    {
        //��ȡջ��ָ�룬�����ǰ�������������������������㲻�Ǹձ����ʵĽڵ㡣�����ǰ�������������������������㲻�Ǹձ����ʵĽ�㡣
        //����ջ��ָ��ָ��������δ�����ʣ�������������������δ�����ʡ���ʱ����������������ջ��
        if (GetTop(S, &p) && p->lchild && pre != p->lchild && !(p->rchild && pre == p->rchild))
            Push(S, p->lchild);
        //���ջ��ָ������������ڣ���δ�����ʡ�����������ջ
        else if (p->rchild && pre != p->rchild)
            Push(S, p->rchild);
        //������������������������ʹ���������ջ�������з��ʡ�����pre��
        else
        {
            Pop(S, &p);
            if (!Visit(p->data))
                return ERROR;
            pre = p;
        }
    }
    return OK;
}
 
//��������Ԫ��ʱ�����ú���
Status PrintElement(TElemType e)
{
    putchar(e);
    return OK;
}
 
//��ʼ��ջ
Status InitStack(Stack *s)
{
    s->base = (BiTree*)malloc(sizeof(BiTree)*STACK_INIT_SIZE);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}
 
//���ջ��Ԫ��
Status GetTop(Stack *s, BiTree *c)
{
    if (StackEmpty(s))
        return ERROR;
    *c = *(s->top - 1);
    return OK;
}
 
//�ж�ջ�Ƿ�Ϊ��
Status StackEmpty(Stack *s)
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
 
//��ջ
Status Pop(Stack *s, BiTree *c)
{
    if (StackEmpty(s))
        return ERROR;
    *c = *(--s->top);
    return OK;
}
