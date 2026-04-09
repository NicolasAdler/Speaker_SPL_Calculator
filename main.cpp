#include <iostream>
#include <fstream>
#include "SPL_Calculator.h"

int main()
{
    std::string filename = "sample_speaker.txt";
    std::ifstream inFile(filename);

    TS_Parameters speaker1;
    speaker1.initialize_speaker(inFile);
    speaker1.solve();
    std::cout<<"Vas: "<<speaker1.get_Vas()<<std::endl;
    std::cout<<"fs: "<<speaker1.get_fs()<<std::endl;
    std::cout<<"Qts: "<<speaker1.get_Qts()<<std::endl;
    std::cout<<"Qes: "<<speaker1.get_Qes()<<std::endl;
    std::cout<<"Qms: "<<speaker1.get_Qms()<<std::endl;
    std::cout<<"Xmax: "<<speaker1.get_Xmax()<<std::endl;
    std::cout<<"Sd: "<<speaker1.get_Sd()<<std::endl;
    std::cout<<"Sensitivity: "<<speaker1.get_Sensitivity()<<std::endl;
    std::cout<<"Cms: "<<speaker1.get_Cms()<<std::endl;
    std::cout<<"Mms: "<<speaker1.get_Mms()<<std::endl;
    std::cout<<"Rms: "<<speaker1.get_Rms()<<std::endl;
    std::cout<<"Bl: "<<speaker1.get_Bl()<<std::endl;
    
    /*
     CORRECT OUTPUT:
	Vas 5.4
	fs 42.4
	Qts 1.361
	Qes 1.6
	Qms 9.108
	Xmax 3.6
	Sd 219
	Sensitivity 77.54
	Re 0.75
	n0 0.00025
	Cms 0.08
	Mms 175.75
	Rms 5.14
	Bl 4.68
     
     */
    // CMS NOT WORKING
    // VAS NOT WORKING

    return 0;
}
