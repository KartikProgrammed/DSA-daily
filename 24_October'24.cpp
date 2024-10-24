#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

//DAILY PROBLEM 951:- Flip Equivalent Binary Trees
// For a binary tree T, we can define a flip operation as follows: choose any node, and swap the left and right child subtrees.
// A binary tree X is flip equivalent to a binary tree Y if and only if we can make X equal to Y after some number of flip operations.
// Given the roots of two binary trees root1 and root2, return true if the two trees are flip equivalent or false otherwise.

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

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL||root2==NULL){
            return false;
        }
        if(root1->val==root2->val){
            bool without=flipEquiv(root1->left,root2->left) && flipEquiv(root1->right,root2->right);
            bool with=flipEquiv(root1->left,root2->right) && flipEquiv(root1->right,root2->left);
            return with || without;
        }
        else{
            return false;
        }
    }
};