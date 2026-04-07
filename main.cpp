#include <iostream>
#include <fstream>
#include "SPL_Calculator.h"

int main()
{
	std::string filename = "sample_speaker.txt";
	std::ifstream inFile(filename);

	TS_Parameters speaker1;
	speaker1.initialize_speaker(speaker1, inFile);

	return 0;
}
