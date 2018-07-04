#include <stdio.h>
#include <malloc.h>
 
#define LIST_LEN 10 //链表长度

typedef struct Node{
         int data;
         struct Node* next;
}Node;
 
Node * List = NULL; //链表
 
//迭代方式
void reverse_ite(Node * list){
         Node * old_head = NULL;         //原来链表的头
         Node * new_head = NULL;      //新链表的头
         Node * cur = list;      //获得原来链表的头
         //每次将原来链表的头取出，并插入到新链表中，并且是新链表的头
         while(cur != NULL){
                   old_head = cur->next;      //将原来链表的头取出，并将第二个节点作为头节点
                   cur->next = new_head;   //将取出的头设为新链表的头
                   new_head = cur;      //新链表的头就是目前新链表的头
                   cur = old_head;        //接着处理
         }
         List = new_head;
}
//递归方式
/*
void reverse_recursive(Node * old_head, Node * new_head){
         if(old_head == NULL){
                   List = new_head;
                   return;
         }
         Node * tmp = old_head->next;        //将原来链表的头取出，并将第二个节点作为原来链表的头节点用于下一层递归
         old_head->next = new_head; //将取出的头设为新链表的头
         reverse_recursive(tmp, old_head);         //接着处理
}
*/
//生成链表
void make_list(){
         List = (Node *)malloc(sizeof(Node) * LIST_LEN);
         int i;
         for(i = 0; i < LIST_LEN - 1; i++){
                   (List + i)->data = i + 1;
                   (List + i)->next = List + i + 1;
         }
         (List + LIST_LEN - 1)->data = LIST_LEN;
         (List + LIST_LEN - 1)->next = NULL;
}
//打印俩表的data
void print_list(){
         Node * cur = List;
         while(cur!=NULL){
                   printf("%d ", cur->data);
                   cur = cur->next;
         }
         printf("\n");
}
 
int main(){
	 make_list();
	 print_list();
	 reverse_ite(List);     //迭代方式
	 //reverse_recursive(List, NULL);     //递归方式
	 print_list();
}
