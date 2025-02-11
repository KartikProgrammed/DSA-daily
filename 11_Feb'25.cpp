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

//1910. Remove All Occurrences of a Substring
// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

//APPROACH:-
//use the inbuilt library functions to find for a substring in a string 
//do it till the find return npos which is returned when the substrings is not found
//if the substr is found erase it using the erase function 

//CODE:-
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            bool found=false;
            if(s.length()<part.length()){
                return s;
            }
            int n=part.size();
            do{
                size_t pos = s.find(part);
                if (pos != std::string::npos) {
                    found=true;
                    s.erase(pos,n);
                } else {
                    found=false;
                }
            }while(found);
            return s;
        }
};


//57. Insert Interval
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it.


//APPROACH:-
//find the specific merge interval and find the new interval using min and max

//CODE:-
class Solution {
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            vector<vector<int>> res;
            int st=newInterval[0];
            int end=newInterval[1];
            bool inserted=false;
            for(int i=0;i<intervals.size();i++){
                if (intervals[i][1] < st) {
                    res.push_back(intervals[i]);
                }
                else if(intervals[i][0]>end){
                    if(!inserted){
                        res.push_back({st,end});
                        inserted=true;
                    }
                    res.push_back(intervals[i]);
                }
                else{
                    st = min(st, intervals[i][0]);
                    end = max(end, intervals[i][1]);
                }
            }
            if(!inserted){
                res.push_back({st,end});
            }
            return res;
        }
    };