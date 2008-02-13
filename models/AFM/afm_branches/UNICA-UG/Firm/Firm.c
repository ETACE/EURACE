
#include 



Firm *newFirm()
{
    Matrix *temp;
     temp=malloc(sizeof(Firm));
     temp->Qd_est; = zerosMatrix(1,2*Parameters.Firms.PriceDecisionGridNr+1);
     temp->P_grid; = zerosMatrix(1,2*Parameters.Firms.PriceDecisionGridNr+1);
     temp->Nd_grid; = zerosMatrix(1,2*Parameters.Firms.PriceDecisionGridNr+1);
     temp->Profits_real_grid; = zerosMatrix(1,2*Parameters.Firms.PriceDecisionGridNr+1);
     temp->technology;= onesCollectionDouble(Parameters.NrTotalDays);
}
