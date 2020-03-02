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
11. 盛最多水的容器。－
12. 整数转罗马数字。分类，情况有点多。
13. 罗马数字转整数。－
14. 最长公共前缀。－
15. 三数之和。直接暴力会TLE，用双指针会好点，不知道还有没有更优的
19. 删除链表的倒数第N个节点。－
20. 有效的括号。－
21. 合并两个有序链表。－
24. 两两交换链表中的节点。－
26. 删除排序数组中的重复项。－
27. 移除元素。－
28. 实现 strStr()。最优的可以用KMP算法，不过这题后台数据量太小。。。
33. 搜索旋转排序数组。－
34. 在排序数组中查找元素的第一个和最后一个位置。－
35. 搜索插入位置。二分。。。
38. 38. 报数。没看懂题目，过...............
48. 旋转图像。－
49. 字母异位词分组。－
50. Pow(x, n)。－
53. 最大子序和。简单的动态规划，dp[i]为以nums[i]结尾包括nums[i]的最大子序和，要求结果为dp中最大的数。
55. 跳跃游戏。－
56. 合并区间。sort的cmp报错???
58. 最后一个单词的长度。－
62. 不同路径。dp
63. 不同路径II。dp
64. 最小路径和。dp
66. 加一。－
67. 二进制求和。－
69. x 的平方根。二分，注意int越界！！！用x/m>m判断而不是x>m*m。
70. 爬楼梯。菲波那契数列，记不住公式啊啊啊，超时啊啊啊。。。
73. 矩阵置零。－
74. 搜索二维矩阵。－
75. 颜色分类。－
81. 搜索旋转排序数组 II。－
82. 删除排序链表中的重复元素 II。－
83. 删除排序链表中的重复元素。
86. 分隔链表。－
88. 合并两个有序数组。－
89. 格雷编码。－　
93. 复原IP地址。－
96. 不同的二叉搜索树。分别以每个点为根，左边左子树，右边右子树，递归。
100. 相同的树。－
101. 对称二叉树。－
104. 二叉树的最大深度。－
105. 从前序与中序遍历序列构造二叉树。－
106. 从中序与后序遍历序列构造二叉树。－
107. 二叉树的层次遍历 II。－
108. 将有序数组转换为二叉搜索树。－
110. 平衡二叉树。－
111. 二叉树的最小深度。－
112. 路径总和。－
114. 二叉树展开为链表。为什么一定要右链？左边不行吗？
118. 杨辉三角。－
119. 杨辉三角 II。用公式推导前后项关系，C(n, m) = n!/(m!(n-m)!), C(n, m-1)=xC(n,m)
121. 买卖股票的最佳时机。应该用DP的，直接暴力过了。
122. 买卖股票的最佳时机 II。根据题目的意思，当天卖出以后，当天还可以买入，所以其实可以第三天卖出，第三天买入，第四天又卖出（（5-1）+ （6-5） === 6 - 1）。所以算法可以直接简化为只要今天比昨天大，就卖出。
125. 验证回文串。－
131. 分割回文串。－
134. 加油站。－
136. 只出现一次的数字。曾经很火的一道题，一个数与自身的异或是0，所有数异或一遍，得到的就是只出现一次的数字。
141. 环形链表。判断链表中是否有环，可用两个指针，一个每次走一步，另一个每次走两步，如果有环必定会相遇。
155. 最小栈。每次入栈2个元素，一个是入栈的元素本身，一个是当前栈元素的最小值
160. 相交链表。查找两个链表的相交点，可用两个指针走两遍，第一遍走掉长度差，短的重新指到长的的头部；第二遍一起走找到相同的地址即可。
162. 寻找峰值。－
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
192. 统计词频。－
193. 有效电话号码。－
194. 转置文件。－
195. 第十行。－
196. 删除重复的电子邮箱。同181，用两张表
197. 上升的温度。datediff返回两日期之差，天数
198. 打家劫舍。动态规划
202. 快乐数。－
203. 移除链表元素。－
204. 计数质数。直接求会超时，leetcode上需要用厄拉多塞筛法，isNotPri[n]，每算一个质数，把它的倍数都划掉，以空间换时间。
205. 同构字符串。题目有岐义，为什么ab-aa是false?s中的b对应a，a不变这样是不行的？
206. 反转链表。－
207. 课程表。－
208. 实现 Trie (前缀树)。－
210. 课程表 II。－
211. 添加与搜索单词 - 数据结构设计。－
217. 存在重复元素。－
219. 存在重复元素 II。用map记录上次出现的位置会更快，这里只用了set慢了50%
220. 存在重复元素 III。－
222. 完全二叉树的节点个数。－
225. 用队列实现栈。－
226. 翻转二叉树。－
231. 2的幂。－
232. 用栈实现队列。－
234. 回文链表。可以修改输入链表你怎么不说?改了输入的数据的题感觉没意义哦～
235. 二叉搜索树的最近公共祖先。－ 
237. 删除链表中的节点。阅读理解+1，题目表述不明确，给定的node就是要删除的那个节点，只有一个参数，想办法删。。。
238. 除自身以外数组的乘积。两个空数组 L 和 R。对于给定索引 i，L[i] 代表的是 i 左侧所有数字的乘积，R[i] 代表的是 i 右侧所有数字的乘积
242. 有效的字母异位词。－
257. 二叉树的所有路径。－
258. 各位相加。－
262. 行程和用户。left join, right join, inner join, on, where
263. 丑数。－
268. 缺失数字。－
278. 第一个错误的版本。－
283. 移动零。－
287. 寻找重复数。可看作是数组链表，有重复数字->有环。
     方法一：step 1, 快慢指针找环，见141；step 2, 确定环的入口，快指针回到头，重新走，必定和慢指针相遇在环入口，数学证明走起～
     方法二：如果原数组可以改变，则可以把当前数字对应下标的数字取负，如果已经是负数说明出现过了
