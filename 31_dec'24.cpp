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