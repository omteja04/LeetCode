/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head) return nullptr;
        ListNode* sentinel = new ListNode(0);
        sentinel -> next = head;

        ListNode* prev = sentinel;
        ListNode* temp = head;

        unordered_set<int> numSet(nums.begin(), nums.end());

        while(temp != NULL) {

            int data = temp -> val;
            if(numSet.find(data) != numSet.end()) {
                prev -> next = temp -> next;
                delete temp;
            } else {
                prev = temp;
            }
            temp = prev -> next;
        }
        ListNode* newHead = sentinel -> next;
        delete sentinel;
        return newHead;
    }
};