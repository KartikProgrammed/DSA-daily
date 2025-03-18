#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//2401. Longest Nice Subarray
// You are given an array nums consisting of positive integers.
// We call a subarray of nums nice if the bitwise AND of every pair of elements that are in different positions in the subarray is equal to 0.
// Return the length of the longest nice subarray.
// A subarray is a contiguous part of an array.
// Note that subarrays of length 1 are always considered nice.

//APPROACH:-
//BRUTE FORCE

//CODE:-
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res=1;
        for(int i=0;i<nums.size();i++){
            int curr=1;
            for(int j=i+1;j<nums.size();j++){
                bool isNice = true;                
                for (int k = i; k < j; k++) {
                    if ((nums[k] & nums[j]) != 0) {
                        isNice = false;
                        break;
                    }
                }
                if (isNice) 
                    curr++;
                else
                    break;
            }
            res=max(curr,res);
        }
        return res;
    }
};


// 103. Binary Tree Zigzag Level Order Traversal
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

//APPROACH:-
//RECURSION

//CODE:-
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void recursion(vector<vector<int>> &res,TreeNode *root,int level){
        if(root==NULL){
            return ;
        }
        if (level >= res.size())
            res.push_back({});

        if (level % 2 == 0)
            res[level].push_back(root->val);
        else
            res[level].insert(res[level].begin(), root->val); 
        recursion(res,root->left,level+1);
        recursion(res,root->right,level+1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        recursion(res,root,0);
        return res;
    }
};