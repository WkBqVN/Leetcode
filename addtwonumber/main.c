// You are given two non - empty linked lists representing two non -
// negative integers.The digits are stored in reverse order,
//     and each of their nodes contains a single
//         digit.Add the two numbers and return the sum as a linked list.
//
//     You may assume the two numbers do not contain any leading zero,
//     except the number 0 itself.
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output : [ 7, 0, 8 ] Explanation : 342 + 465 = 807.
//
//     Example 2 :
//
//     Input : l1 = [0],l2 = [0] Output : [0]
//    Example 3 :
//     Input : l1 = [ 9, 9, 9, 9, 9, 9, 9 ],l2 = [ 9, 9, 9, 9 ] Output
//     : [ 8, 9, 9, 9, 0, 0, 0, 1 ]
//
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *nextNode;
};

struct ListNode *addTwoNumber(struct ListNode *l1, struct ListNode *l2) {
  sstruct ListNode *head = NULL;
    struct ListNode *current = NULL;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {

        int a = (l1 != NULL) ? l1->val : 0;
        int b = (l2 != NULL) ? l2->val : 0;

        int sum = a + b + carry;

        struct ListNode *newNode = malloc(sizeof(struct ListNode));

        newNode->val = sum % 10;
        newNode->nextNode = NULL;

        carry = sum / 10;
        if (head == NULL)
        {
            head = newNode;
        }else{
            current->nextNode = newNode;
        }

        current = newNode;

        if (l1 != NULL)
            l1 = l1->nextNode;

        if (l2 != NULL)
            l2 = l2->nextNode;
    }
    return head;
}
int main() {
  struct ListNode *node_l1_1 = malloc(sizeof(struct ListNode));
  struct ListNode *node_l1_2 = malloc(sizeof(struct ListNode));
  struct ListNode *node_l1_3 = malloc(sizeof(struct ListNode));
  node_l1_1->val = 2;
  node_l1_1->nextNode = node_l1_2;

  node_l1_2->val = 4;
  node_l1_2->nextNode = node_l1_3;

  node_l1_3->val = 3;
  node_l1_3->nextNode = NULL;

  struct ListNode *node_l2_1 = malloc(sizeof(struct ListNode));
  struct ListNode *node_l2_2 = malloc(sizeof(struct ListNode));
  struct ListNode *node_l2_3 = malloc(sizeof(struct ListNode));
  node_l2_1->val = 5;
  node_l2_1->nextNode = node_l2_2;

  node_l2_2->val = 6;
  node_l2_2->nextNode = node_l2_3;

  node_l2_3->val = 4;
  node_l2_3->nextNode = NULL;
  struct ListNode *result = addTwoNumber(node_l1_1, node_l2_1);
  while (result->nextNode != NULL) {
    printf("result is %d\n", result->val);
  }
}
