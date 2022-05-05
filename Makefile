obj-m = debug_smc.o

all: debug_smc.c
	sudo make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -C $(LINUX_PATH) M=$(PWD) modules

clean:
	sudo make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -C $(LINUX_PATH) M=$(PWD) clean


.PHONY: all clean
