# debug_smc

debug_smc is kernel module to debug AARCH64 hypervisor exception trapping form EL1. This module, when loaded, can display register values after making an SMC call to Trusted-Firmware-A, which maybe be trapped & forwarded by Leo Hypervisor at EL2. This is to make sure that hypervisor correctly parses arguments and return correct values. Furthermore, print logs in Hyperisor and Firmware(I use Trusted Firmware- A) as well for better debugging. 

#Requirments

Make sure you have ARM-GNU compiler toolchain installed for AARCH64 and linux kernel source directory.

#Compile

Replace `path/to/kernel/source` with a path to linux kernel source directory.

`git clone https://github.com/SikkiLadho/debug_smc.git`

`make LINUX_PATH=path/to/kernel/source`


#Clean

`make clean LINUX_PATH=/path/to/kernel/source`
