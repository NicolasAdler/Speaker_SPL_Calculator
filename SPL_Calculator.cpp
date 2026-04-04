#include "SPL_Calculator.h"

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

	// KMS FUNCTIONS
	void TS_Parameters::set_Kms(float _Kms)
	{
		this->Kms = _Kms;
	}
	void TS_Parameters::set_Kms(double _Cms)
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
	
