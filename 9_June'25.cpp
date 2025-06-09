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

//1707. Maximum XOR With an Element From Array
// You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].
// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

//Approach:
// Use a trie to store the binary representation of numbers and find the maximum XOR for each query.

// CODE:
struct Node{
    
    Node* limits[2];

    bool hasElement(int curr){
        return limits[curr]!=NULL;
    }

    void put(int curr,Node* node){
        limits[curr]=node;
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

    void insertEle(int n){
        Node *node=root;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(!node->hasElement(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }

    int maxNum(int n){
        Node* node=root;
        int maxnum=0;
        for(int i=31;i>=0;i--){
            int bit=(n>>i)&1;
            if(node->hasElement(1-bit)){
                maxnum|=(1<<i);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int,pair<int,int>>> offlineQueries;
        vector<int> res(queries.size(),0);
        int ind=0;
        sort(nums.begin(), nums.end()); 
        for(auto it:queries){
            offlineQueries.push_back({it[1],{it[0],ind++}});
        }
        sort(offlineQueries.begin(),offlineQueries.end());

        int i=0;
        int n=nums.size();
        Trie trie;
        for(auto it:offlineQueries){
            while(i<n && nums[i]<=it.first){
                trie.insertEle(nums[i]);
                i++;
            }
            if(i!=0){
                res[it.second.second]=trie.maxNum(it.second.first);
            }
            else{
                res[it.second.second]=-1;
            }
        }
        return res;
    }
};