# findex_webpart 第一次搞的简陋文件系统前端

#### 开发日期：2021/01/21

#### 回收日期：2021/02/05

> 一、综述
> 本部分包含三种类型index，一为<u>文件目录index</u>；二为<u>图片index</u>；三为<u>视频index</u>
> 您需要修改的是在index中被两个井号（#）包围的内容 **注意：井号（#）成对出现**
> 有些内容需要批量添加，本文档将会给您作出说明和使用样例

>分类一：**文件目录index**
>
>> 目录内容
>> <pre>
>>     -index.html         目录默认文档
>>     -dstyle.css         目录默认网页使用的样式表
>> </pre>
>
>> 包含内容
>> **#dirname#**  当前目录所在位置
>> **#servername#** 服务器名称 - 起个好听的名字吧 ~
>> **#rootpath#** 根目录位置，决定回到的最初主页
>
>> > tbody内结构（需要用string 的操作符 **+=** 追加或者其他高级方法）
>> >
>> > ```html
>> > <tr>
>> >    	<td data-value="#nextdirname#">
>> >       	 <a class="dirr" href="#nextdirname#">
>> >         	   <img src="dir.png">#nextdirname#
>> >         </a>
>> >    	</td>
>> >    	<td class="details" data-value="#typec#">
>> >        	#typec#
>> >    	</td>
>> >    	<td class="details" data-value="#hotc#">
>> >    		#hotc#
>> >    	</td>
>> > </tr>
>> > ```
>> >
>> > **#nextdirname#** 包含的子目录超链接（相对路径）
>> >
>> > **#filesize#** 文件夹大小
>> >
>> > **#date#** 修改日期
>
>分类二：**图片index**
>
>> 目录内容
>> <pre>
>>     -index.html        目录默认文档
>>     -sstyle.css        图片默认网页使用的样式表
>> </pre>
>
>> 包含内容
>> **#dirname#**  当前目录所在位置
>> **#servername#** 服务器名称 - 起个好听的名字吧 ~
>> **#noimg#** 默认情况下没有文件可显示的默认图片
>
>> > filelist内结构（需要用string 的操作符 **+=** 追加或者其他高级方法）
>> >
>> > ```html
>> >  <a>#filecallpath#</a>
>> > ```
>> > **#filecallpath#** 图片所存在的绝对、相对或网页路径
>>
>> **视频部分和图片部分调用方法一致**



## 感谢使用

All rights reserverd (c) 2018-2021 RiverENC Team
