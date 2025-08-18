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

//679. 24 Game
// You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

// You are restricted with the following rules:

// The division operator '/' represents real division, not integer division.
// For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
// Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
// For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
// You cannot concatenate numbers together
// For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
// Return true if you can get such expression that evaluates to 24, and false otherwise.

// Approach:
// 1. Use backtracking to try all combinations of the four numbers and the four operators
// 2. Evaluate the expression to check if it equals 24.
// 3. Use a helper function to evaluate the expression with two numbers and an operator.
// 4. Use a set to keep track of used numbers to avoid reusing them.
// 5. Return true if a valid expression is found, otherwise return false.


// Code:
#define EPS 0.1
class Solution {
public:

    bool recursion(vector<double>&cards){
        if(cards.size()==1){
            return abs(24-cards[0])<=EPS;
        }
        for(int i=0;i<cards.size();i++){
            for(int j=0;j<cards.size();j++){
                if(i==j){
                    continue;
                }
                double a=cards[i];
                double b=cards[j];
                vector<double> possible={a+b,a-b,b-a,a*b};
                if(abs(b)>0){
                    possible.push_back(a/b);
                }
                if(abs(a)>0){
                    possible.push_back(b/a);
                }
                vector<double> temp;
                for(int k=0;k<cards.size();k++){
                    if(k!=i && k!=j){
                        temp.push_back(cards[k]);
                    }
                }
                for(auto it:possible){
                    temp.push_back(it);
                    if(recursion(temp)){
                        return true;
                    }
                    temp.pop_back();
                }
            }
        }
        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        vector<double> temp;
        for(int i=0;i<cards.size();i++){
            temp.push_back(cards[i]);
        }
        return recursion(temp);
    }
};