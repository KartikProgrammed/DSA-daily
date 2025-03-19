#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//3191. Minimum Operations to Make Binary Array Elements Equal to One I
//You are given a binary array nums.You can do the following operation on the array any number of times (possibly zero):
// Choose any 3 consecutive elements from the array and flip all of them.
// Flipping an element means changing its value from 0 to 1, and from 1 to 0.
// Return the minimum number of operations required to make all elements in nums equal to 1. If it is impossible, return -1.


//APPROACH:-
//GREEDY APPROACH
//conv every 0 to 1 and linearly move fwd

//CODE:-
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        int n=nums.size();
        
        for(int j=0;j<=n-3;j++){
            if(nums[j]==0 && j<n-2){
                res++;
                for(int k=j;k<j+3;k++){
                    nums[k]^=1;
                }
            }
        }
        
        if(*min_element(nums.begin(),nums.end())==0){return -1;}
        return res;
    }
};


//236. Lowest Common Ancestor of a Binary Tree
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

//APPROACH:-
//use a recursive function to find the nodes p and q recursively
//return p/q on finding them
//at a point where a node is returned both p,q we get the lca which is returned

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
    TreeNode* recursion(TreeNode* root,TreeNode* p, TreeNode* q){
        if(root==NULL){return NULL;}
        if(root==p || root==q){
            return root;
        }
        TreeNode* r1=recursion(root->left,p,q);
        TreeNode* r2=recursion(root->right,p,q);
        if(!r1&&!r2){
            return NULL;
        }
        else if(!r1||!r2){
            return r1==NULL?r2:r1;
        }
        
        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recursion(root,p,q);
    }
};


//662. Maximum Width of Binary Tree
// Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.

//APPROACH:-
//BFS
//tip: use unsigned int 64 to pass tc since it overflows otherwise

//CODE:-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<pair<uint64_t,TreeNode*>> q;
        uint64_t res=0;
        q.push({0,root});
        while(!q.empty()){
            uint64_t st;
            long long n=q.size();
            uint64_t end;
            for(int i=0;i<n;i++){
                auto it=q.front();
                q.pop();
                if(i==0){
                    st=it.first;
                }
                if(i==n-1){
                    end=it.first;
                }
                uint64_t ind=it.first;
                TreeNode* curr=it.second;
                if(curr->left){
                    q.push({2*ind+1,curr->left});
                }
                if(curr->right){
                    q.push({2*ind+2,curr->right});
                }
            }
            uint64_t curr=end-st+1;
            res=max(curr,res);
        }
        return res;
    }
};