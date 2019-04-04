#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode Head;
    struct ListNode *ptr = NULL, *current = &Head; 
    
    int carry = 0, result;
    int val1 = l1->val, val2 = l2->val;
    
    while(1) {
        result = val1 + val2 + carry;
        
        carry = 0;
        if(result > 9) {
            carry = 1;
            result -= 10;
        }
            
        
        ptr = malloc(sizeof(struct ListNode));
        ptr->val = result;
        ptr->next = NULL;
        
        current->next = ptr;
        current = ptr;
        
        if( l1->next == l2->next && carry != 1)
            break;
        
        if(l1->next != NULL) {
            l1 = l1->next;
            val1 = l1->val;
        } else {
            val1 = 0;
        }
            
        if(l2->next != NULL) {
           l2 = l2->next; 
           val2 = l2->val;
        } else {
            val2 = 0;
        }
    }
    
    current = Head.next;
    return current;
}
