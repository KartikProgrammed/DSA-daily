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

//3169. Count Days Without Meetings
// You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
// Return the count of days when the employee is available for work but no meetings are scheduled.
// Note: The meetings may overlap.


//Approach:-
//BRUTE FORCE(TLE)

//CODE:-
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<int> slots(days+1,0);
        for(int i=0;i<meetings.size();i++){
            int start=meetings[i][0];
            int end=meetings[i][1];
            for(int j=start;j<=end;j++){
                slots[j]++;
            }
        }
        int res=0;
        for(int i=1;i<=days;i++){
            if(slots[i]==0){
                res++;
            }
        }
        return res;
    }
};

//APPROACH:-
//merge overlap intervals and add busydays 
//subtract from tot days

//CODE:-
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> slots;
        int st=meetings[0][0];
        int end=meetings[0][1];
        for(int i=1;i<meetings.size();i++){
            if(meetings[i][0]<=end){
                end=max(meetings[i][1],end);
            }
            else{
                slots.push_back({st,end});
                end=meetings[i][1];
                st=meetings[i][0];
            }
        }
        slots.push_back({st,end});
        int res=0;
        for(int i=0;i<slots.size();i++){
            res+=slots[i][1]-slots[i][0]+1;
        }
        return days-res;
    }
};