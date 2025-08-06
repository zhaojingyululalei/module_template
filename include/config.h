#ifndef __ZHAO_CONFIG_H
#define __ZHAO_CONFIG_H




#define __ENV_(NAME) \
    static int __init NAME##_init(void) \
    {\
        init();\
        return 0;\
    }\
    static void __exit NAME##_exit(void) \
    {\
      exit();\  
    }\
    module_init(NAME##_init)\
    module_exit(NAME##_exit)\
    MODULE_LICENSE("GPL");\
    MODULE_AUTHOR("wit@zhaixue.cc");\



#endif