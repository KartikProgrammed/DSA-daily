#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_set>
using namespace std;

//DailyProblem 2070:- Most Beautiful Item for Each Query
// You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.

// You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.

// Return an array answer of the same length as queries where answer[j] is the answer to the jth query.

//CODE:-
//Approach1 :- brute force TLE on 2nd last TC
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        vector<int> result(n,0);
        sort(items.begin(),items.end());
        for(int i=0;i<queries.size();i++){
            int ele=INT_MIN;
            for(int j=0;j<items.size();j++){
                if(queries[i]>items[j][0] && ele<items[j][1]){
                    result[i]=items[j][1];
                    ele=items[j][1];
                }
                else if(queries[i]==items[j][0] && ele<items[j][1]){
                    result[i]=items[j][1];
                }
            }
        }
        return result;
    }
};

//Approach2 :- uses Binary Search
class Solution {
public:
    int binaryS(int n,vector<vector<int>> &items){
        int size=items.size();
        int low=0;
        int high=size-1;
        int beauty=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(items[mid][0]<=n){
                beauty=max(beauty,items[mid][1]);
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return beauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n=queries.size();
        vector<int> result(n,0);
        sort(items.begin(),items.end());
        for(int i=1;i<items.size();i++){
            items[i][1]=max(items[i-1][1],items[i][1]);
        }
        for(int i=0;i<queries.size();i++){
            result[i]=binaryS(queries[i],items);
        }
        return result;
    }
};