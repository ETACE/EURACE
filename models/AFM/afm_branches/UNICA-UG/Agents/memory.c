/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
	temp_xmachine = NULL;
	p_xmachine = &temp_xmachine;
	temp_order_message = NULL;
	p_order_message = &temp_order_message;
	temp_orderStatus_message = NULL;
	p_orderStatus_message = &temp_orderStatus_message;
	temp_asset_message = NULL;
	p_asset_message = &temp_asset_message;
	temp_infoAsset_message = NULL;
	p_infoAsset_message = &temp_infoAsset_message;
	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;
	
	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}
	
	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);	
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}
	
	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_location = NULL;
}

/* add_xmachine */
/** \fn xmachine * add_xmachine()
 * \brief Add an X-machine to the current being used X-machine list.
 * \return Pointer to the added X-machine.
 */
xmachine * add_xmachine()
{
	xmachine * current = (xmachine *)malloc(sizeof(xmachine));
	CHECK_POINTER(current);

	current->xmachine_Eurostat = NULL;
	current->xmachine_Household = NULL;
	current->xmachine_ClearingHouse = NULL;
	current->xmachine_Firm = NULL;
	current->next = *p_xmachine;
	*p_xmachine = current;
	
	current_node->agent_total++;

/* add by cg for round-robin so that set_ has something to point at */
	current_xmachine = current;
	
	return current;
}

/** \fn void add_Eurostat_agent(int id, Asset_array * assets, double range, double posx, double posy)
 * \brief Add Eurostat X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param assets Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Eurostat_agent(int id, Asset_array * assets, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Eurostat * current = (xmachine_memory_Eurostat *)malloc(sizeof(xmachine_memory_Eurostat));
		CHECK_POINTER(current);

	new_xmachine->xmachine_Eurostat = current;
	current->id = id;
	current->assets = assets;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_Household_agent(int id, double wealth, Belief * belief, Portfolio * portfolio, Order_array * pendingOrders, Asset_array * assetsowned, int forwardWindow, int backwordWindow, int binsNumber, double randomReturnWeigth, double fundametalReturnWeigth, double chartistReturnWeigth, int holdingPeriodToForwardW, double range, double posx, double posy)
 * \brief Add Household X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param wealth Variable for the X-machine memory.
 * \param belief Variable for the X-machine memory.
 * \param portfolio Variable for the X-machine memory.
 * \param pendingOrders Variable for the X-machine memory.
 * \param assetsowned Variable for the X-machine memory.
 * \param forwardWindow Variable for the X-machine memory.
 * \param backwordWindow Variable for the X-machine memory.
 * \param binsNumber Variable for the X-machine memory.
 * \param randomReturnWeigth Variable for the X-machine memory.
 * \param fundametalReturnWeigth Variable for the X-machine memory.
 * \param chartistReturnWeigth Variable for the X-machine memory.
 * \param holdingPeriodToForwardW Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Household_agent(int id, double wealth, Belief * belief, Portfolio * portfolio, Order_array * pendingOrders, Asset_array * assetsowned, int forwardWindow, int backwordWindow, int binsNumber, double randomReturnWeigth, double fundametalReturnWeigth, double chartistReturnWeigth, int holdingPeriodToForwardW, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Household * current = (xmachine_memory_Household *)malloc(sizeof(xmachine_memory_Household));
		CHECK_POINTER(current);

	new_xmachine->xmachine_Household = current;
	current->id = id;
	current->wealth = wealth;
	current->belief = belief;
	current->portfolio = portfolio;
	current->pendingOrders = pendingOrders;
	current->assetsowned = assetsowned;
	current->forwardWindow = forwardWindow;
	current->backwordWindow = backwordWindow;
	current->binsNumber = binsNumber;
	current->randomReturnWeigth = randomReturnWeigth;
	current->fundametalReturnWeigth = fundametalReturnWeigth;
	current->chartistReturnWeigth = chartistReturnWeigth;
	current->holdingPeriodToForwardW = holdingPeriodToForwardW;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_ClearingHouse_agent(int id, Asset_array * assets, double range, double posx, double posy)
 * \brief Add ClearingHouse X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param assets Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_ClearingHouse_agent(int id, Asset_array * assets, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_ClearingHouse * current = (xmachine_memory_ClearingHouse *)malloc(sizeof(xmachine_memory_ClearingHouse));
		CHECK_POINTER(current);

	new_xmachine->xmachine_ClearingHouse = current;
	current->id = id;
	current->assets = assets;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void add_Firm_agent(int id, int current_shares_outstanding, double total_dividend_payment, double bank_account, double equity, double range, double posx, double posy)
 * \brief Add Firm X-machine to the current being used X-machine list.
 * \param id Variable for the X-machine memory.
 * \param current_shares_outstanding Variable for the X-machine memory.
 * \param total_dividend_payment Variable for the X-machine memory.
 * \param bank_account Variable for the X-machine memory.
 * \param equity Variable for the X-machine memory.
 * \param range Variable for the X-machine memory.
 * \param posx Variable for the X-machine memory.
 * \param posy Variable for the X-machine memory.
 */
