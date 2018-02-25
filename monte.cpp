#include"monte.h"
#include<fstream>
#include<string>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<climits>


using namespace std;

MCopt::MCopt()
{
	
	max=INT_MIN; min=INT_MAX; optionput=0; optioncall=0;
}

void MCopt::setspace()
{
  
  sprice=new double[N];
 
  count=new int[100];
  fill_n(count,100,0);
  
  p=r-sigma*sigma/2;
  q=sqrt(time);
}

double MCopt::getprice(double x)
{
	return startp*exp(p*time+sigma*x*q);
}

void MCopt::calculate()
{  
   double temp,a;
    int i;
	for(i=0;i<N;i++)
	{
		temp=getprice(box_muller());
		sprice[i]=temp;
		if(temp>max) max=temp;
                if(temp<min) min=temp;
        a=temp-strike;

        if(temp>strike) optioncall+=a;
        if(temp<strike) optionput-=a;
       
	}
	
	optioncall/=N; optionput/=N;
	temp=exp(-time*r);
	optioncall*=temp;
	optionput*=temp;
}

void MCopt::distribution()
{
  
   int i,a;
 
    div=(max-min)/100;
    cout<<max<<" -- "<<min<<"  "<<div<<endl;
    
    for(i=0;i<N;i++)
     {
     	a=(sprice[i]-min)/div; if(a>=100) a=99;
     	count[a]++;
     }
    
}

void MCopt::outfile()
{
	ofstream output;
	cout<<"input filename: ";
	string s;
	
	cin>>s;
	const char *ptr=s.c_str();
	
    output.open(ptr);
    cout<<div<<endl;
    int i;
	for(i=0;i<100;i++)
	{     
              cout<<i*div+min<<"  "<<count[i]<<endl;
              output<<i*div+min<<"  "<<count[i]<<endl;
		
	}
   output.close();
}

double box_muller()
{
	double a,b;
	do{
	
	a=1.0*rand()/RAND_MAX;
	b=1.0*rand()/RAND_MAX;
     }
     while(a<1e-40);
	
	return sqrt(-2*log(a))*cos(2*3.14159265358979*b);
	
}

