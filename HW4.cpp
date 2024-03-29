
#include <iostream>
#include <fstream>  
#include <cmath>   
using namespace std;
const float PI = 3.141592;
int main() {
   float t = 0.0, dt, T;

   dt = 0.01;
   T = 6. / 110.;


   ofstream doug("Aliasing.txt");
   for (t = 0.0; t < T; t += dt) {
      doug << t << "   " << 100. * cos(20. * PI * t) * cos(220. * PI * t) << "   " << 60 * sin(240. * PI * t) + 80. * sin(220. * PI * t) << endl;


   }
   doug.close();
   return 123;
}