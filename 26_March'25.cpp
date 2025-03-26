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