void add_Firm_agent(int id, int current_shares_outstanding, double total_dividend_payment, double bank_account, double equity, double range, double posx, double posy)
{
	xmachine * new_xmachine = add_xmachine();
	xmachine_memory_Firm * current = (xmachine_memory_Firm *)malloc(sizeof(xmachine_memory_Firm));
		CHECK_POINTER(current);

	new_xmachine->xmachine_Firm = current;
	current->id = id;
	current->current_shares_outstanding = current_shares_outstanding;
	current->total_dividend_payment = total_dividend_payment;
	current->bank_account = bank_account;
	current->equity = equity;
	current->range = range;
	current->posx = posx;
	current->posy = posy;
}

/** \fn void free_agent()
 * \brief Free the currently being used X-machine.
 */
/* free_agent */
void free_agent()
{
	xmachine * head = *p_xmachine;
	xmachine * tmp = NULL;
	
	while(head)
	{
		if(head == current_xmachine)
		{
			if(tmp) tmp->next = head->next;
			else *p_xmachine = head->next;
			if(head->xmachine_Eurostat)
			{
				free_Asset_array(head->xmachine_Eurostat->assets);
				free(head->xmachine_Eurostat);
			}
			if(head->xmachine_Household)
			{
				free_Order_array(head->xmachine_Household->pendingOrders);
				free_Asset_array(head->xmachine_Household->assetsowned);
				free(head->xmachine_Household);
			}
			if(head->xmachine_ClearingHouse)
			{
				free_Asset_array(head->xmachine_ClearingHouse->assets);
				free(head->xmachine_ClearingHouse);
			}
			if(head->xmachine_Firm)
			{
				free(head->xmachine_Firm);
			}

		free(head);
		head = NULL;
	}
	else
	{
		tmp = head;
		head = tmp->next;
	}
}
	
	current_node->agent_total--;
}

/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	xmachine * head = *p_xmachine;
	xmachine * tmp = NULL;
	
	while(head)
	{
		tmp = head->next;
		if(head->xmachine_Eurostat)
		{
			free_Asset_array(head->xmachine_Eurostat->assets);
			free(head->xmachine_Eurostat);
		}
		if(head->xmachine_Household)
		{
			free(head->xmachine_Household->belief);
			free(head->xmachine_Household->portfolio);
			free_Order_array(head->xmachine_Household->pendingOrders);
			free_Asset_array(head->xmachine_Household->assetsowned);
			free(head->xmachine_Household);
		}
		if(head->xmachine_ClearingHouse)
		{
			free_Asset_array(head->xmachine_ClearingHouse->assets);
			free(head->xmachine_ClearingHouse);
		}
		if(head->xmachine_Firm)
		{
			free(head->xmachine_Firm);
		}
		free(head);
		head = tmp;
	}
	
	*p_xmachine = NULL;
}


/** \fn void set_id(int id) 
 * \brief Set id memory variable for current X-machine.
 * \param id New value for variable.
 */
