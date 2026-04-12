#include "SPL_Calculator.h"

// MMS FUNCTIONS
void TS_Parameters::set_Mms(double _Mms)
{
    this->Mms =  _Mms;
}
void TS_Parameters::set_Mms(double _fs, double _Cms)
{
	_Cms = convert_mm_to_m(_Cms);
    this->Mms = 1 / (pow(2*PI*_fs, 2) * _Cms);
}
double TS_Parameters::get_Mms()
{
    return this->Mms;
}

// CMS FUNCTIONS
void TS_Parameters::set_Cms(double _Cms)
{
    this->Cms = _Cms;
}
void TS_Parameters::set_Cms_with_Mms_and_fs(double _fs, double _Mms)
{
	_Mms = convert_g_to_kg(_Mms);
    this->Cms = 1 / ((4*PI*PI*_fs*_fs) * _Mms);
}
double TS_Parameters::get_Cms()
{
    return this->Cms;
}

// VAS FUNCTIONS
void TS_Parameters::set_Vas(double _Vas)
{
    this->Vas = _Vas;
}
void TS_Parameters::set_Vas(double _Sd, double _Cms)
{	
	_Cms = convert_mm_to_m(_Cms);
	_Sd = convert_cm2_to_m(_Sd);
    this->Vas = (RHO*(C*C)*(_Sd*_Sd) * _Cms);
}
double  TS_Parameters::get_Vas()
{
    return Vas;
}

// KMS FUNCTIONS
void TS_Parameters::set_Kms(float _Kms)
{
    this->Kms = _Kms;
}
void TS_Parameters::set_Kms_with_Cms(double _Cms)
{	
    this->Kms = 1 / _Cms;
}
double TS_Parameters::get_Kms()
{
    return this->Kms;
}

// FS FUNCTIONS
void TS_Parameters::set_fs(double _fs)
{
    this->fs = _fs;
}
void TS_Parameters::set_fs(double _Cms, double _Mms)
{	
	_Cms = convert_mm_to_m(_Cms);
	_Mms = convert_g_to_kg(_Mms);
    this->fs = (1/(2*PI)) * sqrt(1 / (_Cms * _Mms));
}
double TS_Parameters::get_fs()
{
    return this->fs;
}

// QTS FUNCTIONS
void TS_Parameters::set_Qts(double _Qts)
{
    this->Qts = _Qts;
}
void TS_Parameters::set_Qts(double _Qes, double _Qms)
{
    this->Qts = (_Qms * _Qes) / (_Qms + _Qes);
}
double TS_Parameters::get_Qts()
{
    return this->Qts;
}

// SD FUNCTIONS
void TS_Parameters::set_Sd(float _Sd)
{
    this->Sd = _Sd;
}
void TS_Parameters::set_Sd_with_cone_diameter(double cone_diameter)
{
    this->Sd = (PI/4.0) * (cone_diameter * cone_diameter);
}
double TS_Parameters::get_Sd()
{
    return this->Sd;
}

// XMAX FUNCTIONS
void TS_Parameters::set_Xmax(double _Xmax)
{
    this->Xmax = _Xmax;
}
void TS_Parameters::set_Xmax(double cone_height, double gap_height)
{
    this->Xmax = std::abs((cone_height - gap_height)/2.0);
}
double TS_Parameters::get_Xmax()
{
    return this->Xmax;
}

// RMS FUNCTIONS
void TS_Parameters::set_Rms(double _Rms)
{
    this->Rms = _Rms;
}
void TS_Parameters::set_Rms(double _fs, double _Cms, double _Qms)
{
	_Cms = convert_mm_to_m(_Cms);
    this->Rms = (1 / (_Qms * _fs * 2 * PI * _Cms)) * 1000;
}
double TS_Parameters::get_Rms()
{
    return this->Rms;
}

// n0 (Efficiancy) FUNCTIONS
void TS_Parameters::set_n0(double _n0)
{
    this->n0 = _n0;
}
void TS_Parameters::set_n0(double _fs, double _Vas, double _Qes)
{

    this->n0 = 0.000000000964*(_fs*_fs*_fs) * (_Vas/_Qes);
}
double TS_Parameters::get_n0()
{
    return this->n0;
}

// SENSITIVITY FUNCTION
void TS_Parameters::set_Sensitivity(double _Sensitivity)
{
    this->Sensitivity = _Sensitivity;
}
void TS_Parameters::set_Sensitivity_with_n0(double _n0)
{
    this->Sensitivity = 112 + 10*log10(_n0);
}
double TS_Parameters::get_Sensitivity()
{
    return this->Sensitivity;
}

// QES FUNCTIONS
void TS_Parameters::set_Qes(double _Qes)
{
    this->Qes = _Qes;
}
void TS_Parameters::set_Qes(double _Qms, double  _Re, double _Res)
{
    this->Qes = _Qms * (_Re/_Res);
}
void TS_Parameters::set_Qes(double _Qts, double _Qms)
{
    this->Qes = (_Qms * _Qts) / (_Qms - _Qts);
}
double TS_Parameters::get_Qes()
{
    return this->Qes;
}

// QMS FUNCTIONS
void TS_Parameters::set_Qms(double _Qms)
{
    this->Qms = _Qms;
}
void TS_Parameters::set_Qms(double _Qes, double  _Re, double _Res)
{
    this->Qms = _Qes * (_Res/_Re);
}
void TS_Parameters::set_Qms(double _Qts, double _Qes)
{
    this->Qms = (_Qes*_Qts) / (_Qes - _Qts);
}
double TS_Parameters::get_Qms()
{
    return this->Qms;
}

