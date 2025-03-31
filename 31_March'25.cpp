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

//2551. Put Marbles in Bags
// You have k bags. You are given a 0-indexed integer array weights where weights[i] is the weight of the ith marble. You are also given the integer k.
// Divide the marbles into the k bags according to the following rules:
// No bag is empty.
// If the ith marble and jth marble are in a bag, then all marbles with an index between the ith and jth indices should also be in that same bag.
// If a bag consists of all the marbles with an index from i to j inclusively, then the cost of the bag is weights[i] + weights[j].
// The score after distributing the marbles is the sum of the costs of all the k bags.
// Return the difference between the maximum and minimum scores among marble distributions.

//APPROACH:-
//find adj pair sum, sort it and then find max and min sum

//CODE:-
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxSum=0;
        long long minSum=0;
        int m=weights.size()-1;
        vector<long long> pairsum(m,0);

        for(int i=0;i<m;i++){
            pairsum[i]=weights[i]+weights[i+1];
        }
        sort(pairsum.begin(),pairsum.end());

        for(int i=0;i<k-1;i++){
            minSum+=pairsum[i];
            maxSum+=pairsum[m-i-1];
        }
        return maxSum-minSum;
    }
};


//207. Course Schedule
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

//APPROACH:-:-
//detect cycle classic problem

//CODE:-
class Solution {
public:
    bool dfs(vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &pathvis,int curr){
        vis[curr]=true;
        pathvis[curr]=true;

        for(auto it:adj[curr]){
            if(!vis[it]){
                if(dfs(adj,vis,pathvis,it)==true){
                    return true;
                }
            }
            if(pathvis[it]==true){
                return true;
            }
        }
        pathvis[curr]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto pre:prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        int m=prerequisites.size();
        vector<bool> vis(numCourses,false);
        vector<bool> pathvis(numCourses,false);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(adj,vis,pathvis,i)==true){
                    return false;
                }
            }
        }
        return true;
    }
};

//802. Find Eventual Safe States
// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

//APPROACH:-
//find cycle is major problem

//code:-
class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<bool> &vis,vector<bool> &pathvis,int curr,vector<int> &res){
        pathvis[curr]=true;
        vis[curr]=true;
        for(int it:graph[curr]){
            if(!vis[it]){
                if(dfs(graph,vis,pathvis,it,res)){
                    return true;
                }
            }
            if(pathvis[it]){
                return true;
            }
        }
        res.push_back(curr);
        pathvis[curr]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int m=graph.size();
        vector<bool> pathvis(m,false);
        vector<bool> vis(m,false);
        vector<int> res;
        for(int i=0;i<m;i++){
            if(!vis[i]){
                dfs(graph,vis,pathvis,i,res);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};

//1091. Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

//APPROACH:- DFS
//TLE

//CODE:-
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int x,int y,int dist,vector<vector<bool>> &visited){
        int n=grid.size();
        if(x==n-1 && y==n-1){
            return dist;
        }
        visited[x][y]=true;
        int res=INT_MAX;
        if(x>0 && grid[x-1][y]==0 && !visited[x-1][y]){
            res=min(res,dfs(grid,x-1,y,dist+1,visited));
        }
        if(x<n-1 && grid[x+1][y]==0 && !visited[x+1][y]){
            res=min(res,dfs(grid,x+1,y,dist+1,visited));
        }
        if(y>0 && grid[x][y-1]==0 && !visited[x][y-1]){
            res=min(res,dfs(grid,x,y-1,dist+1,visited));
        }
        if(y<n-1 && grid[x][y+1]==0 && !visited[x][y+1]){
            res=min(res,dfs(grid,x,y+1,dist+1,visited));
        }
        if(x>0 && y>0 && grid[x-1][y-1]==0 && !visited[x-1][y-1]){
            res=min(res,dfs(grid,x-1,y-1,dist+1,visited));
        }
        if(x<n-1 && y<n-1 && grid[x+1][y+1]==0 && !visited[x+1][y+1]){
            res=min(res,dfs(grid,x+1,y+1,dist+1,visited));
        }
        if(x>0 && y<n-1 && grid[x-1][y+1]==0 && !visited[x-1][y+1]){
            res=min(res,dfs(grid,x-1,y+1,dist+1,visited));
        }
        if(x<n-1 && y>0 && grid[x+1][y-1]==0 && !visited[x+1][y-1]){
            res=min(res,dfs(grid,x+1,y-1,dist+1,visited));
        }
        visited[x][y] = false;
        return res;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        if(grid[0][0]==1){
            return -1;
        }
        int res=dfs(grid,0,0,1,visited);
        if(res==INT_MAX){
            return -1;
        }
        return res;
    }
};