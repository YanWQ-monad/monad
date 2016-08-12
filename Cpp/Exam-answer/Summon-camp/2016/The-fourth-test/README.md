第四次测试
==========
## 斐波那契数列 a
#### 题目描述
斐波那契数列非常出名，下面给产生出斐波那契数列的函数伪代码：

![斐波那契数列伪代码](https://raw.githubusercontent.com/YanWQ-monad/monad/master/Material/Image/FibonacciPseudocode.png)

考虑到你的英语水平，给出几个单词的翻译： equals(等于)、print(打印)。

现在给定一个整数n，问调用fibonacci(n)函数后，总共会输出多少个数字0和多少个数字1？
#### 输入格式
第一行，一个整数R(1<=R<=10)，表示有R组测试数据。

每组测试数据格式：
  * 一个整数n(1<=n<=40)。

#### 输出格式
共R行，每行两个整数，分别表示打印了0的个数和1的个数。
#### 样例输入
	4
	0 3 6 22
#### 样例输出
	1 0
	1 2
	5 8
	10946 17711
## 切蛋糕 b
#### 题目描述
有一个蛋糕，它是由长度是L的二进制组成的。现在需要把蛋糕切K-1刀，这样蛋糕就会被切成K份，每一份蛋糕其实就是一段连续的二进制（不能有前导0）。小LW今年5岁了，所以她希望把每一份蛋糕的二进制转为十进制之后，都是5的幂，即可以表示成5^X，其中X是整数。求满足题意的最小的正整数K。如果无法完成任务，输出-1。
#### 输入格式
第一行，一个整数R(1<=R<=25)，表示有R组测试数据。
每组测试数据格式如下：
  * 第一行，一个整数L(1<=L<=50)。
  * 第二行，L个二进制数字，0或者1。

#### 输出格式
共R行，每行一个整数。
#### 样例输入
	11
	9
	101101101
	7
	1111101
	5
	00000
	9
	110011011
	10
	1000101011
	27
	111011100110101100101110111
	49
	1101100011010111001001101011011100010111011110101
	4
	0101
	4
	1001
	50
	11111111111111111111111111111111111111111111111111
	14
	10111001110011
#### 样例输出
	3
	1
	-1
	3
	-1
	5
	1
	-1
	-1
	50
	4
## 钱与数字II
#### 题目描述
有n个数字，分别是0到n-1 ，数字0的价钱是money[0]，数字1的价钱是money[1] ,数字2的价钱是money[2]，….数字n-1的价钱是moeny[n-1]。你现在有m元钱，你如何利用这m元钱去购买数字，使得购买回来的数字连 在一起，构成的整数最大？输出最大的整数。给出的钱至少能买1个数字。可以多次买相同的数字。
#### 输入格式
第一行，一个整数R(1<=R<=10)，表示有R组测试数据。
每组测试数据格式：
  * 第一行，n(1<=n<=10)和m(1<=m<=![formula](http://latex.codecogs.com/gif.latex?\10^{18})
)。
  * 第二行，n个整数，第i个整数是money\[i\](1<=money[i]<=![formula](http://latex.codecogs.com/gif.latex?\10^{18})
)。

#### 输出格式
每组测试数据的格式如下：
  * 第一行，最大整数的位数。
  * 第二行，输出最大整数的前50个数字。如果最大整数不足50个数字，则输出最大整数的全部数字。
  * 第三行，输出最大整数的末尾50个数字。如果最大整数不足50个数字，则输出最大整数的全部数字。

#### 样例输入
	5
	3 21
	6 7 8 
	3 21
	1 7 8 
	10 923372036854775807
	1 1 1 1 1 1 1 1 1 1 
	2 923372036854775807
	1 923372036854775807 
	2 923372036854775807
	1 923372036854775806 
#### 样例输出
	3
	210
	210
	15
	100000000000000
	100000000000000
	923372036854775807
	99999999999999999999999999999999999999999999999999
	99999999999999999999999999999999999999999999999999
	1
	1
	1
	2
	10
	10
## 敏感词
#### 题目描述
在百度上，当你尝试输入`GCD”`政治敏感词时，搜索结果会被屏蔽大量的信息。
现在给出n个“敏感词”，每个敏感词都是一个字符串，为了安全，还有“变形敏感词”。

“变形敏感词”：是指把“敏感词”的字符通过若干次交换位置得到的字符串。
例如：`abc`是敏感词，那么`acb`、`bac`、`bca`、`cab`、`cba`都是`abc`的“变形敏感词”。

一个字符串可以同时是多个"敏感词"的"变形敏感词"。例如有两个敏感词：`three`、`there`，那么`heret`既是`three`的"变形敏感词"，又是`there`的"变形敏感词"。

下面定义“变形敏感词”的“危害程度”：
  1. 假设字符串S是敏感词T的“变形感敏词”。
  2. 那么S的“危害程度”，不妨设为val 。
  3. 假设字符串S的长度是L，显然敏感词T的长度也一定是L。
  4. val = 0;
     for(int i=0; i < L; i++)
         if(S[i] != T[i])
             val++。
  5. 如果字符串S同时是多个“敏感词”的“变形敏感词”，那么字符串S的 "危害程度”val取其中的最小值。

我们规定：“敏感词”的“危害程度”等于0。

给定一个符串T，如果存在一种方案，把T切成连续的若干段，使得每一段要么是“敏感词”，要么是“变形敏感词”，那么字符串T是“邪恶字符串”。

例如：给出6个敏感词： `one`、`two`、`three` 、`there`、`twoone`、`eethr`。
那么`neotowheret`是“邪恶字符串”：

方案一：可以把`onetowheret` 切成连续的三段：`one`、`tow`、`heret`，这3段都要么是“变形敏感词”，要么是“变形敏感词”。`one`的“危害程度”是0， `tow`的“危害程度”是2，`heret`的“危害程度”是3,那么T的“危害程度”总和 = 0 +2+3 = 5。

方案二：可以把`onetowheret` 切成连续的两段：`onetow`、`heret`，这两段都要么是“敏感词”，要么是“变形敏感词”。`onetow`的“危害程度”是0，`heret`的“危害程度”是3, 那么T的“危害程度”总和 = 6+3 = 9。
显然，方案一可以使得T的“危害程度”总和最小。
现在的任务是：对于给定的字符串T，如果T是“邪恶字符串”，那么输出T的“危害程度”总和的最小值，如果T不是“邪恶字符串”则输出-1。
#### 输入格式
第一行，一个整数R，表示有R组测试数据。1 <= R <= 10。
每组测试数据格式：
  * 第一行，一个字符串T，长度不超过50,由小写字母构成。
  * 第二行，一个整数n。 表示有n个敏感词，每个敏感词都是由小写字母构成，长度不超过50。
  * 接下来有n行，每行表示一个敏感词。

#### 输出格式
共R行，每行一个整数。
#### 样例输入
	19
	neotowheret
	4
	one two three there 
	abba
	3
	ab ac ad 
	thisismeaningless
	3
	this is meaningful 
	ommwreehisymkiml
	11
	we were here my is mom here si milk where si 
	aaaaa
	3
	aa aaa aaa 
	aaaa
	3
	aa aaa aaa 
	a
	3
	aa aaa aaa 
	aaaaa
	3
	aaa aa aaa 
	bcdaedfbgcha
	1
	abcdbedfagch 
	zacaedfd
	3
	acaz dfde azacdedf 
	ogodtsneeencs
	6
	go good do sentences tense scen 
	ogodtsneeencs
	6
	go good od sentences tense scen 
	sepawaterords
	2
	separate words 
	aaaaaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbb
	1
	bbbbbbbbbbbbbbbbbbbbbbbbbaaaaaaaaaaaaaaaaaaaaaaaaa 
	aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	1
	a 
	aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
	4
	a b aaa ab 
	abbababbabababababababbbabababaaaabababababaababab
	1
	ab 
	zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzx
	2
	xz zz 
	zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzx
	2
	xz zzz 
#### 样例输出
	8
	2
	-1
	10
	0
	0
	-1
	0
	12
	8
	8
	8
	-1
	50
	0
	0
	-1
	2
	2
