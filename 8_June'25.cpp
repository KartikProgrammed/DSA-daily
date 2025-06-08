#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//421. Maximum XOR of Two Numbers in an Array
// Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.


//Approach:
// Use a trie to store the binary representation of numbers and find the maximum XOR pair.

// CODE:
struct Node{
    Node* limits[2];

    bool hasElement(int curr){
        return limits[curr]!=NULL;
    }

    void put(int curr,Node* temp){
        limits[curr]=temp;
    }
    Node* get(int curr){
        return limits[curr];
    }

};

class Trie{
private:
    Node *root;

public:
    Trie(){
        root=new Node();
    }
    void insertEle(int num){
        Node* temp=root;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(!temp->hasElement(bit)){
                temp->put(bit,new Node());
            }
            temp=temp->get(bit);
        }
    }

    int getMax(int num){
        Node* node=root;
        int maxnum=0;
        for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(node->hasElement(1-bit)){
                maxnum=maxnum|(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxnum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();i++){
            trie.insertEle(nums[i]);
        }
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,trie.getMax(nums[i]));
        }
        return maxi;
    }
};