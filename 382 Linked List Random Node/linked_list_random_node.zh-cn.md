# 382. Linked List Random Node

## 分类
* 蓄水池采样

## 解法
用蓄水池采样算法来实现。每次读到一个新的数值，按照1/n的概率随机地选择是否把它作为最后的结果。读完所有输入后返回选中的数值即可。

## 复杂度
* 时间复杂度：`O(n)`
* 空间复杂度：`O(1)`

## 边界条件
无

## 备注
无

## 参考文献
* [蓄水池采样](http://blog.jobbole.com/42550/)
* [Brief explanation for Reservoir Sampling](https://discuss.leetcode.com/topic/53753/brief-explanation-for-reservoir-sampling)
