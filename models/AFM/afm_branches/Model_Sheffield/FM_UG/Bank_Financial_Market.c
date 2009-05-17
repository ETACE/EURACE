#include "header.h" 
int Bank_send_accountInterest(void)
{
   add_accountInterest_message(1, 0.04);
return 0;
}
int Bank_receive_account_update(void)
{
return 0;
}