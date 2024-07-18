/*************************************************************
**************************************************************
    _/    _/  _/_/_/  _/       Numerical Simulation Laboratory
   _/_/  _/ _/       _/       Physics Department
  _/  _/_/    _/    _/       Universita' degli Studi di Milano
 _/    _/       _/ _/       Prof. D.E. Galli
_/    _/  _/_/_/  _/_/_/_/ email: Davide.Galli@unimi.it
**************************************************************
*************************************************************/

#include "dices.h"

using namespace std;
 
void Standard(int M, int N){

   //Parte 1: set del seme del generatore.
   Random rnd;
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
      Primes >> p1 >> p2 ;
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

   //Parte 2: generatore di numeri casuali con il dado standard.
   double sum_std; //Somma dei valori casuali generati.
   double mean_std; // Ne calcolo la media.

   for(int i=0; i<M; i++){ //Numero di realizzazioni, ossia i valori da inserire nell'istogramma.
      //Ad ogni ciclo azzero i valori.
      sum_std = 0; 
	  mean_std = 0;
	  
      for(int j=0; j<N; j++){ //Ogni valore è dato dalla media degli N valori generati casualmente in base ad dado.
	      sum_std += rnd.Rannyu();
      }
	  
      //Calcolo le medie: i valori da inserire nell'istogramma. Scrivo i valori su un file esterno. 
      mean_std = sum_std/double(N);
      cout << i << "  " << mean_std << endl;
 
   }
   
   rnd.SaveSeed();

}

void Exponent(int M, int N){

   //Parte 1: set del seme del generatore.
   Random rnd;
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
      Primes >> p1 >> p2 ;
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

   //Parte 2: generatore di numeri casuali con il dado esponenziale.
   double sum_exp; //Somma dei valori casuali generati.
   double mean_exp; // Ne calcolo la media.

   for(int i=0; i<M; i++){ //Numero di realizzazioni, ossia i valori da inserire nell'istogramma.
      //Ad ogni ciclo azzero i valori.
	  sum_exp = 0; 
	  mean_exp = 0;
	  
      for(int j=0; j<N; j++){ //Ogni valore è dato dalla media degli N valori generati casualmente in base ad dado.
		  sum_exp += rnd.Exponential(1.0);
      }
	  
      //Calcolo le medie: i valori da inserire nell'istogramma. Scrivo i valori su un file esterno.   
	  mean_exp = sum_exp/double(N);
      cout << i << "  " << mean_exp << endl;
   }

   rnd.SaveSeed();

}

void Lorentzian(int M, int N){

   //Parte 1: set del seme del generatore.
   Random rnd;
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
      Primes >> p1 >> p2 ;
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

   //Parte 2: generatore di numeri casuali con il dado Lorentziano.
   double sum_lor; //Somma dei valori casuali generati.
   double mean_lor; // Ne calcolo la media.

   for(int i=0; i<M; i++){ //Numero di realizzazioni, ossia i valori da inserire nell'istogramma.
      //Ad ogni ciclo azzero i valori.
      sum_lor = 0; 
	  mean_lor = 0;
	  
      for(int j=0; j<N; j++){ //Ogni valore è dato dalla media degli N valori generati casualmente in base ad dado.
		  sum_lor += rnd.Cauchy_Lorentz(0,1.0);
      }
	  
      //Calcolo le medie: i valori da inserire nell'istogramma. Scrivo i valori su un file esterno.  
	  mean_lor = sum_lor/double(N);
      cout << i << "  " << mean_lor << endl;
   }

   rnd.SaveSeed();

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
