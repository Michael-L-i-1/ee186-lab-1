#include <stdint.h>
#include "gpio.h"

// Address = RCC base (0x40021000) + AHB2ENR offset (0x4C).
// Kept at file scope so *rcc_ahb2enr is easy to watch in Expressions.
uint32_t* rcc_ahb2enr = (uint32_t*) 0x4002104C;

void enable_gpio_clocks(void)
{
    // 6 = binary 110: bit 1 enables GPIOB; bit 2 enables GPIOC.
    // |= sets these two bits and preserves all other bits.
    *rcc_ahb2enr |= 6;
}
