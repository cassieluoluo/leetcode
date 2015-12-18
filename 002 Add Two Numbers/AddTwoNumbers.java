/**
 ** Definition for singly-linked list.
 ** public class ListNode {
 **     int val;
 **     ListNode next;
 **     ListNode(int x) { val = x; }
 ** }
 **/
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1==null) return l2; // It's a kind of way to opmitimize
        if (l2==null) return l1;
        int carry = 0;
        ListNode rtn = new ListNode(0);
        ListNode p = rtn;
        while(l1!=null || l2!= null){
            ListNode current = new ListNode(0);

            if(l1==null) {
                current.val = l2.val + carry;
                carry = current.val/10;
                current.val %= 10;
                p.next = current;
                p = p.next;
                l2 = l2.next;
            }
            else if(l2==null) {
                current.val = l1.val + carry;
                carry = current.val/10;
                current.val %= 10;
                p.next = current;
                p = p.next;
                l1 = l1.next;
            }
            else {
                current.val = l1.val + l2.val + carry;
                carry = current.val/10;
                current.val %= 10;
                p.next = current;
                p = p.next;
                l1 = l1.next;
                l2 = l2.next;
            }
        }
        if(carry!=0) p.next = new ListNode(carry);
        return rtn.next;
    }
}
