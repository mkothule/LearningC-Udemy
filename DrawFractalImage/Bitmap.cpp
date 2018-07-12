#include <exception>
#include <iostream>
#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace bitmap;
using namespace std;

namespace bitmap {

	Bitmap::Bitmap(int width, int height) : m_width(width), m_height(height)
	{
	try {
		m_pPixels.reset(new uint8_t[width*height*3]{0}); // initialise all memory to 0 - black
		// use reset method to set the memory again

	}
	catch (exception &e) {
		cout << "Exception in allocation memory " << e.what() << endl;
	}
	}

	bool Bitmap::write(string filename) {
		BitmapFileHeader fileHeader;
		BitmapInfoHeader infoHeader;
		
		fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + (m_width*m_height*3);
		fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

		infoHeader.width = m_width;
		infoHeader.height = m_height;
		infoHeader.dataSize = (m_width*m_height * 3);

		ofstream file;
		file.open(filename, ios::out, ios::binary);

		if(!file){
			cout << "Failed to open a file " << endl;
			return false;
		}

		file.write((char *)&fileHeader, sizeof(fileHeader));
		file.write((char *)&infoHeader, sizeof(infoHeader));
		file.write((char *)m_pPixels.get(), m_width*m_height*3);  // get() method return raw pointer 
		// otherwise we cant typecast unique pointer like this

		file.close();
		if (!file) {
			cout << "Failed to close a file " << endl;
			return false;
		}

		return true;
	}

	void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
		uint8_t *pPixel = m_pPixels.get(); // get method returns pointers to raw image

		// y: row
		// x: col
		pPixel += ((y * 3) *m_width + (x * 3));
		pPixel[0] = blue;
		pPixel[1] = green;
		pPixel[2] = red;
		// little endian in bitmap
		// 0xFF8833 
		// red: 33 green: 88 and blue: FF 
	}


	Bitmap::~Bitmap()
	{
	}
}