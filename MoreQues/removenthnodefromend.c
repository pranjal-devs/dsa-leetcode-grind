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

node*removeNthfromend(node*head,int n){
    node*temp=head;
    int count=1;
    while(temp->next!=NULL){
        count++;
        temp=temp->next;
    }
    int i=1;
    node*temp1=head;
    if(count==n) {
        node*toDelete=head;
        head=head->next;
        free(toDelete);
        return head;
    }
    while(i<count-n){
        temp1=temp1->next;
        i++;
    }
    temp1->next=temp1->next->next;
    temp1=temp1->next;
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
    insert(&head,5);
    insert(&head,2);
    insert(&head,13);
    insert(&head,3);
    insert(&head,8);
    display(head);
    head=removeNthfromend(head,2);
    display(head);
    return 0;
}