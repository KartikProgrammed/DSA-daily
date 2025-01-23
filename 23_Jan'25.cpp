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

//1267. Count Servers that Communicate
//You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

// Return the number of servers that communicate with any other server.

//APPROACH:- (Beats 100%)
//count the number of servers in each row and each col
//then count the number of servers in 2nd traversal using the previously counted row and col counts

//CODE:-
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;
        vector<int> col(n,0);
        vector<int> row(m,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    col[j]++;
                    row[i]++;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0 && (row[i]>1 || col[j]>1)){
                    res++;
                }
            }
        }
        return res;
    }
};