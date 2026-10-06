#include <stdint.h>
#include "gpio.h"

// enable the clock register
uint32_t* rcc = (uint32_t*) 0x4002104C;

// mode registers - choose input/output mode for each pin.
uint32_t* gpio_b_mode = (uint32_t*) 0x48000400;
uint32_t* gpio_c_mode = (uint32_t*) 0x48000800;

// output registers
uint32_t* gpio_b_output = (uint32_t*) 0x48000414;
uint32_t* gpio_c_output = (uint32_t*) 0x48000814;

void enable_gpio_clocks(void)
{
    *rcc |= 6;
}

void configure_leds(void)
{
	// turn everything off first
	*gpio_c_output &= ~(1u << 7);
	*gpio_b_output &= ~(1u << 7);
	*gpio_b_output &= ~(1u << 14);

    // here we set the mode bits to 1

    // Green - PC7
    *gpio_c_mode &= ~(3u << 14);
    *gpio_c_mode |=  (1u << 14);

    // Blue - PB7
    *gpio_b_mode &= ~(3u << 14);
    *gpio_b_mode |=  (1u << 14);

    // Red - PB14
    *gpio_b_mode &= ~(3u << 28);
    *gpio_b_mode |=  (1u << 28);
}

void delay(void)
{
    uint32_t count = 0;
    while (count < 1000000)
    {
        count++;
    }
}

void run_part3(void)
{
    enable_gpio_clocks();
    configure_leds();

    while (1)
    {
        // green on
        *gpio_c_output |= (1u << 7);
        delay();

        // green off, blue on
        *gpio_c_output &= ~(1u << 7);
        *gpio_b_output |=  (1u << 7);
        delay();

        // blue off, red on
        *gpio_b_output &= ~(1u << 7);
        *gpio_b_output |=  (1u << 14);
        delay();

        // red off, repeat
        *gpio_b_output &= ~(1u << 14);
    }
}
