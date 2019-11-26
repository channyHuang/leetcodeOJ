# leetcodeOJ
notes while solving problems in leetcode


1. "不能重复利用这个数组中同样的元素"指的是不能利用同一数组同一下标的数两次，不同下标的相同元素可用。。。
2. 两数相加。－
3. 无重复字符的最长子串。用一个数组记录第i个字符上一次出现的下标，已有记录的就更新当前长度，新长度从上一次的下标+1开始
4. 寻找两个有序数组的中位数。－
7. 整数反转。注意int的范围啊范围！！！[-2^31, 2^31-1]!!! int型整数正负转换时不能直接转，加判断！！！
8. 字符串转换整数 (atoi)。注意int的范围+1
9. 回文数。同7
11. 盛最多水的容器。－
13. 罗马数字转整数。－
14. 最长公共前缀。－

20. 有效的括号。－
21. 合并两个有序链表。－

26. 删除排序数组中的重复项。－
27. 移除元素。－

35. 搜索插入位置。二分。。。
56. 合并区间。sort的cmp报错???
58. 最后一个单词的长度。－

66. 加一。－
67. 二进制求和。－
69. x 的平方根。二分，注意int越界！！！用x/m>m判断而不是x>m*m。
70. 爬楼梯。菲波那契数列，记不住公式啊啊啊，超时啊啊啊。。。

83. 删除排序链表中的重复元素。

88. 合并两个有序数组。－

100. 相同的树。－
101. 对称二叉树。－

104. 二叉树的最大深度。－
108. 将有序数组转换为二叉搜索树。－
110. 平衡二叉树。－
111. 二叉树的最小深度。－
112. 路径总和。－
118. 杨辉三角。－
119. 杨辉三角 II。用公式推导前后项关系，C(n, m) = n!/(m!(n-m)!), C(n, m-1)=xC(n,m)
121. 买卖股票的最佳时机。应该用DP的，直接暴力过了。
125. 验证回文串。－
136. 只出现一次的数字。曾经很火的一道题，一个数与自身的异或是0，所有数异或一遍，得到的就是只出现一次的数字。
141. 环形链表。判断链表中是否有环，可用两个指针，一个每次走一步，另一个每次走两步，如果有环必定会相遇。
155. 最小栈。每次入栈2个元素，一个是入栈的元素本身，一个是当前栈元素的最小值
160. 相交链表。查找两个链表的相交点，可用两个指针走两遍，第一遍走掉长度差，短的重新指到长的的头部；第二遍一起走找到相同的地址即可。

167. 两数之和 II - 输入有序数组。
168. Excel表列名称。－
169. 求众数。－
171. Excel表列序号。－
172. 阶乘后的零。统计有多少个5。知道的就很简单，不知道的想破脑袋。。。
175. 组合两个表。left join, right join
176. 第二高的薪水。用max可以
177. 第N高的薪水。distinct; limit m,n
178. 分数排名。rank用大于该分数的个数表示，两层select

180. 连续出现的数字。没有什么是两个表不能解决的问题，如果有，那就三个表。。。
181. 超过经理收入的员工。查找一个表当两个表，对比
182. 查找重复的电子邮箱。group by + having + count
183. 从不订购的客户。not in
184. 部门工资最高的员工。inner join + on
185. 部门工资前三高的所有员工。inner join + on + where + count
189. 旋转数组。面试题。分两种情况，k和n的最大公约数为factor，则需要循环factor次，i从0到factor - 1，每次走一轮从i->(i + k ) % n回到i
190. 颠倒二进制位。－
191. 位1的个数。位运算，还可以再优化，n&(n-1)去掉最后一位1
196. 删除重复的电子邮箱。同181，用两张表
197. 上升的温度。datediff返回两日期之差，天数
198. 打家劫舍。动态规划
202. 快乐数。－
203. 移除链表元素。－
204. 计数质数。直接求会超时，leetcode上需要用厄拉多塞筛法，isNotPri[n]，每算一个质数，把它的倍数都划掉，以空间换时间。
205. 同构字符串。题目有岐义，为什么ab-aa是false?s中的b对应a，a不变这样是不行的？
206. 反转链表。－
217. 存在重复元素。－
231. 2的幂。－
234. 回文链表。可以修改输入链表你怎么不说?改了输入的数据的题感觉没意义哦～
237. 删除链表中的节点。阅读理解+1，题目表述不明确，给定的node就是要删除的那个节点，只有一个参数，想办法删。。。
258. 各位相加。－

262. 行程和用户。left join, right join, inner join, on, where
263. 丑数。－
268. 缺失数字。－
287. 寻找重复数。可看作是数组链表，有重复数字->有环。
     方法一：step 1, 快慢指针找环，见141；step 2, 确定环的入口，快指针回到头，重新走，必定和慢指针相遇在环入口，数学证明走起～
     方法二：如果原数组可以改变，则可以把当前数字对应下标的数字取负，如果已经是负数说明出现过了
299. 猜数字游戏。－
303. 区域和检索 - 数组不可变。可以只求前i个数的和的，愣是把所有i-j和都求出来了，险过。。。
326. 3的幂。不能循环或者递归，就只有充分利用条件：int的范围，3是质数。最大的int且是3的幂的是1162261467
342. 4的幂。不能循环或者递归，枚举总可以了吧
344. 反转字符串。－
349. 两个数组的交集。考集合set的操作，熟悉stl
387. 字符串中的第一个唯一字符。－
389. 找不同。－
401. 二进制手表。－
437. 
541. 反转字符串 II。－
595. 大的国家。select
596. 超过5名学生的课。有坑，表中有重复记录，结果不记。。。
599. 两个列表的最小索引总和。－

601. 体育馆的人流量。有坑，按日期不行，得按id.类似180
620. 有趣的电影。select

626. 换座位。left join
627. 交换工资。sql也有三元语法，xxx = if(xxx, Y, N)
645. 错误的集合。－
989. 数组形式的整数加法。－
1021. 删除最外层的括号。－
1051. 高度检查器。看不懂题目+1，看排好队后谁没站到位置上，统计这些人的个数。
1078. Bigram 分词。－击败了100.00%的用户～哦㖿～
1114. 按序打印。用mutex.
1115. 交替打印foobar。同1114.
1116. 打印零与奇偶数。每个函数只调用一次。。。
1117. H2O 生成。

1137. 第N个菲波那契数。同70。

1179. 重新格式化部门表。pivot是orical的，sql直接一个个选吧。。。

1195. 交替打印字符串。当一个线程退出后另一个线程还在等待锁释放，则会出现死锁，退出不自动释放mutex?

1226. 哲学家进餐。WA。。。
LCP2. 分式化简。－
LCP1. 猜数字。－
