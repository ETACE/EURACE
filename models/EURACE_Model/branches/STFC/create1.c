#include "FINANCIAL_UG/my_library_header.h"

#define NUMFirm 40
#define NUMHousehold 1000
#define NUMMall  2
#define NUMIGFirm 1
#define NUMEurostat 1
#define NUMClearinghouse 1
#define NUMBank 1
#define NUMGovernment 1
#define NUMCentral_Bank 1
#define NUMSTOCKSHOUSE 100
#define NUMRegion 2
#define production_quantity_per_firm  110
#define nr_share NUMHousehold*NUMSTOCKSHOUSE
#define DAYSINMONTH 20
#define INITCAPITAL_PRICE 17
#define INIT_TAX_RATE 0.03
#define TOTAL_UNITS_PER_CAP_STOCK 220
#define EQUITY TOTAL_UNITS_PER_CAP_STOCK*INITCAPITAL_PRICE+PAYMENTACCOUNT
#define PAYMENTACCOUNT 2
#define STOCKPRICE EQUITY/nr_share
#define MEAN_WAGE 1
#define TECNOLOGICAL_FRONTIER 1.5
#define GOV_ID 0
#define BANK_ID 1

void initFirm(struct xmachine_memory_Firm *aFirm, int id, int region_id)
{ int j,k;
  struct xmachine_memory_Firm *agent;
 agent=aFirm;
 agent->id=id;
 agent->region_id=region_id; //int;
 agent->gov_id=GOV_ID;//int;
 agent->day_of_month_to_act =0;//int;
 agent->last_day_of_month_to_act=DAYSINMONTH-1; //int;
 agent->payment_account=PAYMENTACCOUNT; //double;
 agent->bank_id=BANK_ID; //int;
 agent->mean_wage =MEAN_WAGE;//double;
 agent->needed_capital_stock =0;//double;
 agent->actual_cap_price=INITCAPITAL_PRICE; //double;
 agent->mean_specific_skills=1; //double;
 agent->planned_production_quantity=0; //double;
 agent->production_quantity=0; //double;
 agent->planned_output=0; //double;
 agent->output=0; //double;
 agent->unit_costs=0; //double;
 agent->total_supply=0;//double;
 agent->production_costs=0; //double;
 agent->revenue_per_day=0; //double;
 agent->technological_frontier=TECNOLOGICAL_FRONTIER; //double;
 agent->cum_revenue=0; //double;
 agent->out_of_stock_costs=0; //double;

 init_sales_statistics_array(& agent->malls_sales_statistics);
for(j=1;j<=NUMMall;j++)
for(k=1;k<=FIRM_PLANNING_HORIZON;k++)
   add_sales_statistics(&agent->malls_sales_statistics, NUMFirm+NUMHousehold+j,k,production_quantity_per_firm/NUMMall);
  //sales_statistics_array;
 agent->quality=1; //double;
 agent->price=0; //double;
 agent->price_last_month=1; //double;
 agent->demand_capital_stock=0; //double;
 agent->planned_production_costs=0; //double;
 agent->adaption_production_volume_due_to_insufficient_finances=0.05; //double;
 agent->fraction_reserved_for_delayed_payments=0; //double; ????

 init_sold_quantities_per_mall_array(&agent->sold_quantities);
for(j=0;j<NUMMall;j++)
 add_sold_quantities_per_mall(&agent->sold_quantities,NUMFirm+NUMHousehold+j,0,0,0);//sold_quantities_per_mall_array;

 agent->total_sold_quantity=0; //double;
 agent->cum_total_sold_quantity =0;//double;

 init_delivery_volume_per_mall_array(&agent->delivery_volume);
 for(j=0;j<NUMMall;j++)
 add_delivery_volume_per_mall(&agent->delivery_volume,NUMFirm+NUMHousehold+j,production_quantity_per_firm/NUMMall,1,1); //delivery_volume_per_mall_array;
  init_delivery_volume_per_mall_array(&agent->planned_delivery_volume); //delivery_volume_per_mall_array;
 for(j=0;j<NUMMall;j++)
  add_delivery_volume_per_mall(&agent->planned_delivery_volume,NUMFirm+NUMHousehold+j,1,1,1);

 init_mall_info_array(&agent->current_mall_stocks);
for(j=NUMFirm+NUMHousehold;j<NUMFirm+NUMHousehold+NUMMall;j++)
 add_mall_info(&agent->current_mall_stocks, j,production_quantity_per_firm/NUMMall,0.0);
//mall_info_array;

 init_double_array(&agent->last_planned_production_quantities);
for(j=0;j<5;j++)
 add_double(&agent->last_planned_production_quantities, production_quantity_per_firm);
 //double_array;
 agent->total_external_financing_obtained=0;//double;
 agent->capital_costs=0; //double;
 agent->labour_costs=0; //double;
 init_financing_capital_array(&agent->capital_financing); //financing_capital_array;
 agent->financial_resources_for_production=0;//double;
 agent->planned_value_capital_stock=0; //double;????
 agent->total_units_local_inventory=0; //double;
 //agent->dmarketmatrix=0; //int;?????
 init_residual_var_datatype_static_array(agent->residual_var,10); //residual_var_datatype;????
 agent->ebit=0; //double;
 agent->earnings=0; //double;
 agent->tax_rate_corporate=INIT_TAX_RATE; //double;
 agent->tax_rate_vat=0; //double;
 agent->tax_payment=0; //double;
 agent->net_earnings=0; //double;
 agent->previous_net_earnings=0; //double;
 agent->total_interest_payment=0; //double;
 agent->total_debt_installment_payment=0; //double;
 agent->total_dividend_payment=0; //double;
 agent->current_share_price=STOCKPRICE; //double;???
 agent->previous_dividend_per_share=0; //double;
 agent->current_dividend_per_share=0; //double;
 agent->previous_earnings_per_share=0; //double;
 agent->current_earnings_per_share=0; //double;
 agent->previous_dividend_per_earnings=0; //double;
 agent->current_dividend_per_earnings=0; //double;
 agent->debt_earnings_ratio=0; //double;
 agent->debt_equity_ratio=0; //double;
 agent->price_earnings_ratio=0; //double;
 agent->retained_earnings_ratio=0; //double;
 agent->earnings_per_share_ratio_growth=0; //double;
 agent->critical_price_earnings_ratio=0; //double;
 agent->critical_earnings_per_share_ratio=0; //double;
 init_debt_item_array(&agent->loans); //debt_item_array;
 agent->total_debt=0;//double;
 agent->total_value_local_inventory=0; //double;
 init_capital_stock_item_array(&agent->capital_stock); //capital_stock_item_array;
 agent->total_units_capital_stock= TOTAL_UNITS_PER_CAP_STOCK; //double;
 agent->total_value_capital_stock=TOTAL_UNITS_PER_CAP_STOCK*INITCAPITAL_PRICE; //double;
 agent->total_capital_depreciation_value=0;//double;
 agent->total_capital_depreciation_units=0; //double;
 agent->total_assets=EQUITY; //double;
 agent->equity = EQUITY;//double;
 agent->production_liquidity_needs=0; //double;
 agent->financial_liquidity_needs=0; //double;
 agent->total_financial_needs=0; //double;
 agent->external_financial_needs=0; //double;
 agent->bankruptcy_state=0; //int;
 agent->financial_crisis_state=0; //int;
 agent->earnings_per_share=0; //double;
 agent->total_payments=0; //double;
 agent->total_interest_payments=0; //double;
 init_employee_array(&agent->employees); //employee_array;
 agent->wage_offer=MEAN_WAGE; //double;
 agent->technology=TECNOLOGICAL_FRONTIER; //double;
 agent->no_employees=0;//int;
 agent->no_employees_skill_1=0; //int;
 agent->no_employees_skill_2=0; //int;
 agent->no_employees_skill_3=0; //int;
 agent->no_employees_skill_4=0; //int;
 agent->no_employees_skill_5=0; //int;
 agent->vacancies=0; //int;
 agent->average_g_skill=0; //double;
 agent->average_s_skill_of_1=0; //double;
 agent->average_s_skill_of_2=0; //double;
 agent->average_s_skill_of_3=0; //double;
 agent->average_s_skill_of_4=0; //double;
 agent->average_s_skill_of_5=0; //double;
 agent->wage_offer_for_skill_1=MEAN_WAGE; //double;
 agent->wage_offer_for_skill_2=MEAN_WAGE;//double;
 agent->wage_offer_for_skill_3=MEAN_WAGE; //double;
 agent->wage_offer_for_skill_4=MEAN_WAGE; //double;
 agent->wage_offer_for_skill_5=MEAN_WAGE; //double;
 agent->employees_needed=0; //int;
 agent->age=0; //int;
 agent->transfer_payment=0; //double;
 agent->subsidy_payment=0; //double;
 agent->earnings_payout=0; //double;
 agent->current_shares_outstanding=nr_share; //double;

 init_Stock(&agent->stock);
 initializeStock(&agent->stock,id,STOCKPRICE,nr_share);
}