290. 单词规律。－注意一一对应，不多，不少，不重。
292. Nim 游戏。
299. 猜数字游戏。－
300. 最长上升子序列。－
303. 区域和检索 - 数组不可变。可以只求前i个数的和的，愣是把所有i-j和都求出来了，险过。。。
307. 区域和检索 - 数组可修改。应该用线段树的
319. 灯泡开关。完全平方数的因数的个数是奇数个，其它因数成对出现。
326. 3的幂。不能循环或者递归，就只有充分利用条件：int的范围，3是质数。最大的int且是3的幂的是1162261467
338. 比特位计数。－
342. 4的幂。不能循环或者递归，枚举总可以了吧
344. 反转字符串。－
345. 反转字符串中的元音字母。－
349. 两个数组的交集。考集合set的操作，熟悉stl
350. 两个数组的交集 II。不能一次加载所有的元素到内存中怎么办???
367. 有效的完全平方数。－
371. 两整数之和。位运算，a^b是无进位相加，a&b是进位，(a&b)<<1直到0
374. 猜数字大小。－
375. 猜数字大小 II。DP,dp[i][j]为i到j的最大cost。
382. 链表随机节点。－
383. 赎金信。-
386. 字典序排数。递归
387. 字符串中的第一个唯一字符。－
389. 找不同。－
392. 判断子序列。－
398. 随机数索引。－
401. 二进制手表。－
404. 左叶子之和。－
405. 数字转换为十六进制数。－
409. 最长回文串。－
412. Fizz Buzz。－
414. 第三大的数。－
415. 字符串相加。－
421. 数组中两个数的最大异或值。构建字典树，遍历数组作数一，树往下贪心作数二，取最大的那个。
424. 替换后的最长重复字符。滑动窗口，学习了~
429. N叉树的层序遍历。－
434. 字符串中的单词数。－
437. 路径总和 III。－
441. 排列硬币。－
443. 压缩字符串。－
447. 回旋镖的数量。－
448. 找到所有数组中消失的数字。数组元素可以作下标，第一轮把下标为num[i]的置负，第二轮正数对应的下标即为未出现的数
453. 最小移动次数使数组元素相等。n-1个元素+1相当于1个元素-1，反向思维
455. 分发饼干。－
459. 重复的子字符串。－
461. 汉明距离。－ 等于求x^y中1的个数
463. 岛屿的周长。－
470. 用 Rand7() 实现 Rand10()。拒绝概率
475. 供暖器。－
476. 数字的补数。－
478. 在圆内随机生成点。－
482. 密钥格式化。题目跟样例对不上，有问题，说好的除了第一个分组呢？
485. 最大连续1的个数。－
492. 构造矩形。－
496. 下一个更大元素 I。－
500. 键盘行。－
501. 二叉搜索树中的众数。未完成～
504. 七进制数。－
506. 相对名次。map底层是红黑树，插入会自动按key值排序。
507. 完美数。－ 
509. 斐波那契数。－
513. 找树左下角的值。－
519. 随机翻转矩阵。－
520. 检测大写字母。－
521. 最长特殊序列 Ⅰ。－
528. 按权重随机选择。－
530. 二叉搜索树的最小绝对差。
532. 数组中的K-diff数对。－
535. TinyURL 的加密与解密。map空间换时间。
538. 把二叉搜索树转换为累加树。－
541. 反转字符串 II。－
543. 二叉树的直径。－
551. 学生出勤记录 I。－
557. 反转字符串中的单词 III。－
558. 四叉树交集。－注意合并
559. N叉树的最大深度。－ 
561. 数组拆分 I。－
563. 二叉树的坡度。－
566. 重塑矩阵。－`
572. 另一个树的子树。－
537. 复数乘法。不用考虑-1+(-2i)这种？
575. 分糖果。－
581. 最短无序连续子数组。栈，从头遍历 numsnums 数组，升序下标入栈，反之出栈，得左边界，反向得右边界。
589. N叉树的前序遍历。－
590. N叉树的后序遍历。－
594. 最长和谐子序列。－
595. 大的国家。select
596. 超过5名学生的课。有坑，表中有重复记录，结果不记。。。
598. 范围求和 II。－
599. 两个列表的最小索引总和。－
601. 体育馆的人流量。有坑，按日期不行，得按id.类似180
605. 种花问题。－
606. 根据二叉树创建字符串。－
617. 合并二叉树。－ 
620. 有趣的电影。select
621. 任务调度器。－
622. 设计循环队列。－
626. 换座位。left join
627. 交换工资。sql也有三元语法，xxx = if(xxx, Y, N)
628. 三个数的最大乘积。－
633. 平方数之和。－
637. 二叉树的层平均值。－
641. 设计循环双端队列。－
643. 子数组最大平均数 I。－
645. 错误的集合。－
648. 单词替换。－
653. 两数之和 IV - 输入 BST。－
654. 最大二叉树。－
657. 机器人能否返回原点。－ 
661. 图片平滑器。－
665. 非递减数列。分情况讨论吧，当遇到递减时，要么前一个数降，要么后一个数升
669. 修剪二叉搜索树。－
671. 二叉树中第二小的节点。－
674. 最长连续递增序列。－
676. 实现一个魔法字典。－
677. 键值映射。－
680. 验证回文字符串 Ⅱ。－
682. 棒球比赛。－
686. 重复叠加字符串匹配。－ 
687. 最长同值路径。－ 
690. 员工的重要性。－ 
692. 前K个高频单词。－
693. 交替位二进制数。－
696. 计数二进制子串。－
697. 数组的度。－
698. 划分为k个相等的子集。－
700. 二叉搜索树中的搜索。－
701. 二叉搜索树中的插入操作。－ 
703. 数据流中的第K大元素。－
704. 二分查找。－ 
705. 设计哈希集合。－
706. 设计哈希映射。－
709. 转换成小写字母。－
717. 1比特与2比特字符。－
720. 词典中最长的单词。用字典树会超时，排序后用set很快。
724. 寻找数组的中心索引。－
728. 自除数。－
733. 图像渲染。－
744. 寻找比目标字母大的最小字母。－
746. 使用最小花费爬楼梯。－
747. 至少是其他数字两倍的最大数。－
748. 最短完整词。－
762. 二进制表示中质数个计算置位。－
766. 托普利茨矩阵。－
771. 宝石与石头。－ 
777. 在LR字符串中交换相邻字符。－ 
779. 第K个语法符号。－
783. 二叉搜索树结点最小距离。－
784. 字母大小写全排列。－
788. 旋转数字。－
791. 自定义字符串排序。－
796. 旋转字符串。－
797. 所有可能的路径。－
804. 唯一摩尔斯密码词。－ 
806. 写字符串需要的行数。－
807. 保持城市天际线。－
811. 子域名访问计数。－
819. 最常见的单词。－
821. 字符的最短距离。－
824. 山羊拉丁文。－
830. 较大分组的位置。题目不是说“最终结果按照字典顺序输出。”吗？第三个样例是什么鬼？？？
832. 翻转图像。－
836. 矩形重叠。－
840. 矩阵中的幻方。－
844. 比较含退格的字符串。－
846. 一手顺子。只有暴力？
849. 到最近的人的最大距离。－
852. 山脉数组的峰顶索引。－
859. 亲密字符串。－
860. 柠檬水找零。－
867. 转置矩阵。 －
868. 二进制间距。－
872. 叶子相似的树。－
874. 模拟行走机器人。－
876. 链表的中间结点。－
868. 二进制间距。－
883. 三维形体投影面积。－ 
884. 两句话中的不常见单词。－
888. 公平的糖果交换。－
890. 查找和替换模式。－
892. 三维形体的表面积。－
893. 特殊等价字符串组。－
896. 单调数列。－
897. 递增顺序查找树。－
905. 按奇偶排序数组。－
908. 最小差值 I。－
914. 卡牌分组。－ 
917. 仅仅反转字母。－
922. 按奇偶排序数组 II。－
925. 长按键入。－
929. 独特的电子邮件地址。－
933. 最近的请求次数。－
938. 二叉搜索树的范围和。－ 
941. 有效的山脉数组。－是不是不能相信题目中说的length>=3???
执行结果：
执行出错
显示详情
Line 923: Char 34: runtime error: reference binding to null pointer of type 'value_type' (stl_vector.h)
最后执行的输入：
[]
942. 增减字符串匹配。－
944. 删列造序。－ 
949. 给定数字能组成的最大时间。－
950. 按递增顺序显示卡牌。－
953. 验证外星语词典。－
961. 重复 N 次的元素。－
965. 单值二叉树。－
970. 强整数。－
976. 三角形的最大周长。－
977. 有序数组的平方。－
979. 在二叉树中分配硬币。－
985. 查询后的偶数和。－
989. 数组形式的整数加法。－
993. 二叉树的堂兄弟节点。－
994. 腐烂的橘子。－
997. 找到小镇的法官。－
999. 车的可用捕获量。－
1002. 查找常用字符。－ 
1005. K 次取反后最大化的数组和。－
1009. 十进制整数的反码。－
1010. 总持续时间可被 60 整除的歌曲。－
1013. 将数组分成和相等的三个部分。双指针
1018. 可被 5 整除的二进制前缀。－
1021. 删除最外层的括号。－
1022. 从根到叶的二进制数之和。－
1023. 驼峰式匹配。－
1025. 除数博弈。－貌似至今为止唯一一道双击败了100%的题
1029. 两地调度。要使xa+yb <= xb+ya,即xa-xb <= ya-yb，差值排序，前N位去x地即可。
1030. 距离顺序排列矩阵单元格。－
1033. 移动石子直到连续。－
1037. 有效的回旋镖。－ 
1038. 从二叉搜索树到更大和树。－
1042. 不邻接植花。－
1046. 最后一块石头的重量。－
1047. 删除字符串中的所有相邻重复项。－
1051. 高度检查器。看不懂题目+1，看排好队后谁没站到位置上，统计这些人的个数。
1071. 字符串的最大公因子。－
1078. Bigram 分词。－击败了100.00%的用户～哦㖿～
1089. 复写零。－
1103. 分糖果 II。－
1104. 二叉树寻路。－
1108. IP 地址无效化。－ 
1114. 按序打印。用mutex.
1115. 交替打印foobar。同1114.
1116. 打印零与奇偶数。每个函数只调用一次。。。
1117. H2O 生成。
1122. 数组的相对排序。－
1128. 等价多米诺骨牌对的数量。－
1137. 第N个菲波那契数。同70。
1154. 一年中的第几天。－
1160. 拼写单词。－ 
1161. 最大层内元素和。－
1170. 比较字符串最小字母出现频次。－
1175. 质数排列。－
1179. 重新格式化部门表。pivot是orical的，sql直接一个个选吧。。。
1184. 公交站间的距离。－
1185. 一周中的第几天。方法1，算到当前的天数，换星期；方法2，基姆拉尔森计算公式 Week=(Day + 2*Month + 3*(Month+1）/5 + Year + Year/4 - Year/100 + Year/400) % 7；方法3，c++自带函数（奸～）
1189. “气球” 的最大数量。－
1195. 交替打印字符串。当一个线程退出后另一个线程还在等待锁释放，则会出现死锁，退出不自动释放mutex?
1200. 最小绝对差。－
1207. 独一无二的出现次数。－
1217. 玩筹码。－
1221. 分割平衡字符串。－ 
1226. 哲学家进餐。WA。。。
1227. 飞机座位分配概率。令f(i)表示第一个人选择第i个人的座位时，第n个座位被其他人（1到n-1）占用的概率.因此第n个座位被其他人占用的概率为1/n[f(2)+f(3)+...+f(n)]=1/2。
1232. 缀点成线。－
1237. 找出给定方程的正整数解。－
1252. 奇数值单元格的数目。－
1260. 二维网格迁移。－
1261. 在受污染的二叉树中查找元素。－
1266. 访问所有点的最小时间。－
1275. 找出井字棋的获胜者。－
1277. 统计全为 1 的正方形子矩阵。动态规划。f[i][j]表示以[i][j]为右下角的矩阵边长，结果求和。
1281. 整数的各位积和之差。－
1282. 用户分组。－
1287. 有序数组中出现次数超过25%的元素。－
1288. 删除被覆盖区间。－
1290. 二进制链表转整数。－
1295. 统计位数为偶数的数字。－
1299. 将每个元素替换为右侧最大元素。－
1302. 层数最深叶子节点的和。－
1304. 和为零的N个唯一整数。－
1305. 两棵二叉搜索树中的所有元素。－
1309. 解码字母到整数映射。－
1313. 解压缩编码列表。－
1315. 祖父节点值为偶数的节点和。－
1317. 将整数转换为两个无零整数的和。－
1318. 或运算的最小翻转次数。－
1323. 6 和 9 组成的最大数字。－
1325. 删除给定值的叶子节点。－
1331. 数组序号转换。－
1332. 删除回文子序列。－
1347. 制造字母异位词的最小步骤数。说好的排列不同呢？？？
1356. 根据数字二进制下 1 的数目排序。－
1361. 验证二叉树。－
LCP2. 分式化简。－
LCP1. 猜数字。－
