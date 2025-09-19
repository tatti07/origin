#pragma once


namespace mathops {

	double add(double x, double y);      
	double sub(double x, double y);      
	double mul(double x, double y);      

	
	bool safe_div(double x, double y, double& out);

	
	double ipow(double base, int exp);

}
