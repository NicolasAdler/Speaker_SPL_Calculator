#include "SPL_Calculator.h"

	void TS_Parameters::set_Vas(float _Vas)
	{
		this->Vas = _Vas;
	}
	void TS_Parameters::set_Vas(float _Sd, float _Cms)
	{
		this->Vas = RHO*(C*C)*(_Sd*_Sd) * _Cms;
	}
	double  TS_Parameters::get_Vas()
	{
		return Vas;
	}

	
	void TS_Parameters::set_Mms(float _Mms)
	{
		this->Mms =  _Mms;
	}
	
	void TS_Parameters::set_Mms(float _fs, float _Cms)
	{
		this->Mms = 1 / (((2*PI*_fs) * (2*PI*_fs)) * _Cms);
	}
	double TS_Parameters::get_Mms()
	{
		return this->Mms;
	}

	
	void TS_Parameters::set_Cms(float _Cms)
	{
		this->Cms = _Cms;
	}
	void TS_Parameters::set_Cms(float _Vas, float _Sd)
	{
		this->Cms = (_Vas) / ((_Sd * _Sd)*RHO * C);
	}
	double TS_Parameters::get_Cms()
	{
		return this->Cms;
	}
