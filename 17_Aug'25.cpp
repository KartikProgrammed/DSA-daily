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

// 837. New 21 Game

// Alice plays the following game, loosely based on the card game "21".
// Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.
// Alice stops drawing numbers when she gets k or more points.
// Return the probability that Alice has n or fewer points.
// Answers within 10-5 of the actual answer are considered accepted.

// Approach:
// 1. Use dynamic programming to calculate the probability of reaching each score from 0 to
// n.


// Code: (TLE)
class Solution {
public:
    double recursion(int curr,int n,int k,int maxPts,vector<double> &memo){
        if(curr>=k){
            if(curr<=n){
                return 1.0;
            }
            return 0.0;
        }
        if(memo[curr]>=0){
            return memo[curr];
        }
        double op1=0;
        for(int i=1;i<=maxPts;i++){
            op1+=recursion(curr+i,n,k,maxPts,memo);
        }
        return memo[curr]=op1/maxPts;
    }
    double new21Game(int n, int k, int maxPts) {
        int tot=0;
        vector<double> memo(n + maxPts + 1, -1.0);
        return recursion(0,n,k,maxPts,memo);
    }
};


//Approach2:
// 1. Use dynamic programming to calculate the probability of reaching each score from 0 to n.
// 2. Use a sliding window to keep track of the sum of probabilities for the last
// maxPts scores.

// Code:
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                windowSum += dp[i];  // contribute to future
            } else {
                result += dp[i];     // final probability if stopped
            }

            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }

        return result;
    }
};
