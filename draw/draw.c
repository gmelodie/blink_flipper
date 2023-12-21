#include <furi.h>
#include <furi_hal.h>

#include <furi_hal_gpio.h>
#include <furi_hal_resources.h>

#include <gui/gui.h>
#include <locale/locale.h>

#include <stdlib.h>


static void render_callback(Canvas* canvas, void* ctx) {
    furi_mutex_acquire(ctx, 25);

    canvas_set_font(canvas, FontPrimary);
    canvas_draw_str_aligned(
        canvas, 64, 31, AlignRight, AlignBottom, "Hello World!");

    furi_mutex_release(ctx);
}

int draw_main() {

    FuriMutex *state_mutex = furi_mutex_alloc(FuriMutexTypeNormal);

    // Set system callbacks
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, render_callback, state_mutex);

    // Open GUI and register view_port
    Gui* gui = furi_record_open("gui");
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    while(1) {
        furi_mutex_acquire(state_mutex, FuriWaitForever);
        view_port_update(view_port);
        furi_mutex_release(state_mutex);
    }

    view_port_enabled_set(view_port, false);
    gui_remove_view_port(gui, view_port);
    furi_record_close("gui");
    view_port_free(view_port);
    furi_mutex_free(state_mutex);

    return 0;
}
