#ifndef MANDELBROT_H
#define MANDELBROT_H

#define MAX_ITERATION 1250

/**
 * Determines the Color to Return Based on the Amount of Iterations Performed.
 *
 * @param iteration     The Number of Iterations Performed on a Point
 * @returns             A Color Based on the Amount of Iterations
 */
color iteration_color(const int &iteration);

/**
 * Determines the Amount of Iterations a Point goes through before
 * Returning a Color Base on That.
 *
 * @param mb_x  The X Coordinate in the Mandelbrot Set Space
 * @param mb_y  The Y Coordinate in the Mandelbrot Set Space
 * @returns     A Color Based on the Amount of Iterations
 */
color mandelbrot_color(const double &mb_x, const double &mb_y);

/**
 * Draws the Mandelbrot Set By Setting Every Pixel a Color.
 *
 * @param start_mb_x    The X Coordinate of Mandelbrot Space on the Top Left Corner of the Screen
 * @param start_mb_y    The Y Coordinate of Mandelbrot Space on the Top Left Corner of the Screen
 * @param mb_width      The Width of the Mandelbrot Space that is Displayed on Screen
 * @param mb_height     The Width of the Mandelbrot Space that is Displayed on Screen
 */
void draw_mandelbrot(const double &start_mb_x, const double &start_mb_y, const double &mb_width, const double &mb_height);

/**
 * Displays the X and Y Coordinates of the Mouse's Current Position.
 */
void draw_mouse_coordinate();

/**
 * Allows the User to Control the View by Zooming In or Zooming Out. To Zoom In, the User Must Left Click. To Zoom Out, the User Must Right Click.
 *
 * @param start_mb_x    The X Coordinate of Mandelbrot Space on the Top Left Corner of the Screen
 * @param start_mb_y    The Y Coordinate of Mandelbrot Space on the Top Left Corner of the Screen
 * @param mb_width      The Width of the Mandelbrot Space that is Displayed on Screen
 * @param mb_height     The Width of the Mandelbrot Space that is Displayed on Screen
 */
void user_controls(double &start_mb_x, double &start_mb_y, double &mb_width, double &mb_height);

#endif
