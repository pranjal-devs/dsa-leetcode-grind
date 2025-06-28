#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node*next;
}node;
void insert(node**head,int data){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->next=NULL;
    node*temp;
    if(*head==NULL){
        *head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}

node*reorderlist(node*head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node*fast=head;
    node*slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    node*curr=slow;
    node*prev=NULL;
    node*next=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    node*orglist=head;
    node*revlist=prev;
    while(revlist->next!=NULL){
        node*temp1=orglist->next;
        node*temp2=revlist->next;
        orglist->next=revlist;
        revlist->next=temp1;
        orglist=temp1;
        revlist=temp2;
    }
    return head;
}

void display(node*head){
    while(head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}
int main(){
    node*head=NULL;
    insert(&head,10);
    insert(&head,20);
    insert(&head,30);
    insert(&head,40);
    insert(&head,50);
    display(head);
    head=reorderlist(head);
    display(head);
    return 0;
}