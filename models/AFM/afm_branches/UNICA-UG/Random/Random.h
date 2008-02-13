// ADT Random, the most general ADT on the EURACE Project
// Encapsulated type that allows to generate random values
/*Instance Variables:
	a	magic constant = 16807
	m	magic constant = 2147483647
	q	<Object>	description of q
	r	<ArithmeticValue>	description of r
	seed	<Number | Point>	description of seed
*/
#ifndef RANDOM_INCL
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "Double.h"


typedef struct Random Random;

struct Random
{   
      double seed;
};

//initialie: Set a reasonable Park-Miller starting seed     
void initializeRandom(Random *aRandom);



// create an instance of Random
Random *newRandom();
void freeRandom(Random *rnd);

//accessing at the structure 
double getSeed(Random *aRandom);



void setSeed(Random *aRandom, double seed);
 

// Eurace

double nextBetween(Random *aRandom, double min , double max);

//private methods
/*This method generates Random1 instances of Integer in the interval 0 to 16r7FFFFFFF. This 
	method does NOT update the seed; repeated sends answer the same value. The algorithm is 
	described in detail in 'Random1 Number Generators: Good Ones Are Hard to Find' by Stephen K. 
	Park and Keith W. Miller (Comm. Asso. Comp. Mach., 31(10):1192--1201, 1988).
*/
double nextValue(Random *aRandom);

//computation
//probArray holds a set of probabilities that a different event happens. The sum of probArray values 
//must be 1. Return the index in probArray of the event actually happening
int eventFrom(Random *aRandom, double probArray[] );



//Returns a random number with Gaussian distribution having average avg and s.d. std
double gauss(Random *aRandom,double avg ,double std );

//Answer a normally distributed random number with zero mean and standard deviation 1.0.
double gaussian(Random *aRandom);

//Returns a random number with Lognormal distribution having average avg and s.d. std
double logNormal(Random *aRandom, double  avg ,double std) ;

//This method generates random instances of Float in the interval 0 to 1
double next(Random *aRandom);

//	Restituisce un numero casuale intero tra 1 e max
int nextMax(Random *aRandom,int max);

//Return the number of events, distributed according to a Poisson distribution with given lambda
int poissonNr(Random *aRandom, double lambda );



//Answer -1 with probability p1, 1 with probability p2 - p1, zero elsewhere. Assumes that p1, p2 << 
int prob1prob2(Random *aRandom,double p1,double p2);

	
//Answer true with probability p.
int prob(Random *aRandom,double p);


#define RANDOM_INCL
#endif
