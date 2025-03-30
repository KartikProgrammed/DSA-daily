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

// 763. Partition Labels
// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part. For example, the string "ababcc" can be partitioned into ["abab", "cc"], but partitions such as ["aba", "bcc"] or ["ab", "ab", "cc"] are invalid.
// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
// Return a list of integers representing the size of these parts.

//APPROACH:-
//use 2 maps 1 local and 1 global
//if the local count reaches max for every local map partition

//CODE:-
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> global;
        for(int i=0;i<s.length();i++){
            global[s[i]]++;
        }
        int prev=-1;
        unordered_map<char,int> local;
        vector<int> res;
        for(int i=0;i<s.length();i++){
            local[s[i]]++;
            bool ok=true;
            for (auto &entry : local) {
                if (entry.second < global[entry.first]) {
                    ok = false;
                    break;
                }
            }
            if(ok){
                local.clear();
                res.push_back(i-(prev));
                prev=i;
            }
        }
        return res;
    }
};

// 1020. Number of Enclaves
// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

//APPROACH:-
//BFS

//CODE:-
class Solution {
    public:
        int numEnclaves(vector<vector<int>>& grid) {
            int tot=0;
            int bound=0;
            int m=grid.size();
            int n=grid[0].size();
            vector<vector<bool>> visited(m,vector<bool>(n,false));
            queue<pair<int,int>> q;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i==0 || i==m-1 || j==n-1 || j==0){
                        if(grid[i][j]==1){
                            bound++;
                            q.push({i,j});
                            visited[i][j]=true;
                        }
                    }
                    if(grid[i][j]==1){
                        tot++;
                    }
                }
            }
            while(!q.empty()){
                auto it=q.front();
                q.pop();
                int x=it.first;
                int y=it.second;
                if(x>0 && grid[x-1][y]==1 && !visited[x-1][y]){
                    q.push({x-1,y});
                    visited[x-1][y]=true;
                    bound++;
                }
                if(x<m-1 && grid[x+1][y]==1 && !visited[x+1][y]){
                    q.push({x+1,y});
                    visited[x+1][y]=true;
                    bound++;
                }
                if(y>0 && grid[x][y-1]==1 && !visited[x][y-1]){
                    q.push({x,y-1});
                    visited[x][y-1]=true;
                    bound++;
                }
                if(y<n-1 && grid[x][y+1]==1 && !visited[x][y+1]){
                    q.push({x,y+1});
                    visited[x][y+1]=true;
                    bound++;
                }
            }
            return tot-bound;
        }
    };