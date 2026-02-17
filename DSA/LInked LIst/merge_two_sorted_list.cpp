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

Node* merge_sorted_link_list(Node* l1, Node*l2){
    if(l1==nullptr) return l2;
    if(l2==nullptr) return l1;
    //choose haed and forward node
    Node* front=nullptr;
    Node* head=nullptr;
    if(l1->data<l2->data){
        head=l1;
        front=l1;
        l1=l1->next;
    }
    else{
        head=l2;
        front=l2;
        l2=l2->next;
    }
    while(l1!=nullptr && l2!=nullptr){
        if(l1->data<l2->data){
            front->next=l1;
            front=l1;
            l1=l1->next;
        }
        else{
            front->next=l2;
            front=l2;
            l2=l2->next;
        }
    }
    if(l1!=nullptr)
        front->next=l1;
    if(l2!=nullptr)
        front->next=l2;
    
    return head;
}

int main() {
    int arr[]={1,2,3,4,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    Node* head=create_list(arr,size);
    print_linked_list("Created Link List",head);
    
    
    int arr2[]={2,3,4,5,7,10};
    int size2=sizeof(arr2)/sizeof(arr2[0]);
    Node* head2=create_list(arr2,size2);
    print_linked_list("Created Link List2",head2);
    
    Node* merged=merge_sorted_link_list(head,head2);
    print_linked_list("Merged Link List",merged);
    
    
  
    

    return 0;
}