#include <stdint.h>
#include "gpio.h"

// Address = RCC base (0x40021000) + AHB2ENR offset (0x4C).
uint32_t* rcc = (uint32_t*) 0x4002104C;

void enable_gpio_clocks(void)
{
    // 6 = binary 110: bit 1 enables GPIOB; bit 2 enables GPIOC.
    *rcc |= 6;
}
