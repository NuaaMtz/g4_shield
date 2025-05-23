# 这是一个使用G4模拟辐射剂量率随屏蔽层厚度变化曲线的程序

## 重点
1. 如何计算剂量率？  
   探测器内的总剂量沉积是容易得到的。剂量率的计算方法为:
   $$D=\frac{E_{total}}{m\times t}$$
   探测器的质量m是可知的。我们只知道我们发射了多少个粒子，不知道时间，因此时间t就需要进行换算。
   本项目中用的粒子源由GPS来生成如下：
   ```
    /gps/pos/type Beam
    /gps/pos/shape Circle
    /gps/pos/radius 0.1 mm # 束流起点范围,模拟加速器的出射口
    /gps/direction 1 0 0

   ```
   平行束流的时间t由总发射粒子数N、束流通量Φ（单位：粒子数/(秒·面积)）和束流横截面积 A（单位：面积）共同决定，公式为：
   
   $$t=\frac{N}{\Phi \cdot A}$$
   由于粒子源为圆形截面（Circle），半径$r=0.1 mm$，面积$A=0.314mm^2$，如果N代表的就是每秒发射的总粒子数，那么时间直接就变成了
   $$t=\frac{N}{A}$$

   总结，在进行了两点假设的情况下进行了时间的测量，一是“/gps/pos/radius 0.1 mm”，二是“N代表的就是每秒发射的总粒子数”，最后得到的剂量率用得到时间都是基于这两个假设下计算的。

2. 在建模过程中，如果不希望频繁修改源码，如何才能保证每次修改屏蔽层厚度后，
源和屏蔽层、探测器和屏蔽层两者的距离不变。  
    固定这两个距离，当动态修改屏蔽层厚度使，同时修改源和探测器的位置


## 进展

(1) 初步完成了探测器的搭建，但是还不可以修改厚度

这个探测系统的结构如下：

世界体积（World）

形状：立方体
尺寸：边长20米（半长10米）
材料：空气（G4_AIR）
屏蔽层（Shield）

形状：长方体
尺寸：x方向半长1米，y/z方向半长10米（即厚度2米，高宽20米）
材料：铅（G4_Pb）
位置：中心在(3米, 0, 0)，即距离原点3米
探测器（Detector）

形状：立方体
尺寸：边长2米（半长1米）
材料：硅（G4_Si）
位置：中心在(7米, 0, 0)

（2） 沉积能总是0，也许是因为数量不够，也许是系统还是有不合物理规律的地方

<---系统搭建完毕，但是参数还需要用户修改确定