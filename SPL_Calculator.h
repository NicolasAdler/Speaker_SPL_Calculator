#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

#define PI 3.14159265358979
#define RHO 1.225
#define C 343

class TS_Parameters
{
	private:

	double Vas, fs, Qts, Qes, Qms, Xmax, Sd, Sensitivity,
	 Re, Mms, Cms, Kms, Rms;

	double n0;
	
	bool Vas_has_value{false}, fs_has_value{false}, Qts_has_value{false}, 
	Qes_has_value{false}, Qms_has_value{false}, Mms_has_value{false}, 
	Cms_has_value{false},  Kms_has_value{false}, Sd_has_value{false}, 
	Xmax_has_value{false}, Sensitivity_has_value{false},
	Re_has_value{false}, Rms_has_value{false};

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

	void set_Qms(double _Qms);
	void set_Qms(double _Qms);
	double get_Qms();

	
	void set_Qes(double _Qes);
	void set_Qes(double _Qms, double _Re, double _Res);
	double get_Qes();

	void set_Sd(float _Sd);
	void set_Sd_with_cone_diameter(double cone_diameter);
	double get_Sd();

	void set_Xmax(double _Xmax);
	void set_Xmax(double cone_height, double gap_height);
	double get_Xmax();

	void set_Rms(double _Rms);
	void set_Rms(double _fs, double _Mms, double _Cms);
	double get_Rms();

	void set_Sensitivity(double _Sensitivity);
	void set_Sensitivity_with_n0(double _n0);
	double get_Sensitivity();

	void set_n0(double _n0);
	void set_n0(double _fs, double _Vas, double Qes);
	double get_n0();
	
	void set_Re(double _Re);

	void initialize_speaker(std::ifstream& _file);
	void solve();
};
