/************************************
 * \file  my_library_header.h
 * \brief Header for user created library functions.
 ************************************************/

/** \def HISTLENGTH
 * \brief History length of performance of asset allocation rules */
#define HISTLENGTH 60

/** \def EmptyAssetPortfolio
 * \brief Add definition of an empty asset portfolio data structure */
#define EmptyAssetPortfolio  {DEFINITION}

#define NRRULES  
//for messages
#define range
#define x
#define y
#define z



/** function prototypes */
double random_unif();
double sum(double * p, int size);
void cumsum(double * p, int size, double * cumsum);
void cumpdf(double * p, int size, double * cpdf);
double draw(int size, double * cpdf);
int ismember(double i, double * xvec, int size);
void draw_without_replacement(int size, double * cpdf, int Nr_draws, double * draws);
void draw_with_replacement(int size, double * cpdf, int Nr_draws, double * draws);
