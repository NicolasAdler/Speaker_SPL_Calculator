#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

#define PI 3.14159265358979
#define RHO 1.225
#define C 343

class TS_Parameters
{
    private:

    double Vas{0.0}, fs{0.0}, Qts{0.0}, Qes{0.0}, Qms{0.0}, Xmax{0.0}, Sd{0.0}, Sensitivity{0.0},
    Mms{0.0}, Cms{0.0}, Kms{0.0}, Rms{0.0}, Re{0.0}, Res{0.0}, W{0.0};

    double n0{0}, Bl{0}, Vb{0};

    std::vector<double> spl_values;
    int frequency_start{20}, frequency_end{20000};
    
    bool Vas_has_value{false}, fs_has_value{false}, Qts_has_value{false},
    Qes_has_value{false}, Qms_has_value{false}, Mms_has_value{false},
    Cms_has_value{false},  Kms_has_value{false}, Sd_has_value{false},
    Xmax_has_value{false}, Sensitivity_has_value{false}, 
    Re_has_value{false}, Rms_has_value{false}, n0_has_value{false}, Bl_has_value{false},
    Vb_has_value{false}, W_has_value{false};

    public:
    TS_Parameters()
    {
    	spl_values.reserve(19981);
    }
    void set_Vas(double _Vas);
    void set_Vas(double _Sd, double _Cms);
    double get_Vas();

    void set_Mms(double _Mms);
    void set_Mms(double _fs, double _Cms);
    double get_Mms();

    void set_Cms(double _Cms);
    void set_Cms_with_Mms_and_fs(double _fs, double _Mms);
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
    void set_Qms(double _Qes, double  _Re, double _Res);
    void set_Qms(double _Qts, double Qes);
    double get_Qms();

    
    void set_Qes(double _Qes);
    void set_Qes(double _Qms, double _Re, double _Res);
    void set_Qes(double _Qts, double _Qms);
    double get_Qes();

    void set_Sd(float _Sd);
    void set_Sd_with_cone_diameter(double cone_diameter);
    double get_Sd();

    void set_Xmax(double _Xmax);
    void set_Xmax(double cone_height, double gap_height);
    double get_Xmax();

    void set_Rms(double _Rms);
    void set_Rms(double _fs, double _Mms, double _Cms);
    void set_Rms_with_Qms(double _fs, double _Mms, double _Qms);
    double get_Rms();

    void set_Sensitivity(double _Sensitivity);
    void set_Sensitivity_with_n0(double _n0);
    double get_Sensitivity();

    void set_Bl(double _Bl);
    void set_Bl(double _fs, double _Mms, double _Re, double _Qes);
    double get_Bl();

    void set_n0(double _n0);
    void set_n0(double _fs, double _Vas, double Qes);
    double get_n0();
    
    void set_Re(double _Re);
    double get_Re();

    void set_Vb(double _Vb);
    double get_Vb();

    void set_W(double _W);
    double get_W();

    double convert_g_to_kg(double _value_in_grams);
    double convert_kg_to_g(double _value_in_kg);
    double convert_mm_to_m(double _value_in_mm);
    double convert_m_to_mm(double _value_in_m);
    double convert_cm2_to_m2(double _value_in_cm2);
    double convert_m2_to_cm2(double _value_in_m2);


    void initialize_speaker(std::ifstream& _file);
    void solve();
    void compute_transfer_function(std::vector<double>& _spl_values);
    
};

class Ported
{
	private:

	public:
	
};
