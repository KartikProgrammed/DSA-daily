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

// 1353. Maximum Number of Events That Can Be Attended
// You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
// You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
// Return the maximum number of events you can attend.


// Approach:
// 1. Sort the events by their end days.
// 2. Use a priority queue to keep track of the end days of the events that can be attended.
// 3. Iterate through the sorted events and for each event, check if it can be attended
//    by comparing its start day with the end days in the priority queue.
// 4. If it can be attended, add its end day to the priority queue.
// 5. If it cannot be attended, remove the earliest end day from the priority queue
//    and check again if the current event can be attended.
// 6. Continue this process until all events are processed.

// CODE:
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        int count=0;
        int day=events[0][0];
        int i=0;
        while(!pq.empty() || i < n){
            if(pq.empty()){
                day=events[i][0];
            }
            while(i<n && day==events[i][0]){
                pq.push(events[i][1]);
                i++;
            }

            if(!pq.empty()){
                pq.pop();
                count++;
            }
            day++;

            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
        }
        return count;
    }
};