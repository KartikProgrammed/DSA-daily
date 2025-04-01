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

// 2140. Solving Questions With Brainpower
// You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
// The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
// For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
// If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
// If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
// Return the maximum points you can earn for the exam.


//APPROACH:-
//CLASSIC DP

//CODE:-
class Solution {
    typedef long long ll;
    vector<ll> dp;
    
    ll dfs(vector<vector<int>>& questions, int curr) {
        if (curr >= questions.size()) return 0;
        if (dp[curr] != -1) return dp[curr];
        ll take = questions[curr][0] + dfs(questions, curr + questions[curr][1] + 1);
        ll skip = dfs(questions, curr + 1);
        return dp[curr] = max(take, skip);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(), -1);
        return dfs(questions, 0);
    }
};


//1631. Path With Minimum Effort
// You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
// A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
// Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

//APPROACH:-
//DIJKSTRA'S

//CODE:-
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int m=heights.size();
        int n=heights[0].size();
        if(m==1 && n==1){
            return 0;
        }
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        vector<int> dx={1,0,-1,0};
        vector<int> dy={0,1,0,-1};
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int res=INT_MAX;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int curr=it.first;
            int x=it.second.first;
            int y=it.second.second;
            if (x == m - 1 && y == n - 1) return curr;
            for(int i=0;i<4;i++){
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(newx>=0 && newx<m && newy>=0 && newy<n){
                    int ndist=max(curr,abs(heights[x][y]-heights[newx][newy]));
                    if(ndist<dist[newx][newy]){
                        dist[newx][newy]=ndist;
                        pq.push({ndist,{newx,newy}});
                    }
                }
            }
        }
        return res;
    }
};