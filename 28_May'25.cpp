#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

// 3372. Maximize the Number of Target Nodes After Connecting Trees I
// There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
// Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
// Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
// Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

// Approach:
//Use DFS in 2 parts
//for the first part,run the dfs on the first tree to find the number of nodes target to each node in the first tree.
//for the second part,run the dfs on the second tree to find the number of nodes target to each node in the second tree.(use k-1 as the limit for the second tree, since when we connect the first tree's node to the second tree's node, we will have one less edge to traverse) 
//then just add the max of 2nd part to the first part for each node in the first tree.

// CODE:
class Solution {
public:
    int dfs(vector<vector<int>> &adj_list,int curr,int k,vector<bool> &visited){
        if(k<0){
            return 0;
        }
        int res=1;
        visited[curr]=true;
        for(int neighbours:adj_list[curr]){
            if(!visited[neighbours]){
                res+=dfs(adj_list,neighbours,k-1,visited);
            }
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;

        vector<vector<int>> adj_list1(n);
        vector<vector<int>> adj_list2(m);
    
        for(int i=0;i<edges1.size();i++){
            int first=edges1[i][0];
            int second=edges1[i][1];
            adj_list1[first].push_back(second);
            adj_list1[second].push_back(first);
        }
        for(int i=0;i<edges2.size();i++){
            int first=edges2[i][0];
            int second=edges2[i][1];
            adj_list2[first].push_back(second);
            adj_list2[second].push_back(first);
        }
        
        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            vector<bool> visited(m,false);
            maxi=max(maxi,dfs(adj_list2,i,k-1,visited));
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            res[i]=maxi+dfs(adj_list1,i,k,visited);
        }
        return res;
    }
};