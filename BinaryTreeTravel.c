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
 
    //如果当前输入的字符为空格，则(*T)指向空树。
    if (ch == ' ')
    {
        (*T) = NULL;
    }
    else
    {
        if (!((*T) = (BiTree)malloc(sizeof(BiNode))))
            exit(OVERFLOW);
        (*T)->data = ch;             //生成根结点
        CreatBiTree(&((*T)->lchild));    //构造左子树
        CreatBiTree(&((*T)->rchild));    //构造右子树
    }
    return OK;
}
 
/*
 * 采用二叉链表存储结构，Visit是对数据元素操作的应用函数，
 * 先序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
 */
Status PreOrderTraverse_Recursive(BiTree T, Status(*Visit)(TElemType e))
{
    if (T)
    {
        if (Visit(T->data))
            if (PreOrderTraverse_Recursive(T->lchild, Visit))
                if (PreOrderTraverse_Recursive(T->rchild, Visit))
                    return OK;
        return ERROR;   //函数不会执行到这一步，不会返回Error。这样写只是为了没有编译警告。
    }
    else
        return OK;  //当T为空树时，停止递归。
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
/*Status InitStack(Stack *s)  //初始栈
{
    s->base = (BiTree*)malloc(sizeof(BiTree)*STACK_INIT_SIZE);
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
} 
Status GetTop(Stack *s, BiTree *c) //获得栈顶元素
{
    if (StackEmpty(s))
        return ERROR;
    *c = *(s->top - 1);
    return OK;
}
Status StackEmpty(Stack *s)  //判断栈是否为空
{
    if (s->base == s->top)
        return OK;
    return ERROR;
}
//进栈
Status Push(Stack *s, BiTree c)
{
    //如果空间不够，增加空间的分配
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (BiTree*)realloc(s->base, sizeof(BiTree)*(s->stacksize + STACKINCREMENT));
        s->stacksize = s->stacksize + STACKINCREMENT;
    }
 
    *(s->top++) = c;
    return OK;
}
Status Pop(Stack *s, BiTree *c) //出 
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
