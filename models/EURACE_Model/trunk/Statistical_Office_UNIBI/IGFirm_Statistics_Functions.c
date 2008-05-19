/** \fn IGFirm_read_tax_rates()
 * \brief Function to read the tax_rates_message from Government (msg has been filtered).
 */
int IGFirm_read_tax_rates()
{
	//Message send by Government:
	START_GOVERNMENT_TAX_RATES_MESSAGE_LOOP			
		TAX_RATE_CORPORATE = government_tax_rates_message->tax_rate_corporate;
		TAX_RATE_VAT = government_tax_rates_message->tax_rate_vat;
	FINISH_GOVERNMENT_TAX_RATES_MESSAGE_LOOP

	return 0;
}