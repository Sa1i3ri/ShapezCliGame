# 类Shapez的CLI大作业

南京大学计算机科学与技术系的大二上高级程序设计的大作业，因为我是跨选，所以不愿意继续在这门课上花费时间，理论上可以继续使用Qt库以达到GUI界面，达到更好的效果。也是处于相同的原因，我在完成基本要求后就收手了，不愿意继续打磨和拓展，我在这门跨选课上花费的时间已经够多了。

## 三个界面

本游戏主要分为三个界面：1. 主界面，2. 商店界面，3. 游戏界面。

### 1. 主界面

<img src="https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219205556641.png" alt="image-20231219205556641" style="zoom:67%;" />

主界面主要由MainInterface支持。

在游戏开始前，可以自行选择开始新游戏(Press t)，存档(Press b)，读取(Press r)，进入商店(Press s)，进入游戏(Press 1 2 3)，退出游戏(Press 0)

如果开始新游戏(Press t)，则会调用Level类和Map类的初始化进程。

如果存档(Press b)，则会自动记录下当前Level 1、Level2、Level3的关卡进度，场景布置，获取的金钱，在Store内购买的全局强化，在每一Level中的局部强化，写入于save文件夹下的file.csv。

如果读取(Press r)，则会读取save文件夹下的file.csv，将其数据写入本次游戏中，以供继续游玩。

如果进入商店(Press s)，则会进入商店界面。

### 2. 商店界面

<img src="https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219212444207.png" alt="image-20231219212444207" style="zoom:67%;" />

Press 1 来增大交付中心面积（半径）

Press 2 来增加A型矿物的额外大小

Press 3 来增加B型矿物的额外大小

Press 4 来扩大地图面积（H、W，即长、宽）

Press 5 来增加A型矿物的价值

Press 6 来增加B型矿物的价值

不论进行了何种升级，都会重置所有Level。

### 3. 游戏界面

<img src="https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219212947215.png" alt="image-20231219212947215" style="zoom:67%;" />

1. 红色#：可切割的A型矿物
2. 蓝色#：不可切割的B型矿物
3. 绿色箭头：传送带
4. 黄色箭头：开采器
5. 紫色箭头：切割器
6. 白色*：垃圾桶
7. 白色@：交付中心
8. 靛蓝（indigo）色：光标，wasd移动光标

ui下面：

1. 三个任务：

   1. 交付20个A型矿物

   2. 交付30个B型矿物

   3. 交付50个切割后的A型矿物

   4. 完成一个任务后，能获得一个局部强化的机会

      ![image-20231219214328109](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219214328109.png)

2. 切割器、传送带、切割器的速度

3. 金钱

4. 交付的A型矿物、B型矿物，切割后的A型矿物的数量

5. Press 1 选择传送带、Press 2 选择开采器、Press 3 选择切割器、Press 4 选择垃圾桶、Press 5 选择空光标。按下空格键在光标处放置。

6. Press p 让全局运动一个时间单位

7. Press r 让光标选择到的物品旋转一个方向

   

## 类的设计、关系

主要分为四类：

![image-20231219214502133](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219214502133.png)

其中，所有Equipment和所有Mineral都继承于Object

NullObject表示没有物品

<img src="https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219215836948.png" alt="image-20231219215836948" style="zoom:50%;" />

![image-20231219215814010](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219215814010.png)

### 1. Interface

主要管理三个界面

![image-20231219214549729](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219214549729.png)

1. MainInterface：负责展示主界面
2. Level和Map：各有一个board的双重vector，模拟游戏界面的地图。每一个Level内含一个Map作成员变量。Level的board存储每个Level的初始化情况，且记录的是Object的类型。Map的board存储具体Object*指针。Level也会负责从Level的board转换到Map的board。Map是最主要的类，负责所有Object的相互运作、局部任务、光标等。
3. Store：负责展示Store界面和全局变量的增强。

### 2. Equipment

![image-20231219215318636](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219215318636.png)

1. Equipment是抽象类，剩下的都是它的子类。注意每一个继承Equipment的类都会内置一个Mineral成员变量。

   ![image-20231219215456278](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219215456278.png)

2. Extractor：开采器

3. TransmissionBelt：传送带

4. Cutter：切割器

5. RubbishBin：垃圾桶

6. Centre：交付中心

### 3. Mineral

![image-20231219215708036](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219215708036.png)

1. Mineral是抽象类，剩下的都是它的子类

   ![image-20231219215905795](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219215905795.png)

2. AMineral：可切割的A型矿物

3. BMineral：不可切割的B型矿物

4. HalfAMineral：切割后的A型矿物

5. NullMineral：表示没有矿物



### 4. Tools

![image-20231219220101744](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219220101744.png)

1. Cursor：管理光标
2. SavingFile：管理存档系统
3. Window：管理展示、更改颜色等操作

## 存档系统

默认存档位于save文件夹下的file.csv

![image-20231219210412904](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219210412904.png)

##### 存档格式

存档中的前7行，是全局强化和金钱的记录。

![image-20231219210540858](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219210540858.png)

依次记录的是：

1. 交付中心的大小（半径）
2. A型矿物的额外大小
3. B型矿物的额外大小
4. 地图大小（H、W，即长、宽）
5. A型矿物的价值
6. B型矿物的价值
7. 金钱



存档剩余的部分，全部是记录Level信息所用。以Level 1为例

<img src="https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219211058885.png" alt="image-20231219211058885" style="zoom:67%;" />

第1行：告知现在是哪一关(level1)，随后分别是：

1. 已开采的A型矿物数量
2. 已开采的B型矿物数量
3. 已开采的被切割的A型矿物数量
4. 开采器速度
5. 传送带速度
6. 切割器速度
7. 交付中心速度
8. 垃圾桶速度
9. 局部升级次数
10. 是否完成任务1
11. 是否完成任务2
12. 是否完成任务3

接下来，是H * W大小的矩阵，每一个string对应了一个地图上的对象。

对于Equipment的子类而言，由方向和内置的矿物，由类似于这样的语法规定：

![image-20231219211705331](https://salieri-typora.oss-cn-shanghai.aliyuncs.com/img/markdown/image-20231219211705331.png)

‘:'前对应的是Equipment的类型，':'到'+'内对应的是内置矿物的类型，'+'后对应的是方向。

