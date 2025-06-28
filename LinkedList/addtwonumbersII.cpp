#include <iostream>
using namespace std;

// ListNode class representing each node in the linked list
class ListNode {
public:
    int val;      // Data value to store
    ListNode* next; // Pointer to the next node

    // Constructor to initialize node
    ListNode(int value) {
        val = value;
        next = nullptr;
    }
};

// Solution class to handle the linked list operations
class Solution {
public:
    // Function to add a new node at the end of the linked list
    void append(ListNode*& head, int value) {
        ListNode* newNode = new ListNode(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to display all elements in the linked list
    void display(ListNode* head) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        ListNode* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ListNode*reverse(ListNode*head){
        ListNode*curr=head;
        ListNode*next=nullptr;
        ListNode*prev=nullptr;
        while(curr!=nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode*addtwonumbers(ListNode*head1,ListNode*head2){
        ListNode*t1=reverse(head1);
        ListNode*t2=reverse(head2);
        ListNode*dummy=new ListNode(-1);
        ListNode*curr=dummy;
        int carry=0;
        while(t1!=nullptr||t2!=nullptr){
            int sum=carry;
            if(t1) sum+=t1->val;
            if(t2) sum+=t2->val;
            ListNode*newNode=new ListNode(sum%10);
            carry=sum/10;
            curr->next=newNode;
            curr=curr->next;
            if(t1) t1=t1->next;
            if(t2) t2=t2->next;
        }
        if(carry){
            ListNode*lastNode=new ListNode(carry);
            curr->next=lastNode;
        }
        ListNode*final=dummy->next;
        return reverse(final);
    }
};

int main() {
    Solution solution;
    ListNode* head1 = nullptr;
    solution.append(head1, 7);
    solution.append(head1, 2);
    solution.append(head1, 4);
    solution.append(head1, 3);
    solution.display(head1);
    ListNode* head2 = nullptr;
    solution.append(head2, 5);
    solution.append(head2, 6);
    solution.append(head2, 4);
    solution.display(head2);
    ListNode*head3=nullptr;
    head3=solution.addtwonumbers(head1,head2);
    solution.display(head3);
    return 0;
}
