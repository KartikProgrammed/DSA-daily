#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
using namespace std;

//DailyProblem 1072. Flip Columns For Maximum Number of Equal Rows
// You are given an m x n binary matrix matrix.

// You can choose any number of columns in the matrix and flip every cell in that column (i.e., Change the value of the cell from 0 to 1 or vice versa).

// Return the maximum number of rows that have all values equal after some number of flips.

//CODE:-
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();  
        int m = matrix[0].size(); 
        unordered_map<string, int> mp;
        
        for (const auto& row : matrix) {
            string temp = "";
            for (int j = 0; j < m; ++j) {
                temp += (row[j] == row[0] ? '1' : '0');
            }
            mp[temp]++;
        }
        
        int maxi = 0;
        for (auto it : mp) {
            maxi = max(maxi, it.second);
        }
        
        return maxi;
    }
};