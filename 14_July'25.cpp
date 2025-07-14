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

//1290. Convert Binary Number in a Linked List to Integer
// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
// Return the decimal value of the number in the linked list.
// The most significant bit is at the head of the linked list.

//Approach:
// 1. Traverse the linked list and construct the binary number.
// 2. Convert the binary number to decimal by multiplying each bit by its corresponding power of 2.

//CODE:

//   Definition for singly-linked list.
struct ListNode {
  int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        string str="";
        int res=0;
        ListNode* temp=head;
        while(head!=NULL){
            str+=to_string(head->val);
            head=head->next;
        }
        int n=str.length()-1;
        for(int i=n;i>=0;i--){
            res+=pow(2,n-i)*(str[i]-'0');
        }
        return res;
    }
};