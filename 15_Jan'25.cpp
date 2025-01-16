#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include<string>
#include<unordered_map>
#include<stack>
#include<unordered_set>
using namespace std;

//2429. Minimize XOR
// Given two positive integers num1 and num2, find the positive integer x such that:

// x has the same number of set bits as num2, and
// The value x XOR num1 is minimal.
// Note that XOR is the bitwise XOR operation.

// Return the integer x. The test cases are generated such that x is uniquely determined.

// The number of set bits of an integer is the number of 1's in its binary representation.

//APPROACH 1:-
//beats only 100TC

//CODE:-
class Solution {
public:
    int countset(int num1){
        int temp=num1;
        int count=0;
        while(temp>0){
            if(temp%2!=0){
                count++;
            }
            temp/=2;
        }
        return count;
    }
    int minimizeXor(int num1, int num2) {
        int set1=countset(num1);
        int set2=countset(num2);
        int res;
        if(set1-set2==0){
            return num1;
        }
        int diff=set1-set2;
        if(diff>0){
            res=num1;
            while(diff>0){
                if(res%2==0){
                    res++;
                }
                else{
                    res+=2;
                }
                diff--;
            }

        }
        else if(diff<0){
            res=num1;
            while(diff<0){
                if(res%2==0){
                    res+=1;    
                }
                else{
                    res+=2;
                }
                diff++;
            }
        }
        return res;
    }
};

//APPROACH:-
//set unset bits

//CODE:-
class Solution {
public:
    bool isSet(int &num,int bit){
        return num&(1<<bit);
    }
    bool setBit(int &num,int bit){
        return num|= (1<<bit);
    }
    bool unsetBit(int &num,int bit){
        return num&= ~(1<<bit);
    }

    int countset(int num){
        int count=0;
        while(num>0){
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    int minimizeXor(int num1, int num2) {
        int x=num1;
        int currbits=countset(num1);
        int reqbits=countset(num2);
        int bit=0;
        if(currbits==reqbits){
            return num1;
        }
        if(currbits<reqbits){
            while(currbits<reqbits){
                if(!isSet(x,bit)){
                    setBit(x,bit);
                    currbits++;
                }
                bit++;
            }
        }
        else if(currbits>reqbits){
            while(currbits>reqbits){
                if(isSet(x,bit)){
                    unsetBit(x,bit);
                    currbits--;
                }
                bit++;
            }
        }
        return x;
    }
};