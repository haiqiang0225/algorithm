**题目**：

<p>定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。</p>

<p>&nbsp;</p>

<p><strong>示例:</strong></p>

<pre><strong>输入:</strong> 1-&gt;2-&gt;3-&gt;4-&gt;5-&gt;NULL
<strong>输出:</strong> 5-&gt;4-&gt;3-&gt;2-&gt;1-&gt;NULL</pre>

<p>&nbsp;</p>

<p><strong>限制：</strong></p>

<p><code>0 &lt;= 节点个数 &lt;= 5000</code></p>

<p>&nbsp;</p>

<p><strong>注意</strong>：本题与主站 206 题相同：<a href="https://leetcode-cn.com/problems/reverse-linked-list/" one-link-mark="yes">https://leetcode-cn.com/problems/reverse-linked-list/</a></p>


```java
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null) {
            return null;
        }
        // 反转时注意先保存当前反转结点的next域，防止断链，之后依次反转即可
        ListNode pre = head;
        ListNode cur = head.next;
        ListNode curNext = null;
        head.next = null;
        while (cur != null) {
            curNext = cur.next;
            cur.next = pre;
            pre = cur;
            cur = curNext; 
        }
        return pre;
    }
}
```

