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

node*addtwonumbers(node*l1,node*l2){
    node*l3=l1;
    while(l1!=NULL&&l2!=NULL){
        l3->data=l1->data+l2->data;   
        l1=l1->next;
        l2=l2->next;
    }
    return l3;
}

int main(){
    node*head1=NULL;
    insert(&head1,2);
    insert(&head1,4);
    insert(&head1,3);
    node*head2=NULL;
    insert(&head2,5);
    insert(&head2,6);
    insert(&head2,4);
    display(head1);
    display(head2);
    node*head3=NULL;
    head3=addtwonumbers(head1,head2);
    display(head3);
}