void set_id(int id)
{
	if(current_xmachine->xmachine_Eurostat) current_xmachine->xmachine_Eurostat->id = id;
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->id = id;
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->id = id;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->id = id;
}

/** \fn int get_id()
 * \brief Get id memory variable from current X-machine.
 * \return Value for variable.
 */
int get_id()
{
	if(current_xmachine->xmachine_Eurostat) return current_xmachine->xmachine_Eurostat->id;
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->id;
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->id;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->id;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn Asset_array get_assets()
 * \brief Get assets memory variable from current X-machine.
 * \return Value for variable.
 */
Asset_array * get_assets()
{
	if(current_xmachine->xmachine_Eurostat) return current_xmachine->xmachine_Eurostat->assets;
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->assets;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn void set_range(double range) 
 * \brief Set range memory variable for current X-machine.
 * \param range New value for variable.
 */
void set_range(double range)
{
	if(current_xmachine->xmachine_Eurostat) current_xmachine->xmachine_Eurostat->range = range;
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->range = range;
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->range = range;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->range = range;
}

/** \fn double get_range()
 * \brief Get range memory variable from current X-machine.
 * \return Value for variable.
 */
double get_range()
{
	if(current_xmachine->xmachine_Eurostat) return current_xmachine->xmachine_Eurostat->range;
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->range;
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->range;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->range;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_posx(double posx) 
 * \brief Set posx memory variable for current X-machine.
 * \param posx New value for variable.
 */
void set_posx(double posx)
{
	if(current_xmachine->xmachine_Eurostat) current_xmachine->xmachine_Eurostat->posx = posx;
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->posx = posx;
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->posx = posx;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->posx = posx;
}

/** \fn double get_posx()
 * \brief Get posx memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posx()
{
	if(current_xmachine->xmachine_Eurostat) return current_xmachine->xmachine_Eurostat->posx;
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->posx;
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->posx;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->posx;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_posy(double posy) 
 * \brief Set posy memory variable for current X-machine.
 * \param posy New value for variable.
 */
void set_posy(double posy)
{
	if(current_xmachine->xmachine_Eurostat) current_xmachine->xmachine_Eurostat->posy = posy;
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->posy = posy;
	if(current_xmachine->xmachine_ClearingHouse) current_xmachine->xmachine_ClearingHouse->posy = posy;
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->posy = posy;
}

/** \fn double get_posy()
 * \brief Get posy memory variable from current X-machine.
 * \return Value for variable.
 */
double get_posy()
{
	if(current_xmachine->xmachine_Eurostat) return current_xmachine->xmachine_Eurostat->posy;
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->posy;
	if(current_xmachine->xmachine_ClearingHouse) return current_xmachine->xmachine_ClearingHouse->posy;
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->posy;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_wealth(double wealth) 
 * \brief Set wealth memory variable for current X-machine.
 * \param wealth New value for variable.
 */
void set_wealth(double wealth)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->wealth = wealth;
}

/** \fn double get_wealth()
 * \brief Get wealth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_wealth()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->wealth;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn Belief get_belief()
 * \brief Get belief memory variable from current X-machine.
 * \return Value for variable.
 */
Belief * get_belief()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->belief;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn Portfolio get_portfolio()
 * \brief Get portfolio memory variable from current X-machine.
 * \return Value for variable.
 */
Portfolio * get_portfolio()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->portfolio;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn Order_array get_pendingOrders()
 * \brief Get pendingOrders memory variable from current X-machine.
 * \return Value for variable.
 */
Order_array * get_pendingOrders()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->pendingOrders;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn Asset_array get_assetsowned()
 * \brief Get assetsowned memory variable from current X-machine.
 * \return Value for variable.
 */
Asset_array * get_assetsowned()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->assetsowned;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return NULL;
}

/** \fn void set_forwardWindow(int forwardWindow) 
 * \brief Set forwardWindow memory variable for current X-machine.
 * \param forwardWindow New value for variable.
 */
void set_forwardWindow(int forwardWindow)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->forwardWindow = forwardWindow;
}

/** \fn int get_forwardWindow()
 * \brief Get forwardWindow memory variable from current X-machine.
 * \return Value for variable.
 */
int get_forwardWindow()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->forwardWindow;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_backwordWindow(int backwordWindow) 
 * \brief Set backwordWindow memory variable for current X-machine.
 * \param backwordWindow New value for variable.
 */
void set_backwordWindow(int backwordWindow)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->backwordWindow = backwordWindow;
}

