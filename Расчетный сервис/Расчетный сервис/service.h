#pragma once
#include <string>
#include<fstream>
#include"secant.h"
#include<iomanip>

class DataProcessorService
{
private:

	std::string inputfile;
	std::string outputfile;

public:

	DataProcessorService(std::string inputfile, std::string outputfile)
	{
		this->inputfile = inputfile;
		this->outputfile = outputfile;
	}
	void runService()
	{
		std::fstream input(inputfile);
		double P, am_g, am_o, Cp_o, Cp_g, H_target, T;
		if (input.is_open())
		{
			input >> P;
			input >> am_g;
			input >> am_o;
			input >> Cp_o;
			input >> Cp_g;
			input >> H_target;
		}
		else 
			return;
		std::cout << "Ñ÷èòàíû äàííûå èç ôàéëà: " << inputfile << "\nP = " <<
			P << " Ïà\nam_g = " << am_g << "\nam_o = " << am_o <<
			"\nCp_o = " << Cp_o << " Äæ/êã*Ê\nCp_g = " << Cp_g <<
			" Äæ/êã*Ê\nH_target = " << H_target << " Äæ/êã" << std::endl;
		T = calculate(P, am_g, am_o, Cp_o, Cp_g, H_target);

		std::cout << std::fixed << std::setprecision(5) << "T = " << T - 273.15 << " °C" << std::endl;

		std::fstream out("out.txt");
		if (out.is_open())
			out << T - 273.15 << " °C";
	}
};
