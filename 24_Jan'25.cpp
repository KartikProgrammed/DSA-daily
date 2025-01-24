#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 802. Find Eventual Safe State
// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

//APPROACH:-
//Striver approach

//CODE:-
class Solution {
public:
    bool dfs(int node,vector<vector<int>>& adj,vector<int> &vis,vector<int> &Pathvis,vector<int> &check){
            vis[node] = 1;
            Pathvis[node] = 1;
            check[node] = 0;
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    if(dfs(it,adj,vis,Pathvis,check)==true){
                        check[node] = 0;
                        return true;
                    }
                }
                else if(Pathvis[it]){
                check[node] = 0;
                    return true;
                }
                }
                check[node] = 1;
                Pathvis[node] = 0;
                return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>vis(V,0);
        vector<int>Pathvis(V,0);
        vector<int>check(V,0);
        vector<int> ans;
        for(int i=0;i<V;i++){
                if(!vis[i]){
                    dfs(i,graph,vis,Pathvis,check);
                }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};