void initHousehold(struct xmachine_memory_Household *aHousehold, int id, int region_id, int bank_id)
{ 
 struct xmachine_memory_Household *agent;
 agent=aHousehold;
 agent->id=id;
 agent->region_id=region_id;//int;
 init_int_array(&agent->neighboring_region_ids);
 if(region_id==1) add_int(&agent->neighboring_region_ids,2); //int_array;
 if(region_id==2) add_int(&agent->neighboring_region_ids,1);
 agent->gov_id=GOV_ID; //int;
 agent->day_of_month_to_act=0; //int;
 agent->payment_account=NUMSTOCKSHOUSE*STOCKPRICE; //double;
 agent->bank_id=bank_id; //int;
 agent->consumption_budget =0;//double;
 agent->mean_income =0;//double;
 agent->week_of_month =0;//int;
 agent->weekly_budget =0;//double;
 agent->rationed =0;//int;
 agent->mall_completely_sold_out =0;//int;
 init_ordered_quantity_static_array(agent->order_quantity,2);//ordered_quantity;
 init_received_quantities_static_array(agent->received_quantity,2);//received_quantities;
 agent->day_of_week_to_act =0;//int;
 agent->day_of_month_receive_income =0;//int;
 agent->current_productivity_employer =0;//double;
 agent->current_mean_specific_skills_employer =0;//double;
 agent->total_taxes =0;//double;
 agent->cum_total_dividends =0;//double;
 agent->tax_rate_hh_capital =0;//double;
 agent->tax_rate_hh_labour =0;//double;
 agent->price_index =0;//double;
 agent->price_index_base_period =0;//double;
 agent->commuting_costs_price_level_weight =0;//double;
 //agent->last_income =0;//double_array;
 agent->expenditures =0;//double;
 agent->received_dividend =0;//double;
 agent->wage =0;//double;
 agent->wage_reservation =0;//double;
 agent->general_skill =0;//int;
 agent->on_the_job_search =0;//int;
 agent->number_applications =0;//int;
 agent->last_labour_income =0;//double;
 agent->specific_skill =0;//double;
 agent->employee_firm_id =0;//int;
 agent->employer_region_id =0;//int;
 agent->day_of_month_receive_benefit =0;//int;
 agent->unemployment_benefit_pct =0;//double;
 agent->transfer_payment =0;//double;
 agent->subsidy_payment =0;//double;
 agent->wealth =0;//double;
 init_Belief_array(&agent->beliefs);//Belief_array;
 init_Order_array(&agent->pendingOrders);//Order_array;
 init_Asset_array(&agent->assetsowned);//Asset_array;
 init_double_array(&agent->assetWeights);//double_array;
 init_double_array(&agent->assetUtilities);//double_array;
 agent->cash_on_hand =0;//double;
 agent->forwardWindow =0;//int;
 agent->backwardWindow =0;//int;
 agent->bins =0;//int;
 agent->randomWeight =0;//double;
 agent->fundamentalWeight =0;//double;
 agent->chartistWeight =0;//double;
 agent->holdingPeriodToForwardW =0;//int;
 agent->lossaversion =0;//double;
 agent->strategy =0;//double;

}

