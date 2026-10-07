#include "assembly_led.h"

void run_part4(void)
{
    __asm__ volatile (

        // here we enable GPIOB's clock according to previous addressing
        "LDR R0, =0x4002104C\n\t"
        "LDR R1, [R0]\n\t"
        "ORR R1, R1, #2\n\t"
        "STR R1, [R0]\n\t"

        // configure PB7 as an output
        "LDR R0, =0x48000400\n\t"
        "LDR R1, [R0]\n\t"
        "BIC R1, R1, #0xC000\n\t"
        "ORR R1, R1, #0x4000\n\t"
        "STR R1, [R0]\n\t"

        // set PB7 high - blue LED on
        "LDR R0, =0x48000414\n\t"
        "LDR R1, [R0]\n\t"
        "ORR R1, R1, #0x80\n\t"
        "STR R1, [R0]\n\t"

    );

    while (1);
}
