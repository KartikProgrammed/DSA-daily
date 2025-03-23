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

// 1976. Number of Ways to Arrive at Destination
// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

//APPROACH:-
//DIJKSTRA

//CODE:-
class Solution {
public:
    typedef pair<long long,int> P;
    int M=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> graph;
        priority_queue<P,vector<P>,greater<P>> pq;
        vector<long long> result(n,LLONG_MAX);
        vector<int> pathcount(n,0);
        for(int i=0;i<roads.size();i++){
            int curr=roads[i][0];
            int dest=roads[i][1];
            int time=roads[i][2];

            graph[curr].push_back({dest,time});
            graph[dest].push_back({curr,time});
        }
        result[0]=0;
        pathcount[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long currtime=pq.top().first;
            int currnode=pq.top().second;
            pq.pop();

            for(auto& it:graph[currnode]){
                int ngbr=it.first;
                long long newtime=it.second;
                if(currtime+newtime<result[ngbr]){
                    result[ngbr]=currtime+newtime;
                    pq.push({result[ngbr],ngbr});
                    pathcount[ngbr]=pathcount[currnode];
                }
                else if(currtime+newtime==result[ngbr]){
                    pathcount[ngbr]=(pathcount[ngbr]+pathcount[currnode]) % M;
                }
            }
        }
        return pathcount[n-1];
    }
};


//700. Search in a Binary Search Tree
// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.


//APPROACH:-
//BASICS

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL || root->val==val){
            return root;
        }
        if(root->val < val){
            return searchBST(root->right,val);
        }
        return searchBST(root->left,val);
        
    }
};


//701. Insert into a Binary Search Tree
//You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

//APPROACH:-
//BASICS OF BST

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
    void recursion(TreeNode* root,int val){
        if(root->val<val){
            if(root->right==NULL){
                TreeNode* temp=new TreeNode(val);
                root->right=temp;
                return;
            }
            recursion(root->right,val);
        }
        else if(root->val>val){
            if(root->left==NULL){
                TreeNode* temp=new TreeNode(val);
                root->left=temp;
                return;
            }
            recursion(root->left,val);
        }
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp=new TreeNode(val);
            return temp;
        }
        TreeNode* temp=root;
        recursion(root,val);
        return temp;
    }
};


//450. Delete Node in a BST
//Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.


//approach:-
//connect target node's left node to the node's right's leftmost node

//code:-
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
    TreeNode* recursion(TreeNode* root,int val){
        if(root==NULL || (root->left!=NULL&&root->left->val==val) || (root->right!=NULL&&root->right->val==val)){
            return root;
        }
        if(root->val>val){
            return recursion(root->left,val);
        }
        return recursion(root->right,val);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(root->val==key){
            TreeNode* root2=root->right;
            if(root->right==NULL && root->left==NULL){
                return NULL;
            }
            else if(root->left==NULL){
                return root->right;
            }
            else if(root->right==NULL){
                return root->left;
            }
            else{
                TreeNode* tempr=root->right;
                TreeNode* templ=root->left;
                while(tempr->left){
                    tempr=tempr->left;
                }
                tempr->left=templ;
                return root2;
            }
        }
        TreeNode* parent=recursion(root,key);
        if(parent==NULL){
            return root;
        }
        if (parent->left != NULL && parent->left->val == key) {
            TreeNode* nodeToDelete = parent->left;
            
            if (nodeToDelete->left == NULL) { 
                parent->left = nodeToDelete->right;
            } 
            else if (nodeToDelete->right == NULL) {
                parent->left = nodeToDelete->left;
            } 
            else { 
                TreeNode* temp = nodeToDelete->right;
                while (temp->left) { 
                    temp = temp->left;
                }
                temp->left = nodeToDelete->left;
                parent->left = nodeToDelete->right;
            }
        } 
        else if (parent->right != NULL && parent->right->val == key) {
            TreeNode* nodeToDelete = parent->right;

            if (nodeToDelete->left == NULL) { 
                parent->right = nodeToDelete->right;
            } 
            else if (nodeToDelete->right == NULL) { 
                parent->right = nodeToDelete->left;
            } 
            else {
                TreeNode* temp = nodeToDelete->right;
                while (temp->left) { 
                    temp = temp->left;
                }
                temp->left = nodeToDelete->left;
                parent->right = nodeToDelete->right;
            }
        }
        return root;
    }
};


//230. Kth Smallest Element in a BST
//Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

//APPROACH:-
//priority queue

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
    void input(TreeNode* root,priority_queue<int,vector<int>,greater<int>>& pq){
        if(root==NULL){
            return;
        }
        pq.push(root->val);
        if(root->left){
            input(root->left,pq);
        }
        if(root->right){
            input(root->right,pq);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        input(root,pq);
        while(!pq.empty()&&k>1){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};