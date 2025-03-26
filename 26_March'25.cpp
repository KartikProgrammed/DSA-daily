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


//2033. Minimum Operations to Make a Uni-Value Grid
// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
// A uni-value grid is a grid where all the elements of it are equal.
// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

//APPROACH:-
//median does it all


//CODE:-
class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        long long res=0;
        vector<int> vec;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        int n=vec.size();
        for(int i=0;i<n;i++){
            int diff=abs(vec[i]-vec[n/2]);
            if(diff%x!=0){
                return -1;
            }
            res+=diff/x;
        }
        return res;
    }
};