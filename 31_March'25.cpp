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