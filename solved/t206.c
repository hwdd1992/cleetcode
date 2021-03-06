//反转一个单链表。
//
// 示例:
//
// 输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL
//
// 进阶:
//你可以迭代或递归地反转链表。你能否用两种方法解决这道题？
// Related Topics 链表

#include "../common/LinkedList.h"


//leetcode submit region begin(Prohibit modification and deletion)
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    //
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        return head;
    }
    Node newHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}


Node getNode() {
    Node node = (Node) malloc(sizeof(Node));
    return node;
}


Node getHead() {
    int n = 4;
    int arr[n];
    for (int j = 0; j < n; ++j) {
        arr[j] = j;
    }
    Node head = getNode();
    Node temp = head;
    head->val = arr[0];
    for (int i = 1; i < n; ++i) {
        Node newNode = getNode();
        newNode->val = arr[i];
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void show(Node pNode) {
    while (pNode != NULL) {
        if (pNode->next != NULL) {
            printf("%d->", pNode->val);
        }else{
            printf("%d\n", pNode->val);
        }
        pNode = pNode->next;
    }
}

int main(void){
    Node head = getHead();
    show(head);
    head = reverseList(head);
    show(head);
    return 0;
}

//leetcode submit region end(Prohibit modification and deletion)