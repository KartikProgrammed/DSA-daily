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

//1323. Maximum 69 Number

// You are given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).

// Approach:
// 1. Convert the integer to a string to manipulate its digits.
// 2. Iterate through the string and change the first '6' to '9'.
// 3. Convert the string back to an integer and return it.

// Code:
class Solution {
public:
    int maximum69Number (int num) {
        if(num<10){
            return 9;
        }
        string nums=to_string(num);
        for(int i=0;i<nums.length();i++){
            if(nums[i]=='6'){
                nums[i]='9';
                break;
            }
        }
        return stoi(nums);
    }
};


//239. Sliding Window Maximum

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

// Approach:
//use a priority queue to keep track of the maximum elements in the current window.

// Code:
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
            while(!pq.empty() && pq.top().second<= i-k){
                pq.pop();
            }
            if (i >= k - 1) {
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};