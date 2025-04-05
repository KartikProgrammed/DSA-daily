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

// 1863. Sum of All Subset XOR Totals
// The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.
// For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
// Given an array nums, return the sum of all XOR totals for every subset of nums. 
// Note: Subsets with the same elements should be counted multiple times.
// An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.

//APPROACH:-
//RECURSION EITHER USE THE NUM IN XOR OR DONT

//CODE:-
class Solution {
public:
    int recursion(vector<int> nums,int index,int xors){
        if(index==nums.size()){
            return xors;
        }
        int with=recursion(nums,index+1,xors^nums[index]);
        int without=recursion(nums,index+1,xors);
        return with+without;
    }
    int subsetXORSum(vector<int>& nums) {
        return recursion(nums,0,0);
    }
};

//1192. Critical Connections in a Network
// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
// Return all critical connections in the network in any order.

//APPROACH:-
//TARJAN'S ALGO

//CODE:-
class Solution {
private:
    int timer=0;
public:

    void dfs(int node,int parent,vector<bool> &visited,vector<vector<int>> &adj,vector<int> &time,vector<int> &low,vector<vector<int>> &res){
        visited[node]=true;
        time[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent){
                continue;
            }
            if(!visited[it]){
                dfs(it,node,visited,adj,time,low,res);
                low[node]=min(low[node],low[it]);
                if(low[it]>time[node]){
                    res.push_back({node,it});
                }
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n,false);
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>> res;
        dfs(0,-1,visited,adj,time,low,res);
        return res;
    }
};