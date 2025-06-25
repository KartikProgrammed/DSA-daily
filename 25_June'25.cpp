#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

//54. Spiral Matrix
// Given an m x n matrix, return all elements of the matrix in spiral order.


// Approach: Use a loop to traverse the matrix in spiral order. Keep track of the boundaries of the matrix and adjust them as you traverse.
// Time Complexity: O(m * n), where m is the number of rows and n is
// the number of columns in the matrix.

// CODE:
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left=0;
        int right=matrix[0].size()-1;
        int top=0;
        int bottom=matrix.size()-1;
        vector<int> res;

        while(top<=bottom && left<=right){
            for(int j=left;j<=right;j++){
                res.push_back(matrix[top][j]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    res.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return res;
    }
};