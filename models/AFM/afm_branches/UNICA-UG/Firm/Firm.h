

#define PriceDecisionGridNr 

typedef struct Firm  Firm;
struct Firm 
{

   Matrix *Qd_est; 
   Matrix *P_grid; 
   Matrix *Nd_grid; 
   Matrix *Profits_real_grid; 
   CollectionDouble *technology;
}
 
Firm *newFirm();
