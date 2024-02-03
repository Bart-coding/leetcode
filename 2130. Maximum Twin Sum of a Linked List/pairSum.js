/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {number}
 */
var pairSum = function(head) {
    if (head.next.next === null) return head.val + head.next.val;
    let slow = head, fast = head;
    let stack = [];
    while (fast !== null) {
        stack.push(slow.val);
        slow = slow.next;
        fast = fast.next.next;
    }
    let maxTwinSum = 0;
    while (slow !== null) {
        let sum = stack.pop() + slow.val;
        if (sum > maxTwinSum) maxTwinSum = sum;
        slow = slow.next;
    }
    return maxTwinSum;
};