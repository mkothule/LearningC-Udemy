#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace bitmap {

	Mandelbrot::Mandelbrot()
	{
	}


	Mandelbrot::~Mandelbrot()
	{
	}


	int Mandelbrot::getIterations(double x, double y) {
		complex<double> z = 0; // both real and imag are set to 0
		complex<double> c(x,y); // real to x and imag to y
		int iterations = 0;
		while (iterations < MAX_ITERATIONS) {
			z = (z*z) + c;
			if (abs(z) > 2) // magnitude greater than 2 then break
			{
				break;
			}
			iterations++;
		}

		return iterations;
	}

}