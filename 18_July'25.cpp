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

//141. Linked List Cycle
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Approach:
// 1. Use two pointers, slow and fast.
// 2. Move slow by one step and fast by two steps.
// 3. If they meet, there is a cycle; otherwise, if fast reaches the end, there is no cycle.

// CODE:
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }
        ListNode* temp1=head;
        ListNode* temp2=head;
        while(temp2!=NULL && temp2->next!=NULL){
            temp1=temp1->next;
            temp2=temp2->next->next;
            
            if(temp1==temp2){
                return true;
            }
        }
        return false;
    }
};