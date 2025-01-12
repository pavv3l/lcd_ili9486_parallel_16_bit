#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "parallel_16.pio.h"

#define D0 6
#define D15 21
#define BITSIZE 16
#define WRX 22 // LCD mcu read bytres on rising edge
#define RDX // when only writing operations, always HIGH
#define CSX 23// LOW for write command code, HIGH for parameter or display data

#define COLOR(r8, g8, b8)                    \
    ((uint16_t)(((b8) >> 3) & 0x1FU) << 11 | \
     (uint16_t)(((g8) >> 2) & 0x3FU) << 5 | (uint16_t)(((r8) >> 3) & 0x1FU))

void initGpio()
{
    gpio_init(WRX);
    gpio_set_dir(WRX, GPIO_OUT);
    gpio_init(CSX);
    gpio_set_dir(CSX, GPIO_OUT);
    for(int i = D0; i <= D15; i++)
    {
        gpio_init(i);
        gpio_set_dir(i, GPIO_OUT);
    }
}

int main()
{
    stdio_init_all();

    PIO pio = pio0;
    uint offset = pio_add_program(pio, &parallel_lcd_program);
    printf("Loaded program at %d\n", offset);

    printf("System Clock Frequency is %d Hz\n", clock_get_hz(clk_sys));
    printf("USB Clock Frequency is %d Hz\n", clock_get_hz(clk_usb));

    while (true)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