void initMall(struct xmachine_memory_Mall *aMall, int id, int region_id)
{ struct xmachine_memory_Mall *agent;
 agent=aMall;
 agent->id=id;
 agent->region_id = region_id;//int;
 agent->gov_id =0;//int;
 init_mall_stock_array(&agent->current_stock);//mall_stock_array;
 init_sales_in_mall_array(&agent->firm_revenues);//sales_in_mall_array;
 agent->total_supply =0;//double;
 //agent->export_volume_matrix =0;//double;
 //agent->export_value_matrix =0;//double;
 //agent->export_previous_value_matrix =0;//double;
 
}

void initIGFirm(struct xmachine_memory_IGFirm *aIGFirm, int id, int region_id)
{ struct xmachine_memory_IGFirm *agent;
 agent=aIGFirm;
 agent->id=id;
 //agent->id =0;//int;
 agent->region_id =0;//int;
 agent->gov_id =0;//int;
 agent->bank_id =0;//int;
 agent->day_of_month_to_act =0;//int;
 agent->payment_account =0;//double;
 agent->productivity =0;//double;
 agent->capital_good_price =0;//double;
 agent->revenue_per_day =0;//double;
 agent->tax_rate_corporate =0;//double;
 agent->tax_rate_vat =0;//double;
 agent->tax_payment =0;//double;
 agent->net_profit =0;//double;
 agent->outstanding_shares =0;//int;
 agent->current_dividend_per_share =0;//double;
 agent->cum_revenues =0;//double;
 agent->age =0;//int;
 agent->transfer_payment =0;//double;
 agent->subsidy_payment =0;//double;
 
}

