#include <iostream>
#include <fstream>
#include "SPL_Calculator.h"

int main()
{
	std::string filename = "no_Vas.txt";
	std::ifstream inFile(filename);

	TS_Parameters speaker1;
	speaker1.initialize_speaker(inFile);
	speaker1.solve();
	
	std::cout<<"You are here!\n";
	std::cout<<speaker1.get_Vas()<<std::endl;

	return 0;
}
