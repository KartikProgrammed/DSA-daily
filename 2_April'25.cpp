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

// 2873. Maximum Value of an Ordered Triplet I
// You are given a 0-indexed integer array nums.
// Return the maximum value over all triplets of indices (i, j, k) such that i < j < k. If all such triplets have a negative value, return 0.
// The value of a triplet of indices (i, j, k) is equal to (nums[i] - nums[j]) * nums[k].

//APPROACH:-
//3 POINTER

//CODE:-
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        if(nums.size()<3){
            return 0;
        }
        long long res = 0;
        int maxe = nums[0];
        int maxdif = 0; 

        for (int i = 1; i < nums.size()-1; i++) {
            maxdif = max(maxdif, maxe - nums[i]);
            res = max(res, (long long)maxdif * nums[i+1]);
            maxe = max(maxe, nums[i]);
        }
        return res;
    }
};


//1976. Number of Ways to Arrive at Destination
// You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
// You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
// Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

//APPROACH:-
//DIJKSTRA

//CODE:-
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
        vector<long long> dist(n,LLONG_MAX);
        vector<int> ways(n,0);
        ways[0]=1;
        int MOD=1e9+7;
        vector<vector<pair<int,int>>> adj(n);
        for(auto road:roads){
            int u=road[0];
            int v=road[1];
            int x=road[2];
            adj[u].push_back({v,x});
            adj[v].push_back({u,x});
        }
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            long long time=it.first;
            int node=it.second;
            if(time>dist[node]){
                continue;
            }
            for(auto neigh:adj[node]){
                int nnode=neigh.first;
                long long ntime=neigh.second;
                long long tot=time+ntime;
                if(ntime+time<dist[nnode]){
                    dist[nnode]=tot;
                    ways[nnode]=ways[node];
                    pq.push({tot,nnode});
                }
                else if(tot==dist[nnode]){
                    ways[nnode]=(ways[nnode]+ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};