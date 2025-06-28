#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
void insert(node**head,int value){
    node*temp;
    node*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
node*sort(node*head){
    node*i,*j;
    int temp;
    for(i=head;i!=NULL;i=i->next){
        for(j=head;j!=NULL;j=j->next){
            if(i->data<j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
    return head;
}

node*insertionsort(node*head){
    node*dummy=(node*)malloc(sizeof(node));
    dummy->next=NULL;
    while(head){
        node*next=head->next;
        node*temp=dummy;
        while(temp->next&&temp->next->data<head->data){
            temp=temp->next;
        }
        head->next=temp->next;
        temp->next=head;
        head=next;
    }
    return dummy->next;
}
int main(){
    node*head=NULL;
    insert(&head,-1);
    insert(&head,5);
    insert(&head,3);
    insert(&head,4);
    insert(&head,0);
    head=insertionsort(head);
    display(head);
}