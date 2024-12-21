#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

//2872. Maximum Number of K-Divisible Components
// There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

// You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

// A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

// Return the maximum number of components in any valid split.

//CODE:-
//BRUTE FORCE:- idk why it wont work for the given test cases, while ik it wont work for any other of the test cases but the given test cases shouldve been passed do let me know where is this losing its way
class Solution {
public:
    bool check(vector<vector<int>> edges,int i,int j){
        for(int i=0;i<edges.size();i++){
            if((edges[i][0]==i && edges[i][1]==j) || (edges[i][0]==j && edges[i][1]==i)){
                return true;
            }
        }
        return false;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> vertices;
        int count=0;
        for(int i=0;i<n;i++){
            vertices.push_back(i);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-2;j++){
                int sum=0;
                if(check(edges,vertices[i],vertices[j]) && check(edges,vertices[i],vertices[j+1])){
                    sum=values[i]+values[j]+values[j+1];
                    if(sum%k==0){
                        count+=1;
                        break;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return count;
    }
};

//DFS solution
class Solution {
public:
    int dfs(int node,int parent,vector<int> &values,vector<vector<int>> &adj,int &count,int k){
        int sum=values[node];

        for(int neighbour:adj[node]){
            if(neighbour!=parent){
                sum+=dfs(neighbour,node,values,adj,count,k);
                sum%=k;
            }
        }
        if(sum%k==0){
            count++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for(auto &iter:edges){
            adj[iter[0]].push_back(iter[1]);
            adj[iter[1]].push_back(iter[0]);
        }
        int count=0;
        dfs(0,-1,values,adj,count,k);
        return count;
    }
};