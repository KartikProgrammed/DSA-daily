#include <bits/stdc++.h>
using namespace std;


//2471. Minimum Number of Operations to Sort a Binary Tree by Level
//You are given the root of a binary tree with unique values.
// In one operation, you can choose any two nodes at the same level and swap their values.
// Return the minimum number of operations needed to make the values at each level sorted in a strictly increasing order.
// The level of a node is the number of edges along the path between it and the root node.

//CODE:-
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> helper;
        helper.push(root);
        int swaps=0;
        while(!helper.empty()){
            vector<int> helper2;
            int n=helper.size();
            for(int i=0;i<n;i++){
                if(helper.front()->left!=NULL){
                    helper2.push_back(helper.front()->left->val);
                    helper.push(helper.front()->left);
                }
                if(helper.front()->right!=NULL){
                    helper.push(helper.front()->right);
                    helper2.push_back(helper.front()->right->val);
                }
                helper.pop();
            }
            vector<int> sorted_helper2 = helper2;
            sort(sorted_helper2.begin(), sorted_helper2.end());
            unordered_map<int, int> index_map;

            for (int i = 0; i < helper2.size(); i++) {
                index_map[helper2[i]] = i;
            }

            for (int i = 0; i < helper2.size(); i++) {
                while (helper2[i] != sorted_helper2[i]) {
                    swaps++;
                    int correct_index = index_map[sorted_helper2[i]];

                    index_map[helper2[i]] = correct_index;
                    index_map[helper2[correct_index]] = i;

                    swap(helper2[i], helper2[correct_index]);
                }
            }
        }
        return swaps;
    }
};

//907. Sum of Subarray Minimums
// Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

//approach:-
//finding minimum element after and before each element and calculating the total as required (take mod 1e9+7 as said by the question at the end)
//CODE:
class Solution {
public:
    const int MOD = 1e9 + 7;

    int sumSubarrayMins(vector<int>& arr) {
        stack<int> helper;
        int n=arr.size();
        int tot=0;
        vector<int> nextSmaller(n,n);
        vector<int> prevSmaller(n,-1);
        for(int i=0;i<arr.size();i++){
            while(!helper.empty() && arr[helper.top()]>arr[i]){
                helper.pop();
            }
            if(!helper.empty()){
                prevSmaller[i]=helper.top();
            }
            helper.push(i);
        }
        while(!helper.empty()){
            helper.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!helper.empty() && arr[helper.top()]>=arr[i]){
                helper.pop();
            }
            if(!helper.empty()){
                nextSmaller[i]=helper.top();
            }
            helper.push(i);
        }
        for(int i=0;i<n;i++){
            long long left =i -  prevSmaller[i];
            long long right = nextSmaller[i] - i;
            tot = (tot + arr[i] * left * right) % MOD;
        }
        return tot;
    }
};