void initEurostat(struct xmachine_memory_Eurostat *aEurostat, int id, int region_id)
{ struct xmachine_memory_Eurostat *agent;
 agent=aEurostat;
 agent->id=id;
 //agent->id =0;//int;
 agent->region_id =0;//int;
 agent->no_regions =0;//int;
 agent->switch_datastorage =0;//int;
 agent->num_households =0;//int;
 agent->no_households_skill_1 =0;//int;
 agent->no_households_skill_2 =0;//int;
 agent->no_households_skill_3 =0;//int;
 agent->no_households_skill_4 =0;//int;
 agent->no_households_skill_5 =0;//int;
 agent->employed =0;//int;
 agent->employed_skill_1 =0;//int;
 agent->employed_skill_2 =0;//int;
 agent->employed_skill_3 =0;//int;
 agent->employed_skill_4 =0;//int;
 agent->employed_skill_5 =0;//int;
 agent->unemployed =0;//int;
 agent->unemployment_rate =0;//double;
 agent->unemployment_rate_skill_1 =0;//double;
 agent->unemployment_rate_skill_2 =0;//double;
 agent->unemployment_rate_skill_3 =0;//double;
 agent->unemployment_rate_skill_4 =0;//double;
 agent->unemployment_rate_skill_5 =0;//double;
 agent->average_wage =0;//double;
 agent->average_wage_skill_1 =0;//double;
 agent->average_wage_skill_2 =0;//double;
 agent->average_wage_skill_3 =0;//double;
 agent->average_wage_skill_4 =0;//double;
 agent->average_wage_skill_5 =0;//double;
 agent->average_s_skill =0;//double;
 agent->average_s_skill_1 =0;//double;
 agent->average_s_skill_2 =0;//double;
 agent->average_s_skill_3 =0;//double;
 agent->average_s_skill_4 =0;//double;
 agent->average_s_skill_5 =0;//double;
 agent->no_firms =0;//int;
 agent->no_vacancies =0;//int;
 agent->no_employees =0;//int;
 agent->no_employees_skill_1 =0;//int;
 agent->no_employees_skill_2 =0;//int;
 agent->no_employees_skill_3 =0;//int;
 agent->no_employees_skill_4 =0;//int;
 agent->no_employees_skill_5 =0;//int;
 agent->firm_average_wage =0;//double;
 agent->firm_average_wage_skill_1 =0;//double;
 agent->firm_average_wage_skill_2 =0;//double;
 agent->firm_average_wage_skill_3 =0;//double;
 agent->firm_average_wage_skill_4 =0;//double;
 agent->firm_average_wage_skill_5 =0;//double;
 agent->firm_average_s_skill =0;//double;
 agent->firm_average_s_skill_1 =0;//double;
 agent->firm_average_s_skill_2 =0;//double;
 agent->firm_average_s_skill_3 =0;//double;
 agent->firm_average_s_skill_4 =0;//double;
 agent->firm_average_s_skill_5 =0;//double;
 init_firm_data_array(&agent->region_firm_data);//firm_data_array;
 init_household_data_array(&agent->region_household_data);//household_data_array;
 init_tax_rates_item_static_array(agent->government_tax_rates,27);//tax_rates_item;
 agent->total_earnings =0;//double;
 agent->total_debt =0;//double;
 agent->total_assets =0;//double;
 agent->total_equity =0;//double;
 agent->average_debt_earnings_ratio =0;//double;
 agent->average_debt_equity_ratio =0;//double;
 agent->labour_share_ratio =0;//double;
 agent->cpi =0;//double;
 agent->gdp =0;//double;
 agent->monthly_sold_quantity =0;//double;
 agent->monthly_output =0;//double;
 agent->monthly_revenue =0;//double;
 agent->monthly_planned_output =0;//double;
 agent->price_index =0;//double;
 init_history_item_static_array(agent->history_monthly,3);//history_item;
 init_history_item_static_array(agent->history_quarterly,5);//history_item;
 init_history_item(&agent->monthly_growth_rates);//history_item;
 init_history_item(&agent->quarterly_growth_rates);//history_item;
 init_history_item(&agent->annual_growth_rates_monthly);//history_item;
 init_history_item(&agent->annual_growth_rates_quarterly);//history_item;
 agent->no_firm_births =0;//int;
 agent->no_firm_deaths =0;//int;
 //agent->firm_age_distribution =0;//int;
 //agent->firm_age_distribution_multiperiod =0;//int;
 //agent->firm_age_distribution_1_period_lag =0;//int;
 //agent->firm_age_distribution_2_period_lag =0;//int;
 agent->firm_birth_rate =0;//double;
 agent->firm_death_rate =0;//double;
 //agent->survival_rate =0;//double;
 //agent->survival_rate_multiperiod_1 =0;//double;
 //agent->survival_rate_multiperiod_2 =0;//double;
// agent->survival_rate_multiperiod =0;//double;
// agent->max_firm_creation =0;//int;
 //agent->recession_started =0;//int;
 //agent->recession_duration =0;//int;
 //agent->export_volume_matrix =0;//double;
 //agent->export_value_matrix =0;//double;
 //agent->export_previous_value_matrix =0;//double;
 //agent->region_export_volume =0;//double;
 //agent->region_import_volume =0;//double;
 //agent->region_export_value =0;//double;
 //agent->region_import_value =0;//double;
 //agent->region_import_previous_value =0;//double;
 
}

