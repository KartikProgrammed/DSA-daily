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

//1504. Count Submatrices With All Ones
// Given an m x n binary matrix mat, return the number of submatrices that have all ones.

//Approach:-
//use a 1D array to store the count of consecutive ones in each column.
//for each row, calculate the number of submatrices with all ones using a stack to keep track of the heights of the columns.

//CODE:-
class Solution {
public:

    int onedarr(vector<int> &arr){
        int res=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==1){
                count++;
                res+=count;
            }
            else{
                count=0;
            }
        }
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int res=0;
        for(int startrow=0;startrow<m;startrow++){
            vector<int> vec(n,1);
            for(int endrow=startrow;endrow<m;endrow++){
                for(int col=0;col<n;col++){
                    vec[col]=vec[col] & mat[endrow][col];
                }
                res+=onedarr(vec);
            }
        }
        return res;
    }
};