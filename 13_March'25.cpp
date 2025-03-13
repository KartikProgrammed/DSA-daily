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

// 3356. Zero Array Transformation II
// You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].

// Each queries[i] represents the following action on nums:

// Decrement the value at each index in the range [li, ri] in nums by at most vali.
// The amount by which each value is decremented can be chosen independently for each index.
// A Zero Array is an array with all its elements equal to 0.

// Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

//APPROACH 1(TLE):-

//CODE
class Solution {
public:
    void reduce(vector<int>&nums,int l,int r,int val){
        for(int i=l;i<=r;i++){
            if(nums[i]>=val)
                nums[i]-=val;
            else
                nums[i]=0;
        }
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        if(*max_element(nums.begin(),nums.end())==0){
                return 0;
            }
        for(int i=0;i<queries.size();i++){
            reduce(nums,queries[i][0],queries[i][1],queries[i][2]);
            if(*max_element(nums.begin(),nums.end())==0){
                return i+1;
            }
        }
        return -1;
    }
};

//APPROACH 2:- 
//DIFFERENCE ARRAY

//CODE:-
/*
By   :: savetrees
Used :: Difference Array & Binary Search
*/
class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size(),q=queries.size();
        if(count(nums.begin(),nums.end(),0)==n)return 0; 
        auto check=[&](int mid){
            vector<int>diff(n+1,0),cur(nums);
            for(int i=0;i<mid;i++){
                int l=queries[i][0],r=queries[i][1],val=queries[i][2];
                diff[l]-=val;
                diff[r+1]+=val;
            }
            int sum=0,zeroCount=0;
            for(int i=0;i<n;i++){
                sum+=diff[i];
                cur[i]=max(0,cur[i]+sum);
                if(cur[i]==0)zeroCount++;
            }
            return zeroCount==n;
        };
        int lo=1,hi=q,ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid)){ans=mid;hi=mid-1;}
            else lo=mid+1;
        }
        return ans;
    }
};


// 110. Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced.

//APPROACH
//find height of each nodes left and right return -1 if unbalanced

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
        int recursion(TreeNode *root){
            if(root==NULL){
                return 0;
            }
            int op1=recursion(root->left);
            if(op1==-1)
                return -1;
            int op2=recursion(root->right);
            if(op2==-1)
                return -1;
            
            if(abs(op1-op2)>1)
                return -1;
            return max(op1,op2)+1;
        }
        bool isBalanced(TreeNode* root) {
            int res= recursion(root);
            if(res==-1){
                return false;
            }
            return true;
        }
    };