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

// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

//APPROACH:-
//curr root will always be start of preorder

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
    TreeNode* Recursion(vector<int> &preorder,int prest,int prend,vector<int>& inorder,int inst,int inend,unordered_map<int,int> &map){
        if(inst>inend||prest>prend){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prest]);
        int ind=map[root->val];
        int numst=ind-inst;

        root->left=Recursion(preorder,prest+1,prest+numst,inorder,inst,ind-1,map);
        root->right=Recursion(preorder,prest+numst+1,prend,inorder,ind+1,inend,map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        TreeNode* root=Recursion(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,map);
        return root;
    }
};


//3108. Minimum Cost Walk in Weighted Graph
// There is an undirected weighted graph with n vertices labeled from 0 to n - 1.
// You are given the integer n and an array edges, where edges[i] = [ui, vi, wi] indicates that there is an edge between vertices ui and vi with a weight of wi.
// A walk on a graph is a sequence of vertices and edges. The walk starts and ends with a vertex, and each edge connects the vertex that comes before it and the vertex that comes after it. It's important to note that a walk may visit the same edge or vertex more than once.
// The cost of a walk starting at node u and ending at node v is defined as the bitwise AND of the weights of the edges traversed during the walk. In other words, if the sequence of edge weights encountered during the walk is w0, w1, w2, ..., wk, then the cost is calculated as w0 & w1 & w2 & ... & wk, where & denotes the bitwise AND operator.
// You are also given a 2D array query, where query[i] = [si, ti]. For each query, you need to find the minimum cost of the walk starting at vertex si and ending at vertex ti. If there exists no such walk, the answer is -1.
// Return the array answer, where answer[i] denotes the minimum cost of a walk for query i.

//APPROACH:-
// DSU

//CODE:-
class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x] == x)
            return x;
        
        return parent[x] = find(parent[x]);
    }
    void Union(int x, int y) {
        parent[y] = x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        
        parent.resize(n);
        vector<int> cost(n);  
	    for(int i = 0; i<n; i++) {
	        parent[i] = i;
            cost[i]   = -1;
        }
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            

            if (parent_u != parent_v) {
                cost[parent_u] &= cost[parent_v];
                Union(parent_u, parent_v);
            }

            cost[parent_u] &= w;
        }
        
        vector<int> res;
        for (auto &q : query) {
            int s = q[0];
            int t = q[1];
            
            int p1 = find(s);
            int p2 = find(t);
            
            if (s == t)
                res.push_back(0);
            else if (p1 != p2)
                res.push_back(-1);
            else
                res.push_back(cost[p1]);
        }
        return res;
    }
};

// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

//APPROACH:-
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
    TreeNode* Recursion(vector<int>& inorder,int inst,int inend,vector<int>& postorder,int prest,int prend,unordered_map<int,int> &map){
        if(inst>inend||prest>prend){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[prend]);
        int ind=map[root->val];
        int numst=ind-inst;

        root->left=Recursion(inorder,inst,ind-1,postorder,prest,prest+numst-1,map);
        root->right=Recursion(inorder,ind+1,inend,postorder,prest+numst,prend-1,map);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> map;
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        TreeNode* root=Recursion(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,map);
        return root;
    }
};


//297. Serialize and Deserialize Binary Tree
// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.
// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.

//APPROACH:-
//multiple queues used

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
class Codec {
public:
    int maxheight(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left=maxheight(root->left);
        int right=maxheight(root->right);
        return max(left,right)+1;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        int h=maxheight(root);
        string res="";
        queue<TreeNode*> q;
        if(root==NULL){
            return "n";
        }
        q.push(root);
        res+=to_string(root->val);
        int curr=1;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    res+=","+to_string(node->left->val);
                }
                else if(!node->left && curr<h){
                    res+=",n";
                }
                if(node->right){
                    q.push(node->right);
                    res+=","+to_string(node->right->val);
                }
                else if(!node->right && curr<h){
                    res+=",n";
                }
            }
            curr++;
        }
        // if (!res.empty()) res.pop_back();
        return res;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "n") return NULL;  // Edge case: empty tree

        stringstream ss(data);
        string val;
        getline(ss, val, ',');

        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Process left child
            if (getline(ss, val, ',')) {
                if (val != "n") {
                    node->left = new TreeNode(stoi(val));
                    q.push(node->left);
                }
            }

            // Process right child
            if (getline(ss, val, ',')) {
                if (val != "n") {
                    node->right = new TreeNode(stoi(val));
                    q.push(node->right);
                }
            }
        }

        return root;
    }
};
