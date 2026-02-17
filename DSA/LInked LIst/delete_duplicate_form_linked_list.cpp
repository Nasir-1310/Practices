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

Node* remove_duplicate_form_list(Node* head){
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        if(temp->data==temp->next->data){
            //duplicate found
            Node* dup=temp->next;
            temp->next=temp->next->next;
            delete dup;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

int main() {
    int arr[]={1,2,2,3,4,4,5,7,7,7,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    Node* head=create_list(arr,size);
    
    print_linked_list("Created Link List",head);
    
    head=remove_duplicate_form_list(head);
    print_linked_list("After Removing duplicate",head);
    

    return 0;
}