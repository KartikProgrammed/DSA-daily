#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
using namespace std;

//Daily Problem 2583:- Kth largest Sum in a Binary Tree

// You are given the root of a binary tree and a positive integer k.
// The level sum in the tree is the sum of the values of the nodes that are on the same level.
// Return the kth largest level sum in the tree (not necessarily distinct). If there are fewer than k levels in the tree, return -1.
// Note that two nodes are on the same level if they have the same distance from the root.

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long sum=0;
            int size=q.size();
            while(size>0){
                TreeNode* node=q.front();
                q.pop();
                sum+= (long long)node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
                size--;
            }
            result.push_back(sum);
        }
        sort(result.begin(),result.end(),greater<long long>());
        if(k>result.size()){
            return -1;
        }
        else{
            return result[k-1];
        }
    }
};