#pragma once

#include <cstdint>

using namespace std;

#pragma pack(2) // align below data to 2 bytes - No padding

namespace bitmap {
	struct BitmapFileHeader { // all members of structor are public by default
		char header[2]{ 'B', 'M' };   // Signature
		int32_t fileSize;  // file of entire file header + data
		int32_t reserved{ 0 }; // not used
		int32_t dataOffset; // after how many bytes data actually starts
	};
}
