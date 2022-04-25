/**
 * @file    debug_smc.c
 * @author  Mushahid Hussain
 * @date    25 April 2022
 * @version 0.1
 * @brief  A kernel module to debug hypervisor exception trapping form EL1. This module can display register values after making an SMC call to Trusted-Firmware-A, which maybe be trapped & forwarded by Leo Hypervisor at EL2. This is to make sure that hypervisor correctly parses arguments and return correct values. Furthermore, print logs in Hyperisor and Firmware(I use Trusted Firmware- A) as well.
*/

#include <linux/module.h>     /* Needed by all modules */
#include <linux/kernel.h>     /* Needed for KERN_INFO */
#include <linux/init.h>       /* Needed for the macros */
#include <linux/types.h>

MODULE_LICENSE("GPL");

MODULE_AUTHOR("Mushahid Hussain, Osama Mohammad");

MODULE_DESCRIPTION("A kernel module to debug an SMC from EL1(Linux Kerenl.");

MODULE_VERSION("0.1");

#define U(_x) (_x##U)


//smc function id, which needs to be debuged.
#define PSCI_DEBUG_LEO		U(0xc400000A)


static int __init hello_start(void)
{

    printk(KERN_INFO "Loading Leo Debug module...\n");

    //moving values into smc with smc_fid in x0, see smc calling convention.
    register uint64_t r0 __asm__("x0") = PSCI_DEBUG_LEO;
    register uint64_t r1 __asm__("x1") = 1;
    register uint64_t r2 __asm__("x2") = 2;
    register uint64_t r3 __asm__("x3") = 3;
    register uint64_t r4 __asm__("x4") = 4;
    register uint64_t r5 __asm__("x5") = 5;
    register uint64_t r6 __asm__("x6") = 6;
    register uint64_t r7 __asm__("x7") = 7;

   //making an smc call and saving output register values.
    __asm__ volatile(
		"smc #0"
		: /* Output registers, also used as inputs ('+' constraint). */
		"+r"(r0), "+r"(r1), "+r"(r2), "+r"(r3), "+r"(r4), "+r"(r5),
		"+r"(r6), "+r"(r7));

    //printing register values
    printk(KERN_EMERG, ",X0:%llx, X1:%llx,  X2:%llx,  X3:%llx,  X4:%llx,  X5:%llx, X6:%llx,  X7:%llx", r0,r1,r2,r3,r4,r5,r6,r7);

   return 0;
}

static void __exit hello_end(void)
{
    printk(KERN_INFO "Goodbye Mr.\n");
}

module_init(hello_start);
module_exit(hello_end);

