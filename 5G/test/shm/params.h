#ifndef __GET_STRUCT_PARAMS_H
#define __GET_STRUCT_PARAMS_H 1


#ifndef offsetof
#define offsetof(type, number) __builtin_offsetof(type, number)
#endif


#define ENUM2VAR(Enum) var_##Enum##_##12


#define VARIABLE_DEF(type, enum_name) type ENUM2VAR(enum_name)
#define VARIABLE_STR(len,  enum_name) char ENUM2VAR(enum_name)[len]
#define VARIABLE_V(Enum) ENUM2VAR(Enum)

#define UINT(name)    VARIABLE_DEF(unsigned int, name)

/* Define Structure ***************************************************************************************************/
#define STRUCT()



/* Params Structure ***************************************************************************************************/





#endif /*<__GET_STRUCT_PARAMS_H>*/