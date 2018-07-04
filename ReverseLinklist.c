#include <stdio.h>
#include <malloc.h>
 
#define LIST_LEN 10 //������

typedef struct Node{
         int data;
         struct Node* next;
}Node;
 
Node * List = NULL; //����
 
//������ʽ
void reverse_ite(Node * list){
         Node * old_head = NULL;         //ԭ�������ͷ
         Node * new_head = NULL;      //�������ͷ
         Node * cur = list;      //���ԭ�������ͷ
         //ÿ�ν�ԭ�������ͷȡ���������뵽�������У��������������ͷ
         while(cur != NULL){
                   old_head = cur->next;      //��ԭ�������ͷȡ���������ڶ����ڵ���Ϊͷ�ڵ�
                   cur->next = new_head;   //��ȡ����ͷ��Ϊ�������ͷ
                   new_head = cur;      //�������ͷ����Ŀǰ�������ͷ
                   cur = old_head;        //���Ŵ���
         }
         List = new_head;
}
//�ݹ鷽ʽ
/*
void reverse_recursive(Node * old_head, Node * new_head){
         if(old_head == NULL){
                   List = new_head;
                   return;
         }
         Node * tmp = old_head->next;        //��ԭ�������ͷȡ���������ڶ����ڵ���Ϊԭ�������ͷ�ڵ�������һ��ݹ�
         old_head->next = new_head; //��ȡ����ͷ��Ϊ�������ͷ
         reverse_recursive(tmp, old_head);         //���Ŵ���
}
*/
//��������
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
//��ӡ�����data
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
	 reverse_ite(List);     //������ʽ
	 //reverse_recursive(List, NULL);     //�ݹ鷽ʽ
	 print_list();
}
