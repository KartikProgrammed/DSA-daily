#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<numeric>
#include<climits>
using namespace std;

//3160. Find the Number of Distinct Colors Among the Balls
// You are given an integer limit and a 2D array queries of size n x 2.

// There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.

// Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.

// Note that when answering a query, lack of a color will not be considered as a color.


//APPROACH:-
//1 map stores the color of each ball at current time
//1 map stores the freq of each color
//the count stores the unique colors and its value is appended into the result array
//the count is calculated along with each pass
//use of unorderedmap passes the TC when a vector is used Memory limit exceeds

//CODE:-
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> map;
        int count=0;
        vector<int> res;
        unordered_map<int,int> balls;
        for(int i=0;i<queries.size();i++){
            int ball=queries[i][0];
            int color=queries[i][1];
            if(map[ball]==0){ //ball was uncolored before
                map[ball]=color;
                if (balls[color]==0){ //unique color added
                    count++;
                }
                balls[color]++;
            }
            else if(map[ball]>0){ //color has to be removed first
                int curr=map[ball];
                map[ball]=color;
                if(balls[curr]==1){ //only this ball was colored with this color
                    count--;
                }
                balls[curr]--;
                if (balls[color]==0){ //unique color added
                    count++;
                }
                balls[color]++;
            }
            res.push_back(count);
        } 
        return res;   
    }
};


//860. Lemonade Change
//At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

// Note that you do not have any change in hand at first.

// Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

//APPROACH:-
//basic greedy approach

//CODE:- (beats 100%)
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5){
            return false;
        }
        vector<int> map(3,0);
        for(int i=0;i<bills.size();i++){
            int curr=bills[i];
            if(curr==5){
                map[0]++;
                continue;
            
            }
            else{
                curr-=5;
                if(curr==15){
                    if(map[1]>0 && map[0]>0){
                        map[1]--;
                        map[0]--;
                    }
                    else if(map[0]>=3){
                        curr-=15;
                        map[0]-=3;
                    }
                    else{
                        return false;
                    }
                }
                else if(curr==5){
                    if(map[0]>0){
                        curr-=5;
                        map[0]--;
                    }
                }
            }
            if(bills[i]==10){
                map[1]++;
            }
            else{
                map[2]++;
            }
        }
        return true;
    }
};