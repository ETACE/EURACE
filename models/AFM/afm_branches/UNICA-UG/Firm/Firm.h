


typedef struct Firm  Firm;
struct Firm 
{

 int id;
 int current_shares_outstanding;
 double total_dividend_payment;
 double bank_account;
 double equity;
}
 
Firm *newFirm();
