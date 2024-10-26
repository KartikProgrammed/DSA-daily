#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 2458:- height of binary tree after subtree removal queries
// You are given the root of a binary tree with n nodes. Each node is assigned a unique value from 1 to n. You are also given an array queries of size m.
// You have to perform m independent queries on the tree where in the ith query you do the following:
// Remove the subtree rooted at the node with the value queries[i] from the tree. It is guaranteed that queries[i] will not be equal to the value of the root.
// Return an array answer of size m where answer[i] is the height of the tree after performing the ith query.

struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
   };
//Aproach 1:- TLE but my 1st try
//VERY INTRUISIVE but wont pass above 35 TC
class Solution {
public:
    int traverse(int curr,vector<int> &queries,TreeNode* node,int maxtillhere){
        if(node==NULL||node->val==queries[curr]){
            return maxtillhere;
        }
        return max(traverse(curr,queries,node->left,maxtillhere+1),traverse(curr,queries,node->right,maxtillhere+1));
    }
    void recursion(int curr,vector<int> &queries,TreeNode* node,vector<int> &result){
        if(curr>=queries.size()){
            return;
        }
        result.push_back(traverse(curr,queries,node,-1));
        recursion(curr+1,queries,node,result);
    }
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        vector<int> result;
        recursion(0,queries,root,result);
        return result;
    }
};