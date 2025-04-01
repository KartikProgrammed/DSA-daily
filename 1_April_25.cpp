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

// 2140. Solving Questions With Brainpower
// You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].
// The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and make a decision whether to solve or skip each question. Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. If you skip question i, you get to make the decision on the next question.
// For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
// If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
// If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
// Return the maximum points you can earn for the exam.


//APPROACH:-
//CLASSIC DP

//CODE:-
class Solution {
    typedef long long ll;
    vector<ll> dp;
    
    ll dfs(vector<vector<int>>& questions, int curr) {
        if (curr >= questions.size()) return 0;
        if (dp[curr] != -1) return dp[curr];
        ll take = questions[curr][0] + dfs(questions, curr + questions[curr][1] + 1);
        ll skip = dfs(questions, curr + 1);
        return dp[curr] = max(take, skip);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        dp.resize(questions.size(), -1);
        return dfs(questions, 0);
    }
};
