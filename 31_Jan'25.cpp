#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

// 827. Making A Large Island
// You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

// Return the size of the largest island in grid after applying this operation.

// An island is a 4-directionally connected group of 1s.

//APPROACH:-
//since the constraints are too tight brute force wont work
//we use an approach wherein we think of mapping the size of islands already present without flipping any water to land
//map the size and a unique id of the island in a unordered map
//calculate the total size by adding 1 to the neighbouring islands of a water

//CODE:-
class Solution {
public:
    int DFS(vector<vector<bool>>&visited ,vector<vector<int>> &grid,int id,int i,int j){
        int m=grid.size();
        int n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0 || visited[i][j]==true){
            return 0;
        }
        grid[i][j]=id;
        visited[i][j]=true;
        
        return 1+DFS(visited,grid,id,i-1,j)+DFS(visited,grid,id,i+1,j) +DFS(visited,grid,id,i,j-1) +DFS(visited,grid,id,i,j+1);
    }
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> map;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int currid=2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    int size=DFS(visited,grid,currid,i,j);
                    map[currid]=size;
                    currid++;
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]==0){
                    int curr=1;
                    unordered_set<int> neighbors; 
                    if (i > 0) neighbors.insert(grid[i - 1][j]);
                    if (i < m - 1) neighbors.insert(grid[i + 1][j]);
                    if (j > 0) neighbors.insert(grid[i][j - 1]);
                    if (j < n - 1) neighbors.insert(grid[i][j + 1]);
                    for(int iter:neighbors){
                        curr+=map[iter];
                    }
                    res=max(curr,res);
                }
            }
        }
        if (res == 0) {
            res = m * n;
        }
        return res;
    }
};


// 703. Kth Largest Element in a Stream
// You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

// You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

// Implement the KthLargest class:

// KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
// int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.
 

//APPROACH:-
// use a min heap to find the kth largest element 
//by default pop elements when the size goes beyond k and in the add function manipulate the input and push accordingly

//CODE:-
class KthLargest {
private:
    int elements;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        elements=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if (pq.size() > elements) {
                pq.pop(); // Maintain only k largest elements in the heap
            }
        }
        
    }
    
    int add(int val) {
        if(pq.size()<elements){
            pq.push(val);
        }
        else if(val>pq.top()){
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */