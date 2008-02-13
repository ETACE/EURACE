

#define NrMonths 2
#define NrDaysInMonth  5
#define NrMonthsInitialization 1
#define NrDaysInitialization NrMonthsInitialization*NrDaysInMonth

#define NrTotalMonths NrMonths + NrMonthsInitialization
#define NrTotalDays  NrTotalMonths*NrDaysInMonth
#define NrDaysInYear
#define AssetsBeliefsDefaultStd 0.5
#define PriceReturn_min  -0.9 
#define MonthlyWageGrowthRate 0.001
#define WageSigma  0.004
int current_day ;
int  current_month; 
