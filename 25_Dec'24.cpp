#include <bits/stdc++.h>
using namespace std;

//515. Find Largest Value in Each Tree Row
// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

//APPROACH:-
//since we need to find the max element in each ROW, we instantly think of BFS..
//We use BFS to find all elements row wise store them in an arr named currArr 
//the max of this currArr would be pushed into the result arr which is at last returned as the output

//CODE:- (Beats 100%)
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

//735. Asteroid Collision
// We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.


//APPROACH:-
//use a monotonic stack, the -ve asteroids in the start shall be ignored since they pave away
//push the starting asteroids 
//if theres an asteroid with -ve value and our stack has +ve on top
//their abs are computed and if the -ve asteroid is destroyed we compute the flag as true preventing its push to the stack

//CODE:- (Beats 100%)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> result;
        for(int i=0;i<asteroids.size();i++){
            bool flag=false;
            while(!st.empty() && asteroids[st.top()]>0 && asteroids[i]<0){
                int first=asteroids[st.top()];
                int second=asteroids[i];
                if(abs(first)>abs(second)){
                    flag=true;
                    break;
                }
                else if(abs(first)==abs(second)){
                    st.pop();
                    flag=true;
                    break;
                }
                else if(abs(first)<abs(second)){
                    st.pop();
                }
            }
            if(!flag){
                st.push(i);
            }

        }
        while(!st.empty()){
            result.push_back(asteroids[st.top()]);
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};
