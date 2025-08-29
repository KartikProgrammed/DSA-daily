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


//3021. Alice and Bob Playing Flower Game

// Alice and Bob are playing a turn-based game on a field, with two lanes of flowers between them. There are x flowers in the first lane between Alice and Bob, and y flowers in the second lane between them.


//Approach:-
// We can use a greedy approach to solve this problem. Alice will always try to maximize her score
// and Bob will always try to minimize Alice's score. We can simulate the game by iterating through the flowers and keeping track of the scores of both players.
// If Alice's score is greater than Bob's score at the end of the game, we return true. Otherwise, we return false.


//CODE:-
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if((j+i)%2==0){
                    continue;
                }
                res++;
            }
        }
        return res;
    }
};


//Approach2:-
// We can use a mathematical approach to solve this problem. We can calculate the number of ways Alice can win by considering the parity of the sum of the indices of the flowers. If the sum is odd, Alice wins. We can calculate the number of odd sums by considering the number of odd and even indices in both lanes.


//CODE:-
class Solution {
public:
    long long flowerGame(int n, int m) {
        long long res=floor((double) n*m/2);
        return res;
    }
};