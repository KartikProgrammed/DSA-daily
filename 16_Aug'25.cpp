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


//901. Online Stock Span

// Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.
// The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.
// For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
// Also, if the prices of the stock in the last four days is [7,34,1,2] and the price of the stock today is 8, then the span of today is 3 because starting from today, the price of the stock was less than or equal 8 for 3 consecutive days.
// Implement the StockSpanner class:
// StockSpanner() Initializes the object of the class.
// int next(int price) Returns the span of the stock's price given that today's price is price.


// Approach:
// 1. Use a stack to keep track of the prices and their spans.
// 2. For each price, pop elements from the stack until the top of the stack has a price greater than the current price.
// 3. The span for the current price is the difference between the current index and the
// index of the last price that was greater than the current price.
// 4. Push the current price and its span onto the stack.
// 5. Return the span for the current price.

// Code:
class StockSpanner {
private:
    stack<pair<int,int>> stk;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        if(stk.empty() || stk.top().first > price){
            stk.push({price,1});
            return 1;
        }
        int temp=1;
        while(!stk.empty() && stk.top().first<=price){
            temp+=stk.top().second;
            stk.pop();
        }
        stk.push({price,temp});
        return temp;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */