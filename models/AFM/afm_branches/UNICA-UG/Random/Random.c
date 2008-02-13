// ADT Random, the most general ADT on the EURACE Project
// Encapsulated type that allows to generate random values
/*Instance Variables:
	a	magic constant = 16807
	m	magic constant = 2147483647
	q	<Object>	description of q
	r	<ArithmeticValue>	description of r
	seed	<Number | Point>	description of seed
*/
#include "Random.h"
#define a  ((double) 16807)
#define m  ((double) 2147483647)



double q; 
double r;




//Create a new instance of ADT Random

Random *newRandom()
{
       Random *temp;
       temp = malloc(sizeof(Random));
       initializeRandom(temp);
       return temp;
}

//initialie: Set a reasonable Park-Miller starting seed     
void initializeRandom(Random *aRandom)
{   q = quo(m ,a);
    r = fmod(m ,a);
    aRandom->seed =2345678901.0+clock();//( double ) clock() ;
    printf("valore %f",aRandom->seed);
	next(aRandom);
}
//accessing at the structure 

double getSeed(Random *aRandom)
{
       return aRandom->seed;
}


void setSeed(Random *aRandom, double seed)
 {
     aRandom->seed=seed;
 }
//This method generates random instances of Float in the interval 0 to 1
double next(Random *aRandom)
    {
      double answer;
      aRandom->seed= nextValue(aRandom);
      answer=aRandom->seed / m;
      return answer;
}
// Eurace

double nextBetween(Random *aRandom, double min , double max)
	{ double answer;
             answer= min +  next(aRandom) * (max - min);
      return answer;
    }

//private methods
/*This method generates Random1 instances of Integer in the interval 0 to 16r7FFFFFFF. This 
	method does NOT update the seed; repeated sends answer the same value. The algorithm is 
	described in detail in 'Random1 Number Generators: Good Ones Are Hard to Find' by Stephen K. 
	Park and Keith W. Miller (Comm. Asso. Comp. Mach., 31(10):1192--1201, 1988).
*/
double nextValue(Random *aRandom)
{ 
    double answer,lo, hi, aLoRHi,seed;
    seed=aRandom->seed;
	hi =  quo(seed,q);
	lo = seed - (hi * q);
	aLoRHi = a * lo - (r * hi);

    if(aLoRHi > 0.0)	answer = aLoRHi;
				else answer =aLoRHi + m;
	return answer;
}

//computation
//probArray holds a set of probabilities that a different event happens. The sum of probArray values 
//must be 1. Return the index in probArray of the event actually happening
int eventFrom(Random *aRandom, double  probArray[] )
{ 
    double rnd, accum , answer;
    int size,k,cond;
	rnd = next(aRandom);
	accum = 0.0;
	size=sizeof(probArray);
	cond=1;
	k=0;
	while(cond&&(k<size))
	{ 
			accum = accum + probArray[k];
			if(rnd < accum) 
                   { 
                   answer=k;
                    cond=0; 
                    }
			k++;
    }
    return answer;
}
//	Return the number of events, with maximum number nTot, each with small probability prob

//Returns a random number with Gaussian distribution having average avg and s.d. std
double gauss(Random *aRandom,double avg ,double std )
	{
     double answer;
     answer=avg + (gaussian(aRandom) * std);
     return answer;
}

//Answer a normally distributed random number with zero mean and standard deviation 1.0.
double gaussian(Random *aRandom)
	{
    double gauss;
    int k;
	gauss = -6;
	for(k=0;k<12;k++)
    gauss = gauss + next(aRandom);
	
	return gauss;
    }
//Returns a random number with Lognormal distribution having average avg and s.d. std
double logNormal(Random *aRandom, double  avg ,double std) 
	
{
	double ls ,lm;
	double savg,sstd,answer;
	savg=avg*avg;
	sstd=std*std;
	lm = log(savg / sqrt((savg  + sstd ))); 
    ls = sqrt(log((savg  + sstd ) /savg )) ;
	answer=exp(gauss(aRandom, lm , ls)) ;
	return answer;

}

//	Restituisce un numero casuale intero tra 0 e max-1
int nextMax(Random *aRandom,int max)
{

     int number;
     number = (int) (next(aRandom) * max) ;
  
	return number;
}

//Return the number of events, distributed according to a Poisson distribution with given lambda
int poissonNr(Random *aRandom, double lambda )


{
     double expLambda ,lambdaRTX,rnd, accum , fatt ;
     int answer,cond;
    double k ;
	if(lambda < 2.0E-8) answer=0;
	else
    {
	 expLambda = exp(-lambda);
	 rnd = next(aRandom);
	 if(rnd < expLambda )answer=0;
	 else
     {
	  accum = expLambda;
	  fatt = 1.0;
	  k = 1.0;
	  cond=1;
	  lambdaRTX = lambda;
              while((k < 10.1)&&(cond))
	          {
               fatt = fatt * k;
			   accum = accum + (lambdaRTX * expLambda / fatt);
			   if(rnd < accum) 
               {
                       answer= ceil(k);
                     //answer= rounded(k);
                      cond=0;
                }
			   else{
			        lambdaRTX = lambda * lambdaRTX;
			        k = k + 1;
                   }
              }
      if(cond) answer=11.0;  
      }
     }	
	return answer;
}
//Answer -1 with probability p1, 1 with probability p2 - p1, zero elsewhere. Assumes that p1, p2 << 
int prob1prob2(Random *aRandom,double p1,double p2) 
{

	double rnd ,answer;
	rnd = next(aRandom);
	if(rnd > p2 ) answer=0;
	else
	if (rnd < p1)answer=-1;
	else answer=1;
	return answer;
}	
	
//Answer true with probability p.
int prob(Random *aRandom,double p)
{ 
   int answer;	
	if(p < 0.01)
	{
    if(next(aRandom) < 0.01)  answer=next(aRandom) < (p * 100.0);  
      else answer= (next(aRandom) < p) ;
    }
    else answer=next(aRandom)<p;
    return answer;
}

void freeRandom(Random *rnd)
{ free(rnd);}

