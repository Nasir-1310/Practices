#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> restoreArray(vector<int> shuffled) {
    // Sort the array
    sort(shuffled.begin(), shuffled.end());
    
    // Count occurrences of each number
    map<int, int> count;
    for (int num : shuffled) {
        count[num]++;
    }
    
    vector<int> result;
    
    // Process each number
    for (int num : shuffled) {
        // If this number is already used up, skip it
        if (count[num] == 0) {
            continue;
        }
        
        // This number is part of original array
        result.push_back(num);
        count[num]--;
        
        // Remove its double from the count
        int doubled = num * 2;
        count[doubled]--;
    }
    for(auto it : count) {
        if(it.second != 0) {
            // If any count is not zero, return empty array (invalid case)
            return {};
        }
    }


    return result;
}

// Helper function to print vector
void printVector(vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    // Example 1
    vector<int> shuffled1 = {10, 3, 14, 5, 6, 7};
    cout << "Input: ";
    printVector(shuffled1);
    vector<int> result1 = restoreArray(shuffled1);
    cout << "Output: ";
    printVector(result1);
    cout << endl;
    
    
    return 0;
}