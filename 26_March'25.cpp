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


//2033. Minimum Operations to Make a Uni-Value Grid
// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
// A uni-value grid is a grid where all the elements of it are equal.
// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

//APPROACH:-
//median does it all


//CODE:-
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        long long res=0;
        vector<int> vec;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        int n=vec.size();
        for(int i=0;i<n;i++){
            int diff=abs(vec[i]-vec[n/2]);
            if(diff%x!=0){
                return -1;
            }
            res+=diff/x;
        }
        return res;
    }
};


//DFS in a graph
// Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Traversal (DFS) starting from vertex 0, visiting vertices from left to right as per the adjacency list, and return a list containing the DFS traversal of the graph.
// Note: Do traverse in the same order as they are in the adjacency list.

//APPROACH:-
//STACK - Iterative approach

//CODE:-
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool> visited(n,false);
        stack<int> stk;
        vector<int> res;
        
        for(int start=0;start<n;start++){
            if(!visited[start]){
                stk.push(start);
                visited[start]=true;
                while(!stk.empty()){
                    int curr=stk.top();
                    stk.pop();
                    res.push_back(curr);
                    for(int i=adj[curr].size()-1;i>=0;i--){
                        if(!visited[adj[curr][i]]){
                            stk.push(adj[curr][i]);
                            visited[adj[curr][i]]=true;
                        }
                    }
                }
            }
        }
        return res;
    }
};

//APPROACH 2: 
//RECURSION

//CODE:-
class Solution {
  public:
    void dfs(vector<int> &res,int curr,vector<bool> &visited,vector<vector<int>>& adj){
        if(visited[curr]){
            return;
        }
        res.push_back(curr);
        visited[curr]=true;
        for(int i=0;i<adj[curr].size();i++){
            dfs(res,adj[curr][i],visited,adj);
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        vector<int> res;
        int n=adj.size();
        vector<bool> visited(n,false);
        for(int i=0;i<adj.size();i++){
            dfs(res,i,visited,adj);
        }
        return res;
    }
};


//BFS in a graph
//Given a undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.
// Note: Do traverse in the same order as they are in the adjacency list.

//approach:-
//use a queue

//CODE:-
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int> res;
        queue<int> q;
        int v=adj.size();
        vector<bool> visited(v,false);
        visited[0]=true;
        q.push(0);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            res.push_back(curr);
            for(int i=0;i<adj[curr].size();i++){
                if(!visited[adj[curr][i]]){
                    q.push(adj[curr][i]);
                    visited[adj[curr][i]]=true;
                }
            }
        }
    return res;
    }
};


//547. Number of Provinces
// There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.
// A province is a group of directly or indirectly connected cities and no other cities outside of the group.
// You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.
// Return the total number of provinces.


//APPROACH:-
//BFS

//CODE:-
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
       int v=isConnected.size();
       int res=0;
        if(v==0){
            return res;
        }
        vector<int> visited(v,false);
        queue<int> q;
        vector<vector<int>> adj(v);
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(isConnected[i][j]==1)
                    adj[i].push_back(j);
            }
        } 
        for(int st=0;st<v;st++){
            if(!visited[st]){
                res++;
                q.push(st);
                visited[st]=true;
                while(!q.empty()){
                    int curr=q.front();
                    q.pop();
                    for(int neigh=0;neigh<adj[curr].size();neigh++){
                        if(!visited[adj[curr][neigh]]){
                            q.push(adj[curr][neigh]);
                            visited[adj[curr][neigh]]=true;
                        }
                    }
                }
            }
        }
        return res;
    }
};