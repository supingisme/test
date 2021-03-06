
SSE/AVX并行优化基础

SIMD扩展指令集
和本文集上一篇介绍的NEON类似，SSE/AVX也是SIMD（单指令多数据）扩展指令集，只不过neon是针对arm架构的，而sse/avx是针对X86架构的。其实它们的原理都是殊途同归的，都是一个指令可以同时对多个数据进行操作，当然这里又多少个数据可以同时操作，还是由指令集架构的向量寄存器的长度和数据类型的长度决定的。举个例子：AVX的向量寄存器长度是256位，如果要对float32类型的数据进行并行计算，可以同时操作256/32=4个float16数据。与neon类似，我们也按寄存器、数据类型、指令来介绍。

寄存器
SSE的向量寄存器长度是128位，即如果要操作32位的int类型数据，可以同时操作4个，而AVX的向量寄存器是256位的，可同时操作的同类型数据是sse的两倍。

数据类型
Intel ICC和开源的GCC编译器都支持SSE/AVX指令集C接口（intrinsic）的编译。接口声明再intrinsic.h头文件中。其数据类型命名主要又__m128/__m256、__m128d/__m256i（d表示双精度，i表示整型）。

指令
指令函数的命名可大致分为三个部分，三个部分之间分别用“_”隔开。如_mm_hadd_ps。

第一部分是_mm或_mm256。前者表示是SSE指令，操作的向量长度是64位或128位。_mm256表示是AVX指令，操作的向量长度是256位。
第二部分是运算名称，如_add、mul等，又一些运算名称会增加修饰符，如_loadu表示不对齐到向量长度的存储器访问。
第三部分是操作数据的信息，_ps表示操作向量中所有的单精度数据；_pd表示操作向量中所有双精度数据；_pixx表示操作向量中所有的xx位又符号整型数据，向量寄存器长度为64位；_epixx表示操作向量中所有的xx位的又符号整型数据，向量寄存器长度为128为；_epuxx表示操作向量中所有的xx位的无符号整型数据，向量寄存器长度为128位；_ss表示只操作向量中第一个单精度数据；si128表示操作向量寄存器中的第一个128位有符号整型。

作者：半笔闪
链接：https://www.jianshu.com/p/92a4f3d4434e
来源：简书
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
