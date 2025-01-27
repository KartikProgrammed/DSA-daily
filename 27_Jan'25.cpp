#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<numeric>
#include<climits>
using namespace std;
// 1462. Course Schedule IV
// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

// You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

// Return a boolean array answer, where answer[j] is the answer to the jth query.


//APPROACH:-
//Use dfs directly

//CODE:-
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj,int src,int dest,vector<bool> &visited){
        visited[src]=true;
        if(dest==src){
            return true;
        }
        bool ret=false;
        for(auto& iter:adj[src]){
            if(!visited[iter]){
                ret=ret || dfs(adj,iter,dest,visited);
            }
        }
        return ret;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>> adj;

        for(auto &iter:prerequisites){
            int src=iter[0];
            int dest=iter[1];
            adj[src].push_back(dest);
        }
        int q=queries.size();
        vector<bool> result(q);
        for(int i=0;i<q;i++){
            int src=queries[i][0];
            int dest=queries[i][1];
            vector<bool> visited(numCourses,false);
            result[i]=dfs(adj,src,dest,visited);
        }
        return result;
    }
};