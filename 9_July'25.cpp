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

// 3439. Reschedule Meetings for Maximum Free Time I
// You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.
// You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].
// You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.
// The relative order of all the meetings should stay the same and they should remain non-overlapping.
// Return the maximum amount of free time possible after rearranging the meetings.
// Note that the meetings can not be rescheduled to a time outside the event.

 
// Approach:
// Use a greedy approach to find the maximum free time after rescheduling meetings.

// CODE:
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freeTime;
        freeTime.push_back(startTime[0]);

        for(int i=1;i<startTime.size();i++){
            freeTime.push_back(startTime[i]-endTime[i-1]);
        }
        freeTime.push_back(eventTime-endTime[startTime.size()-1]);
        int i=0;
        int j=0;
        int maxSum=0;
        int curr=0;
        int n=startTime.size();
        while(j<n){
            curr+=freeTime[j];
            if(i<n && j*i-1>k+1){
                curr-=freeTime[i];
                i++;
            }
            maxSum=max(maxSum,curr);
            j++;
        }
        return maxSum;
    }
};