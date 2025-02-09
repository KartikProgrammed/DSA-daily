#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//2364. Count Number of Bad Pairs
// You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].

// Return the total number of bad pairs in nums.

//APPROACH:- (TLE)
//Brute Force the solution with complexity of O(nlogn)

//CODE:-
class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            long long count=0;
            for(int i=0;i<nums.size();i++){
                for(int j=i+1;j<nums.size();j++){
                    if(j-i != nums[j]-nums[i]){
                        count++;
                    }
                }
            }
            return count;
        }
    };