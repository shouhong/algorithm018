### 第九周学习笔记

#### Rabin-Karp 算法
1. 基本思想：
	* 假设子串的长度为 M（pat），目标字符串的长度为 N（txt）
	* 计算子串的 hash 值 hash_pat
	* 计算目标字符串 txt 中每个长度为 M 的子串的 hash 值（共需计算 N-M+1 次）
	* 比较 hash 值：如果 hash 值不同，字符串必然比匹配；如果 hash 值相同，还需要使用朴素算法再次判断
2. 计算字符串 txt 中每个长度为 M 的子串的 hash 值的算法：
	* Hash 值将每个字符当作一位，按 256 进制计算
	* 为了防止超过整数的最大表示范围，计算过程不断对某个大的质数（如 9997）取余
	* 计算的过程是一个滑动窗口，每次只需将最高位置去掉，再添加一个最低位，不用对每个字符都处理

#### KMP 算法
1. KMP 算法（Knuth-Morris-Pratt）的思想：当子串与目标字符串不匹配时，其实已经知道了已经匹配的那部分字符，如已经匹配到 “ABCDAB”后，发现不匹配了，那下一次匹配可以直接跳到下一个AB处（即右移4 位，而不是 1 位），这样就提高了效率。
2. 参考链接：
	* [https://www.bilibili.com/video/av11866460?from=search&seid=17425875345653862171](https://www.bilibili.com/video/av11866460?from=search&seid=17425875345653862171)
	* [https://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html](https://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)