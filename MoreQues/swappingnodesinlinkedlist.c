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


node*swapnodes(node*head,int k){
    if(head==NULL||k<=0) return head;
    node*temp=head;
    node*temp1=head;
    node*temp2=head;
    int i=1;
    int len=1;
    int j=1;
    while(temp->next!=NULL){
        temp=temp->next;
        len++;
    }
    if(k>len) return head;
    while(i<k){
        temp1=temp1->next;
        i++;
    }
    while(j<=len-k){
        temp2=temp2->next;
        j++;
    }
    
    int tempdata=temp1->data;
    temp1->data=temp2->data;
    temp2->data=tempdata;
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
    head=swapnodes(head,2);
    display(head);
    return 0;
}