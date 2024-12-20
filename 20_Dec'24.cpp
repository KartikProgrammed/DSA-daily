#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//2415. Reverse Odd Levels of Binary Tree
//Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.
// For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
// Return the root of the reversed tree.
// A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.
// The level of a node is the number of edges along the path between it and the root node.

//CODE:-

// Definition for a binary tree node.
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
    void helper(TreeNode* leftN,TreeNode* rightN,int currdepth){
        if(leftN==NULL || rightN==NULL){
            return ;
        }
        if(currdepth%2==1){
            int temp=leftN->val;
            leftN->val=rightN->val;
            rightN->val=temp;
        }
        helper(leftN->left,rightN->right,currdepth+1);
        helper(leftN->right,rightN->left,currdepth+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left,root->right,1);
        return root;
    }
};