void initClearinghouse(struct xmachine_memory_Clearinghouse *aClearinghouse, int id, int region_id)
{ struct xmachine_memory_Clearinghouse *agent;
 agent=aClearinghouse;
 agent->id=id;
 //agent->id =0;//int;
 agent->region_id =0;//int;
 init_Asset_array(&agent->assets);//Asset_array;
 init_ClearingMechanism(&agent->clearingmechanism);//ClearingMechanism;
 
}

void initBank(struct xmachine_memory_Bank *aBank, int id, int region_id)
{ struct xmachine_memory_Bank *agent;
 agent=aBank;
 agent->id=id;
 //agent->id =0;//int;
 agent->region_id =0;//int;
 agent->gov_id =0;//int;
 agent->cash =0;//double;
 agent->total_credit =0;//double;
 agent->equity =0;//double;
 agent->bce_debt =0;//double;
 agent->alfa =0;//double;
 agent->value_at_risk =0;//double;
 agent->min_interest =0;//double;
 //agent->bank_gamma =0;//double;
 //agent->profits =0;//double;
 agent->bank_lambda =0;//double;
 agent->bce_interest =0;//double;
 agent->bank_dividend_rate =0;//double;
 agent->tax_rate_corporate =0;//double;
 agent->number_of_shares =0;//int;
 agent->debt_period =0;//double;
 agent->loan_request_message_found =0;//int;
 agent->day_of_month_to_act =0;//int;
 
}

