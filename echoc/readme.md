# echoc 一个可由cmd使用的局部彩色命令行程序，用以美化您的批处理。

#### 开发日期：2018/01/08

#### 回收日期：2021/02/02

##### 下面是一种程序输出的实现方法，可输入至cmd进行试验

```
@echo off
echoc This  is  the first test of $GREEN echoc $CLEAR application -n $CLEAR
echoc This is a $LINE lined information -n This is a -sw FBSWAP information -n $CLEAR
echoc This is a $BLUE col -b $YELLOW our -b $CYAN ful $CLEAR text -n $CLEAR
echoc With all $BLACK_BOLD colors $WHITE_BOLD can be displayed $RED in $RED_BOLD te -b $YELLOW_BOLD rm -b $BLUE_BOLD in -b $MAGENTA al -n $CLEAR
echoc This is a log type time format -n -t -n
echoc xxx $LINE cdwf xfff $CLEAR -b -p -n test input [ ] -b -b -b 
pause>nul
echoc -n
echoc $RED_B red background with $GREEN green words
pause>nul
cls
echoc Welcome to a menu -n -n
echoc $RED_B -p -c Home -n -n
echoc $GREEN_B -p -c Edit -n -n
echoc $YELLOW_B -p -c View -n -n
echoc $CYAN_B -p -c Options -n -n
echoc $MAGENTA_B -p -c About -n -n
pause>nul
```
