#include <bits/stdc++.h>
using namespace std;

//1014. Best Sightseeing Pair
// You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.

// The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.

// Return the maximum score of a pair of sightseeing spots.


//APPROACH 1:- Brute force (TLE) 
//CODE:-
class Solution {
public:
    int score(vector<int> &values,int i,int j){
        int result=values[i]+values[j]+(i-j);
        return result;
    }
    int maxScoreSightseeingPair(vector<int>& values) {
        int currmax=INT_MIN;
        for(int i=0;i<values.size();i++){
            for(int j=i+1;j<values.size();j++){
                int curr=score(values,i,j);
                if(curr>currmax){
                    currmax=curr;
                }
            }
        }
        return currmax;
    }
};

//APPROACH 2:- 
//Greedy APPROACH
//think of the score as values[i]+i + values[j]-j 

//CODE:-
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int left=values[0];
        int maxtillhere=INT_MIN;
        for(int j=1;j<values.size();j++){
            maxtillhere=max(maxtillhere,left+values[j]-j);
            left=max(left,values[j]+j);
        }
        return maxtillhere;
    }
};
