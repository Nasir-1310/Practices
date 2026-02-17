// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};

Node* create_list(int arr[], int n){
    if(n==0)
        return nullptr;
    
    
    Node* temp=new Node();
    temp->data=arr[0];
    temp->next=nullptr;
    
   Node* head=temp;
   
    for(int i=1;i<n;i++){
        Node* newNode=new Node();
        newNode->data=arr[i];
        newNode->next=nullptr;
        temp->next=newNode;
        temp=newNode;
        
    }
    return head;
}

void print_linked_list(string msg,Node* head){
     Node* temp=head;
     cout<<msg<<": ";
    while(temp!=nullptr){
        cout<<temp->data;
        if(temp->next)
            cout<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

Node* find_middle_element(Node* head){
    Node* fast;
    Node* slow;
    fast=head;
    slow=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
       
    }
    return slow;
}


int main() {
    int arr[]={1,2,3,4,5,10,24,30};
    int size=sizeof(arr)/sizeof(arr[0]);
    Node* head=create_list(arr,size);
    
    print_linked_list("Created Link List",head);
    
    Node* middle=find_middle_element(head);
   cout<<"MIddle element is: "<<middle->data<<" ";
   
    return 0;
}