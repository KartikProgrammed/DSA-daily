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

// 1751. Maximum Number of Events That Can Be Attended II
// You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
// You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
// Return the maximum sum of values that you can receive by attending events.


// Approach:
//Use dynamic programming to solve the problem.

// CODE:
class Solution {
public:
    unordered_map<string, int> memo;
    int dp(vector<vector<int>>& events,int curr,int time,int k){
        if(curr>=events.size()){
            return 0;
        }
        string key = to_string(curr) + "," + to_string(time) + "," + to_string(k);
        if (memo.count(key)) return memo[key];
        int op1=INT_MIN;

        if(time<events[curr][0] && k>0){
            op1=events[curr][2]+dp(events,curr+1,events[curr][1],k-1);
        }    
        int op2=dp(events,curr+1,time,k);
        return memo[key]=max(op1,op2);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        return dp(events,0,-1,k);
    }
};
 