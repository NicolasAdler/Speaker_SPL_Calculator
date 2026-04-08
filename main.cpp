#include <iostream>
#include <fstream>
#include "SPL_Calculator.h"

int main()
{
    std::string filename = "//Users/nicolasadler/Documents/2026/rockford/Speaker_SPL_Calculator/sample_speaker_no_fs.txt";
    std::ifstream inFile(filename);

    TS_Parameters speaker1;
    speaker1.initialize_speaker(inFile);
    speaker1.solve();
    
    std::cout<<speaker1.get_fs()<<std::endl;

    return 0;
}
