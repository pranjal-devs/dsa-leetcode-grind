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

void merge(node**head1,node**head2,node**head3){
    node*temp=*head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=*head2;
    *head3=*head1;
    
}

node* mergeandsort(node*head1,node*head2){
    node*head3=head1;// list 3 
    node*temp=head1;
    while (temp!=NULL&&temp->next!=NULL){
        temp=temp->next;
    }
    if (temp!=NULL){
        temp->next=head2;
    } 
    else{
        head3=head2;
    }
    node*i,*j;
    int tempx;
    for(i=head3;i!=NULL;i=i->next) {
        for (j=i->next;j!= NULL;j=j->next){
            if (i->data>j->data){
                tempx=i->data;
                i->data=j->data;
                j->data=tempx;
            }
        }
    }
    return head3;
}


int main(){
    node*head1=NULL;
    insert(&head1,1);
    insert(&head1,2);
    insert(&head1,4);
    node*head2=NULL;
    insert(&head2,1);
    insert(&head2,3);
    insert(&head2,4);
    display(head1);
    display(head2);
    node*head3=NULL;
    head3=mergeandsort(head1,head2);
    display(head3);
}