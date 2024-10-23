#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

// //Daily Problem 2641:Cousins in Binary Tree II
// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.
// Two nodes of a binary tree are cousins if they have the same depth with different parents.
// Return the root of the modified tree.
// Note that the depth of a node is the number of edges in the path from the root node to it.

// CODE:-
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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> q;
        int prev=root->val;
        q.push(root);
        while(!q.empty()){
            int curr=0;
            int size=q.size();
            while(size>0){
                TreeNode *node=q.front();
                q.pop();
                int LR=(node->left?node->left->val:0)+(node->right?node->right->val:0);
                if(node->left){
                    node->left->val=LR;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val=LR;
                    q.push(node->right);
                }
                curr+=LR;
                node->val=prev-node->val;
                size--;
            }
            prev=curr;
        }
        return root;
    }
};