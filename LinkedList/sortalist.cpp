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
    ListNode*findmiddle(ListNode*head){
        ListNode*fast=head->next;
        ListNode*slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode*mergeTwoLists(ListNode*list1,ListNode*list2){
        ListNode*dummynode=new ListNode(-1);
        ListNode*temp=dummynode;
        while(list1!=nullptr&&list2!=nullptr){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1) temp->next=list1;
        else temp->next=list2;

        return dummynode->next;
    }
    ListNode*sortList(ListNode*head){
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode*middle=findmiddle(head);
        ListNode*righthead=middle->next;
        middle->next=NULL;
        ListNode*lefthead=head;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return mergeTwoLists(lefthead,righthead);
    }

};

int main() {
    Solution solution;
    ListNode* head = nullptr;
    solution.append(head, 5);
    solution.append(head, 2);
    solution.append(head, 4);
    solution.append(head, 3);
    solution.display(head);
    head=solution.sortList(head);
    solution.display(head);
    return 0;
}
