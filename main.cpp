#include <iostream>
#include <fstream>
#include "SPL_Calculator.h"

int main()
{
    std::string filename = "//Users/nicolasadler/Documents/2026/rockford/Speaker_SPL_Calculator/sample_speaker.txt";
    std::ifstream inFile(filename);

    TS_Parameters speaker1;
    speaker1.initialize_speaker(inFile);
    //speaker1.set_Mms(speaker1.get_fs(), speaker1.get_Cms());
    speaker1.solve();
    std::cout<<speaker1.get_Vas()<<std::endl;
    std::cout<<speaker1.get_fs()<<std::endl;
    std::cout<<speaker1.get_Qes()<<std::endl;
    std::cout<<speaker1.get_Qms()<<std::endl;
    std::cout<<speaker1.get_Xmax()<<std::endl;
    std::cout<<speaker1.get_Sd()<<std::endl;
    std::cout<<speaker1.get_Sensitivity()<<std::endl;
    std::cout<<speaker1.get_Cms()<<std::endl;
    
    /*
     CORRECT OUTPUT:
     5.4
     42.4
     1.6
     9.108
     3.6
     219
     77.54
     0.08
     
     */
    //FS NOT WORKING

    return 0;
}