/** \fn int get_backwordWindow()
 * \brief Get backwordWindow memory variable from current X-machine.
 * \return Value for variable.
 */
int get_backwordWindow()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->backwordWindow;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_binsNumber(int binsNumber) 
 * \brief Set binsNumber memory variable for current X-machine.
 * \param binsNumber New value for variable.
 */
void set_binsNumber(int binsNumber)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->binsNumber = binsNumber;
}

/** \fn int get_binsNumber()
 * \brief Get binsNumber memory variable from current X-machine.
 * \return Value for variable.
 */
int get_binsNumber()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->binsNumber;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_randomReturnWeigth(double randomReturnWeigth) 
 * \brief Set randomReturnWeigth memory variable for current X-machine.
 * \param randomReturnWeigth New value for variable.
 */
void set_randomReturnWeigth(double randomReturnWeigth)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->randomReturnWeigth = randomReturnWeigth;
}

/** \fn double get_randomReturnWeigth()
 * \brief Get randomReturnWeigth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_randomReturnWeigth()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->randomReturnWeigth;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_fundametalReturnWeigth(double fundametalReturnWeigth) 
 * \brief Set fundametalReturnWeigth memory variable for current X-machine.
 * \param fundametalReturnWeigth New value for variable.
 */
void set_fundametalReturnWeigth(double fundametalReturnWeigth)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->fundametalReturnWeigth = fundametalReturnWeigth;
}

/** \fn double get_fundametalReturnWeigth()
 * \brief Get fundametalReturnWeigth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_fundametalReturnWeigth()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->fundametalReturnWeigth;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_chartistReturnWeigth(double chartistReturnWeigth) 
 * \brief Set chartistReturnWeigth memory variable for current X-machine.
 * \param chartistReturnWeigth New value for variable.
 */
void set_chartistReturnWeigth(double chartistReturnWeigth)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->chartistReturnWeigth = chartistReturnWeigth;
}

/** \fn double get_chartistReturnWeigth()
 * \brief Get chartistReturnWeigth memory variable from current X-machine.
 * \return Value for variable.
 */
double get_chartistReturnWeigth()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->chartistReturnWeigth;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_holdingPeriodToForwardW(int holdingPeriodToForwardW) 
 * \brief Set holdingPeriodToForwardW memory variable for current X-machine.
 * \param holdingPeriodToForwardW New value for variable.
 */
void set_holdingPeriodToForwardW(int holdingPeriodToForwardW)
{
	if(current_xmachine->xmachine_Household) current_xmachine->xmachine_Household->holdingPeriodToForwardW = holdingPeriodToForwardW;
}

/** \fn int get_holdingPeriodToForwardW()
 * \brief Get holdingPeriodToForwardW memory variable from current X-machine.
 * \return Value for variable.
 */
int get_holdingPeriodToForwardW()
{
	if(current_xmachine->xmachine_Household) return current_xmachine->xmachine_Household->holdingPeriodToForwardW;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_current_shares_outstanding(int current_shares_outstanding) 
 * \brief Set current_shares_outstanding memory variable for current X-machine.
 * \param current_shares_outstanding New value for variable.
 */
void set_current_shares_outstanding(int current_shares_outstanding)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->current_shares_outstanding = current_shares_outstanding;
}

/** \fn int get_current_shares_outstanding()
 * \brief Get current_shares_outstanding memory variable from current X-machine.
 * \return Value for variable.
 */
int get_current_shares_outstanding()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->current_shares_outstanding;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (int)0;
}

