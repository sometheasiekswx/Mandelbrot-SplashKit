#include "splashkit.h"
#include "mandelbrot.h"

// Change the color by changing the "iteration_color" functions

// color iteration_color(const int &iteration)
// {
//     if (iteration >= MAX_ITERATION)
//     {
//         return COLOR_BLACK;
//     }
//     else
//     {
//         double hue = (255 * iteration) / MAX_ITERATION;

//         return hsb_color(hue, 0.025, 0.95);
//     }
// }

color iteration_color(const int &iteration)
{
    if (iteration >= MAX_ITERATION)
    {
        return COLOR_BLACK;
    }
    else if (iteration < 25)
    {
        double hue = 0.5 + (iteration / MAX_ITERATION);

        if (hue > 1)
        {
            hue = -1;
        }

        return hsb_color(hue, 0.8, 0.9);
    }
    else
    {
        double hue = (255 * iteration) / MAX_ITERATION;

        return hsb_color(hue, 0.025, 0.95);
    }
}

// ^^^ Change the color by changing the "iteration_color" functions ^^^

color mandelbrot_color(const double &mb_x, const double &mb_y)
{
    double x_temp;

    double x = mb_x;
    double y = mb_y;

    int iteration = 0;

    while (((x * x) + (y * y) <= 4) && (iteration < MAX_ITERATION))
    {
        x_temp = (x * x) - (y * y) + mb_x;
        y = 2 * x * y + mb_y;
        x = x_temp;

        iteration++;
    }

    return iteration_color(iteration);
}

void draw_mandelbrot(const double &start_mb_x, const double &start_mb_y, const double &mb_width, const double &mb_height)
{
    double scale_width = mb_width / screen_width();
    double scale_height = mb_height / screen_height();
    int x;
    int y;
    double mx;
    double my;
    color mb_color;

    x = 0;

    while (x < screen_width())
    {
        y = 0;

        while (y < screen_height())
        {
            mx = start_mb_x + (x * scale_width);
            my = start_mb_y + (y * scale_height);

            mb_color = mandelbrot_color(mx, my);

            draw_pixel(mb_color, x, y);

            y++;
        }

        x++;
    }
}

void draw_mouse_coordinate()
{
    int x = mouse_x();
    int y = mouse_y();

    fill_rectangle(COLOR_BLACK, 0, 0, 125, 10);

    draw_text("X: " + std::to_string(x), COLOR_RED, "Calibri", 100, 0, 0);
    draw_text("Y: " + std::to_string(y), COLOR_RED, "Calibri", 100, 75, 0);
};

void user_controls(double &start_mb_x, double &start_mb_y, double &mb_width, double &mb_height)
{
    double new_mb_width;
    double new_mb_height;
    double location_user_clicked;

    if (mouse_clicked(LEFT_BUTTON))
    {
        new_mb_width = mb_width / 2;
        location_user_clicked = start_mb_x + mouse_x() / screen_width() * mb_width;
        start_mb_x = location_user_clicked - new_mb_width / 2;
        mb_width = new_mb_width;

        new_mb_height = mb_height / 2;
        location_user_clicked = start_mb_y + mouse_y() / screen_height() * mb_height;
        start_mb_y = location_user_clicked - new_mb_height / 2;
        mb_height = new_mb_height;
    }
    if (mouse_clicked(RIGHT_BUTTON))
    {
        new_mb_width = mb_width * 2;
        location_user_clicked = start_mb_x + mouse_x() / screen_width() * mb_width;
        start_mb_x = location_user_clicked - new_mb_width / 2;
        mb_width = new_mb_width;

        new_mb_height = mb_height * 2;
        location_user_clicked = start_mb_y + mouse_y() / screen_height() * mb_height;
        start_mb_y = location_user_clicked - new_mb_height / 2;
        mb_height = new_mb_height;
    }
}
