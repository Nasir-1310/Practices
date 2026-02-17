class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int,int>> ans;
        
        Node* left = head;
        
        /// traverse to the end of the list
        while(head!= nullptr && head->next!=nullptr){
            head = head->next;
        }
        Node* right = head;
        
        while(left!= right && left->prev != right){
            if(left->data + right->data == target){
                ans.push_back(make_pair(left->data, right->data));
                left = left->next;
                right = right->prev;
            }
            else if(left->data + right->data > target){
                right = right->prev;
            }else{
                left = left->next;
            }
        }
        
        return ans;    
        
    }
};


