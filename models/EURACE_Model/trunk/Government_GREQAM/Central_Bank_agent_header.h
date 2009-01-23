/**
 * \file  Central_Bank_agent_header.h
 * \brief Header for agent type memory access.
 */

/** \def BANK_ACCOUNTS
 * \brief Direct access to bank_accounts of Central_Bank agent memory variable. */
#define BANK_ACCOUNTS (current_xmachine_Central_Bank->bank_accounts)
/** \def GOV_ACCOUNTS
 * \brief Direct access to gov_accounts of Central_Bank agent memory variable. */
#define GOV_ACCOUNTS (current_xmachine_Central_Bank->gov_accounts)
