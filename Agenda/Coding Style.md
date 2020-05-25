# 一点简单的代码规范
### 大括号、变量、函数名习惯与 Cocos2dx 源码基本保持一致：

+ 大括号统一换行。
    + 建议只有一行的条件、循环语句都用大括号包围。
    + 如果 `if` 语句只有一行且短小，可以不使用大括号。
    + 但是 `if` 配对的 `else` 应该与 `if` 同样 有/无 大括号。
+ 变量名使用
    + 局部变量和参数统一使用小驼峰。
    + 类成员变量使用 `m_` 前缀，接小驼峰。
    + 全局变量（避免在代码逻辑中使用全局变量）`g` 开头大驼峰。
    + 常量（全局或局部）`k` 开头大驼峰。
    + 指针变量/指针形参 `p` 开头大驼峰。 
        + 参数应该满足这个规则
        + cocos 自带类用 create 方法产生的返回值都是指针，如果你用 auto 或其他方式来推断这个值的类型，可以不使用 `p` 前缀。


+ 类名
    + 统一大驼峰。
+ 函数名
    + 成员函数使用小驼峰。
    + 普通函数也使用小驼峰。

例子：

``` C++
string gXy = "不准乱用全局变量";

class MyScene : public Scene {
public:
    void startButtonCallback(Ref *);
    
    int    m_anIntValue = 0;
    string     m_dczTql = "DCZTQL";
    const string   kLjs = "帮 ljsxgg 找 npy";
}

/**
 *@brief   开始游戏的回调
 *@param   pSender: 暂时没用的指针
  *@date   05/25/2020 [(modified / bug fixed) by xxx]
  *@author zzy
*/
void MyScene::startButtonCallback(Ref *pSender) {
    Director::getInstance()->replaceScene(SafeMap::create())
}
```

### 其他规则：

+ 使用 Doxygen 为每一个*类*和*函数*写明功能，必须包含 `@brief` 和其他重要的解释。合写文件建议使用 `@author` 表明函数作者。
+ 不论是在代码中还是注释中，建议以一定的方式对齐增加美观度。
+ 一行不超过 120 字符，可以在长行适当处截断换行。
+ 一个函数不建议超过 50 行。
+ 减少宏的使用，尽量使用 const。
+ 在保证每个函数都有 Doxygen 注释的情况下，函数间还要有一行或以上的空行。
+ `+ = - * / & | += -= *= /= &= \= == != < > >= <= && || ` 符号前后都要有一个空格，`, ; `前面不空格，后面总是要有一个空格（或换行）。
+ 使用**换行符**尽量阔绰，函数声明间也需要换行，以便区分哪个注释是哪个函数的。预处理与代码之间保持一行或以上的空间。函数与函数之间也要保持一行以上。