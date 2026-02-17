#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void findPairs(Node* head, int target) {
    Node* left = head;  
    Node* right = head;

    // go to last node
    while (right->next)
        right = right->next;

    while (left != right && left->prev != right) {
        int sum = left->data + right->data;

        if (sum == target) {
            cout << "(" << left->data << ", " << right->data << ") ";
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
            left = left->next;
        else
            right = right->prev;
    }
}
