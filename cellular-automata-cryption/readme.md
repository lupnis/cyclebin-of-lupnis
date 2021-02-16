# 基于细胞自动机的加密算法

#### 创建日期:最初版本于2018年使用C#创建，现已遗失，2021/02/16补档

#### 回收日期:2021/02/16

> 这是一个好的算法，也是一次深刻的教训，由于过去的无知，本算法晚于2020/08/07 发出，这是个悲伤的故事。下面是使用方法

> Principle of CAC - CAC加密的原理
>
> CAC is based on the cellular automata , we use the specific private key to encrypt data.
>
> **CAC加密算法基于细胞自动机，我们可以使用特定的私钥来对数据进行几乎无法逆推的加密**

>Firstly, we need to initialize the graph and keypairs, using
>
>```c++
>CACEnc cacentity(mapsize, keypairs, maxdepth);
>```
>
>to create a empty map to contain codes to be encrypted.
>
>**首先，我们使用上述代码实例化CAC的初始图**

> Then, we can use 
>
> ```c++
> cacentity.input(stream);
> ```
>
> to give the map a state to start encryption
>
> **接下来，我们使用上述命令来建立用于加密的状态**

>After the input, we can use the encryption function:
>
>```c++
>cacentity.calcNext();
>```
>
>or:
>
>```c++
>cacentity.calc(times);
>```
>
>to run the cellular automata either a single step or more times
>
>**然后，我们可以使用上述函数来进行细胞自动机的单次运算或连续次数的运算**

> To get the code after encryption, use
>
> ```c++
> std::string s=cacentity.getString();
> ```
>
> **若要获得密文，使用上述函数并用std::string来保存返回值**

## Conclusion - 总结

This this just a very primitive project, I will never maintain it due to my losing motivation of this algorithm, that is all. Remember that one teenager lost his  chance to post a  paper which is creative because of his carelessness, and NEVER BE A SECOND ME.

**此处包含的代码仅为最初对版本，由于对此算法失去了动力，我将不会再对其维护。请记得一个由于没有意识和懒惰而失去了提交有创造性意义论文机会的人，并且记住，<font color=#FF0000 >莫失良机</font>**
