notes while solving problems in leetcode


1. "不能重复利用这个数组中同样的元素"指的是不能利用同一数组同一下标的数两次，不同下标的相同元素可用。。。
2. 两数相加。－
3. 无重复字符的最长子串。用一个数组记录第i个字符上一次出现的下标，已有记录的就更新当前长度，新长度从上一次的下标+1开始
4. 寻找两个有序数组的中位数。－
5. 最长回文子串。遍历每个字母作为中心，往两边扩展找回文，记录长度并更新。
6. Z 字形变换。要么以空间换时间，要么以时间换空间。以时间换空间下标计算太麻烦了，懒得算。。。
7. 整数反转。注意int的范围啊范围！！！[-2^31, 2^31-1]!!! int型整数正负转换时不能直接转，加判断！！！
8. 字符串转换整数 (atoi)。注意int的范围+1
9. 回文数。同7
10. 正则表达式匹配。c++11有regex, regex_match, 不过效率不快哦
11. 盛最多水的容器。－
12. 整数转罗马数字。分类，情况有点多。
13. 罗马数字转整数。－
14. 最长公共前缀。－
15. 三数之和。直接暴力会TLE，用双指针会好点，不知道还有没有更优的
16. 最接近的三数之和。双指针
17. 电话号码的字母组合。－
18. 四数之和。双指针
19. 删除链表的倒数第N个节点。－
20. 有效的括号。－
21. 合并两个有序链表。－
22. 括号生成。递归
23. 合并K个排序链表。－
24. 两两交换链表中的节点。－
25. K 个一组翻转链表。链表操作
26. 删除排序数组中的重复项。－
27. 移除元素。－
28. 实现 strStr()。最优的可以用KMP算法，不过这题后台数据量太小。。。
29. 两数相除。滑动窗口，除数每次增加一倍
30. 串联所有单词的子串。给的words可能有重复，hashmap
31. 下一个排列。一次遍历
32. 最长有效括号。栈
33. 搜索旋转排序数组。－
34. 在排序数组中查找元素的第一个和最后一个位置。－
35. 搜索插入位置。二分。。。
36. 有效的数独。只需要判断已填的数是否有冲突，不需要考虑它是否有解
37. 解数独。深搜
38. 38. 报数。没看懂题目，过...............
39. 组合总和。回溯
40. 组合总和 II。回溯
41. 缺失的第一个正数。有重复元素，不能用快排了
42. 接雨水。分治，找到中间最高的块，比其中一边高则分两部分，比两边都矮就直接用小边界减掉高度并相加
43. 字符串相乘。大数乘法
44. 通配符匹配。递归的话会TLE, 只能二维dp了
45. 跳跃游戏 II。只需要推断出最小步数是递增的
46. 全排列。回溯
47. 全排列 II。回溯，BFS，剪枝
48. 旋转图像。－
49. 字母异位词分组。－
50. Pow(x, n)。－
51. N皇后。深搜。
52. N皇后II。还是深搜，可共用上题的解答。
53. 最大子序和。简单的动态规划，dp[i]为以nums[i]结尾包括nums[i]的最大子序和，要求结果为dp中最大的数。
54. 螺旋矩阵。数组
55. 跳跃游戏。－
56. 合并区间。sort的cmp报错???
57. 插入区间。分情况，插前面，插后面，插中间的话修改已有区间的头尾。
58. 最后一个单词的长度。－
59. 螺旋矩阵 II。－
60. 第k个排列。回溯
61. 旋转链表。链表操作
62. 不同路径。dp
63. 不同路径II。dp
64. 最小路径和。dp
65. 有效数字。为什么".1"是true?
66. 加一。－
67. 二进制求和。－
68. 文本左右对齐。就字符串处理
69. x 的平方根。二分，注意int越界！！！用x/m>m判断而不是x>m*m。
70. 爬楼梯。菲波那契数列，记不住公式啊啊啊，超时啊啊啊。。。
71. 简化路径。栈操作
72. 编辑距离。二维dp
73. 矩阵置零。－
74. 搜索二维矩阵。－
75. 颜色分类。－
76. 最小覆盖子串。可以用map,有点耗时。
77. 组合。－
79. 单词搜索。回溯
80. 删除排序数组中的重复项 II。－
81. 搜索旋转排序数组 II。－
82. 删除排序链表中的重复元素 II。－
83. 删除排序链表中的重复元素。
84. 柱状图中最大的矩形。注意重复元素。题解说用单调栈
85. 最大矩形。二维dp?
86. 分隔链表。－
87. 扰乱字符串。递归就可以
88. 合并两个有序数组。－
89. 格雷编码。－　
90. 子集 II。回溯
91. 解码方法。dp
92. 反转链表 II。链表插入操作
93. 复原IP地址。－
94. 二叉树的中序遍历。－
95. 不同的二叉搜索树 II。－ 
96. 不同的二叉搜索树。分别以每个点为根，左边左子树，右边右子树，递归。
97. 交错字符串。二维dp
98. 验证二叉搜索树。递归
99. 恢复二叉搜索树。Morris遍历方法。在遇到逆序对的时候，如果是第一次遇见，则存储索引小的那个，如果不是，则存储索引大的那个。可以把前驱结点的右指针这一特性利用起来，从而降低空间复杂度。
100. 相同的树。－
101. 对称二叉树。－
102. 二叉树的层次遍历。－ 
103. 二叉树的锯齿形层次遍历。－
104. 二叉树的最大深度。－
105. 从前序与中序遍历序列构造二叉树。－
106. 从中序与后序遍历序列构造二叉树。－
107. 二叉树的层次遍历 II。－
108. 将有序数组转换为二叉搜索树。－
109. 有序链表转换二叉搜索树。－
110. 平衡二叉树。－
111. 二叉树的最小深度。－
112. 路径总和。－
113. 路径总和 II。DFS
114. 二叉树展开为链表。为什么一定要右链？左边不行吗？一定要右链而且按顺序才能过
115. 不同的子序列。二维dp，结果要用long long，不然会溢出。
116. 填充每个节点的下一个右侧节点指针。－
117. 填充每个节点的下一个右侧节点指针 II。先右节点后左节点
118. 杨辉三角。－
119. 杨辉三角 II。用公式推导前后项关系，C(n, m) = n!/(m!(n-m)!), C(n, m-1)=xC(n,m)
121. 买卖股票的最佳时机。应该用DP的，直接暴力过了。
122. 买卖股票的最佳时机 II。根据题目的意思，当天卖出以后，当天还可以买入，所以其实可以第三天卖出，第三天买入，第四天又卖出（（5-1）+ （6-5） === 6 - 1）。所以算法可以直接简化为只要今天比昨天大，就卖出。
123. 买卖股票的最佳时机 III。三维dp，dp[i][j][k]表示第i天第j次交易，k=0或1表示买入或卖出，注意边界条件
124. 二叉树中的最大路径和。递归吧
125. 验证回文串。－
126. 单词接龙 II。广搜TLE，深搜也TLE。不知道为什么题解里用广搜的都过了，放弃、
127. 单词接龙。广搜
128. 最长连续序列。可以用unordered_set记录下数组，然后对每个数x，先判断x-1不在set中，因为如果x-1在set中，那么x不可能是开头。然后x逐渐+1找到以x开头最长的长度。O(2n)?
129. 求根到叶子节点数字之和。dfs
130. 被围绕的区域。－
131. 分割回文串。－
132. 分割回文串 II。一维dp。dp[i]为s[0-i]的结果
133. 克隆图。－
134. 加油站。－
135. 分发糖果。贪心，分数最少的先发。
136. 只出现一次的数字。曾经很火的一道题，一个数与自身的异或是0，所有数异或一遍，得到的就是只出现一次的数字。
137. 只出现一次的数字 II。看了官方解答～
```
	    # first appearance: 
            # add num to seen_once 
            # don't add to seen_twice because of presence in seen_once
            
            # second appearance: 
            # remove num from seen_once 
            # add num to seen_twice
            
            # third appearance: 
            # don't add to seen_once because of presence in seen_twice
            # remove num from seen_twice
            seen_once = ~seen_twice & (seen_once ^ num)
            seen_twice = ~seen_once & (seen_twice ^ num)
```
138. 复制带随机指针的链表。官方的新旧交替更优些
139. 单词拆分。广搜深搜都会超时，dp,dp[i]表示s(0,i)可以被拆分
140. 单词拆分 II。dp[i]表示s(i, len)的所有拆分。可以先判断下是否包含dict中没有的字母，简单排除这种不能拆分的情况。
141. 环形链表。判断链表中是否有环，可用两个指针，一个每次走一步，另一个每次走两步，如果有环必定会相遇。
142. 环形链表 II。快慢指针找到环中的一个节点，快指针回到头节点，两个指针同时移动一步，相逢时即指向环的第一个节点。
143. 重排链表。链表操作
144. 二叉树的前序遍历。－
145. 二叉树的后序遍历。树，遍历
146. LRU缓存机制。c++11 unordered_map
147. 对链表进行插入排序。链表操作
148. 排序链表。－ 
150. 逆波兰表达式求值。栈
151. 翻转字符串里的单词。string的find_first_of, find_first_not_of
153. 寻找旋转排序数组中的最小值。二分
154. 寻找旋转排序数组中的最小值 II。emmm...
155. 最小栈。每次入栈2个元素，一个是入栈的元素本身，一个是当前栈元素的最小值
160. 相交链表。查找两个链表的相交点，可用两个指针走两遍，第一遍走掉长度差，短的重新指到长的的头部；第二遍一起走找到相同的地址即可。
162. 寻找峰值。－
164. 最大间距。桶排序，学到了
165. 比较版本号。－ 
166. 分数到小数。数学吧
167. 两数之和 II - 输入有序数组。
168. Excel表列名称。－
169. 求众数。－
171. Excel表列序号。－
172. 阶乘后的零。统计有多少个5。知道的就很简单，不知道的想破脑袋。。。
173. 二叉搜索树迭代器。自己实现可中断的中序遍历
174. 地下城游戏。二维dp，但是不能从左上到右下动态规划，需要从右下到左上动态规划。
175. 组合两个表。left join, right join
176. 第二高的薪水。用max可以
177. 第N高的薪水。distinct; limit m,n
178. 分数排名。rank用大于该分数的个数表示，两层select
179. 最大数。字符串排序
180. 连续出现的数字。没有什么是两个表不能解决的问题，如果有，那就三个表。。。
181. 超过经理收入的员工。查找一个表当两个表，对比
182. 查找重复的电子邮箱。group by + having + count
183. 从不订购的客户。not in
184. 部门工资最高的员工。inner join + on
185. 部门工资前三高的所有员工。inner join + on + where + count
187. 重复的DNA序列。滑动窗口+4进制
188. 买卖股票的最佳时机 IV。三维dp，k大的时候会超内存，剪枝当k>=n/2时同122。
189. 旋转数组。面试题。分两种情况，k和n的最大公约数为factor，则需要循环factor次，i从0到factor - 1，每次走一轮从i->(i + k ) % n回到i
190. 颠倒二进制位。－
191. 位1的个数。位运算，还可以再优化，n&(n-1)去掉最后一位1
192. 统计词频。－
193. 有效电话号码。－
194. 转置文件。－
195. 第十行。－
196. 删除重复的电子邮箱。同181，用两张表
197. 上升的温度。datediff返回两日期之差，天数
198. 打家劫舍。动态规划
199. 二叉树的右视图。－
200. 岛屿数量。DFS
201. 数字范围按位与。按位与，n&(n-1)
202. 快乐数。－
203. 移除链表元素。－
204. 计数质数。直接求会超时，leetcode上需要用厄拉多塞筛法，isNotPri[n]，每算一个质数，把它的倍数都划掉，以空间换时间。
205. 同构字符串。题目有岐义，为什么ab-aa是false?s中的b对应a，a不变这样是不行的？
206. 反转链表。－
207. 课程表。－
208. 实现 Trie (前缀树)。－
209. 长度最小的子数组。用 2 个指针，一个指向数组开始的位置，一个指向数组最后的位置，并维护区间内的和sum 大于等于 s 同时数组长度最小。
210. 课程表 II。－
211. 添加与搜索单词 - 数据结构设计。－
212. 单词搜索 II。字典构建字典树，搜网格。
214. 最短回文串。不能用dp，会超空间。s和reverse(s.begin(), s.end())比较查找以s[0]开头的最长回文串。题解说KMP更快~
215. 数组中的第K个最大元素。小根堆。
216. 组合总和 III。－
217. 存在重复元素。－
218. 天际线问题。扫描线，用set自动排序，set存储所有高度。
219. 存在重复元素 II。用map记录上次出现的位置会更快，这里只用了set慢了50%
220. 存在重复元素 III。－
222. 完全二叉树的节点个数。－
223. 矩形面积。结果不溢出不表示过程不溢出啊～
224. 基本计算器。递归算括号会超时，需要用栈，注意计算数字的时候num = num * 10 + s[i] - '0';可能会溢出int，用long long过了
225. 用队列实现栈。－
226. 翻转二叉树。－
227. 基本计算器 II。样例有问题，"-3+2*21/10"输出是0
228. 汇总区间。一遍遍历过
229. 求众数 II。n/k的众数最多只有k-1个。对于这个题，超过n/3的数最多只能有3-1 = 2 个，我们可以先选出两个候选人A,B。 遍历数组，如果投A（当前元素等于A），则A的票数++;如果投B（当前元素等于B），B的票数++；如果A,B都不投（即当前与A，B都不相等）,那么检查此时A或B的票数是否减为0，如果为0,则当前元素成为新的候选人；如果A,B两个人的票数都不为0，那么A,B两个候选人的票数均减一。最后还需要再遍历一遍数组确认
230. 二叉搜索树中第K小的元素。－
231. 2的幂。－
232. 用栈实现队列。－
234. 回文链表。可以修改输入链表你怎么不说?改了输入的数据的题感觉没意义哦～
235. 二叉搜索树的最近公共祖先。－ 
236. 二叉树的最近公共祖先。－ 
237. 删除链表中的节点。阅读理解+1，题目表述不明确，给定的node就是要删除的那个节点，只有一个参数，想办法删。。。
238. 除自身以外数组的乘积。两个空数组 L 和 R。对于给定索引 i，L[i] 代表的是 i 左侧所有数字的乘积，R[i] 代表的是 i 右侧所有数字的乘积
239. 滑动窗口最大值。双向队列，STL-deque。存储下标，每次删除队列后面比当前值小的下标，over~
240. 搜索二维矩阵 II。－
241. 为运算表达式设计优先级。不用去重
242. 有效的字母异位词。－
257. 二叉树的所有路径。－
258. 各位相加。－
260. 只出现一次的数字 III。x & (-x)保留最后一位1。
262. 行程和用户。left join, right join, inner join, on, where
263. 丑数。－
264. 丑数 II。dp，数组，三个指针分别指向同2，3，5相乘的下一个数，取最小的加入数组，移动对应指针
268. 缺失数字。－
273. 整数转换英文表示。字符串处理
274. H指数。二分？
275. H指数 II。同上题一样
278. 第一个错误的版本。－
283. 移动零。－
284. 顶端迭代器。－
287. 寻找重复数。可看作是数组链表，有重复数字->有环。
     方法一：step 1, 快慢指针找环，见141；step 2, 确定环的入口，快指针回到头，重新走，必定和慢指针相遇在环入口，数学证明走起～
     方法二：如果原数组可以改变，则可以把当前数字对应下标的数字取负，如果已经是负数说明出现过了
