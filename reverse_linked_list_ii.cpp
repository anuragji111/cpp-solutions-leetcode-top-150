Statement 61) Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

Example 1:


Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

--------------------------------------------------------------------------
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
    ListNode* reverseBetween(ListNode* head, int left, int right){
        if(head==NULL) return head;
        cout<<"done"<<endl;
        if(head->next==NULL) return head;
        cout<<"done2"<<endl;
        int l=left;
        ListNode *prev=NULL;
        ListNode* ans=head;
       

        while(l>1)
        {
            prev=head;
            head=head->next;
            l--;
        }


        cout<<head->val;
        int loop=right-left+1;
        ListNode* pre=NULL;
        ListNode* nex;
        ListNode* last;
        ListNode* prev2=head;


        while(loop)
        {
            if(head)
           { 
               nex=head->next;
            head->next=pre;
            pre=head;
            head=nex;
            }

            loop--;
        }
        if(prev!=nullptr)
        {if(pre!=nullptr)
        {
            prev->next=pre;
        }


        else prev->next=NULL;}
        else ans=pre;
        prev2->next=head;

        return ans;
    }
};
