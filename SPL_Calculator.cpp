#include "SPL_Calculator.h"

// MMS FUNCTIONS
void TS_Parameters::set_Mms(double _Mms)
{
    this->Mms =  _Mms;
}
void TS_Parameters::set_Mms(double _fs, double _Cms)
{
    this->Mms = 1 / (((2*PI*_fs) * (2*PI*_fs)) * _Cms);
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
void TS_Parameters::set_Cms(double _Vas, double _Sd)
{
    this->Cms = (_Vas) / ((_Sd * _Sd)*RHO * C);
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
    this->Vas = RHO*(C*C)*(_Sd*_Sd) * _Cms;
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
    this->Qts = 1 / ((1/_Qes) + (1/_Qms));
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
void TS_Parameters::set_Rms(double _fs,double _Mms, double _Cms)
{
    this->Rms = (2*PI*_fs) * sqrt(_Mms / _Cms);
}
void TS_Parameters::set_Rms_with_Qms(double _fs, double _Mms, double _Qms)
{
    this->Rms = (2*PI*_fs*_Mms) / (_Qms);
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
void TS_Parameters::set_n0(double _fs, double _Vas, double Qes)
{
    double first = (4*PI*PI) * (C*C*C);
    double second = (_fs*_fs*_fs*_Vas) / Qes;
    this->n0 = first * second;
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
    this->Qes = _Qts - _Qms;
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
void TS_Parameters::set_Qms(double _Qts, double Qes)
{
    this->Qms = _Qts - Qes;
}
double TS_Parameters::get_Qms()
{
    return this->Qms;
}

// RE FUNCTIONS
void TS_Parameters::set_Re(double _Re)
{
    this->Re = _Re;
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
        
        if(Vas == 0.0 && Sd && Cms)
        {
            set_Vas(this->Sd, this->Cms);
            update = true;
        }
        if(Cms == 0.0 && Vas && Sd)
        {
            set_Cms(this->Vas, this->Sd);
            update = true;
        }
        if(Mms == 0.0 && fs && Cms)
        {
            set_Mms(this->fs, this->Cms);
            update = true;
        }
//        else if(Kms == 0.0 && Cms)
//        {
//            set_Kms_with_Cms(this->Cms);
//        }
        if((fs == 0.0) && Cms && Mms)
        {
            set_fs(this->Cms, this->Mms);
            update = true;
        }
        if(Qts == 0.0 && Qes &&Qms)
        {
            set_Qts(this->Qes, this->Qms);
            update = true;
        }
        else if(Qms == 0.0 && Qes && Re && Res)
        {
            set_Qms(this->Qes, this->Re, this->Res);
            update = true;
        }
        else if(Qms == 0.0 && Qts && Qes)
        {
            set_Qms(this->Qts, this->Qes);
            update = true;
        }
        else if(Qes == 0.0 && Qms && Re && Res)
        {
            set_Qes(this->Qms, this->Re, this->Res);
            update = true;
        }
        else if(Qes == 0.0 && Qts && Qms)
        {
            set_Qes(this->Qts, this->Qms);
            update = true;
        }
        else if(Rms == 0.0 && fs && Mms && Cms)
        {
            set_Rms(this->fs, this->Mms, this->Cms);
            update = true;
        }
        else if(Rms == 0.0 && fs && Mms && Qms)
        {
            set_Rms_with_Qms(this->fs, this->Mms, this->Qms);
            update = true;
        }
        else if(Sensitivity == 0.0 && n0)
        {
            set_Sensitivity_with_n0(this->n0);
            update = true;
        }
        else if(n0 == 0.0 && fs && Vas && Qes)
        {
            set_n0(this->fs, this->Vas, this->Qes);
            update = true;
        }
    } while(update);
}

