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

	void TS_Parameters::set_Rms(double _Rms)
	{
		this->Rms = _Rms;
	}
	void TS_Parameters::set_Rms(double _fs,double _Mms, double _Cms)
	{
		this->Rms = (2*PI*_fs) * sqrt(_Mms / _Cms);
	}
	double TS_Parameters::get_Rms()
	{
		return this->Rms;
	}
	
