Description of settings for policy experiments
===============================================
The policy experiment below can be run with the 0_default.xml file, except the following settings should be set:

<trading_activity>0.0</trading_activity>
<carrol_consumption_parameter>0.01</carrol_consumption_parameter>
<gov_policy_switch_quantitative_easing>1</gov_policy_switch_quantitative_easing>

Without these settings it cannot be guaranteed that the experiment will run in finite time, or will end before you need the output, whichever comes first.
Below, a parameter range is denoted by [x0:dx:x1], where x0 is the starting value, dx is the increment and x1 is the end value.

Tax rate experiment
====================
Parameters to vary:

<const_income_tax_rate>0.05</const_income_tax_rate>

Range: values in the interval
[0.02:0.02:0.20]

Energy shock experiment
=======================
Constants to set: switch on these flags

<policy_exp_energy_shock>1</policy_exp_energy_shock>
<policy_exp_stabilization>0</policy_exp_stabilization>
<symmetric_shock>1</symmetric_shock>

Paramaters to set: default setting starts the energy shock after 1000+240 iterations, and ends at t=1480.

<energy_shock_start>1240</energy_shock_start>
<energy_shock_end>1480</energy_shock_end>

Parameters to vary:

<const_energy_shock_intensity>0.0</const_energy_shock_intensity>

Range: 4 values: [0.05:0.05:0.20]

<energy_shock_frequency>0</energy_shock_frequency>
Range: 4 values
[x0:dx:x1]=[0:20:60]


Stabilization experiment
========================
Constants to set:

<policy_exp_energy_shock>1</policy_exp_energy_shock>
<policy_exp_stabilization>1</policy_exp_stabilization>

Parameters to vary:

<subsidy_trigger_on>0.03</subsidy_trigger_on>

Range: values in the interval
[-0.05:0.01:0.05]

<subsidy_trigger_off>0.03</subsidy_trigger_off>

Range: values in the interval
[0.0:0.01:0.05]
