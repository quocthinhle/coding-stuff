import java.util.Arrays;
import java.util.List;

// link to problem: https://leetcode.com/problems/merge-k-sorted-lists

class ListNode {
	int val;
	ListNode next;
	ListNode() {}
	ListNode(int val) {this.val = val; }
	ListNode(int val, ListNode next) {
		this.val = val;
		this.next = next;
	}
}

class Solution1 {
	public ListNode MergeKLists(ListNode[] lists) {
		if (lists.length == 0) return null;
		if (lists.length == 1) return lists[0];

		int mid = (int) lists.length / 2;
		ListNode[] listLeft = Arrays.copyOfRange(lists, 0, mid);
		ListNode[] listRight = Arrays.copyOfRange(lists, mid + 1, lists.length);
		
		ListNode ResLeft = MergeKLists(listLeft);
		ListNode ResRight = MergeKLists(listRight);

		return Merge2Lists(ResLeft, ResRight);
	}

	public ListNode Merge2Lists(ListNode a, ListNode b) {
		if (a == null) return b;
		ListNode Result = new ListNode();
		ListNode through = Result;
		while (a != null && b != null) {
			if (a.val > b.val) {
				through.val = b.val;
				b = b.next;
			}
			else {
				through.val = a.val;
				a = a.next;
			}

			if (a != null || b != null) {
				through.next = new ListNode();
				through = through.next;
			}
		}

		while (a != null) {
			through.val = a.val;
			a = a.next;
			if (a != null) {
				through.next = new ListNode();
				through = through.next;
			}
		}

		while (b != null) {
			through.val = b.val;
			b = b.next;
			if (b != null) {
				through.next = new ListNode();
				through = through.next;
			}
		}

		return Result;
	}
}

public class MergeKLists {
	public static void main(String[] args) {

	}
}