/** \fn void set_total_dividend_payment(double total_dividend_payment) 
 * \brief Set total_dividend_payment memory variable for current X-machine.
 * \param total_dividend_payment New value for variable.
 */
void set_total_dividend_payment(double total_dividend_payment)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->total_dividend_payment = total_dividend_payment;
}

/** \fn double get_total_dividend_payment()
 * \brief Get total_dividend_payment memory variable from current X-machine.
 * \return Value for variable.
 */
double get_total_dividend_payment()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->total_dividend_payment;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_bank_account(double bank_account) 
 * \brief Set bank_account memory variable for current X-machine.
 * \param bank_account New value for variable.
 */
void set_bank_account(double bank_account)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->bank_account = bank_account;
}

/** \fn double get_bank_account()
 * \brief Get bank_account memory variable from current X-machine.
 * \return Value for variable.
 */
double get_bank_account()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->bank_account;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}

/** \fn void set_equity(double equity) 
 * \brief Set equity memory variable for current X-machine.
 * \param equity New value for variable.
 */
void set_equity(double equity)
{
	if(current_xmachine->xmachine_Firm) current_xmachine->xmachine_Firm->equity = equity;
}

/** \fn double get_equity()
 * \brief Get equity memory variable from current X-machine.
 * \return Value for variable.
 */
double get_equity()
{
	if(current_xmachine->xmachine_Firm) return current_xmachine->xmachine_Firm->equity;

    /* suppress compiler warning by returning dummy value */
    /* this statement should rightfully NEVER be reached */
    return (double)0;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->range;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->range;
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->range;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->range;

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->id;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->id;
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->id;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->id;

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->posx;
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posx;
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->posx;
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->posx;

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    if (current_xmachine->xmachine_Eurostat) value = current_xmachine->xmachine_Eurostat->posy; 
    if (current_xmachine->xmachine_Household) value = current_xmachine->xmachine_Household->posy; 
    if (current_xmachine->xmachine_ClearingHouse) value = current_xmachine->xmachine_ClearingHouse->posy; 
    if (current_xmachine->xmachine_Firm) value = current_xmachine->xmachine_Firm->posy; 

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}
/** \fn void randomisexagent()
 * \brief Randomise the current X-machine list.
 * 
 * \author LS Chin (CCLRC)
 * \date March 2007
 */
void randomisexagent() {

    int i, rnd;
    int xm_count;
    xmachine *current;
    xmachine **address_list;
    
    xm_count = current_node->agent_total;

    /* allocate mem for dynamic temp array */
    address_list = (xmachine **)malloc(sizeof(xmachine *) * xm_count);
	CHECK_POINTER(address_list);

    p_xmachine = &current_node->agents;
    
    /* populate address list */
    i = 0;
    current = *p_xmachine;
    while(current)
    {
        address_list[i] = current;
        current = current->next;
        i++;
    }

    /* randomise address list */
    for (i = xm_count - 1; i > 0; i--)
    {
        /* get random number */
        rnd = (int)((double)i * rand() / (RAND_MAX + 1.0));

        if (rnd == i) continue;

        /* use 'current' as temp var to swap addresses */
        current = address_list[i];
        address_list[i] = address_list[rnd];
        address_list[rnd] = current;
    }

    /* build new xmachine list from randomised address list */
    *p_xmachine = NULL;
    for (i = 0; i < xm_count; i++)
    {
        address_list[i]->next = *p_xmachine;
        *p_xmachine = address_list[i];
    }

    free(address_list);
}


