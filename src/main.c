#define KIT_IMPL
#include "include/kit.h"

#define KIT_RECT kit_rect(0, 0, 50, 50)

int vol = 0.5;

int main(int argc, char **argv) {

    kit_Context *ctx = kit_create("HELLO", 256, 192, KIT_SCALE2X | KIT_HIDECURSOR | KIT_FPS30);
    double *dt;

    while (kit_step(ctx, dt)) {
    if (kit_key_pressed(ctx, SDLK_ESCAPE)) { break; }
        // fullscreen pressed
        if (kit_key_pressed(ctx, SDLK_f)) {
         SDL_SetWindowFullscreen(ctx->window, SDL_WINDOW_FULLSCREEN_DESKTOP);
        }
          kit_clear(ctx, KIT_BLUE);
          kit_draw_text(ctx, KIT_WHITE, "hello!", 10, 10);
          kit_draw_text(ctx, KIT_WHITE, "welcome to kit.h!", 10, 20);
        }
      /* Clean up */
    kit_destroy(ctx);
    return 0;
}
