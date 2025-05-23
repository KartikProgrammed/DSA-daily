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

//70. Climbing Stairs
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

//APPROACH:-
//DP-1D

//CODE:-
class Solution {
public:
    int recursion(int n,vector<int> &mem){
        if(n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        if(mem[n]!=-1){
            return mem[n];
        }
        int one=recursion(n-1,mem);
        int two=recursion(n-2,mem);
        return mem[n]=one+two;
    }
    int climbStairs(int n) {
        vector<int> mem(n+1,-1);
        return recursion(n,mem);
    }
};

//198. House Robber
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int recursion(vector<int>& nums,int curr,int sum,bool choose,vector<vector<int>> &memo){
        if(curr>=nums.size()){
            return sum;
        }
        if (memo[curr][choose] != -1) {
            return memo[curr][choose] + sum;
        }
        if(!choose){
            return recursion(nums,curr+1,sum,true,memo);
        }
        int r1=recursion(nums,curr+1,sum,true,memo);
        int r2=recursion(nums,curr+1,sum+nums[curr],false,memo);
        return memo[curr][choose]=max(r1,r2);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> memo(nums.size(), vector<int>(2, -1));
        return recursion(nums,0,0,true,memo);
    }
};


//213. House Robber II
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

//APPROACH:-
//DP

//CODE:-
class Solution {
public:
    int recursion(vector<int>& nums, int curr, vector<int>& memo, int end) {
        if (curr > end) return 0;
        if (memo[curr] != -1) return memo[curr];

        int rob = nums[curr] + recursion(nums, curr + 2, memo, end);
        int skip = recursion(nums, curr + 1, memo, end);

        return memo[curr] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> memo1(n, -1);
        int case1 = recursion(nums, 0, memo1, n - 2);
        vector<int> memo2(n, -1);
        int case2 = recursion(nums, 1, memo2, n - 1);

        return max(case1, case2);
    }
};
