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

   //PARTE 1: GENERATORE DI NUMERI CASUALI
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

   //PARTE 2: MEDIA A BLOCCHI
   int i,j; //Contatori.

   int M; //Numero totale di lanci: alla fine M = 100000.
   int N=10; //Numero di blocchi.
   int L=100; // L = M/N, numero di elementi per ogni blocco.
   
   double sum; //Somma degli elementi in un blocco.  
   double mean[N]; //Vettore contenente le medie degli elementi di ogni blocco.
   double square[N]; //Vettore contenente i quadrati delle medie degli elementi di ogni blocco.

 
   for(i=0; i<N; i++){ //Per ogni blocco
      sum=0; //Azzero la somma ad ogni ciclo.
	  
      for(j=0; j<L; j++){ //All'interno di ciascun blocco.
         sum += rnd.Rannyu();
      }
	  
      mean[i] = sum/double(L); //Questo e' il valor medio del blocco i-esimo. 
	  square[i] = mean[i]*mean[i];
      cout << "La media del blocco " << i << " vale: " << mean[i] << endl;
	  cout << "Il quadrato della media del blocco " << i << " vale: " << square[i] << endl;

   }
   
   M = L*N; /*Il numero totale di valori generati e' pari al numero di
              elementi di un blocco per il numero totale di blocchi.*/
   cout << "Ho generato in totale " << M << " elementi." << endl;
   
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
