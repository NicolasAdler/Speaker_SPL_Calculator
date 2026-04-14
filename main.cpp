#include <iostream>
#include <fstream>
#include <vector>
#include "SPL_Calculator.h"

int main()
{
    std::string filename = "sample_speaker.txt";
    std::ifstream inFile(filename);

    if(!inFile)
    {
    	std::cerr <<"Error: Could not find or open " <<filename <<std::endl;
    	return 1;
    }
    std::ofstream SPL("sample_speaker_spl.txt");

    if(!SPL)
    {
    	std::cerr<<"Error: could not create output file\n";
    }

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
   // std::cout<<"Re: "<<speaker1.get_Re()<<std::endl;
    std::cout<<"n0: "<<speaker1.get_n0()<<std::endl;
    std::cout<<"Cms: "<<speaker1.get_Cms()<<std::endl;
    std::cout<<"Mms: "<<speaker1.get_Mms()<<std::endl;
    std::cout<<"Rms: "<<speaker1.get_Rms()<<std::endl;
    std::cout<<"Bl: "<<speaker1.get_Bl()<<std::endl;
    std::cout<<"Volume of Box: "<<speaker1.get_Vb()<<std::endl;

	std::vector<double> spl_values;
	spl_values.resize(20001);
    speaker1.compute_transfer_function(spl_values);
    
    for (const auto& value : spl_values)
    {
        SPL << value << "\n";
    }
    SPL.close();

    std::cout<<"Success: Data written to smaple_speaker_spl.txt" <<std::endl;
    
    
    return 0;
}
