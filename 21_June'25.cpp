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

// 3085. Minimum Deletions to Make String K-Special
// You are given a string word and an integer k.
// We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
// Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
// Return the minimum number of characters you need to delete to make word k-special.

// Approach: Count frequency of each character, then check the maximum frequency and minimum frequency.

// CODE:
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<word.size();i++){
            map[word[i]-'a']++;
        }
        int res=INT_MAX;
        for(auto curr:map){
            int mini=curr.first;
            int count=curr.second;
            int del=0;
            for(auto y:map){
                if(count>y.second){
                    del+=y.second;
                }
                else if(y.second>count+k){
                    del+=y.second-count-k;
                }
            }
            res=min(del,res);
        }
        return res;
    }
};

//121. Best Time to Buy and Sell Stock
// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//Approach: brute force to find the maximum profit by checking all pairs of days. (TLE for large inputs)

// CODE:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        for(int i=0;i<prices.size();i++){
            int curr=0;
            for(int j=i+1;j<prices.size();j++){
                curr=max(prices[j]-prices[i],curr);
            }
            res=max(res,curr);
        }
        return res;
    }
};

//Approach: use a single pass to find the maximum profit by keeping track of the minimum price seen so far and the maximum profit.
//kadane's algorithm can be used to find the maximum profit in O(n) time.

// CODE:
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int mini=prices[0];
        for(int i=1;i<prices.size();i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            else{
                res=max(res,prices[i]-mini);
            }
        }
        return res;
    }
};