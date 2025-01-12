#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/dma.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "parallel_16.pio.h"

#define COLOR(r8, g8, b8)                  \
    ((uint16_t)(((b8) >> 3) & 0x1FU) << 11 | \
    (uint16_t)(((g8) >> 2) & 0x3FU) << 5 | (uint16_t)(((r8) >> 3) & 0x1FU))


int main()
{
    stdio_init_all();

    PIO pio = pio0;
    uint offset = pio_add_program(pio, &parallel_lcd_program
    
    );
    printf("Loaded program at %d\n", offset);

    printf("System Clock Frequency is %d Hz\n", clock_get_hz(clk_sys));
    printf("USB Clock Frequency is %d Hz\n", clock_get_hz(clk_usb));
    // For more examples of clocks use see https://github.com/raspberrypi/pico-examples/tree/master/clocks

    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
