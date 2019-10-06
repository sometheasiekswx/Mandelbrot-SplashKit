#include "splashkit.h"
#include "mandelbrot.h"

/**
 * The main sequence for the program. This will:
 *
 *  - Sets the Starting Location and Size of the Mandelbrot Set
 *  - Draws the Mandelbrot Set
 *  - Allow the User to Zoom In or Zoom Out
 *  - Loops Until the User Chooses to Exit
 *
 * @returns   0 to indicate success to the operating system
 */
int main()
{
    double start_mb_x = -2.5;
    double start_mb_y = -1.5;
    double mb_width = 4;
    double mb_height = 3;

    // Adjust the size of the screen
    open_window("Mandelbrot Set", 320 * 1.25, 240 * 1.25);

    while (!quit_requested() && !key_down(ESCAPE_KEY))
    {
        process_events();

        draw_mandelbrot(start_mb_x, start_mb_y, mb_width, mb_height);

        draw_mouse_coordinate();

        user_controls(start_mb_x, start_mb_y, mb_width, mb_height);

        refresh_screen(60);
    }

    return 0;
}
