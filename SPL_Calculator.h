#include <iostream>
#include <cmath>

#define PI 3.14159265358979
#define RHO 1.225
#define C 343

class TS_Parameters
{
	private:

	double Vas, fs, Qts, Mms, Cms, Kms, Qes, Qms, Sd, Xmax, Sensitivity, Re, Rms;

	public:
	void set_Vas(double _Vas);
	void set_Vas(double _Sd, double _Cms);
	double get_Vas();

	void set_Mms(double _Mms);
	void set_Mms(double _fs, double _Cms);
	double get_Mms();

	void set_Cms(double _Cms);
	void set_Cms(double _Vas, double _Sd);
	double get_Cms();

	void set_Kms(float _Kms);
	void set_Kms_with_Cms(double _Cms);
	double get_Kms();

	void set_fs(double _fs);
	void set_fs(double _Cms, double _Mms);
	double get_fs();

	void set_Qts(double _Qts);
	void set_Qts(double Qes, double Qms);
	double get_Qts();

	void set_Sd(float _Sd);
	void set_Sd_with_cone_diameter(double cone_diameter);
	double get_Sd();

	void set_Xmax(double _Xmax);
	void set_Xmax(double cone_height, double gap_height);
	double get_Xmax();

	void set_Rms(double _Rms);
	void set_Rms(double _fs, double _Mms, double _Cms);
	double get_Rms();


	void initialize_speaker()
	{
		
	}
	
};
