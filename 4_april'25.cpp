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

// 1123. Lowest Common Ancestor of Deepest Leaves
// Given the root of a binary tree, return the lowest common ancestor of its deepest leaves.
// Recall that:
// The node of a binary tree is a leaf if and only if it has no children
// The depth of the root of the tree is 0. if the depth of a node is d, the depth of each of its children is d + 1.
// The lowest common ancestor of a set S of nodes, is the node A with the largest depth such that every node in S is in the subtree with root A.

//APPROACH:-
//First find maxheight
//then find the ancestor based on if 2 nodes are at maxh-1 or 1

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
    int maxheight(TreeNode* root,int depth){
        
        if(root==NULL){
            return depth;
        }
        int left=maxheight(root->left,depth+1);
        int right=maxheight(root->right,depth+1);
        return max(left,right);
    }
    TreeNode* parent(TreeNode* root,int curr,int maxh){
        if(root==NULL){
            return NULL;
        }
        
        if(curr==maxh){
          return root;  
        }
        TreeNode* left = parent(root->left, curr + 1, maxh);
        TreeNode* right= parent(root->right, curr + 1, maxh);
        if(left&&right){
            return root;
        }
        return left==NULL?right:left;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int maxh=maxheight(root,0);
        return parent(root,0,maxh-1);
    }
};

//721. Accounts Merge
// Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
// Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

//APPROACH:-
//DISJOINT SETS

//CODE:-
class DisjointSet{
public:
vector<int> parent;
vector<double> size;

    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findUPar(int u){
        if(parent[u]==u){
            return parent[u];
        }
        return parent[u]=findUPar(parent[u]);
    }
    void unionBySize(int u,int v){
        int uv=findUPar(v);
        int uu=findUPar(u);
        if(uu==uv){
            return;
        }
        if(size[uv]<size[uu]){
            parent[uv]=uu;
            size[uu]+=size[uv];
        }
        else{
            parent[uu]=uv;
            size[uv]+=size[uu];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> map;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(map.find(accounts[i][j])==map.end()){
                    map[accounts[i][j]]=i;
                }
                else{
                    ds.unionBySize(i,map[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mails(n);
        for(auto it:map){
            string mail=it.first;
            int node=it.second;
            int realnode=ds.findUPar(node);
            mails[realnode].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i=0;i<n;i++){
            if(mails[i].size()==0){
                continue;
            }
            sort(mails[i].begin(),mails[i].end());
            vector<string> temp;
            string name=accounts[i][0];
            temp.push_back(name);
            for(auto it:mails[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};

//827. Making A Large Island
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
// Return the size of the largest island in grid after applying this operation.
// An island is a 4-directionally connected group of 1s.

//APPROACH:-
//DISJOINT SET

//CODE:-

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<vector<int>> idgrid(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                idgrid[i][j]=n*i+j;
            }
        }
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int oldid=i*n+j;
                    for(int k=0;k<4;k++){
                        int newr=i+dx[k];
                        int newc=j+dy[k];
                        int newid=newr*n+newc;
                        if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                            ds.unionBySize(oldid,newid);
                        }
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int curr=1;
                    unordered_set<int> uniqueParents;
                    for(int k=0;k<4;k++){
                        int newr=i+dx[k];
                        int newc=j+dy[k];
                        int newid=newr*n+newc;
                        if(newr>=0 && newr<n && newc>=0 && newc<n && grid[newr][newc]==1){
                            int par=ds.findUPar(newid);
                            uniqueParents.insert(par);
                        }
                    }
                    for (int p : uniqueParents) {
                        curr += ds.size[p];
                    }
                    res=max(res,curr);
                }
            }
        }
        return res==0?n*n:res;
    }
};