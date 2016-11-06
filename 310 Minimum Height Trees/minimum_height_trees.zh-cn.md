# 310. Minimum Height Trees

## 分类
* 图

## 解法
首先找到所有叶节点，也就是入度为1的节点，将它们从图中移除。新产生的叶节点也重复做同样的操作，直到只剩下一个或两个节点，这就是最终结果。

## 复杂度
* 时间复杂度：`O(n)`
* 空间复杂度：`O(n)`

## 边界条件
单个节点直接返回自己即可。

## 备注
移除入度为1的节点可以通过队列来实现。

## 参考文献
[https://discuss.leetcode.com/topic/30956/two-o-n-solutions](https://discuss.leetcode.com/topic/30956/two-o-n-solutions)
[https://discuss.leetcode.com/topic/30572/share-some-thoughts](https://discuss.leetcode.com/topic/30572/share-some-thoughts)
