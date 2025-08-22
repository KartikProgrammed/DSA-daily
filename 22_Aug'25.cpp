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

// 3195. Find the Minimum Area to Cover All Ones I

// You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

// Return the minimum possible area of the rectangle.

// Approach:
// 1. Find the minimum and maximum row indices that contain a 1.
// 2. Find the minimum and maximum column indices that contain a 1.
// 3. Calculate the area of the rectangle defined by these indices.

// CODE:
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minRow=-1;
        int minCol=-1;
        int maxRow=-1;
        int maxCol=-1;
        bool got=false;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    if(minRow==-1){
                        minRow=i;
                        maxRow=i;
                        minCol=j;
                        maxCol=j;
                    }else{
                        minRow=min(minRow,i);
                        maxRow=max(maxRow,i);
                        minCol=min(minCol,j);
                        maxCol=max(maxCol,j);
                    }
                    got=true;
                }
            }
        }
        if(!got){
            return 0;
        }
        int length=maxCol-minCol+1;
        int breadth=maxRow-minRow+1;
        return length*breadth;
    }
};