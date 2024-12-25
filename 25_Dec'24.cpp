#include <bits/stdc++.h>
using namespace std;

//515. Find Largest Value in Each Tree Row
// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

//APPROACH:-
//since we need to find the max element in each ROW, we instantly think of BFS..
//We use BFS to find all elements row wise store them in an arr named currArr 
//the max of this currArr would be pushed into the result arr which is at last returned as the output

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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> result;
        if(root==NULL){
            return result;
        }
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> currArr;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                currArr.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
                q.pop();
            }
            int maxi=*max_element(currArr.begin(),currArr.end());
            result.push_back(maxi);
        }
        return result;
    }
};