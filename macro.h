//由于宏是全局的，所以为了避免同名的宏冲突 在调用宏之后最好#undef取消定义。

/*
宏定义
#define ADD(a,b) (a+b)


使用
ADD(1, 2)

使用后undef
#undef ADD
*/

//或者在使用前检查是否有定义 如果有就取消定义并且重新定义

#ifndef _MACRO_H_INCLUDED_
#define _MACRO_H_INCLUDED_

#ifdef ADD
#undef ADD
#endif 

#define ADD(a, b) (a+b)

#endif
