// 21. Merge Two Sorted Lists

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* curr = (struct ListNode*)malloc(sizeof(struct ListNode));
    curr->val = 0;
    curr->next = NULL;
    struct ListNode* res = curr;    
    struct ListNode* tmp1 = l1;
    struct ListNode* tmp2 = l2;
    
    while(tmp1!=NULL || tmp2 != NULL){
        int temp1=INT_MAX;
        int temp2=INT_MAX;
        if(tmp1!=NULL) temp1 = tmp1->val;
        if(tmp2!=NULL) temp2 = tmp2->val;
        
        if(temp1<=temp2){
            struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
            node->val = temp1;
            node->next = NULL;
            curr->next = node;
            curr = curr->next;
            tmp1 = tmp1->next;
        }else{
            struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
            node->val = temp2;
            node->next = NULL;
            curr->next = node;
            curr = curr->next;
            tmp2 = tmp2->next;
        }
    }
    
    return res->next;
}