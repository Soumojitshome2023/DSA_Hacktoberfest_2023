/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){
        struct ListNode* san = head;
        struct ListNode* sh = head;
        if(head)
        sh=sh->next;
        while(san && sh){
            //swap(sh->val,san->val);
            int temp=sh->val;
            sh->val=san->val;
            san->val=temp;
            san=sh->next;
            if(san)
            sh=san->next;
        }
        return head;
}
