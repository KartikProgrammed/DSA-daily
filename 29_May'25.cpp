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

// 3373. Maximize the Number of Target Nodes After Connecting Trees II
// There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
// You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
// Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
// Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
// Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.
 

class Solution {
public:
    int dfs(vector<vector<int>> &adj_list,int curr,int k,vector<bool> &visited){
        int res=1;
        visited[curr]=true;
        if(k%2!=0){
            res=0;
        }
        for(int neighbour:adj_list[curr]){
            if(!visited[neighbour]){
                res+=dfs(adj_list,neighbour,k+1,visited);
            }
        }
        return res;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1;
        int m=edges2.size()+1;
        vector<vector<int>> adj_list1(n);
        vector<vector<int>> adj_list2(m);

        for(auto &it:edges1){
            adj_list1[it[0]].push_back(it[1]);
            adj_list1[it[1]].push_back(it[0]);
        }
        for(auto &it:edges2){
            adj_list2[it[0]].push_back(it[1]);
            adj_list2[it[1]].push_back(it[0]);
        }

        int maxi=INT_MIN;
        for(int i=0;i<m;i++){
            vector<bool> visited(m,false);
            maxi=max(maxi,dfs(adj_list2,i,1,visited));
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            vector<bool> visited(n,false);
            res[i]=maxi+dfs(adj_list1,i,0,visited);
        }
        return res;
    }
};  