289. 生命游戏。－
290. 单词规律。－注意一一对应，不多，不少，不重。
292. Nim 游戏。
295. 数据流的中位数。stl的multiset，允许重复的元素。insert时有重复的元素会放在相同元素的最后。
297. 二叉树的序列化与反序列化。字符串处理
299. 猜数字游戏。－
300. 最长上升子序列。－
303. 区域和检索 - 数组不可变。可以只求前i个数的和的，愣是把所有i-j和都求出来了，险过。。。
304. 二维区域和检索 - 矩阵不可变。dp
306. 累加数。回溯
307. 区域和检索 - 数组可修改。应该用线段树的
309. 最佳买卖股票时机含冷冻期。dp
310. 最小高度树。拓扑排序，每次同时入度去掉入度为1的节点，剩下的即是根
312. 戳气球。二维dp。dp[i][j]表示开区间i-j的最大数，dp[i][j]=dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]。
313. 超级丑数。堆
315. 计算右侧小于当前元素的个数。快排会TLE,二分
316. 去除重复字母。每次根据当前字母决定前一个字母要不要留。1.当前字母已存在，跳过当前字母；2. 前一个字母可删且比当前字母大，删；3. 其它情况把当前字母要上
318. 最大单词长度乘积。26位数字记录每个单词每个字母出现与否
319. 灯泡开关。完全平方数的因数的个数是奇数个，其它因数成对出现。
321. 拼接最大数。分治。先从两个数组里各选出i和k-i个（参考402），然后归并，但因为是有重复元素的归并，并不能按照普通的方法，可以借用STL里面的lexicographical_compare函数判断两个数组的字典序大小
322. 零钱兑换。dp
324. 摆动排序 II。分成前后两部分。排序后反序，如果r的个数大于(length(nums) + 1)/2，还是会出现相邻。但实际上，这种情况是不存在有效解的。
326. 3的幂。不能循环或者递归，就只有充分利用条件：int的范围，3是质数。最大的int且是3的幂的是1162261467
328. 奇偶链表。链表操作
329. 矩阵中的最长递增路径。记忆化搜索。
330. 按要求补齐数组。贪心
331. 验证二叉树的前序序列化。栈
332. 重新安排行程。－
334. 递增的三元子序列。一次遍历
336. 回文对。字典树。注意输入中有空字符串
337. 打家劫舍 III。－
338. 比特位计数。－
341. 扁平化嵌套列表迭代器。栈
342. 4的幂。不能循环或者递归，枚举总可以了吧
343. 整数拆分。dp
344. 反转字符串。－
345. 反转字符串中的元音字母。－
347. 前 K 个高频元素。大根堆
349. 两个数组的交集。考集合set的操作，熟悉stl
350. 两个数组的交集 II。不能一次加载所有的元素到内存中怎么办???
352. 将数据流变为多个不相交区间。数据比较弱，直接用数组也能过
354. 俄罗斯套娃信封问题。dp
355. 设计推特。设计
357. 计算各个位数不同的数字个数。－
365. 水壶问题。模拟
367. 有效的完全平方数。－
368. 最大整除子集。dp,dp[i]表示以nums[i]结尾的最大长度，从后往前更新。从前往后贪心WA
371. 两整数之和。位运算，a^b是无进位相加，a&b是进位，(a&b)<<1直到0
373. 查找和最小的K对数字。堆，返回无顺序
374. 猜数字大小。－
375. 猜数字大小 II。DP,dp[i][j]为i到j的最大cost。
376. 摆动序列。dp,up[], down[]两个数组更新
377. 组合总和 Ⅳ。一维dp,需要做溢出处理，否则中间会有的溢出int
378. 有序矩阵中第K小的元素。－ 
380. 常数时间插入、删除和获取随机元素。可以用c++11的unorder_map
381. O(1) 时间插入、删除和获取随机元素 - 允许重复。unordered_multiset险过，容易超时。
382. 链表随机节点。－
383. 赎金信。-
384. 打乱数组。Fisher-Yates 洗牌算法
385. 迷你语法分析器。栈
386. 字典序排数。递归
387. 字符串中的第一个唯一字符。－
388. 文件的最长绝对路径。字符串处理
389. 找不同。－
390. 消除游戏。找规律，每删除一次，总个数减半，等差，差翻倍，头数字要么保持，要么为下一个数
391. 完美矩形。扫描线算法超时。比面积，比四个角的点，用顶点出现次数的奇偶性可以判断重叠。
392. 判断子序列。－
393. UTF-8 编码验证。位运算
394. 字符串解码。深搜
395. 至少有K个重复字符的最长子串。分治，以小于k的字母为分割点
396. 旋转函数。用两式相减求得推导公式
397. 整数替换。3特殊
398. 随机数索引。－
399. 除法求值。有权并查集，或深搜
400. 第N个数字。找规律，迭代
401. 二进制手表。－
402. 移掉K位数字。栈
403. 青蛙过河。一维dp?我用的是map
404. 左叶子之和。－
405. 数字转换为十六进制数。－
406. 根据身高重建队列。排序
409. 最长回文串。－
410. 分割数组的最大值。二维dp
412. Fizz Buzz。－
413. 等差数列划分。数学
414. 第三大的数。－
415. 字符串相加。－
416. 分割等和子集。二维dp
417. 太平洋大西洋水流问题。广搜深搜都可以
419. 甲板上的战舰。一次遍历，找头X计数
421. 数组中两个数的最大异或值。构建字典树，遍历数组作数一，树往下贪心作数二，取最大的那个。
423. 从英文中重建数字。－
424. 替换后的最长重复字符。滑动窗口，学习了~
427. 建立四叉树。四叉树
429. N叉树的层序遍历。－
430. 扁平化多级双向链表。链表基本操作
432. 全 O(1) 的数据结构。map+set
433. 最小基因变化。广搜
434. 字符串中的单词数。－
435. 无重叠区间。贪心
436. 寻找右区间。排序，二分
437. 路径总和 III。－
438. 找到字符串中所有字母异位词。统计
441. 排列硬币。－
442. 数组中重复的数据。－ 
443. 压缩字符串。－
445. 两数相加 II。链表操作
447. 回旋镖的数量。－
448. 找到所有数组中消失的数字。数组元素可以作下标，第一轮把下标为num[i]的置负，第二轮正数对应的下标即为未出现的数
449. 序列化和反序列化二叉搜索树。[1,2,3,null,4,null,null]
450. 删除二叉搜索树中的节点。－
451. 根据字符出现频率排序。－
452. 用最少数量的箭引爆气球。贪心
453. 最小移动次数使数组元素相等。n-1个元素+1相当于1个元素-1，反向思维
454. 四数相加 II。map
455. 分发饼干。－
456. 132模式。先用minn[len]找到前i个数中最小的数，j从后往前找，利用栈
457. 环形数组循环。－
458. 可怜的小猪。每一只猪有多少种状态，存活，第一次挂，第二次挂。。。states^x >= n。记得之前面试遇到过类似的问题，面试官问有1000瓶水，100只老鼠，怎么找出有毒的那瓶水，相比于这道题的难度，发现面试官简直不要太善良^_^然而还是没有答出来。。。
459. 重复的子字符串。－
460. LFU 缓存。hashmap + set。
461. 汉明距离。－ 等于求x^y中1的个数
462. 最少移动次数使数组元素相等 II。数学，中位数
463. 岛屿的周长。－
464. 我能赢吗。TLE
467. 环绕字符串中唯一的子字符串。dp[i]表示以'a'+i结尾的子串的个数，vector还有个函数叫accumulate
468. 验证IP地址。字符串
470. 用 Rand7() 实现 Rand10()。拒绝概率
472. 连接词。字典树
473. 火柴拼正方形。四个数组表示四条边，回溯
474. 一和零。三维dp，dp[i][m][n]
475. 供暖器。－
476. 数字的补数。－
477. 汉明距离总和。－
478. 在圆内随机生成点。－
480. 滑动窗口中位数。用multiset飘过。应该是distance(sets.begin(), itr)耗时了，考虑到每次插入删除时中位数最多移动两位，可以进一步优化。
481. 神奇字符串。没看懂题目。。。
482. 密钥格式化。题目跟样例对不上，有问题，说好的除了第一个分组呢？
485. 最大连续1的个数。－
486. 预测赢家。dp. 当前操作的选手（注意，不一定是先手）与另一位选手最多的分数差
491. 递增子序列。深搜
492. 构造矩形。－
493. 翻转对。二叉搜索树会TLE，归并可以过，algorithm里面有merge和inplace_merge函数可用
494. 目标和。深搜+剪枝
495. 提莫攻击。遍历
496. 下一个更大元素 I。－
497. 非重叠矩形中的随机点。－
498. 对角线遍历。边界处理
500. 键盘行。－
501. 二叉搜索树中的众数。未完成～
502. IPO。题目不清楚，不用扣掉资本的嘛？
503. 下一个更大元素 II。栈
504. 七进制数。－
506. 相对名次。map底层是红黑树，插入会自动按key值排序。
507. 完美数。－ 
508. 出现次数最多的子树元素和。题目不太好理解，子树的元素和，出现最多的那个值，返回这个值对应的根
509. 斐波那契数。－
513. 找树左下角的值。－
515. 在每个树行中找最大值。－ 
516. 最长回文子序列。二维dp，可以倒着算，保证子问题已经被计算
518. 零钱兑换 II。一维dp
519. 随机翻转矩阵。TLE
520. 检测大写字母。－
521. 最长特殊序列 Ⅰ。－
522. 最长特殊序列 ⅠⅠ。如果存在这样的特殊序列，那么它一定是某个给定的字符串。
523. 连续的子数组和。－ 
524. 通过删除字母匹配到字典里最长单词。排序后比较
525. 连续数组。count+-,相同的count表示中间一段满足条件
526. 优美的排列。回溯
528. 按权重随机选择。－
529. 扫雷游戏。搜索
530. 二叉搜索树的最小绝对差。
532. 数组中的K-diff数对。－
535. TinyURL 的加密与解密。map空间换时间。
537. 复数乘法。int和string互转 
538. 把二叉搜索树转换为累加树。－
539. 最小时间差。排序？
540. 有序数组中的单一元素。－
541. 反转字符串 II。－
542. 01 矩阵。广搜，但是不是搜1，而是搜0，把所有0看成一个超级0都加到队列进行广搜。
543. 二叉树的直径。－
547. 朋友圈。并查集
551. 学生出勤记录 I。－
554. 砖墙。统计？
556. 下一个更大元素 III。找到位置+sort
557. 反转字符串中的单词 III。－
558. 四叉树交集。－注意合并
559. N叉树的最大深度。－ 
560. 和为K的子数组。数组
561. 数组拆分 I。－
563. 二叉树的坡度。－
565. 数组嵌套。遍历
566. 重塑矩阵。－`
567. 字符串的排列。滑动窗口+1
572. 另一个树的子树。－
575. 分糖果。－
576. 出界的路径数。二维三维dp
581. 最短无序连续子数组。栈，从头遍历 numsnums 数组，升序下标入栈，反之出栈，得左边界，反向得右边界。
583. 两个字符串的删除操作。二维dp
589. N叉树的前序遍历。－
590. N叉树的后序遍历。－
592. 分数加减运算。字符串处理
594. 最长和谐子序列。－
595. 大的国家。select
596. 超过5名学生的课。有坑，表中有重复记录，结果不记。。。
598. 范围求和 II。－
599. 两个列表的最小索引总和。－
601. 体育馆的人流量。有坑，按日期不行，得按id.类似180
605. 种花问题。－
606. 根据二叉树创建字符串。－
609. 在系统中查找重复文件。用了c++11貌似编译不过。。。
```c++
regex re("[\\s()]+");
vector<string> sub(sregex_token_iterator(paths[i].begin(), paths[i].end(), re, -1), sregex_token_iterator());
```
611. 有效三角形的个数。数组
617. 合并二叉树。－ 
620. 有趣的电影。select
621. 任务调度器。－
622. 设计循环队列。－
623. 在二叉树中增加一行。－
626. 换座位。left join
627. 交换工资。sql也有三元语法，xxx = if(xxx, Y, N)
628. 三个数的最大乘积。－
633. 平方数之和。－
636. 函数的独占时间。栈
637. 二叉树的层平均值。－
638. 大礼包。深搜
641. 设计循环双端队列。－
643. 子数组最大平均数 I。－
645. 错误的集合。－
646. 最长数对链。一维dp,类似于最长上升子序列
647. 回文子串。－
648. 单词替换。－
649. Dota2 参议院。每个删除后面最近的异类
650. 只有两个键的键盘。一维dp
652. 寻找重复的子树。直接深搜会超时，可以用hash map.树用字符串表示，记录字符串出现的次数
653. 两数之和 IV - 输入 BST。－
654. 最大二叉树。－
655. 输出二叉树。先计算最大宽度和高度，再从上往下填数字
657. 机器人能否返回原点。－ 
658. 找到 K 个最接近的元素。二分
659. 分割数组为连续子序列。为什么WA?令 C = count[x+1] - count[x] ，如果 C > 0 ，必须有 C 个子序列从 x+1 开始，如果 C < 0 ，必须有 -C 个子序列在 x 结束。注意：需要连续整数、长度至少为3
661. 图片平滑器。－
662. 二叉树最大宽度。－
665. 非递减数列。分情况讨论吧，当遇到递减时，要么前一个数降，要么后一个数升
667. 优美的排列 II。先+k-(k-1)+(k-2)...把所有的差值走一遍，剩下的按顺序排列即可
669. 修剪二叉搜索树。－
670. 最大交换。字符比较
671. 二叉树中第二小的节点。－
673. 最长递增子序列的个数。一维dp，两个数组一个记录长度一个记录个数，最后的结果不一定是最大那个或是所有的和的~不要固定思维
674. 最长连续递增序列。－
676. 实现一个魔法字典。－
677. 键值映射。－
678. 有效的括号字符串。记录当前最大可能和最小可能的左括号数。
680. 验证回文字符串 Ⅱ。－
682. 棒球比赛。－
684. 冗余连接。并查集？
685. 冗余连接 II。从头遍历边，有环有双父亲，返回该边；有环，之前有双父亲，返回之前导致双父亲的边；有双父亲，之前有环，返回当前子节点和之前的父亲节点所在的边。
686. 重复叠加字符串匹配。－ 
687. 最长同值路径。－ 
688. “马”在棋盘上的概率。没看懂题目，样例一难道不是1/8*2/8 + 1/8*2/8?
690. 员工的重要性。－ 
692. 前K个高频单词。－
693. 交替位二进制数。－
695. 岛屿的最大面积。深搜
696. 计数二进制子串。－
697. 数组的度。－
698. 划分为k个相等的子集。－
700. 二叉搜索树中的搜索。－
701. 二叉搜索树中的插入操作。－ 
703. 数据流中的第K大元素。－
704. 二分查找。－ 
705. 设计哈希集合。－
706. 设计哈希映射。－
707. 设计链表。双链表
709. 转换成小写字母。－
710. 黑名单中的随机数。随机
712. 两个字符串的最小ASCII删除和。二维dp,dp[i][j]表示s1[0,i]和s2[0,j]的结果
713. 乘积小于K的子数组。定右界，找左界
714. 买卖股票的最佳时机含手续费。dp,维持两个数，一个花费，一个赚到的
717. 1比特与2比特字符。－
718. 最长重复子数组。dp. 子数组一定要连续？也没说啊～
719. 找出第 k 小的距离对。对距离二分查找
720. 词典中最长的单词。用字典树会超时，排序后用set很快。
721. 账户合并。并查集
722. 删除注释。注意前后顺序，包含情况，一行多种注释情况
724. 寻找数组的中心索引。－
725. 分隔链表。－
728. 自除数。－
729. 我的日程安排表 I。同731
731. 我的日程安排表 II。map, maps[time]表示当前时间开始，后面的时间被占用，maps[start]++; maps[end]--; 遍历maps计算count大于等于3时表示有3重以上占用
733. 图像渲染。－
735. 行星碰撞。栈
738. 单调递增的数字。贪心
739. 每日温度。栈
740. 删除与获得点数。一维dp
743. 网络延迟时间。最小路径
744. 寻找比目标字母大的最小字母。－
745. 前缀和后缀搜索。字典树搜前缀，搜到后比较后缀，可过
746. 使用最小花费爬楼梯。－
747. 至少是其他数字两倍的最大数。－
748. 最短完整词。－
752. 打开转盘锁。广搜，好慢～
756. 金字塔转换矩阵。深搜，剪枝
762. 二进制表示中质数个计算置位。－
763. 划分字母区间。－
764. 最大加号标志。二维dp
765. 情侣牵手。贪心。固定奇数位置不变，移动偶数位即可。
766. 托普利茨矩阵。－
767. 重构字符串。排序
768. 最多能完成排序的块 II。可以从后往前，计算当前[i,len]的最小值和个数，和排序后当前位值的值和个数比较。
769. 最多能完成排序的块。－
771. 宝石与石头。－ 
773. 滑动谜题。广搜。
775. 全局倒置与局部倒置。取前i-2个当中最大的和当前的比较即可
777. 在LR字符串中交换相邻字符。－ 
779. 第K个语法符号。－
780. 到达终点。递归。
781. 森林中的兔子。数学？
783. 二叉搜索树结点最小距离。－
784. 字母大小写全排列。－
785. 判断二分图。不一定连通
788. 旋转数字。－
787. K 站中转内最便宜的航班。堆+剪枝，不然会超时
790. 多米诺和托米诺平铺。二维dp，三种情况，列平齐、上列多一块，下列多一块
791. 自定义字符串排序。－
792. 匹配子序列的单词数。字符串匹配
794. 有效的井字游戏。－
795. 区间子数组个数。dp
796. 旋转字符串。－
797. 所有可能的路径。－
801. 使序列递增的最小交换次数。二维dp，0－当前位不交换，1－当前位交换
802. 找到最终的安全状态。拓扑排序
804. 唯一摩尔斯密码词。－ 
806. 写字符串需要的行数。－
807. 保持城市天际线。－
809. 情感丰富的文字。题目有歧义，长度达到3以上，d->ddd正确，dd->ddd难道不可以理解为第一个d不变，第二个d只扩展到长度为2？
811. 子域名访问计数。－
813. 最大平均值和的分组。二维dp
814. 二叉树剪枝。－
817. 链表组件。链表没有说明有没有重复值，如果考虑有重复的话。。。
819. 最常见的单词。－
820. 单词的压缩编码。字典树
821. 字符的最短距离。－
824. 山羊拉丁文。－
825. 适龄的朋友。年龄范围一般在0-200之间，按年龄记数。
826. 安排工作以达到最大收益。排序
830. 较大分组的位置。题目不是说“最终结果按照字典顺序输出。”吗？第三个样例是什么鬼？？？
831. 隐藏个人信息。字符串操作
832. 翻转图像。－
833. 字符串中的查找与替换。字符串操作
835. 图像重叠。－
836. 矩形重叠。－
837. 新21点。为什么N=10,K=2,W=10的概率会是0.99？？？不应该是0.12???
838. 推多米诺。双指针
840. 矩阵中的幻方。－
841. 钥匙和房间。BFS
842. 将数组拆分成斐波那契序列。类似于306，回溯
843. 猜猜这个单词。先计算每两个单词的匹配度。每次要猜的单词为与其它单词匹配度[0-6]中最多的单词数最少的那个单词。
844. 比较含退格的字符串。－
845. 数组中的最长山脉。数组比较
846. 一手顺子。只有暴力？
848. 字母移位。字符处理
849. 到最近的人的最大距离。－
852. 山脉数组的峰顶索引。－
853. 车队。排序，和最后一个比，时间小于等于为一队，时间大于新队，更新为最后一个
855. 考场就座。map
856. 括号的分数。栈
859. 亲密字符串。－
860. 柠檬水找零。－
861. 翻转矩阵后的得分。贪心
862. 和至少为 K 的最短子数组。前缀和+双端队列。
863. 二叉树中所有距离为 K 的结点。广搜
865. 具有所有最深结点的最小子树。和1123完全一样
867. 转置矩阵。 －
868. 二进制间距。－
869. 重新排序得到2的幂。记录位数出现的次数即可。
870. 优势洗牌。数组
872. 叶子相似的树。－
873. 最长的斐波那契子序列的长度。二维dp
874. 模拟行走机器人。－
875. 爱吃香蕉的珂珂。二分
876. 链表的中间结点。－
877. 石子游戏。dp?转换成+和-,求穿插插入符号能得到的最大值
868. 二进制间距。－
880. 索引处的解码字符串。栈，注意K从1开始
881. 救生艇。双指针
883. 三维形体投影面积。－ 
884. 两句话中的不常见单词。－
885. 螺旋矩阵 III。－
886. 可能的二分法。广搜
888. 公平的糖果交换。－
889. 根据前序和后序遍历构造二叉树。－
890. 查找和替换模式。－
892. 三维形体的表面积。－
893. 特殊等价字符串组。－
894. 所有可能的满二叉树。－
896. 单调数列。－
897. 递增顺序查找树。－
898. 子数组按位或操作。剪枝
900. RLE 迭代器。计数
901. 股票价格跨度。标签是栈，没用到
904. 水果成篮。双指针
905. 按奇偶排序数组。－
907. 子数组的最小值之和。对每个数，记录左边比它小的下标，右边比它小的下标，用栈，再计算个数。
908. 最小差值 I。－
909. 蛇梯棋。广搜
910. 最小差值 II。遍历分割点
911. 在线选举。先统计后二分查找
912. 排序数组。难度中等？？？
914. 卡牌分组。－ 
915. 分割数组。－
916. 单词子集。对每个字母，取b中包含最多该字母的那个单词，对应的该字母个数，组成一个单词，再和A比较。
917. 仅仅反转字母。－
919. 完全二叉树插入器。树操作
921. 使括号有效的最少添加。－
922. 按奇偶排序数组 II。－
923. 三数之和的多种可能。数学排列组合
925. 长按键入。－
926. 将字符串翻转到单调递增。dp，前一个翻转和不翻转dp[2][len]
927. 三等分。最后一个1后面的0为每部分的尾部0的个数，反推。
929. 独特的电子邮件地址。－
930. 和相同的二元子数组。另算S＝0，其它同1248
932. 漂亮数组。分治，分奇偶
933. 最近的请求次数。－
934. 最短的桥。深搜+广搜
935. 骑士拨号器。二维dp
938. 二叉搜索树的范围和。－ 
939. 最小面积矩形。遍历对角线
941. 有效的山脉数组。－是不是不能相信题目中说的length>=3???
执行结果：
执行出错
显示详情
Line 923: Char 34: runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h)
最后执行的输入：
[]
942. 增减字符串匹配。－
944. 删列造序。－ 
945. 使数组唯一的最小增量。排序？
946. 验证栈序列。栈
947. 移除最多的同行或同列石头。题目表述不清楚。。。在二维坐标系中给定若干个石头stones。对于一个石头i来说，当存在另一个石头j与它处于同一行或同一列时，我们才能将i移除掉。问我们最多能移除多少个石头？
处于同一行或同一列的石头属于同一堆，一堆最终可以删到只剩一个，并查集
948. 令牌放置。双指针贪心
949. 给定数字能组成的最大时间。－
950. 按递增顺序显示卡牌。－
951. 翻转等价二叉树。－
953. 验证外星语词典。－
954. 二倍数对数组。可以用队列
955. 删列造序 II。贪心
957. N 天后的牢房。所以，两头的房怎么算？
959. 由斜杠划分区域。深搜
958. 二叉树的完全性检验。－
961. 重复 N 次的元素。－
962. 最大宽度坡。贪心
963. 最小面积矩形 II。算对角中点是否重合判断是否平行四边行，再判断垂直
965. 单值二叉树。－
966. 元音拼写检查器。字符串比较
967. 连续差相同的数字。深搜
968. 监控二叉树。从下往上搜索，每个节点共有installed, watched, empty三种状态，empty的是需要父节点安装的，最后还要判断根是否empty，是的话+1，因为根没有父节点了。
969. 煎饼排序。－
970. 强整数。－
971. 翻转二叉树以匹配先序遍历。计数，深搜
973. 最接近原点的 K 个点。－
974. 和可被 K 整除的子数组。记录和取余
976. 三角形的最大周长。－
977. 有序数组的平方。－
978. 最长湍流子数组。滑动窗口+2
979. 在二叉树中分配硬币。－
980. 不同路径 III. 深搜
981. 基于时间的键值存储。二分
982. 按位与为零的三元组。暴力会超时，难度为困难的就别考虑用暴力了。hash走起
983. 最低票价。一维dp,dp[i] = min(dp[i - 1] + cost[0], dp[k] + cost[1], dp[m] + cost[2]),其中days[m]为与i相差大于等于30的最大m，k同理。
984. 不含 AAA 或 BBB 的字符串。贪心
985. 查询后的偶数和。－
986. 区间列表的交集。－
987. 二叉树的垂序遍历。队列
988. 从叶结点开始的最小字符串。深搜
989. 数组形式的整数加法。－
990. 等式方程的可满足性。并查集，先处理相等的再处理不相等的
991. 坏了的计算器。从Y着手，因为除法好分奇偶，优先除
993. 二叉树的堂兄弟节点。－
994. 腐烂的橘子。－
995. K 连续位的最小翻转次数。贪心
997. 找到小镇的法官。－
998. 最大二叉树 II。树的基本操作
999. 车的可用捕获量。－
1002. 查找常用字符。－ 
1003. 检查替换后的词是否有效。字符串
1004. 最大连续1的个数 III。滑动窗口+3
1005. K 次取反后最大化的数组和。－
1006. 笨阶乘。递归
1007. 行相等的最少多米诺旋转。贪心
1008. 先序遍历构造二叉树。－ 
1009. 十进制整数的反码。－
1010. 总持续时间可被 60 整除的歌曲。－
1011. 在 D 天内送达包裹的能力。二分
1013. 将数组分成和相等的三个部分。双指针
1014. 最佳观光组合。存储A[i]+i的最大值
1016. 子串能表示从 1 到 N 数字的二进制串。bitset，#include<bitset>和string可以转化，效率高
1017. 负二进制转换。进制数
1018. 可被 5 整除的二进制前缀。－
1019. 链表中的下一个更大节点。可以用栈
1020. 飞地的数量。深搜，求和，不是最大值
1021. 删除最外层的括号。－
1022. 从根到叶的二进制数之和。－
1023. 驼峰式匹配。－
1024. 视频拼接。一维dp
1025. 除数博弈。－貌似至今为止唯一一道双击败了100%的题
1026. 节点与其祖先之间的最大差值。深搜
1027. 最长等差数列。提交返回“内部出错”？？？
1028. 从先序遍历还原二叉树。字符串处理
1029. 两地调度。要使xa+yb <= xb+ya,即xa-xb <= ya-yb，差值排序，前N位去x地即可。
1030. 距离顺序排列矩阵单元格。－
1031. 两个非重叠子数组的最大和。数组
1032. 字符流。反向初始化，用时100%
1033. 移动石子直到连续。－
1035. 不相交的线。同最长公共子序列，dp
1037. 有效的回旋镖。－ 
1038. 从二叉搜索树到更大和树。－
1039. 多边形三角剖分的最低得分。二维dp.dp[i][j]表示从i到j的结果值，dp[i][(i + j) % len] = min(dp[i][(i + j) % len], dp[i][k] + dp[k][(i + j) % len] + A[i] * A[k] * A[(i + j) % len]);
1040. 移动石子直到连续 II。c++编译器有点问题，有时候提交会出现莫名编译错误，同样的代码再次提交又正常
1042. 不邻接植花。－
1043. 分隔数组以得到最大和。一维dp。长度最多为 K 指的是分隔后每段的长度，不是分隔的段数，一开始理解错了纠结了好久...
1046. 最后一块石头的重量。－
1047. 删除字符串中的所有相邻重复项。－
1048. 最长字符串链。一维dp
1049. 最后一块石头的重量 II。脑筋转个弯，将这些数字分成两拨，使得他们的和的差最小。变成0－1背包问题
1051. 高度检查器。看不懂题目+1，看排好队后谁没站到位置上，统计这些人的个数。
1052. 爱生气的书店老板。sliding window
1053. 交换一次的先前排列。贪心
1054. 距离相等的条形码。只排序不加点优化会超时哦～
1071. 字符串的最大公因子。－
1072. 按列翻转得到最大值等行数。“行上所有值都相等”指的是一整行全是0或全是1，如果某两行可以通过这个规则达成一致，要么它们全等，要么它们相反。
1073. 负二进制数相加。没有c++?
1078. Bigram 分词。－击败了100.00%的用户～哦㖿～
1079. 活字印刷。回溯。本来想用数学的排列组合直接计算的，算得头有点大。。。
1080. 根到叶路径上的不足节点。深搜
1081. 不同字符的最小子序列。同316
1089. 复写零。－
1090. 受标签影响的最大值。贪心
1091. 二进制矩阵中的最短路径。BFS
1093. 大样本统计。双指针
1094. 拼车。类似于1353参加会议
1103. 分糖果 II。－
1104. 二叉树寻路。－
1105. 填充书架。一维dp
1108. IP 地址无效化。－ 
1109. 航班预订统计。不需要list、线段树等等，定义 counter[] 数组记录每站的人数变化即可
1110. 删点成林。栈
1111. 有效括号的嵌套深度。栈算深度，深度为奇设1。
1114. 按序打印。用mutex.
1115. 交替打印foobar。同1114.
1116. 打印零与奇偶数。每个函数只调用一次。。。
1117. H2O 生成。
1122. 数组的相对排序。－
1123. 最深叶节点的最近公共祖先。－
1124. 表现良好的最长时间段。谁能想得到这是递增栈？
1128. 等价多米诺骨牌对的数量。－
1129. 颜色交替的最短路径。图，广搜
1130. 叶值的最小代价生成树。dp。跟标签栈好像没有什么关系
1131. 绝对值表达式的最大值。依旧和位运算没太大关系，数学题，直接暴力会TLE。把Point(i, arr[i], arr[j])看作三维空间中的一个点，题目就是要求所有这些点中曼哈顿距离最远的两个点的距离。“任意两个点的曼哈顿距离就等于：这两个点到8个角落的曼哈顿距离差绝对值的最大值”
1137. 第N个菲波那契数。同70。
1138. 字母板上的路径。模拟
1139. 最大的以 1 为边界的正方形。二维dp
1140. 石子游戏 II。f[i][j]表示在i~n-1堆石子中 且最多拿前2*j堆时先手能拿到的最大>数量，则f[i][j] = max(sum_a[i~n-1] - f[i+k][max(j,k)])  1<=k<=2*j
1144. 递减元素使数组呈锯齿状。贪心
1145. 二叉树着色游戏。先计算以每个节点为根的树有多少个节点，对于x，最优的y一定是x的邻节点，直接计算玩家所得的数量即可
1146. 快照数组。map
1154. 一年中的第几天。－
1155. 掷骰子的N种方法。二维dp
1156. 单字符重复子串的最大长度。对26个字符进行统计
1160. 拼写单词。－ 
1161. 最大层内元素和。－
1162. 地图分析。－
1163. 按字典序排在最后的子串。c++17有string_view，substr不另外开空间。第二次遇到lexicographical_compare。如果当前字母和前一个字母相同，不管后面什么情况都是选前一个。
1169. 查询无效交易。比较
1170. 比较字符串最小字母出现频次。－
1171. 从链表中删去总和值为零的连续节点。还可以再优化的，懒得改了～
1172. 餐盘栈。map+set，maps用iterator和直接maps[idx]插入貌似时间不一样？
1175. 质数排列。－
1177. 构建回文串检测。把 ‘a’-'z' 对应一个26位的二进制数的每一位，当字符c出现奇数次时为1，偶数次时为0，转化成位运算
1178. 猜字谜。位运算。遍历两个数组会TLE，考虑到puzzles的字符长度只有7，2^7 = 128，应该遍历puzzles的子集。for (int j = phash; j; j = ((j - 1) & phash))能够遍历所有子集，需要去掉不包含首字母的那些。
1179. 重新格式化部门表。pivot是orical的，sql直接一个个选吧。。。
1184. 公交站间的距离。－
1185. 一周中的第几天。方法1，算到当前的天数，换星期；方法2，基姆拉尔森计算公式 Week=(Day + 2*Month + 3*(Month+1）/5 + Year + Year/4 - Year/100 + Year/400) % 7；方法3，c++自带函数（奸～）
1186. 删除一次得到子数组最大和。一维dp,计算前i个和后j个的最大和，再遍历删除的数
1189. “气球” 的最大数量。－
1190. 反转每对括号间的子串。字符串
1191. K 次串联后最大子数组之和。先计算数组中的最大和，若sum>=0,则最大和＝maxrev + sum * (k-2) + maxpre, 否则最大和＝maxpre + maxrev.
1195. 交替打印字符串。当一个线程退出后另一个线程还在等待锁释放，则会出现死锁，退出不自动释放mutex?
1200. 最小绝对差。－
1201. 丑数 III。数学
1202. 交换字符串中的元素。并查集，尽量优化findParents，不然很容易TLE
1206. 设计跳表。类似于线段树的操作，空间复杂度要优。
1207. 独一无二的出现次数。－
1208. 尽可能使字符串相等。sliding window
1209. 删除字符串中的所有相邻重复项 II。栈
1217. 玩筹码。－
1218. 最长定差子序列。一维dp
1219. 黄金矿工。深搜
1221. 分割平衡字符串。－ 
1222. 可以攻击国王的皇后。－
1223. 掷骰子模拟。二维dp，注意减去重复的和转移时不合法的数量
1226. 哲学家进餐。WA。。。
1227. 飞机座位分配概率。令f(i)表示第一个人选择第i个人的座位时，第n个座位被其他人（1到n-1）占用的概率.因此第n个座位被其他人占用的概率为1/n[f(2)+f(3)+...+f(n)]=1/2。
1232. 缀点成线。－
1233. 删除子文件夹。字符串比较
1234. 替换子串得到平衡字符串。双指针
1237. 找出给定方程的正整数解。－
1238. 循环码排列。二进制码转格雷码：G = B ^ B >> 1；格雷码转二进制码：B = ^(G >> i)
1239. 串联字符串的最大长度。记得剪枝，不然会超时
1247. 交换字符使得字符串相同。－ 
1248. 统计「优美子数组」。记下标，用下标数组算。类似于930
1249. 移除无效的括号。删除最少的，不是删除所有哦
1252. 奇数值单元格的数目。－
1253. 重构 2 行二进制矩阵。贪心
1254. 统计封闭岛屿的数目。搜索
1255. 得分最高的单词集合。深搜。
1260. 二维网格迁移。－
1261. 在受污染的二叉树中查找元素。－
1262. 可被三整除的最大和。dp。记dp[i]为余为i的和
1266. 访问所有点的最小时间。－
1267. 统计参与通信的服务器。－
1268. 搜索推荐系统。字典树
1275. 找出井字棋的获胜者。－
1276. 不浪费原料的汉堡制作方案。贪心
1277. 统计全为 1 的正方形子矩阵。动态规划。f[i][j]表示以[i][j]为右下角的矩阵边长，结果求和。
1281. 整数的各位积和之差。－
1282. 用户分组。－
1283. 使结果不超过阈值的最小除数。数学
1284. 转化为全零矩阵的最少反转次数。数据量超级小，勇敢地用广搜吧
1286. 字母组合迭代器。abc前面是ab,ac,下一个难道不是ba吗？为什么ba没有排名？
1287. 有序数组中出现次数超过25%的元素。－
1288. 删除被覆盖区间。－
1289. 下降路径最小和  II。二维dp。广搜深搜都会TLE
1290. 二进制链表转整数。－
1291. 顺次数。排序
1292. 元素和小于等于阈值的正方形的最大边长。可以用滑动窗口
1295. 统计位数为偶数的数字。－
1296. 划分数组为连续数字的集合。排序
1297. 子串的最大出现次数。好像和标签位运算没有太大关系。。。
1298. 你能从盒子里获得的最大糖果数。类递归
1299. 将每个元素替换为右侧最大元素。－
1300. 转变数组后最接近目标值的数组和。二分
1302. 层数最深叶子节点的和。－
1304. 和为零的N个唯一整数。－
1305. 两棵二叉搜索树中的所有元素。－
1306. 跳跃游戏 III。广搜
1309. 解码字母到整数映射。－
1310. 子数组异或查询。－
1311. 获取你好友已观看的视频。广搜
1312. 让字符串成为回文串的最少插入次数。二维dp
1313. 解压缩编码列表。－
1315. 祖父节点值为偶数的节点和。－
1317. 将整数转换为两个无零整数的和。－
1318. 或运算的最小翻转次数。－
1319. 连通网络的操作次数。并查集
1323. 6 和 9 组成的最大数字。－
1324. 竖直打印单词。字符串操作
1325. 删除给定值的叶子节点。－
1328. 破坏回文串。贪心
1329. 将矩阵按对角线排序。－
1331. 数组序号转换。－
1332. 删除回文子序列。－
1333. 餐厅过滤器。sort
1334. 阈值距离内邻居最少的城市。图，广搜
1337. 方阵中战斗力最弱的 K 行。可以用大根堆的，没写好
1338. 数组大小减半。排序？
1339. 分裂二叉树的最大乘积。要求的是最大值的取模，而不是取模后的最大值，所以不能提前取模
1340. 跳跃游戏 V。递归+一维dp
1343. 大小为 K 且平均值大于等于阈值的子数组数目。这里要的子数组是要连续的可以重复的
1345. 跳跃游戏 IV。广搜可以
1347. 制造字母异位词的最小步骤数。说好的排列不同呢？？？
1348. 推文计数。map+vector二分查找
1352. 最后 K 个数的乘积。dp
1353. 最多可以参加的会议数目。两队，一队按开始时间排序，一队包含当前时间并按结束时间排序
1356. 根据数字二进制下 1 的数目排序。－
1357. 每隔 n 个顾客打折。设计
1358. 包含所有三种字符的子字符串数目。字符串处理
1359. 有效的快递序列数目。递归，数学，公式
1361. 验证二叉树。－
1365. 有多少小于当前数字的数字。－ 
1366. 通过投票对团队排名。多重排序
1367. 二叉树中的列表。递归
1371. 每个元音包含偶数次的最长子字符串。对s的每一位，记录当前元音出现的奇偶性（状态压缩，位运算），状态相同表示这段字符串满足条件。
1372. 二叉树中的最长交错路径。dp
1373. 二叉搜索子树的最大键值和。递归
1375. 灯泡开关 III。set
1376. 通知所有员工所需的时间。广搜
1377. T 秒后青蛙的位置。广搜，注意考虑各种边界情况。
1379. 找出克隆二叉树中的相同节点。－
1380. 矩阵中的幸运数。－
1381. 设计一个支持增量操作的栈。－
1382. 将二叉搜索树变平衡。遍历一遍再建树竟然内存消耗100%
1385. 两个数组间的距离值。－
1386. 安排电影院座位。计数
1389. 按既定顺序创建目标数组。－
1391. 检查网格中是否存在有效路径。广搜或深搜
1396. 设计地铁系统。checkout可能有异常
1399. 统计最大组的数目。统计
1400. 构造 K 个回文字符串。贪心
1402. 做菜顺序。数学？
1403. 非递增顺序的最小子序列。贪心
1404. 将二进制表示减到 1 的步骤数。位运算
1405. 最长快乐字符串。贪心
1408. 数组中的字符串匹配。字符串匹配
1409. 查询带键的排列。链表
1410. HTML 实体解析器。直接操作比string::find_first_of快
1414. 和为 K 的最少斐波那契数字数目。贪心，第45个f就超过了10^9
1415. 长度为 n 的开心字符串中字典序第 k 小的字符串。深搜
1418. 点菜展示表。map搞掟
1419. 数青蛙。记录每个字符后当前五个字母的次数，再判断就ok了
1422. 分割字符串的最大得分。dp
1423. 可获得的最大点数。遍历2k次及可
1431. 拥有最多糖果的孩子。贪心
1432. 改变一个整数能得到的最大差值。贪心
1433. 检查一个字符串是否可以打破另一个字符串。贪心
1424. 对角线遍历 II。直接遍历会超时，记录下标进行排序
1436. 旅行终点站。广搜
1437. 是否所有 1 都至少相隔 k 个元素。数组
1438. 绝对差不超过限制的最长连续子数组。数组
1442. 形成两个异或相等数组的三元组数目。异或，相同的中间即为需要的数组
1443. 收集树上所有苹果的最少时间。从下往上遍历，数边
1455. 检查单词是否为句中其他单词的前缀。字符串比较
1456. 定长子串中元音的最大数目。-
1457. 二叉树中的伪回文路径。深搜
1460. 通过翻转子数组使两个数组相等。比较数组元素~
1461. 检查一个字符串是否包含所有长度为 K 的二进制子串。二进制
1470. 重新排列数组。-
1471. 数组中的 k 个最强值。-
1472. 设计浏览器历史记录。-
1476. 子矩形查询。暴力竟然也能过~
1477. 找两个和为目标值且不重叠的子数组。用长度为key存储multimap，遍历multimap
1482. 制作 m 束花所需的最少天数。天数二分查找
1483. 树节点的第 K 个祖先。ACM模板Binary Lifting。dp[node][j] 存储的是 node 节点距离为 2^j 的祖先是谁。
1489. 找到最小生成树里的关键边和伪关键边。Kruskal算法
1496. 判断路径是否相交。
1497. 检查数组对是否可以被 k 整除。map对,余数
1498. 满足条件的子序列数目。遍历数组固定最小值，二分找最大值，res+= 2^(endPos - stPos);
1505. 最多 K 次交换相邻数位后得到的最小整数。fenwich tree记录前面有多少个已经被挪走了。x&(-x)是把x的二进制中最右一个1前面的都去掉。lowbit数状数组经典。
1515. 服务中心的最佳位置。只看一个点的时候的目标函数，固定y轴，沿着x轴的二阶导恒非负，同理y轴。三分逼近。
1520. 最多的不重叠子字符串。类似于最长递增子序列？
1523. 在区间范围内统计奇数数目。-
1524. 和为奇数的子数组数目。动态规划，dp[i]表示以arr[i]结尾的满足条件的子数组数目
1525. 字符串的好分割数目。-
1526. 形成目标数组的子数组最少增加次数。分治会TLE，可以贪心，看当前位置，如果比前后都大，则减到前后两数中较大的数，处理边界。
1528. 重新排列字符串。-
1529. 灯泡开关 IV。按顺序贪心
1530. 好叶子节点对的数量。树
1542. 找出最长的超赞子字符串。位运算。
1544. 整理字符串。-
1545. 找出第 N 个二进制字符串中的第 K 位。计算
1546. 和为目标值的最大数目不重叠非空子数组数目。直接贪心，因为如果[a,c]和[b,d]，那么必选[a,c]，如果有[b,d]...最大数目，把[b,d]换成[a,c]一样成立，所以可以直接贪心，不用考虑各种组合。
1553. 吃掉 N 个橘子的最少天数。优化，记忆化搜索。每次在操作2和3前，操作1的次数不超过2。map记录已经计算过的数。
1556. 千位分隔数。-
1557. 可以到达所有点的最少点数目。图
1558. 得到目标数组的最少函数调用次数。反向操作，模拟
1560. 圆形赛道上经过次数最多的扇区。-
1561. 你可以获得的最大硬币数目。-
1562. 查找大小为 M 的最新分组。线段树。
1572. 矩阵对角线元素的和。-
1573. 分割字符串的方案数。long long
1574. 删除最短的子数组使剩余数组有序。只删除一个子数组
1576. 替换所有的问号。-
1577. 数的平方等于两数乘积的方法数。hash map
1578. 避免重复字母的最小删除成本。栈
1585. 检查字符串是否可以通过排序子字符串得到另一个字符串。看成冒泡，如果有比它更大的在后面，那么不能继续往前
1593. 拆分字符串使唯一子字符串的数目最大。直接回溯就好。。。
1594. 矩阵的最大非负积。二维dp。dpmax和dpmin
1598. 文件夹操作日志搜集器。栈
1599. 经营摩天轮的最大利润。模拟
1600. 皇位继承顺序。树，递归
1606. 找到处理最多请求的服务器。优先队列+set，优先队列存储工作中的server，set存储当前可用的index，priority_queue，set有lower_bound可以直接用于查找
1611. 使整数变为 0 的最少操作次数。格雷码操作。
5336. 上升下降字符串。－ 
5350. 将整数按权重排序。排序？
5352. 生成每种字符都是奇数个的字符串。－
5368. 找出数组中的幸运数。－
5369. 统计作战单位数。－
5372. 逐步求和得到正数的最小值。－
5388. 重新格式化字符串。－
5396. 连续字符。-
5397. 最简分数。-
5398. 统计二叉树中好节点的数目。深搜
5404. 用栈操作构建数组。模拟
5410. 课程安排 IV。广搜
5420. 商品折扣后的最终价格。-
5424. 数组中两元素的最大乘积。-
5425. 切割后面积最大的蛋糕。-
5426. 重新规划路线。广搜
5515. 设计停车系统。-
5516. 警告一小时内使用相同员工卡大于等于三次的人。感觉题出得有bug。。。
5518. 给定行和列的和求可行矩阵。贪心
LCP2. 分式化简。－
LCP1. 猜数字。－
LCP3. 机器人大冒险。直接模拟会超时，把所有坐标缩小到一个回合里判断
LCP 06. 拿硬币。位运算速度快
LCP 07. 传递信息。图
LCP 08. LCP 08. 剧情触发时间。暴力也能过，可以优化
LCP 09. 最小跳跃次数。栈。
LCP 12. 小张刷题计划。二分查找
LCP 19. LCP 19. 秋叶收藏集。dp。用 sum[x] 表示 [0, x) 区间内红叶数量，需要操作的总次数为 (i - sum[i]) + (n - j - sum[n] + sum[j]) + (sum[j] - sum[i]), 整理后得到 n - sum[n] + (i - 2 * sum[i]) - (j - 2 * sum[j]), j 确定时 i - 2 * sum[i] 最小,遍历j
LCP 23. 魔术排列。k只能为第一次重排列后和target相同的前面的数的个数。
