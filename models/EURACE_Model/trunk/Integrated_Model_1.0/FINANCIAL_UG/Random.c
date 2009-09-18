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
double ierf[]={ -3.6427727,-1.8213863677184485,-1.6449763571331872,-1.5344856217777185,-1.4522197815622468,-1.3859038243496775,
-1.3299219143360630,-1.2812143237490619,-1.2379219927112444,-1.1988272177415733,-1.1630871536766743,-1.1300932068852447,
-1.0993909519492191,-1.0706317121429472,-1.0435418436397585,-1.0179024648320276,-0.99353562834730424,-0.97029461851300924,
-0.94805697623234997,-0.92671937749552902,-0.90619380243682324,-0.88640462220354344,-0.86728635099387485,-0.84878188837096091,
-0.83084112847456015,-0.81341984759761865,-0.79647880561170736,-0.77998301356170241,-0.76390113173723651,-0.74820497118498519,
-0.73286907795921674,-0.71787038409775483,-0.70318791282203608,-0.68880252811655640,-0.67469672087225274,-0.66085442534238581,
-0.64726086087507340,-0.63390239483887112,-0.62076642340926991,-0.60784126748116207,-0.59511608144999473,-0.58258077298879651,
-0.57022593225950946,-0.55804276925044749,-0.54602305813905516,-0.53415908774970244,-0.52244361731717903,-0.51086983688356091,
-0.49943133175366350,-0.48812205051595892,-0.47693627620446988,-0.46586860023505738,-0.45491389879854005,-0.44406731143474232,
-0.43332422154706796,-0.42268023864756182,-0.41213118214846539,-0.40167306653867352,-0.39130208780283204,-0.38101461095753197,
-0.37080715859355801,-0.36067640032575804,-0.35061914306308928,-0.34063232202099475,-0.33071299240667357,-0.32085832171518147,
-0.31106558258078476,-0.30133214613370579,-0.29165547581744200,-0.28203312162630179,-0.27246271472675426,-0.26294196242969720,
-0.25346864348386577,-0.24404060366338223,-0.23465575162492167,-0.22531205501217810,-0.21600753678729465,-0.20674027177068635,
-0.19750838337227367,-0.18831004049856323,-0.17914345462129161,-0.17000687699449396,-0.16089859600789128,-0.15181693466541812,
-0.14276024817854746,-0.13372692166481973,-0.12471536794266060,-0.11572402541417945,-0.10675135602818442,-9.77958433161436186E-002,
-8.88559904942576584E-002,-7.99303186252031533E-002,-7.10173648334547075E-002,-6.21156805684038721E-002,-5.32238299097659295E-002,
-4.43403879100054410E-002,-3.54639389687185780E-002,-2.65930752340884334E-002,-1.77263950266780337E-002,-8.86250128095060485E-003,
0.0000000000000000,8.86250128095060485E-003,1.77263950266780337E-002,2.65930752340884334E-002,3.54639389687186751E-002,4.43403879100055381E-002,
5.32238299097660267E-002,6.21156805684039623E-002,7.10173648334548047E-002,7.99303186252032505E-002,8.88559904942577555E-002,9.77958433161437157E-002,
0.10675135602818452,0.11572402541417953,0.12471536794266071,0.13372692166481984,0.14276024817854766,0.15181693466541812,0.16089859600789128,
0.17000687699449396,0.17914345462129161,0.18831004049856323,0.19750838337227367,0.20674027177068635,0.21600753678729465,0.22531205501217810,
0.23465575162492167,0.24404060366338223,0.25346864348386577,0.26294196242969731,0.27246271472675437,0.28203312162630190,0.29165547581744211,
0.30133214613370585,0.31106558258078487,0.32085832171518158,0.33071299240667368,0.34063232202099486,0.35061914306308933,0.36067640032575810,
0.37080715859355812,0.38101461095753208,0.39130208780283204,0.40167306653867352,0.41213118214846539,0.42268023864756182,0.43332422154706796,
0.44406731143474232,0.45491389879854005,0.46586860023505738,0.47693627620446988,0.48812205051595892,0.49943133175366350,0.51086983688356091,
0.52244361731717903,0.53415908774970244,0.54602305813905516,0.55804276925044749,0.57022593225950968,0.58258077298879662,0.59511608144999506,
0.60784126748116218,0.62076642340927002,0.63390239483887123,0.64726086087507384,0.66085442534238614,0.67469672087225296,0.68880252811655662,
0.70318791282203608,0.71787038409775483,0.73286907795921674,0.74820497118498519,0.76390113173723651,0.77998301356170241,0.79647880561170736,
0.81341984759761865,0.83084112847456015,0.84878188837096091,0.86728635099387485,0.88640462220354344,0.90619380243682324,0.92671937749552902,
0.94805697623234997,0.97029461851300935,0.99353562834730447,1.0179024648320278,1.0435418436397590,1.0706317121429476,1.0993909519492193,
1.1300932068852454,1.1630871536766747,1.1988272177415735,1.2379219927112453,1.2812143237490619,1.3299219143360630,1.3859038243496775,
1.4522197815622468,1.5344856217777185,1.6449763571331872,1.8213863677184485,3.6427727};

double quo(double c,double b)
{  
    double temp;
    temp= (int)(c/b);
 
    return temp;

}


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
     
	hi =  (int)(seed/q);
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

//return a value with a normal distribution, this algorithm is the most quick.

double fast_gauss()
{
 int i;
 double r,unif;
 unif=next(); 
 i=(int)(unif*200);
 r= (ierf[i] + (ierf[i+1] - ierf[i])*(unif*200 - i));

 return r;
}




