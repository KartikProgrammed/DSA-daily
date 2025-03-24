#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//3169. Count Days Without Meetings
// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
// Return the count of days when the employee is available for work but no meetings are scheduled.
// Note: The meetings may overlap.


//Approach:-
//BRUTE FORCE(TLE)

//CODE:-
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int> slots(days+1,0);
        for(int i=0;i<meetings.size();i++){
            int start=meetings[i][0];
            int end=meetings[i][1];
            for(int j=start;j<=end;j++){
                slots[j]++;
            }
        }
        int res=0;
        for(int i=1;i<=days;i++){
            if(slots[i]==0){
                res++;
            }
        }
        return res;
    }
};

//APPROACH:-
//merge overlap intervals and add busydays 
//subtract from tot days

//CODE:-
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> slots;
        int st=meetings[0][0];
        int end=meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]<=end){
                end=max(meetings[i][1],end);
            }
            else{
                slots.push_back({st,end});
                end=meetings[i][1];
                st=meetings[i][0];
            }
        }
        slots.push_back({st,end});
        int res=0;
        for(int i=0;i<slots.size();i++){
            res+=slots[i][1]-slots[i][0]+1;
        }
        return days-res;
    }
};


//98. Validate Binary Search Tree
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

//APPROACH:-
//BST'S inorder is always sorted

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
    void inordertrav(TreeNode* root,vector<int> &inorder){
        if(root!=NULL){
            inordertrav(root->left,inorder);
            inorder.push_back(root->val);
            inordertrav(root->right,inorder);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        inordertrav(root,inorder);
        for(int i=1;i<inorder.size();i++){
            if(inorder[i]<=inorder[i-1]){
                return false;
            }
        }
        return true;
    }
};


//235. Lowest Common Ancestor of a Binary Search Tree
// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.
// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

//APPROACH:-
//BST BASICS

//CODE:-
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL){
            return NULL;
        }
        if(p->val < root->val &&root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if(q->val>root->val&&root->val<p->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
    }
};


//1008. Construct Binary Search Tree from Preorder Traversal
//Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
// It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
// A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
// A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.


//APPROACH:-
//the root is the 1st element of the tree
//insert all other elements according to bst rules

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
    void insertBST(TreeNode* root,int val){
        TreeNode* ins=new TreeNode(val);
        TreeNode* temp=root;
        TreeNode* prev=temp;
        while(temp!=NULL){
            if(temp->val < val){
                prev=temp;
                temp=temp->right;
            }
            else{
                prev=temp;
                temp=temp->left;
            }
        }
        if(prev->val < val){
            prev->right=ins;
        }
        else{
            prev->left=ins;
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++){
            insertBST(root,preorder[i]);
        }
        return root;
    }
};