// Bl FUNCIONS
void TS_Parameters::set_Bl(double _Bl)
{
	this->Bl = _Bl;
}
void TS_Parameters::set_Bl(double _fs, double _Mms, double _Re, double _Qes)
{
	_Mms = convert_g_to_kg(_Mms);
	this->Bl = sqrt((2*PI*_fs*_Mms*_Re)/(_Qes));
}
double TS_Parameters::get_Bl()
{
	return this->Bl;
}

// RE FUNCTIONS
void TS_Parameters::set_Re(double _Re)
{
    this->Re = _Re;
}

// CONVERSION FUNCTIONS
double TS_Parameters::convert_g_to_kg(double _value_in_grams)
{
	return _value_in_grams / 1000;
}
double TS_Parameters::convert_mm_to_m(double _value_in_mm)
{
	return _value_in_mm / 1000;
}
//TEST PLS!!!!!
double TS_Parameters::convert_cm2_to_m2(double _value_in_cm2)
{
	_value_in_cm2 = _value_in_cm2 * (1/100) * (1/100);
	return _value_in_cm2;
}



void TS_Parameters::initialize_speaker(std::ifstream& _file)
{
    
    if(!_file.is_open())
    {
        return;
    }
    else
    {
        std::string parameter_name;
        double value;
        while(_file >> parameter_name >> value)
        {
            if(parameter_name == "Vas")
            {
                this->set_Vas(value);
                Vas_has_value = true;
                
            }
            else if(parameter_name == "fs")
            {
                this->set_fs(value);
                fs_has_value = true;
            }
            else if(parameter_name == "Qts")
            {
                this->set_Qts(value);
                Qts_has_value = true;
            }
            else if(parameter_name == "Qes")
            {
                this->set_Qes(value);
                Qes_has_value = true;
            }
            else if(parameter_name == "Qms")
            {
                this->set_Qms(value);
                Qms_has_value = true;
            }
            else if(parameter_name == "Xmax")
            {
                this->set_Xmax(value);
                Xmax_has_value = true;
            }
            else if(parameter_name == "Sd")
            {
                this->set_Sd(value);
                Sd_has_value = true;
            }
            else if(parameter_name == "Sensitivity")
            {
                this->set_Sensitivity(value);
                Sensitivity_has_value = true;
            }
            else if(parameter_name == "Re")
            {
                this->set_Re(value);
                Re_has_value = true;
            }
            else if(parameter_name == "n0")
            {
            	this->set_n0(value);
            	n0_has_value = true;
            }
            else if(parameter_name == "Cms")
            {
                this->set_Cms(value);
                Cms_has_value = true;
            }
            else if(parameter_name == "Mms")
            {
                this->set_Mms(value);
                Mms_has_value = true;
            }
            else if(parameter_name == "Rms")
            {
                this->set_Rms(value);
                Rms_has_value = true;
            }
            else if(parameter_name == "Bl")
            {
                this->set_Bl(value);
                Bl_has_value = true;
            }            
            else
            {
                std::cout<<"Parameter name is unrecognized\n";
                break;
            }
        }
    }
}

void TS_Parameters::solve()
{
    bool update;
    do
    {
        update = false;
        
        if(Vas == 0.0 && Sd != 0 && Cms!= 0)
        {
            set_Vas(this->Sd, this->Cms);
            update = true;
        }
        if(Cms == 0.0 && fs != 0 && Mms != 0)
        {
            set_Cms_with_Mms_and_fs(this->fs, this->Mms);
            update = true;
        }
        if(Mms == 0.0 && fs != 0 && Cms != 0)
        {
            set_Mms(this->fs, this->Cms);
            update = true;
        }
        if(Kms == 0.0 && Cms != 0)
        {
            set_Kms_with_Cms(this->Cms);
        }
        if((fs == 0.0) && Cms != 0 && Mms != 0)
        {
            set_fs(this->Cms, this->Mms);
            update = true;
        }
        if(Qts == 0.0 && Qes != 0 && Qms != 0)
        {
            set_Qts(this->Qes, this->Qms);
            update = true;
        }
        if(Qms == 0.0 && Qes != 0 && Re && Res != 0)
        {
            set_Qms(this->Qes, this->Re, this->Res);
            update = true;
        }
        if(Qms == 0.0 && Qts != 0 && Qes != 0)
        {
            set_Qms(this->Qts, this->Qes);
            update = true;
        }
        if(Qes == 0.0 && Qms != 0 && Re && Res != 0)
        {
            set_Qes(this->Qms, this->Re, this->Res);
            update = true;
        }
        if(Qes == 0.0 && Qts != 0 && Qms != 0)
        {
            set_Qes(this->Qts, this->Qms);
            update = true;
        }
        if(Rms == 0.0 && fs != 0 && Mms && Cms != 0)
        {
            set_Rms(this->fs, this->Mms, this->Cms);
            update = true;
        }
        if(Rms == 0.0 && fs != 0 && Mms && Qms != 0)
        {
            set_Rms(this->fs, this->Cms, this->Qms);
            update = true;
        }
        if(Sensitivity == 0.0 && n0 != 0)
        {
            set_Sensitivity_with_n0(this->n0);
            update = true;
        }
        if(n0 == 0.0 && fs != 0 && Vas != 0 && Qes != 0)
        {
            set_n0(this->fs, this->Vas, this->Qes);
            update = true;
        }
        if(Bl == 0 && fs != 0 && Mms != 0 && Re != 0 && Qes != 0)
        {
        	set_Bl(this->fs, this->Mms,this->Re, this->Qes);
        	update = true;
        }
    } while(update);
}

