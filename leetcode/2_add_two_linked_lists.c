// Example:

// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//Using another node to store the results
// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
//     struct ListNode* curr = (struct ListNode*)malloc(sizeof(struct ListNode));
//     curr->val = 1;
//     curr->next = NULL;
    
//     int carry = 0;
//     struct ListNode* head = curr;
     
    
//     while(l1 != NULL || l2 != NULL){
//         int a = 0;
//         int b = 0;
//         int sum =0;
        
//         if (l1 != NULL) {
//             a = l1->val;
//             l1 = l1->next;
//         }
//         if (l2 != NULL) {
//             b = l2->val;
//             l2 = l2->next;
//         }
        
//         sum = a + b + carry;
//         carry = sum/10;
//         if (sum >= 10) sum = sum%10; 
        
//         struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
//         node->val = sum;
//         node->next = NULL;
//         curr->next = node;
//         curr = curr->next;
//     }
    
//     if (carry > 0){
//         struct ListNode* carry_node  = (struct ListNode*)malloc(sizeof(struct ListNode));
//         carry_node->val = carry;
//         carry_node->next = NULL;
//         curr->next = carry_node;
//         curr = curr->next;
//     }

//     return head->next;
    
// }


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;
    int flag = 0;
    struct ListNode* res = l1;
     
    // when both of equal length
    while(l1->next != NULL && l2->next != NULL){
        sum = l1->val + l2->val + carry;
        carry = sum/10;
        if (sum >= 10) sum = sum%10; 
        l1->val = sum;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    // when both of equal length
    if (l1->next == NULL && l2->next == NULL){
        sum = l1->val + l2->val + carry;
        carry = sum/10;
        if (sum >= 10) sum = sum%10; 
        l1->val = sum;
        if (carry > 0){
            struct ListNode* carry_node  = (struct ListNode*)malloc(sizeof(struct ListNode));
            carry_node->val = carry;
            carry_node->next = NULL;
            l1->next = carry_node;
            l1 = l1->next;
        }
        flag = 1;
    }
    
    // when l1 length is more than l2
    if (l1->next != NULL && l2->next == NULL){
        sum = l1->val + l2->val + carry;
        carry = sum/10;
        if (sum >= 10) sum = sum%10; 
        l1->val = sum;
        l1 = l1->next;
    }
    
    // when l2 length is more than l1
    if (l1->next == NULL && l2->next != NULL){
        l1->next = l2->next;
        l2->next = NULL;
        sum = l1->val + l2->val + carry;
        carry = sum/10;
        if (sum >= 10) sum = sum%10; 
        l1->val = sum;
        l1 = l1->next;
    }
    
    // when l1 and l2 length not equal
    while(l1->next != NULL){
        sum = l1->val + carry;
        carry = sum/10;
        if (sum >= 10) sum = sum%10; 
        l1->val = sum;
        l1 = l1->next;
    }
    
    // when l1 and l2 length not equal, flag used for the same
    if (l1->next == NULL && flag == 0){
        sum = l1->val + carry;
        carry = sum/10;
        if (sum >= 10) sum = sum%10; 
        l1->val = sum;
        if (carry > 0){
            struct ListNode* carry_node  = (struct ListNode*)malloc(sizeof(struct ListNode));
            carry_node->val = carry;
            carry_node->next = NULL;
            l1->next = carry_node;
            l1 = l1->next;
        }
    }

return res;
    
}