/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;
	
	while(current)
	{
		tmp = current;
		current = current->next;
	}
	
	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}
	
	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->order_messages = NULL;
	current->orderStatus_messages = NULL;
	current->asset_messages = NULL;
	current->infoAsset_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;
	
	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
	
	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
	FILE *file;
	char data[100];
	
	
	/* Free x-machine memory */

	current_node = *p_node_info;
	while(current_node)
	{
		p_xmachine = &current_node->agents;

	freexmachines();
	current_node->agent_total = 0;

		current_node = current_node->next;
	}

	/* Free space partitions linked list */
	free_node_info();
	

	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<totaltime>", file);
	sprintf(data, "%ld", total_time);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);

	
	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");
		
		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Eurostat != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Eurostat->posx;
			y_xmachine = current_xmachine->xmachine_Eurostat->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Household != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Household->posx;
			y_xmachine = current_xmachine->xmachine_Household->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_ClearingHouse != NULL)
		{
			x_xmachine = current_xmachine->xmachine_ClearingHouse->posx;
			y_xmachine = current_xmachine->xmachine_ClearingHouse->posy;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Firm != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Firm->posx;
			y_xmachine = current_xmachine->xmachine_Firm->posy;
			z_xmachine = 0.0;
		}
		
		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    /* Remove agent */
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    /* Add agent */
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;
			
			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
