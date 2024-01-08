Statement 58) You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:


Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 

Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.

-------------------------------------------------------------------------------------------------------
SOLUTION = class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);  // Dummy head for result list
        ListNode* current = dummyHead;         // Pointer for building result list
        int carry = 0;                         // Carry for digit addition

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }

        return dummyHead->next;  // Return the actual result list, excluding dummy head
    }
};

---------------------------------------------------------------------------------------------------------
Explanation:

Dummy Head: A dummy head node is created to simplify the process of managing the head of the result list.
Initialization: Pointers current and carry are initialized to traverse the lists and handle carry-overs.
Iterative Addition:
While there are nodes in either list or a carry exists:
Calculate the sum of current digits and the carry.
Update the carry for the next iteration.
Create a new node with the sum's units digit and append it to the result list.
Move pointers to the next nodes in both lists.
Return Result: The actual result list starts after the dummy head, so its next node is returned.
Key Points:

The code handles lists of different lengths and potential carry-overs effectively.
It builds the result list in reverse order, ensuring correct digit placement.
The dummy head simplifies handling edge cases and avoids special checks for the first node.
