#pragma once

#include <cstdint>

using namespace std;

#pragma pack(2) // align below data to 2 bytes - No padding

namespace bitmap {

	struct BitmapInfoHeader {
		int32_t headerSize{ 40 }; // Size of this header = 10 * int32_t = 10 * 4 bytes = 40 bytes
		int32_t width;
		int32_t height;
		int16_t planes{ 1 };
		int16_t bitsPerPixel{ 24 }; // 8-bit per channel
		int32_t compression{ 0 }; // No compression
		int32_t dataSize{ 0 }; // Size of data in this bitmap file - set later
		int32_t horizontalResolution{ 2400 };
		int32_t verticalResolution{ 2400 };
		int32_t color{ 0 };
		int32_t importantColors{ 0 };
	};
}