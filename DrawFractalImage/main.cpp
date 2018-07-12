#include <iostream>
#include <string>
#include <memory>
#include <math.h>

#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

#define MIN(a,b) (a>b ? b : a)
#define MAX(a,b) (a>b ? a : b)

using namespace std;
using namespace bitmap;


int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;
	Bitmap bitmap(WIDTH, HEIGHT); // width: 1920 and height: 1200

	double min = 9999999;
	double max = -9999999;

	unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{ 0 }); // Histogram for improving volor information of mandelbrot image
	unique_ptr<int[]> fractal(new int[WIDTH*HEIGHT]); // Storing number of iteration per pixle location

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT; // -200 is subtracted to get the small lobe of the mandelbrot set into picture 
			double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y*WIDTH + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}
			/*
			// Code for setting color
			uint8_t color = (uint8_t)(256 * (((double)iterations) / Mandelbrot::MAX_ITERATIONS));
			color = color*color*color;
			bitmap.setPixel(x, y, 0, color, color);
			*/
		}
	}

	/*
	// Validation histogram
	int sum = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		cout << "Bin: " << i << " Value: " << histogram[i] << endl;
		sum += histogram[i];
	}

	cout << "Total is: " << sum << endl;
	*/

	int total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		total += histogram[i];
	}

	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {

			uint8_t red = 0;
			uint8_t green = 0; // 255 ^ hue (hue is going from 1 to 0)
			uint8_t blue = 0;

			int iterations = fractal[y*WIDTH + x];
			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				double hue = 0.0;
				for (int i = 0; i < iterations; i++) { // increasing color by an amount equal to number of iterations for the pixels
					hue += ((double)histogram[i]) / total;
				}
				green = pow(255, hue); // 255 ^ hue (hue is going from 1 to 0)
			}
			// image will gave bright color in the area where iteration number is high and darker where iteration number is small

			bitmap.setPixel(x, y, red, green, blue);
		}
	}
	bitmap.write("test.bmp");
	cout << "Finished" << endl;
	while (1);
	return 0;
}