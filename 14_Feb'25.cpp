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

//1352. Product of the Last K Numbers
// Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

// Implement the ProductOfNumbers class:

// ProductOfNumbers() Initializes the object with an empty stream.
// void add(int num) Appends the integer num to the stream.
// int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
// The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

//APPROACH:-
//create an array and push elements whatever are added
//compute the product of last k elements

//CODE:- 
class ProductOfNumbers {
    private:
        vector<int> vec;
    public:
        ProductOfNumbers() {}
        
        void add(int num) {
            vec.push_back(num);
        }
        
        int getProduct(int k) {
            int res=1;
            int st=vec.size()-k;
            for(int i=st;i<vec.size();i++){
                res*=vec[i];
            }
            return res;
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */

//APPROACH 2:-
//compute the product of k last elements while adding new elements
//the vec would be used to store the product this time

//CODE:-
class ProductOfNumbers {
    private:
        vector<int> vec;
    public:
        ProductOfNumbers() {}
        
        void add(int num) {
            for(int i=0;i<vec.size();i++){
                vec[i]=vec[i]*num;
            }
            vec.push_back(num);
        }
        
        int getProduct(int k) {
            int st=vec.size()-k;
            return vec[st];
        }
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */

//56. Merge Intervals
// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input

//APPROACH:-
//find the overlapping intervals 
//merge them accordingly if prev intervals end >= next interval's start

//CODE:-
class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            int n=intervals.size();
            if(n<=1){
                return intervals;
            }
            sort(intervals.begin(),intervals.end());
            int st=intervals[0][0];
            int next=intervals[0][1];
            vector<vector<int>> res;
            for(int i=1;i<n;i++){
                if(next>=intervals[i][0]){
                    next=max(next,intervals[i][1]);
                }
                else{
                    res.push_back({st,next});
                    st=intervals[i][0];
                    next=intervals[i][1];
                }
            }
            res.push_back({st,next});
            return res;
        }
    };


//435. Non-overlapping Intervals
// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Note that intervals which only touch at a point are non-overlapping. For example, [1, 2] and [2, 3] are non-overlapping.

//APPROACH:-
//compute prev pointer which points at prev intervals end and curr intervals start
//update prev pointer accordingly such that it we remove the larger interval so as to accomadate max intervals
//increment count 

//CODE:-
class Solution {
    public:
        int eraseOverlapIntervals(vector<vector<int>>& intervals) {
            sort(intervals.begin(),intervals.end());
            int count=0;
            int n=intervals.size();
            if(n<=1){
                return 0;
            }
            int prev=intervals[0][1];
            int i=1;
            while(i<n){
                if(prev>intervals[i][0]){
                    count++;
                    prev=min(prev,intervals[i][1]);
                }
                else{
                    prev=intervals[i][1];
                }
                i++;
            }
            return count;
        }
    };