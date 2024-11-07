#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2275:-Largest Combination With Bitwise AND Greater Than Zero
// The bitwise AND of an array nums is the bitwise AND of all integers in nums.

// For example, for nums = [1, 5, 3], the bitwise AND is equal to 1 & 5 & 3 = 1.
// Also, for nums = [7], the bitwise AND is 7.
// You are given an array of positive integers candidates. Evaluate the bitwise AND of every combination of numbers of candidates. Each number in candidates may only be used once in each combination.

// Return the size of the largest combination of candidates with a bitwise AND greater than 0

//CODE:-
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> bitCounts(32, 0);
        
        for (int candidate : candidates) {
            for (int bit = 0; bit < 32; ++bit) {
                if (candidate & (1 << bit)) { //checks for the bit 1 at different positions 
                    bitCounts[bit]++;
                }
            }
        }
        return *max_element(bitCounts.begin(), bitCounts.end());
    }
};

//dry run
// for ex, choose [2,3]
// 2 is selected first 
//     32 times a loop will run as:
//         2 & (1<<0) == 2 & 0001 = 0
//         2 & (1<<1) == 2 & 0010 = 1 since 2 is 0010 and now the array bitcount will be incremented on index 1
//         2 & (1<<2) == 2 && 0100 =0 
//         so on 
// 3 is selected now and done the same way

// like this we can get the max elements which have 1 on a common position, when we have 1 at a common position, their AND is always > 0 and we return the max element of the bitcount arr