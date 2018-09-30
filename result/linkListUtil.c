/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     struct ListNode *next;
 *      * };
 *       */
struct ListNode* oddEvenList(struct ListNode* head) {
    /*特殊条件*/
    if(head==NULL || head->next==NULL || head->next->next==NULL)
    {
        return head;
    }
    
    /*原链表存储奇数节点，偶数链表外链*/
    struct ListNode *pcur=head, *pnext=NULL, *evenhead=NULL, *evenprev=NULL;
    
    /*遍历链表，条件为满足奇数和偶数节点*/
    while(pcur->next && pcur->next->next)
    {
        pnext=pcur->next;  //pnext指向下一个偶数节点
        
        pcur->next=pnext->next; /*原链表只存储奇数节点*/
        
        /*处理偶数节点*/
        if(evenhead == NULL)
        {
            evenhead=pnext;
            evenprev=pnext;
        }
        else
        {
            evenprev->next=pnext;
            evenprev=pnext;
        }
        /*偶数链表的末尾节点指向空*/
        evenprev->next=NULL;

        /*当前节点前进下一个节点（已跳过偶数节点）*/
        pcur=pcur->next;
    }
    
    /*如果奇数节点有下一个节点，则该节点是偶数节点，应该挂接在偶数链表*/
    if(pcur->next)
    {
        evenprev->next=pcur->next;
    }
    /*奇数链表的末尾指针指向偶数链表的头节点*/
    pcur->next=evenhead;
    
    return head;
}
