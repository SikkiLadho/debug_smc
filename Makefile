obj-m = debug_smc.o

all: x86_build

clean: x86_clean RPI_clean

x86_build: hello_world.c
	sudo make -C /lib/modules/5.4.0-52-generic/build M=$(PWD) modules

x86_clean:
	sudo make -C /lib/modules/5.4.0-52-generic/build M=$(PWD) clean

RPI_build: debug_smc.c
	sudo make ARCH=arm64 CROSS_COMPILE=/home/larbs/leo_project/gcc-arm-gnu/bin/aarch64-none-linux-gnu- -C /home/larbs/leo_project/linux M=$(PWD) modules

RPI_clean:
	sudo make ARCH=arm64 CROSS_COMPILE=/home/larbs/leo_project/gcc-arm-gnu/bin/aarch64-none-linux-gnu- -C /home/larbs/leo_project/linux M=$(PWD) clean


.PHONY: all clean x86_build x86_clean RPI_build RPI_clean
