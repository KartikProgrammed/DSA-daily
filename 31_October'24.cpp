#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<unordered_set>
using namespace std;

//DailyProblem 2463:0-Minimum total distance travelled
// There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.

// The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.

// All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.

// At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.

// Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired.

// Note that

// All robots move at the same speed.
// If two robots move in the same direction, they will never collide.
// If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
// If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
// If the robot moved from a position x to a position y, the distance it moved is |y - x|.

//CODE:-
class Solution {
public:
    typedef long long ll;
    ll solve(vector<int>& robot, vector<int>& fac,int ri,int fi,vector<vector<ll>> &t){
        if(ri>=robot.size())
            return 0;
        if(fi>=fac.size()){
            return 1e12;
        }
        if(t[ri][fi]!=-1){
            return t[ri][fi];
        }
        ll take=abs(robot[ri]-fac[fi]) + solve(robot,fac,ri+1,fi+1,t);
        ll skip=solve(robot,fac,ri,fi+1,t);
        return t[ri][fi]=min(take,skip);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        vector<int> fac;
        for(int i=0;i<factory.size();i++){
            int limit=factory[i][1];
            int posi=factory[i][0];
            for(int j=0;j<limit;j++){
                fac.push_back(posi);
            }
        }
        vector<vector<ll>> t(robot.size()+1,vector<ll>(fac.size()+1,-1));
        return solve(robot,fac,0,0,t);
    }
};