int_array * init_int_array()
{
	int_array * new_array = (int_array *)malloc(sizeof(int_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
void sort_int_array(int_array * array)
{
	int i, j, temp;
	/* Using bubble sorts nested loops */
	for(i=0; i<(array->size-1); i++)
	{
		for(j=0; j<(array->size-1)-i; j++) 
		{
			/* Comparing the values between neighbours */
			if(*(array->array+j+1) < *(array->array+j))
			{
                /* Swap neighbours */
                temp = *(array->array+j); 
                *(array->array+j) = *(array->array+j+1);
                *(array->array+j+1) = temp;
			}
		}
	}
}

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
int quicksort_int(int * array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (int *)realloc(array->array, (array->total_size * sizeof(int)));
	}
	array->array[array->size] = new_int;
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prints */
	for(i=0; i<array->size; i++)
	{
		printf("%d> %d", i, array->array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
float_array * init_float_array()
{
	float_array * new_array = (float_array *)malloc(sizeof(float_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	array->size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
void sort_float_array(float_array * array)
{
	int i, j;
	float temp;
	/* Using bubble sorts nested loops */
	for(i=0; i<(array->size-1); i++)
	{
		for(j=0; j<(array->size-1)-i; j++) 
		{
			/* Comparing the values between neighbours */
			if(*(array->array+j+1) < *(array->array+j))
			{
                /* Swap neighbours */
                temp = *(array->array+j); 
                *(array->array+j) = *(array->array+j+1);
                *(array->array+j+1) = temp;
			}
		}
	}
}

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
int quicksort_float(float * array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (float *)realloc(array->array, (array->total_size * sizeof(float)));
	}
	array->array[array->size] = new_float;
	array->size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<array->size; i++)
	{
		printf("%d> %f", i, array->array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
double_array * init_double_array()
{
	double_array * new_array = (double_array *)malloc(sizeof(double_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
		CHECK_POINTER(new_array->array);
	return new_array;
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	array->size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
void sort_double_array(double_array * array)
{
	int i, j;
	double temp;
	
	/* Using bubble sorts nested loops */
	for(i=0; i<(array->size-1); i++)
	{
		for(j=0; j<(array->size-1)-i; j++) 
		{
			/* Comparing the values between neighbours */
			if(*(array->array+j+1) < *(array->array+j))
			{
                /* Swap neighbours */
                temp = *(array->array+j); 
                *(array->array+j) = *(array->array+j+1);
                *(array->array+j+1) = temp;
			}
		}
	}
}

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
int quicksort_double(double * array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ; 
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else 
	    {
	      i--;
	    }
	}
	return 0;
}

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (double *)realloc(array->array, (array->total_size * sizeof(double)));
	}
	array->array[array->size] = new_double;
	array->size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prints */
	for(i=0; i<array->size; i++)
	{
		printf("%d> %f", i, array->array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
char_array * init_char_array()
{
	char_array * new_array = (char_array *)malloc(sizeof(char_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
		CHECK_POINTER(new_array->array);
	new_array->array[0] = '\0';
	return new_array;
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	array->size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free(array->array);
	free(array);
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if(array->size + 1 == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (char *)realloc(array->array, (array->total_size * sizeof(char)));
	}
	array->array[array->size] = new_char;
	array->array[array->size + 1] = '\0';
	array->size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( (array->size + 1) * sizeof(char));
		CHECK_POINTER(new_string);
	return strcpy(new_string, array->array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", array->array);
}

/* Functions for the Portfolio datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
Portfolio_array * init_Portfolio_array()
{
	Portfolio_array * new_array = (Portfolio_array *)malloc(sizeof(Portfolio_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (Portfolio **)malloc(ARRAY_BLOCK_SIZE * sizeof(Portfolio *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_Portfolio_array(Portfolio_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_Portfolio_array(Portfolio_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_Portfolio(Portfolio_array * array, double bankAccount)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (Portfolio **)realloc(array->array, (array->total_size * sizeof(Portfolio *)));
	}
	array->array[array->size] = (Portfolio *)malloc(sizeof(Portfolio));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->bankAccount = bankAccount;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_Portfolio(Portfolio_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the Asset datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
Asset_array * init_Asset_array()
{
	Asset_array * new_array = (Asset_array *)malloc(sizeof(Asset_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (Asset **)malloc(ARRAY_BLOCK_SIZE * sizeof(Asset *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_Asset_array(Asset_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_Asset_array(Asset_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_Asset(Asset_array * array, int issuer, int quantity, double lastPrice)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (Asset **)realloc(array->array, (array->total_size * sizeof(Asset *)));
	}
	array->array[array->size] = (Asset *)malloc(sizeof(Asset));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->issuer = issuer;
	array->array[array->size]->quantity = quantity;
	array->array[array->size]->lastPrice = lastPrice;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_Asset(Asset_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the Belief datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
Belief_array * init_Belief_array()
{
	Belief_array * new_array = (Belief_array *)malloc(sizeof(Belief_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (Belief **)malloc(ARRAY_BLOCK_SIZE * sizeof(Belief *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_Belief_array(Belief_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_Belief_array(Belief_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_Belief(Belief_array * array, double expectedPriceReturns, double expectedTotalReturns, double expectedCashFlowYield, double volatility)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (Belief **)realloc(array->array, (array->total_size * sizeof(Belief *)));
	}
	array->array[array->size] = (Belief *)malloc(sizeof(Belief));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->expectedPriceReturns = expectedPriceReturns;
	array->array[array->size]->expectedTotalReturns = expectedTotalReturns;
	array->array[array->size]->expectedCashFlowYield = expectedCashFlowYield;
	array->array[array->size]->volatility = volatility;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_Belief(Belief_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}
/* Functions for the Order datatype */
/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
Order_array * init_Order_array()
{
	Order_array * new_array = (Order_array *)malloc(sizeof(Order_array));
		CHECK_POINTER(new_array);
	new_array->size = 0;
	new_array->total_size = ARRAY_BLOCK_SIZE;
	new_array->array = (Order **)malloc(ARRAY_BLOCK_SIZE * sizeof(Order *));
		CHECK_POINTER(new_array->array);
	
	return new_array;
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_Order_array(Order_array * array)
{
	array->size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_Order_array(Order_array * array)
{
	int i;
	
	for(i = 0; i < array->size; i++)
	{
		free(array->array[i]);
	}
	free(array->array);
	free(array);
}

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_Order(Order_array * array, int issuer, int quantity, double price, int assetId)
{
	if(array->size == array->total_size)
	{
		array->total_size = array->total_size + ARRAY_BLOCK_SIZE;
		array->array = (Order **)realloc(array->array, (array->total_size * sizeof(Order *)));
	}
	array->array[array->size] = (Order *)malloc(sizeof(Order));
		CHECK_POINTER(array->array[array->size]);

	array->array[array->size]->issuer = issuer;
	array->array[array->size]->quantity = quantity;
	array->array[array->size]->price = price;
	array->array[array->size]->assetId = assetId;
	
	array->size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_Order(Order_array * array, int index)
{
	int i;
	
	if(index <= array->size)
	{
		/* memcopy?? */
		for(i = index; i < array->size - 1; i++)
		{
			array->array[i] = array->array[i+1];
		}
		array->size--;
	}
}

