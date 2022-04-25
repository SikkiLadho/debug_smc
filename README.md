# debug_smc


Kernel A kernel module to debug AARCH64 hypervisor exception trapping form EL1. This module can display register values after making an SMC call to Trusted-Firmware-A, which maybe be trapped & forwarded by Leo Hypervisor at EL2. This is to make sure that hypervisor correctly parses arguments and return correct values. Furthermore, print logs in Hyperisor and Firmware(I use Trusted Firmware- A) as well.


#Compile

`git clone https://github.com/SikkiLadho/debug_smc.git`

`make`


#Clean

`make clean`
