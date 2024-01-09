Statement 64) Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.

-----------------------------------------------------------------
SOLUTION = /**
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;  // Handle empty list

        ListNode* dummy = new ListNode(0, head);  // Create a dummy head
        ListNode* prev = dummy;

        while (head) {
            while (head->next && head->val == head->next->val) {
                head = head->next;  // Skip duplicates
            }
            if (prev->next == head) {  // No duplicates found
                prev = prev->next;
            } else {
                prev->next = head->next;  // Remove duplicates
            }
            head = head->next;
        }

        return dummy->next;  // Return the modified list
    }
};
