#ifndef MONTE_H
#define MONTE_H
class MCopt
{
	public:
		MCopt();
                double startp, sigma, r, strike;
		int N;
		double time;
		double optioncall,optionput;
		void setspace();
		void calculate();
		void distribution();
		void outfile();
       private:
                double *sprice;
                int *count;
                double max,min,p,q,div;
                double getprice(double x);
		
};


double box_muller();
#endif
