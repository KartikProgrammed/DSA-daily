#include <bits/stdc++.h>
using namespace std;

//983. Minimum Cost For Tickets
// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.


//APPROACH 1:- (TLE) 
//everytime theres 3 options either 1d pass 7d or 30d 
//choose one of them each recursive call and return the minium of them

//CODE:- 
class Solution {
public:
    int recursion(vector<int> &days,vector<int> &costs,int spent,int curr){
        if(curr>=days.size()){
            return spent; 
        }
        int curr7=0;
        int curr30=0;
        for(int i=curr;i<days.size();i++){
            if(days[i]>days[curr]+6){
                curr7=i;
                break;
            }
        }
        for(int i=curr;i<days.size();i++){
            if(days[i]>days[curr]+29){
                curr30=i;
                break;
            }
        }
        curr7=curr7>0?curr7:days.size();
        curr30=curr30>0?curr30:days.size();
        int r1=recursion(days,costs,spent+costs[0],curr+1);
        int r2=recursion(days,costs,spent+costs[1],curr7);
        int r3=recursion(days,costs,spent+costs[2],curr30);
        return min({r1,r2,r3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return recursion(days,costs,0,0);
    }
};

//APPROACH 1 Modified:- (MEMOISATION)

//CODE:- 
class Solution {
public:
    int recursion(vector<int> &days,vector<int> &costs,int spent,int curr,unordered_map<int,int>& map){
        if(curr>=days.size()){
            return spent; 
        }
        if(map.find(curr)!=map.end()){
            return map[curr]+spent;
        }
        int curr7=days.size();
        int curr30=days.size();
        for(int i=curr;i<days.size();i++){
            if(days[i]>days[curr]+6){
                curr7=i;
                break;
            }
        }
        for(int i=curr;i<days.size();i++){
            if(days[i]>days[curr]+29){
                curr30=i;
                break;
            }
        }
        int r1=recursion(days,costs,spent+costs[0],curr+1,map);
        int r2=recursion(days,costs,spent+costs[1],curr7,map);
        int r3=recursion(days,costs,spent+costs[2],curr30,map);
        map[curr]=min({r1,r2,r3})-spent;
        return min({r1,r2,r3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> map;
        return recursion(days,costs,0,0,map);
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

//APPROACH:- 
//basic monoonic stack concepts used

//CODE:-
class StockSpanner {
public:
    StockSpanner() {
        currindex=0;
        
    }
    
    int next(int price) {
        int ans=1;
        while(!prices.empty() && price>=stocks[prices.top()]){
            ans+=result[prices.top()];
            prices.pop();
        }
        stocks.push_back(price);
        prices.push(currindex);
        result.push_back(ans);
        currindex+=1;
        return ans;
    }
private:
    int currindex=0;
    stack<int> prices;
    vector<int> result;
    vector<int> stocks;
};
