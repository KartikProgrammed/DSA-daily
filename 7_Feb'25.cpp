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

//3160. Find the Number of Distinct Colors Among the Balls
// You are given an integer limit and a 2D array queries of size n x 2.

// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

// Note that when answering a query, lack of a color will not be considered as a color.


//APPROACH:-
//1 map stores the color of each ball at current time
//1 map stores the freq of each color
//the count stores the unique colors and its value is appended into the result array
//the count is calculated along with each pass
//use of unorderedmap passes the TC when a vector is used Memory limit exceeds

//CODE:-
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> map;
        int count=0;
        vector<int> res;
        unordered_map<int,int> balls;
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(map[ball]==0){ //ball was uncolored before
                map[ball]=color;
                if (balls[color]==0){ //unique color added
                    count++;
                }
                balls[color]++;
            }
            else if(map[ball]>0){ //color has to be removed first
                int curr=map[ball];
                map[ball]=color;
                if(balls[curr]==1){ //only this ball was colored with this color
                    count--;
                }
                balls[curr]--;
                if (balls[color]==0){ //unique color added
                    count++;
                }
                balls[color]++;
            }
            res.push_back(count);
        } 
        return res;   
    }
};