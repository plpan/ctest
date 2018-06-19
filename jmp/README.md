### setjmp & longjmp
Reference: https://opensource.apple.com/source/libplatform/libplatform-161.20.1/include/setjmp.h.auto.html

#### jmp_buf
保存环境变量：本质上就是一个int数组；实际上是一个struct数组，数组就一个元素
可以测试打印jmp_buf变量中的元素来建议数组元素和寄存器的一一对应关系

#### setjmp
保存当前线程的环境变量：主要是寄存器(rflags, rip, rbp, rsp, ...)
正常函数调用，setjmp返回0值，而longjmp跳转回来时，返回值非0

#### longjmp
恢复上一次保存的环境变量，并且代码将会重新跳转到setjmp，并且可以指定setjmp的返回值，禁止传0值

#### 使用场景
可以用在异常处理: http://web.eecs.utk.edu/~huangj/cs360/360/notes/Setjmp/lecture.html

#### 使用禁忌
因为setjmp是将当前线程的环境变量保存至jmp_buf变量中，包括线程栈的数据(sp)，如果setjmp在临时函数中调用，然后在临时函数退出后在调用longjmp，那么栈的信息将会丢失，直接会导致SegmentFault
