#include <furi_hal.h>

int blink_main(void* p) {
    UNUSED(p);
    bool on = false;

    furi_hal_gpio_init_simple(&gpio_ext_pb3, GpioModeOutputPushPull);

    while (1) {
        on = !on;
        furi_hal_gpio_write(&gpio_ext_pb3, on);
        furi_delay_ms(1000);
    }

    furi_hal_gpio_init_simple(&gpio_ext_pb3, GpioModeAnalog);

    return 0;
}

