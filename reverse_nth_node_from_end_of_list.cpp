Statement 63) Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

----------------------------------------------------------
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
 ListNode*Reverse(ListNode*&head){
     ListNode*curr=head;
     ListNode*prev=NULL;
     while(curr!=NULL){
         ListNode*forw=curr->next;
         curr->next=prev;
         prev=curr;
         curr=forw;
     }
     return prev;
 }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      
      ListNode*temp1=Reverse(head);
      ListNode*temp=temp1;
      if(n==1){
        ListNode*del=temp1;
        temp1=temp1->next;
        delete del;
      }
      else{

      for(int i=0;i<n-2;i++){
          temp=temp->next;
      }
      ListNode*flag=temp->next;
      temp->next=flag->next;
      delete flag;
      }
      ListNode*ret=Reverse(temp1);
        return ret; 
        
    }
};
