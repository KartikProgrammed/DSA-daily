#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<stack>
#include <sstream>
#include <map>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//122. Best Time to Buy and Sell Stock II
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
// Find and return the maximum profit you can achieve.

//APPROACH:-
//dp

//CODE:-
class Solution {
public:
 vector<vector<int>> dp;
int rec(vector<int>& prices,int curr,bool holding){
    if(curr>=prices.size()){
        return 0;
    }
    if (dp[curr][holding] != -1) {
        return dp[curr][holding];
    }
    int res=0;
    if(holding){
        int op1=prices[curr]+rec(prices,curr+1,false); //sell
        int op2=rec(prices,curr+1,true); //dont sell
        res=max(op1,op2);
    }
    else{
        
        int op1=-prices[curr]+rec(prices,curr+1,true);
        int op2=rec(prices,curr+1,false);
        res=max(op2,op1);
    }
    return dp[curr][holding]= res;
}
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector<int>>(n, vector<int>(2, -1));
        return rec(prices,0,false);
    }
};