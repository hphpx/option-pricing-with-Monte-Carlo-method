#include"monte.h"
#include<iostream>
using namespace std;

//This is a program pricing the European put/call options without dividend.
int main()
{
	MCopt opt;
        opt.N=100000;          //Number of simulation
        opt.time=5.0/252;      //time to expiration date
        opt.r=0.04;            //risk-free interest rate
        opt.sigma=0.2;         //volatility
        opt.strike=162.5;
        opt.startp=162.41;
	opt.setspace();
	opt.calculate();
	opt.distribution();     //create the data for histogram
	opt.outfile();
	cout<<opt.optioncall<<"  "<<opt.optionput<<endl;
	return 0;
	
}
