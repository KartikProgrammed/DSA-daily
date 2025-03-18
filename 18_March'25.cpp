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


//987. Vertical Order Traversal of a Binary Tree
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.
// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).
// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.
// Return the vertical order traversal of the binary tree.

//APPROACH:-
//BFS

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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        vector<vector<int>> res;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root,{0,0}});
        while(!q.empty()){
            auto [node,pos]=q.front();
            q.pop();
            int col=pos.first;
            int row=pos.second;
            nodes[col][row].insert(node->val);
            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }
        for (auto &[col, rows] : nodes) {
            vector<int> colNodes;
            for (auto &[row, values] : rows) {
                colNodes.insert(colNodes.end(), values.begin(), values.end());
            }
            res.push_back(colNodes);
        }
        return res;
    }
};


//199. Binary Tree Right Side View 
// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

//APPROACH:-
//BFS

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
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        vector<int> res;
        if(root==NULL){
            return res;
        }
        q.push({0,root});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int ind=it.first;
            TreeNode *node=it.second;
            if(ind+1>res.size()){
                res.push_back(node->val);
            }
            if(node->right){
                q.push({ind+1,node->right});
            }
            if(node->left){
                q.push({ind+1,node->left});
            }
        }
        return res;
    }
};



//101. Symmetric Tree
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

//APPROACH
//RECURSION

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
    bool recursion(TreeNode* t1,TreeNode *t2){
        if(!t1&&!t2)
            return true;
        if(!t1||!t2){
            return false;
        }
        bool op1=recursion(t1->left,t2->right);
        bool op2=recursion(t1->right,t2->left);
        return (t1->val==t2->val)&&op1&&op2;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return recursion(root->left,root->right);
    }
};