// ADT Random, the most general ADT on the EURACE Project
// Encapsulated type that allows to generate random values
/*Instance Variables:
	a	magic constant = 16807
	m	magic constant = 2147483647
	q	<Object>	description of q
	r	<ArithmeticValue>	description of r
	seed	<Number | Point>	description of seed
*/
#include "my_library_header.h"
/** \def a
 * \brief magic constant = 16807 */
/** \def m
 * \brief magic constant = 2147483647*/
#define a  ((double) 16807)

#define m  ((double) 2147483647)



double q=127773.000000; 
double r=2836.000000;


double seed=2345678901.0;


/** \fn void initializeRandom()
 * \brief Set a reasonable Park-Miller starting seed 
 */


void initializeRandom()
{   
    q = quo(m ,a);
    r = fmod(m ,a);
    seed=2345678901.0+clock();//( double ) clock() ;
    next();
}

/** \fn double getSeed()
 * \brief accessing at the variable
 * \param aRandom Pointer to the Random seed.
 */
double getSeed()
{
       return seed;
}

/** \fn void setSeed( double seme)
 * \brief set the variable
 * \param aRandom Pointer to the Random seed.
 * \param seed the seed.
 */
void setSeed( double seme)
 {  q = quo(m ,a);
    r = fmod(m ,a);
    seed=seme;
     next();
 }
/** \fn double next()
 * \brief  This function generates random float number in the interval 0 to 1
 */


double next()
    {
      double answer;
      seed= nextValue();
      answer=seed / m;
      return answer;
}

/** \fn double nextBetween( double min , double max)
 * \brief This function generates random float number in the interval min to max
 *\param  min the lowest value of the interval
 *\param  min the biggest value of the interval
 */

double nextBetween(double min , double max)
	{ double answer;
             answer= min +  next() * (max - min);
      return answer;
    }

//private methods
/*This method generates Random1 instances of Integer in the interval 0 to 16r7FFFFFFF. This 
	method does NOT update the seed; repeated sends answer the same value. The algorithm is 
	described in detail in 'Random1 Number Generators: Good Ones Are Hard to Find' by Stephen K. 
	Park and Keith W. Miller (Comm. Asso. Comp. Mach., 31(10):1192--1201, 1988).
*/

/** \fn double nextValue()
 * \brief This function generates a random integer number in the interval 0 to 16r7FFFFFFF. This function does NOT update the seed; repeated sends answer the same value. The algorithm is described in detail in 'Random1 Number Generators: Good Ones Are Hard to Find' by Stephen K. Park and Keith W. Miller (Comm. Asso. Comp. Mach., 31(10):1192--1201, 1988).
 *\return answer 
 */
double nextValue()
{ 
    double answer,lo, hi, aLoRHi;
     
	hi =  quo(seed,q);
	lo = seed - (hi * q);
	aLoRHi = a * lo - (r * hi);

    if(aLoRHi > 0.0)	answer = aLoRHi;
				else answer =aLoRHi + m;
	return answer;
}
/** \fn int eventFrom( double  probArray[] )
 * \brief probArray holds a set of probabilities that a different event happens. The sum of probArray values must be 1. Return the index in probArray of the event actually happening
 *\param probArray[] probabilities 
 *\return  return the index in probArray of the event actually happening
 */

int eventFrom(double  probArray[] )
{ 
    double rnd, accum , answer;
    int size,k,cond;
	rnd = next();
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
/** \fn double gauss(double avg ,double std )
 * \brief Returns a random number with Gaussian distribution having average avg and s.d. std
 *\param  avg average 
 *\param  std standard deviation
 *\return  return the index in probArray of the event actually happening
 */
double gauss(double avg ,double std )
	{
     double answer;
     answer=avg + (gaussian() * std);
     return answer;
}
/** \fn double gaussian()
 * \brief answer a normally distributed random number with zero mean and standard deviation 1.0.
 *\return  returns a normally distributed random number with zero mean and standard deviation 1.0.
 */
//Answer a normally distributed random number with zero mean and standard deviation 1.0.
double gaussian()
	{
    double gauss;
    int k;
	gauss = -6;
	for(k=0;k<12;k++)
    gauss = gauss + next();
	
	return gauss;
    }

/** \fn double logNormal( double  avg ,double std) 
 * \brief Returns a random number with Lognormal distribution having average avg and s.d. std
 *\param  avg average 
 *\param  std standard deviation
 *\return Returns a random number with Lognormal distribution having average avg and s.d. std
 */
//
double logNormal( double  avg ,double std) 
	
{
	double ls ,lm;
	double savg,sstd,answer;
	savg=avg*avg;
	sstd=std*std;
	lm = log(savg / sqrt((savg  + sstd ))); 
    ls = sqrt(log((savg  + sstd ) /savg )) ;
	answer=exp(gauss( lm , ls)) ;
	return answer;

}

//	Restituisce un numero casuale intero tra 0 e max-1
int nextMax(int max)
{

     int number;
     number = (int) (next() * max) ;
  
	return number;
}

//Return the number of events, distributed according to a Poisson distribution with given lambda
int poissonNr( double lambda )


{
     double expLambda ,lambdaRTX,rnd, accum , fatt ;
     int answer,cond;
    double k ;
	if(lambda < 2.0E-8) answer=0;
	else
    {
	 expLambda = exp(-lambda);
	 rnd = next();
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
int prob1prob2(double p1,double p2) 
{

	double rnd ,answer;
	rnd = next();
	if(rnd > p2 ) answer=0;
	else
	if (rnd < p1)answer=-1;
	else answer=1;
	return answer;
}	
	
//Answer true with probability p.
int prob(double p)
{ 
   int answer;	
	if(p < 0.01)
	{
    if(next() < 0.01)  answer=next() < (p * 100.0);  
      else answer= (next() < p) ;
    }
    else answer=next()<p;
    return answer;
}