void initGovernment(struct xmachine_memory_Government *aGovernment, int id, int region_id)
{ struct xmachine_memory_Government *agent;
 agent=aGovernment;
 agent->id=id;
 //agent->id =0;//int;
 //agent->list_of_regions =0;//int;
 agent->payment_account =0;//double;
 agent->day_of_month_to_act =0;//int;
 initializeBond(&agent->bond,id,NUMHousehold*100,50,0.02);
 init_Order(&agent->pending_order);//Order;
 agent->deficit =0;//double;
 agent->unemployment_benefit_pct =0;//double;
 agent->money_financing_fraction =0;//double;
 agent->gdp_fraction_consumption =0;//double;
 agent->gdp_fraction_investment =0;//double;
 agent->tax_rate_corporate =0;//double;
 agent->tax_rate_hh_labour =0;//double;
 agent->tax_rate_hh_capital =0;//double;
 agent->tax_rate_vat =0;//double;
 agent->monthly_tax_revenues =0;//double;
 agent->yearly_tax_revenues =0;//double;
 agent->monthly_unemployment_benefit_payment =0;//double;
 agent->yearly_unemployment_benefit_payment =0;//double;
 agent->hh_transfer_payment =0;//double;
 agent->firm_transfer_payment =0;//double;
 agent->monthly_transfer_payment =0;//double;
 agent->yearly_transfer_payment =0;//double;
 agent->hh_subsidy_payment =0;//double;
 agent->firm_subsidy_payment =0;//double;
 agent->monthly_subsidy_payment =0;//double;
 agent->yearly_subsidy_payment =0;//double;
 agent->monthly_bond_coupon_payment =0;//double;
 agent->yearly_bond_coupon_payment =0;//double;
 agent->gov_interest_rate =0;//double;
 agent->yearly_interest_payment =0;//double;
 agent->yearly_gov_investment =0;//double;
 agent->yearly_gov_consumption =0;//double;
 agent->total_income =0;//double;
 agent->total_expenditure =0;//double;
 agent->total_debt =0;//double;
 agent->budget_deficit =0;//double;
 agent->total_money_financing =0;//double;
 agent->total_bond_financing =0;//double;
 agent->country_wide_mean_wage =0;//double;
 agent->num_unemployed =0;//int;
 agent->gdp =0;//double;
 agent->gdp_growth =0;//double;
 agent->gdp_forecast =0;//double;
 agent->total_income_forecast =0;//double;
 agent->total_expenditure_forecast =0;//double;
 agent->budget_forecast =0;//double;
 
}

void initCentral_Bank(struct xmachine_memory_Central_Bank *aCentral_Bank, int id, int region_id)
{ struct xmachine_memory_Central_Bank *agent;
 agent=aCentral_Bank;
 agent->id=id;
 //agent->id =0;//int;
 //agent->accounts =0;//double;
 
}

