//
// Created by 徐彬斌 on 2022/10/31.
//
//6 将两个递增的有序链表合并为一个递增的有序链表。要求结果链表仍使用原来两个链表的存储空间，
//不另外占用其他的存储空间。表中不允许有重复的数据。【中】
#include "2-6.h"

//第一条链表
struct LNode * L=NULL;//头
struct LNode * head=NULL;//首
struct LNode * p=NULL;
//第二条链表
struct LNode * L1=NULL;//头
struct LNode * head1=NULL;//首
struct LNode * p1=NULL;
//代理链表
struct LNode * L2=NULL;//头
struct LNode * q=NULL;//L2备用地址
struct LNode * q1=NULL;//备用地址
int main(){
    int i=0,length;
    printf("请输入链表的长度\n");
    scanf("%d",&length);
    head=(struct LNode *)malloc(sizeof(struct  LNode));
    L=head;
    printf("请依次输入链表的内容\n");
    for(i;i<length;i++){
        p = (struct LNode *)malloc(sizeof(struct  LNode));
        scanf("%d",&p->data);
        p->next=NULL;
        head->next=p;
        head=p;
    }
    int i1=0,length1;
    printf("请输入链表的长度\n");
    scanf("%d",&length1);

    head1=(struct LNode *)malloc(sizeof(struct  LNode));
    L1=head1;
    printf("请依次输入链表的内容\n");
    for(i1;i1<length1;i1++){
        p1= (struct LNode *)malloc(sizeof(struct  LNode));
        scanf("%d",&p1->data);
        p1->next=NULL;
        head1->next=p1;
        head1=p1;
    }
    L2=(struct LNode *)malloc(sizeof(struct  LNode));
    q=L2;//备用合并链表起始地址
    p=L->next;
    p1=L1->next;
    while(p&&p1){
        if(p->data<p1->data){
            L2->next=p;
            L2=p;
            p=p->next;
        }else if(p->data==p1->data){
            L2->next=p;
            L2=p;
            p=p->next;
            q1=p1->next;//备用相同元素的下一个地址指向
            free(p1);
            p1=q1;

        }else if(p->data>p1->data){
            L2->next=p1;
            L2=p1;
            p1=p1->next;
        }
    }
    L2->next=p?p:p1;
    free(L1);
    printf("合并后链表的内容\n");
    p=q->next;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }

}