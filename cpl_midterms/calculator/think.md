## 1.负数

1 + + 1//err  
1 + - 1  
1 - - - 1

in fact, this can wait until later  
TODO...

- [ ] done.

## 2.float:

1. 类型不同
2. 求值之前的逻辑判断以确定返回时的type
3. 词法检查  
   //err

...

## 3.more =

ok with that.

# 伪代码：

输入：

1. num（float/int）:type,num;
2. operation:(,),+,-,*,/,= type;
3. variable: >type,name<,num;

数据结构：  
each tokens:

```c
//type enum
enum type
{
FLOAT,
INT,
L_BRACKET,
R_BRACKET,
...
};


//each tokens
struct token
{
enum type token_type;
union
{
char name[40];
int num_int;
float num_float;
} value;
};
```

return:

```c
typedef struct return_value {
    enum {
        INT,
        FLOAT,
        ERROR
    } return_type;
    union {
        int int_val;
        double double_val;
    } val;
} Value;


```

the variable:

```c
struct variable
    {
        type variable_type;
        char name[40];
        union
        {
            int int_value;
            double double_value;
        } value;
    };
```

stack

#### 具体实现：

while(没结束)  
输入一行；  
词法分析；（统计 ‘=’ 数量）  
函数：将等号去掉；  
打印结果；

去等号函数：  evalAssign(l, r)
如果（等号数量 == 0）  
函数：语法分析及赋值；  
else if（这一个为变量&&下一个为‘=’）  
调用 l+2 的 去等号函数； 
else  
返回错误信息；



语法分析及赋值函数：  
if （l小于r）  
return 错误信息  
if （l == r）
return 一个合规的return_value;  
if （检查配对括号函数）  
语法分析及赋值函数（。。。）
else if（检查是否为-num/-（）函数）
return - 语法分析及赋值函数（l+1）；
else
找到著运算符函数；
如果合规：
调用递归；
否则 err







找到主运算符函数：//ret =-1
遇见括号：
压栈/出栈

栈是空的：  
//找+or-  
从后往前找：  
找到+ ： 找到第一个 
找到- ： 如果下一个为运算符：continue；  
else：记录；  
//找*or/  
找到第一个；

记得清空栈。
return

检查是否为-num/-（）函数：
 if（这个不为负号）
  false；  
 else if（只有2个且下一个合规）
  true；
 else
  return 检查（）函数；





检查（）函数：
if（没有（，）形式）
 false；
循环：
 栈空了到底：
  true；







new        ok                err

 old       ok                   ok      

           fuzhi    caozuo




