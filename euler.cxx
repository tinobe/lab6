#include <fstream>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

int main (){
  
const double lambda = -0.5;
const int         N = 10;
const double    thl = log(0.5)/lambda;
const double      T = 5*thl;
const double     dt = T/N;
const double     y0 = 1;
double yn=y0;

cout << dt*lambda << endl;

 ofstream out("Dataforward.txt");
 out << 0 << " " << y0 << endl;
        for(int i=1;i<N;i++){
	  yn+=lambda*yn*dt;
	  out << i*dt << " " << yn << endl;
	  
	}
out.close();

yn=y0;
 ofstream out1("Databackward.txt");
 out1 << 0 << " " << y0 << endl;
        for(int i=1;i<N;i++){
	  yn/=(1-dt*lambda);
	  out1 << i*dt << " " << yn << endl;
	}
out1.close();

yn=y0;
 ofstream out2("Datatra.txt");
 out2 << 0 << " " << y0 << endl;
        for(int i=1;i<N;i++){
	  yn/=(1-dt*lambda/2)/(1+dt*lambda/2);
	  out2 << i*dt << " " << yn << endl;
	}
out2.close();
return 0;
}