int main(void)
{
       FILE *file;
       int i,region_id;
       int temp;
       file = fopen("0.xml", "w");
       struct xmachine_memory_Firm aFirm[NUMFirm];
       struct xmachine_memory_Household aHousehold[NUMHousehold];
       struct xmachine_memory_Mall aMall[NUMMall];
       struct xmachine_memory_IGFirm aIGFirm[NUMIGFirm];
       struct xmachine_memory_Eurostat aEurostat[NUMEurostat];
       struct xmachine_memory_Clearinghouse aClearinghouse[NUMClearinghouse];
       struct xmachine_memory_Bank aBank[NUMBank];
       struct xmachine_memory_Government aGovernment[NUMGovernment];
       struct xmachine_memory_Central_Bank aCentral_Bank[NUMCentral_Bank];
         
       
        fputs("<states>\n<itno>", file);
        fputs("0",file);
	    fputs("</itno>\n", file);

        region_id = 1;
        temp = 0;
        
        for (i = temp; i < (int)NUMGovernment + temp; i++)
        {
           initGovernment(&aGovernment[i - temp],i,region_id);
           write_Government_agent(file,&aGovernment[i - temp]);

           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMGovernment + temp;
        
        for (i = temp; i < (int)NUMBank + temp; i++)
        {
           initBank(&aBank[i - temp],i,region_id);
           write_Bank_agent(file,&aBank[i - temp]);
           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMBank + temp;
        
        
        for (i = temp; i < (int)NUMFirm + temp; i++)
        {
           initFirm(&aFirm[i - temp],i,region_id);
           write_Firm_agent(file,&aFirm[i - temp]);
           
           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMFirm + temp;
        
        for (i = temp; i < (int)NUMHousehold + temp; i++)
        {
           initHousehold(&aHousehold[i - temp],i,region_id,BANK_ID);
           write_Household_agent(file,&aHousehold[i - temp]);
  
           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMHousehold + temp;
        
        
        for (i = temp; i < (int)NUMMall + temp; i++)
        {
           initMall(&aMall[i - temp],i,region_id);
           write_Mall_agent(file,&aMall[i - temp]);
        
           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMMall + temp;
        
        for (i = temp; i < (int)NUMCentral_Bank + temp; i++)
        {
           initCentral_Bank(&aCentral_Bank[i - temp],i,region_id);
           write_Central_Bank_agent(file,&aCentral_Bank[i - temp]);
  
           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMCentral_Bank + temp;
        
        
        for (i = temp; i < (int)NUMIGFirm + temp; i++)
        {
           initIGFirm(&aIGFirm[i - temp],i,region_id);
           write_IGFirm_agent(file,&aIGFirm[i - temp]);
           
           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMIGFirm + temp;

        for (i = temp; i < (int)NUMEurostat + temp; i++)
        {
           initEurostat(&aEurostat[i - temp],i,region_id);
           write_Eurostat_agent(file,&aEurostat[i - temp]);

           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }
        temp = (int)NUMEurostat + temp;

        for (i = temp; i < (int)NUMClearinghouse + temp; i++)
        {
           initClearinghouse(&aClearinghouse[i - temp],i,region_id);
           write_Clearinghouse_agent(file,&aClearinghouse[i - temp]);

           region_id++;
           if (region_id > NUMRegion) region_id = 1;    
        }


        /*for(region_id=1;region_id<NUMRegion;region_id++)
        {for(i=0;i<(int)NUMFirm/NUMRegion;i++)
        {
         temp = (region_id - 1) * (NUMFirm/NUMRegion);
         initFirm(&aFirm[i - temp],i - temp,region_id);
         write_Firm_agent(file,&aFirm[i - temp]);
        }
        
        for(i=NUMFirm;i<NUMFirm+NUMHousehold;i++)
        {
         initHousehold(&aHousehold[i],i,region_id,BANK_ID);
         write_Household_agent(file,&aHousehold[i-NUMFirm]);
        }
        }
        
        for(i=NUMFirm+NUMHousehold;i<NUMFirm+NUMHousehold+NUMMall;i++)
        {
         initMall(&aMall[i],i,region_id);
         write_Mall_agent(file,&aMall[i-(NUMFirm+NUMHousehold)]);
        }
        
        for(i=NUMFirm+NUMHousehold+NUMMall;i<NUMFirm+NUMHousehold+NUMMall+NUMIGFirm;i++)
        {
         initIGFirm(&aIGFirm[i],i,region_id);
         write_IGFirm_agent(file,&aIGFirm[i-(NUMFirm+NUMHousehold+NUMMall)]);
        }
        
        for(i=NUMFirm+NUMHousehold+NUMMall+NUMIGFirm;i<NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat;i++)
        {
         initEurostat(&aEurostat[i],i,region_id);
         write_Eurostat_agent(file,&aEurostat[i-(NUMFirm+NUMHousehold+NUMMall+NUMIGFirm)]);
        }
        
        for(i=NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat;i<NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse;i++)
        {
         initClearinghouse(&aClearinghouse[i],i,region_id);
         write_Clearinghouse_agent(file,&aClearinghouse[i-(NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse)]);
        }
        
        for(i=NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse;i<NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse+NUMBank;i++)
        {
         initBank(&aBank[i],i,region_id);
         write_Bank_agent(file,&aBank[i-(NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse+NUMBank)]);
        }
        
        for(i=NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse+NUMBank;i<NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse+NUMBank+NUMGovernment;i++)
        {
         initGovernment(&aGovernment[i],i,region_id);
         write_Government_agent(file,&aGovernment[i-(NUMFirm+NUMHousehold+NUMMall+NUMIGFirm+NUMEurostat+NUMClearinghouse+NUMBank+NUMGovernment)]);
        }
        
        for(i=0;i<NUMCentral_Bank;i++)
        {
         initCentral_Bank(&aCentral_Bank[i],i,region_id);
         write_Central_Bank_agent(file,&aCentral_Bank[i]);
        }
        */
        
       fputs("</states>\n" , file);
       fclose(file);
}
