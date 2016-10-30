# 401. Binary Watch

## 分类
* 枚举法
* 分类2

## 解法
### 枚举法
由于时间的总数量并不多，一共有`12*60=720`种组合，所以可以逐一尝试。判断对应的二进制位和输入是否相等，相等的话就记录结果。在C/C++里，有一个gcc的内置函数`int __builtin_popcount (unsigned int x);`可以用来统计一个整数里包含的1的个数。

* 时间复杂度：`O(1)`
* 空间复杂度：`O(n)`

## 边界条件
无

## 备注
无

## 参考文献
[Bit Fiddling – 3](https://blogs.msdn.microsoft.com/jeuge/2005/06/08/bit-fiddling-3/)