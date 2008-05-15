/** \fn IGFirm_read_tax_rates()
 * \brief IGFirms reads the tax_rates_messages from Governments
 */
int IGFirm_read_tax_rates()
{
	//Message send by Government:
	START_GOVERNMENT_TAX_RATES_MESSAGE_LOOP			
		if(government_tax_rates_message->gov_id == GOV_ID)
		{
			TAX_RATE_CORPORATE = government_tax_rates_message->tax_rate_corporate;
			TAX_RATE_VAT = government_tax_rates_message->tax_rate_vat;
		}
	FINISH_GOVERNMENT_TAX_RATES_MESSAGE_LOOP

	return 0;
}