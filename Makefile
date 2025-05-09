
#config  不允许$(shell )
MODULE_NAME := newled
KDIR := /home/zhao/linux/imx6ull/linux/linux-imx-rel_imx_4.1.15_2.1.0_ga_alientek
SRCS := main.c 


INCLUDEDIR := include
SRCDIR := src
OBJS := $(patsubst %.c, %.o, $(SRCS))
OBJECTS := $(foreach obj, $(OBJS), $(SRCDIR)/$(obj))
CURRENT_PATH := $(PWD)
ifneq ($(KERNELRELEASE),)

obj-m := $(MODULE_NAME).o
$(MODULE_NAME)-objs := $(OBJECTS)
ccflags-y := -I$(CURRENT_PATH)/$(INCLUDEDIR)

else
EXTRA_CFLAGS += -DDEBUG 



all:
		$(MAKE)  -C $(KDIR) M=$(PWD) modules
.PHONY: test clean
test:
	@echo "SRCS: $(SRCS)"
	@echo "OBJS: $(OBJS)"
	@echo "OBJECTS: $(OBJECTS)"
clean:
		$(MAKE)  -C $(KDIR) M=$(PWD) modules clean
endif



# ifneq ($(KERNELRELEASE),)
# obj-m := hello.o
# hello-objs := main.o add.o sub.o
# else
# EXTRA_CFLAGS += -DDEBUG 
# KDIR := /home/linux-5.10.4
# ARCH_ARGS := ARCH=arm CROSS_COMPILE=arm-linux-gnueabi-

# all:
# 		make  $(ARCH_ARGS) -C $(KDIR) M=$(PWD) modules
# clean:
# 		make  $(ARCH_ARGS) -C $(KDIR) M=$(PWD) modules clean
# endif

