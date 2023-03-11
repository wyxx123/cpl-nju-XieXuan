# 期末复习要点：

* ### %s读入数据：尽量不用getchar or (" %c")
    1. 多次读入：（含遍数）将每一遍封装函数。->7.括号序列  <br />
       优点：方便用return跳出多次循环，方便封装。
    2. 撒酱亲传：关于命令的读入：用scan+op[0]判断  
       e.g. 7.内存分配：
    3. 分清输出空格和0（0 ！= 空格） -- clion 很坑的一点：会帮你把0换为空格。

````c
int main(void)
{
    	int n = 0;
	int q = 0;
	scanf("%d%d", &n, &q);

	for (int i = 0; i < q; i++)
	{
		char op[3] = { 0 };
		scanf("%s", op);

		if (op[0] == 'A')
		{
			int input_id = 0;
			int input_size = 0;
			scanf("%d%d", &input_id, &input_size);

			//TODO: add codes here.
			//allocate(input_id, input_size);
		}
		else //op[0] == 'Q'
		{
			//TODO: add codes here.
			//question();
		}
	}
	return 0;	
}
````

* ### 关于不同同级别情况之间的组合（多出现在递归/策略问题）
        分清楚“只要任一就可”与“所有都要”的区别  
            1. 只要任一： （一开始为假），子函数一真即真
            2. 所有都要： （一开始为真），子函数一假即假
        实现方法：1. 母问题本身为一个函数，用return
                2. 用一个bool变量记录，但是每种情况要先做变量
                t/f的判断
* ### 关于循环中记录一个（最先的/最后的数据）：结合数组下标及是否
  更新的逻辑。
* ### 多轮读入变量：初始化
        要初始化的变量在循环之外的地方（main or 全局）找

## 易错点：

* ### 去哪里找数据？ >多个数组 or 变量混淆
* ### 关于数据和condition之间的对应关系不清->C位出道：chart
* ### 数组开多大？ 小心漏0！ 几个0就是10的几次方。 malloc要写为：

````c
    int* array = malloc(SIZE * sizeof(*array));
````

* ### True 和 False 的大小写问题（包括输入输出格式的问题）
* ### 标准输入输出->第三章
* ### 关于数据大小太大的问题：
  e.g. float 与 double 混淆 ， 用乘法来
  判断两个数据的正负是否相同（大数据测试）
* ### 浮点数运算（<math.h>的一些问题）
    1. 开三次方根：不用pow（n,1.0 / 3）- 会在
       数据为负数时出错。
    2. 计算2^n时，尽量用（1 << n），避免使用浮点数

## 常用思路：

* ### 循环枚举法：遍历所有情况
* ### 递归（每一步，）

## 数据结构：

* ### 使用数据结构：‘栈’来解决
* ### 多个数组记录（index来联系）-（存储多组相同类型信息） 二维数组记录：int (*ptr)[2]
* ### 结构体数组 （存储多组不同类型信息）
* ### 棋盘/表格 -> 二维数组
* ### 桶标记法： 对于有固定序号（数，字符ascii）的数据，其出现次数可以用一个以数据本身性质为下标的数组统计
* ### vector向量 + 边界检测

## 特别注意：某些 ***常用设置***：

1. 设置-外观与行为-外观-dark
2. 外观-字体大小-16
3. 代码-代码格式化操作-重新格式化代码-alt+x
4. 运行代码已改变成 shift + F10 快捷键
5. 编辑器-代码样式-C/C++-设置自定义-Microsoft

## 关于一些字符串操作函数：

* strstr:

````c
char * strstr ( const char *, const char * );

/*

  Returns a pointer to the first occurrence of str2 in str1,
or a null pointer if str2 is not part of str1.

  The matching process does not include 
the terminating null-characters, but it stops there.

 */

char *operators = " + - * / < > = == >= <= != "; // why there is space?
char *tmp = malloc(4096);
sprintf(tmp, " %s ", s); // add space in the front and rear of s
if (strstr(operators, tmp)) return true; // !!
return false;
````

* sprintf();

````c
int sprintf ( char * str, const char * format, ... );
/*

  sprintf
Write formatted data to string
Composes a string with the same text that would be printed if format was used on printf
, but instead of being printed, the content is stored as a C string in the buffer pointed by str.

 
  return value:

  On success, the total number of characters written is returned. 
This count does not include the additional null-character automatically 
appended at the end of the string.
  On failure, a negative number is returned.
 
*/
````

* strchr();

  Locate first occurrence of character in string
  Returns a pointer to the first occurrence of character in the C string str.

  The terminating null-character is considered part of the C string. Therefore, it can also be located in order to
  retrieve a pointer to the end of a string.

````c
//e.g.
char *semi = strchr(s, ';'); // find position of semicolon
if (semi)
{ // strchr() returns NULL if there's no semicolon
*semi = '\0';
process(s);
process(semi + 1); // what's after semicolon is another part
}
else
process(s);
````

* isdigit();
  Check if character is decimal digit
  Checks whether c is a decimal digit character.

  Return: 0-false, !0-true

* strcat();
  Appends a copy of the source string to the destination string. The terminating null character in destination is
  overwritten
  by the first character of source, and a null-character is included at the end of the new string formed by the
  concatenation of both in destination.

  Return Value:
  destination is returned.

````c
char * strcat ( char * destination, const char * source );

````

## 一些常见的exit codes：

1. 0xC0000005 (越界访问) Segmentation fault
2. 0xC00000FD (stack overflow)
3. 0xC0000374 (堆已损坏 -- overflow)

## 一些东西

### T1

* 选择排序：它的工作原理是：第一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，然后再从剩余的未排序元素中寻找到最小（大）元素，然后放到已排序的序列的末尾。
* 冒泡排序：
*

插入排序：插入排序是一种最简单的排序方法，它的基本思想是将一个记录插入到已经排好序的有序表中，从而一个新的、记录数增1的有序表。在其实现过程使用双层循环，外层循环对除了第一个元素之外的所有元素，内层循环对当前元素前面有序表进行待插入位置查找，并进行移动

* 归并排序：归并排序是建立在归并操作上的一种有效，稳定的排序算法，该算法是采用分治法（Divide and
  Conquer）的一个非常典型的应用。将已有序的子序列合并，得到完全有序的序列；即先使每个子序列有序，再使子序列段间有序。若将两个有序表合并成一个有序表，称为二路归并。
  
  
  # 插件：
  1. ai代码：aixcoder / tabnine ai
  2. rainbow brackets(要钱qwq, 但是免费版配上后面的也差不多) / rainbow
  3. indent rainbow
  4. vim -- 在期中后建议再使用
  5. wakatime
  6. comments highlighter
  7. fast-scrolling
  8. codeglance pro
  9. 中文语音包
  10. 整活向： rainbow fart,  active-power-mode-x
