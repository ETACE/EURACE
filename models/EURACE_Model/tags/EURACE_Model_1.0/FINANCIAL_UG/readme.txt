------refactoring

1) Eurostat:unused, removed 
2) added info_firm message, this message contains information about the firm: earning expected, earing payout expected and equity and the historical , the info_firm are sended after the computation of the balance sheet 
price of its stock. The info_firm message is necessary to the household in order to form its belifs.
3)Histogram removed: the utility of each stock are computed using directly the time-series of returns without the discrete pdf 
4) Portfolio  ADT removed: the assetsowned+payment_account replaces the memory variable portfolio

