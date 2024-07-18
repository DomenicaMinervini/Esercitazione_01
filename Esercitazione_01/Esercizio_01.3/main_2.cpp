/*************************************************************
**************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
**************************************************************
*************************************************************/

#include <string>
#include "random.h"

using namespace std;
 
int main (int argc, char *argv[]){

   //Parte 1: generatore di numeri casuali.
   Random rnd;
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
      Primes >> p1 >> p2 ;
   } else cerr << "PROBLEM: Unable to open Primes" << endl;
   Primes.close();

   ifstream input("seed.in");
   string property;
   if (input.is_open()){
      while ( !input.eof() ){
         input >> property;
         if( property == "RANDOMSEED" ){
            input >> seed[0] >> seed[1] >> seed[2] >> seed[3];
            rnd.SetRandom(seed,p1,p2);
         }
      }
      input.close();
   } else cerr << "PROBLEM: Unable to open seed.in" << endl;

   //Parte 2: genero le sbarrette.
   int d = 5; //Spessore della striscia di pavimento.
   int L = 4; //Lunghezza dell'ago.
   int n_thr = 1000; //Numero dei lanci.
   int n_hit = 0; //Numero di aghi che toccano la linea.
   
   double a; //Posizione della cruna relativamente all'inizio della striscia.
   double x; //y; //Coordinate della punta dell'ago.
   double b; //Somma della posizione della cruna e della punta.
   //double perc; //Percentuale di aghi che toccano la linea.
   double pi = 0; //Pi greco.
   
   for(int i=0; i<n_thr; i++){
	  a = d*rnd.Rannyu();
	  x = L*rnd.Rannyu();
	  //y = L*(1.0-(x*x)/(L*L));
	  
      //cout << a << "  " << x << "  " << y << "  " << endl;
	  b = a + x;
	  if(b > d){ //Se la punta va nella striscia successiva, ossia se tocca la linea,
	     n_hit++; //incrementa di 1 i casi favorevoli.	  
	  }
   }
   pi = 2.0*L*n_thr/(d*n_hit);
   cout << "Stima di pi greco: " << pi << endl;
   
   //perc = 100.0*double(n_hit)/double(n_thr);
   //cout << "Percentuale di aghi sulla linea: " << perc << endl;
   
   rnd.SaveSeed();
   return 0;
}

/*************************************************************
**************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
**************************************************************
*************************************************************/
