In the policy experiment we investigated two policy measures. 
The policies are investing in human capital (skill upgrade) and strengthen of R&D activities leading to higher technological frontier growth.

The effects of these policies,where they are either implemented separately or carried out combined, 
are studied for two kinds of countries, old EU member states and new members (joined in 2004 during the Eastward Enlargement) . 
Here we took 2 representatives, Germany and Poland.

The general set up of the model is an one region/economy model with 1600 hh and 80 firms, where it is initialized in a way that 
it matches empirical data either for Germany or Poland (i.e. differences in quality and quantity of the capital stock, initial GDP...).

Note that one pop file represents only one country!

**********************************************************************************************

Policy measures:
1. The technology improving policy measure:  Without policy the technological frontier evolves with the same (slow) speed in both countries. 
A political intervention leads to a higher speed. Technically speaking, we change the model parameter "productivity_progress" from 0.0125 to 0.025.

2. General skill upgrade: Initially, both countries have different distributions of general skills among the 5 skill groups (1 to 5, with 1 the lowest skill level, 5 the highest).

Poland has a "low" skill distribution and Germany a "medium" skill distribution.

A skill upgrading policy shifts Germany's general skill distribution from  the medium to the high skill distribution. 
For Poland we assume two opportunities: either the general skills are increased up to the medium level (the initial distribution of Germany) or to the highest level.  
Technically, we use different distributions for the household memory variable "general_skill".

Table of distributions for the low, medium and high skill case

skill group:   1   2   3   4   5  
low:    42%    33%    20%    4%    1%      
medium:   10%   30%   40%   15%   5%
high:   5%   5%   5%   5%   80%


In the pop file we have:
*discrete((0.42,1),(0.33,2),(0.2,3),(0.04,4),(0.01,5)) for the low skill distribution,

*discrete((0.1,1),(0.3,2),(0.4,3),(0.15,4),(0.05,5))  for the medium case

*discrete((0.05,1),(0.05,2),(0.05,3),(0.05,4),(0.8,5)) for the highest skill distribution.



******************************************************************************************
From this it follows that we have 4 different settings for Germany and 6 for Poland, and consequently 4 pop files for Germany and 6 for Poland.

In the folder Exp you can find two sub folders, (called Germany and Poland) where we stored the pop files for the policy experiments.


XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
Folder Germany:

----------------------------------------------------------------------------------
*pop_GERMANY_BASE_SCENARIO.pop:  This pop file is the initialization for Germany without a policy measure.

Skill distribution: medium             technological progress: slow

--------------------------------------------------------------------------------
*pop_GERMANY_ONE_POLICY_TECHNOLOGY_IMPROVEMENT.pop:  Here only the technology improving policy measure is implemented.

Skill distribution: medium             technological progress: fast
--------------------------------------------------------------------------------
*pop_GERMANY_ONE_POLICY_SKILL_UPGRADE.pop:  Only the skill upgrading policy is implemented.

Skill distribution: high                technological progress: slow
---------------------------------------------------------------------------------
*pop_GERMANY_COMBINED_POLICIES_TECHNOLOGY_IMPROVEMENT_and_SKILL_UPGRADE.pop:  A combination of both policies. 


Skill distribution: high                technological progress: fast
---------------------------------------------------------------------------------------


XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx

Folder Poland:

pop_POLAND_BASE_SCENARIO.pop:   Initial pop file without policy.


Skill distribution: low                technological progress: slow
------------------------------------------------------------------------------------------------
pop_POLAND_ONE_POLICY_MEDIUM_SKILL_UPGRADE.pop: One policy implemented: medium skill upgrade


Skill distribution: medium                technological progress: slow
-------------------------------------------------------------------------------------------------
pop_POLAND_ONE_POLICY_HIGH_SKILL_UPGRADE.pop: One policy implemented: high skill disirtibution (with low technological progress)

Skill distribution: high                technological progress: slow
------------------------------------------------------------------------------------------------------
pop_POLAND_ONE_POLICY_TECHNOLOGY_IMPROVEMENT.pop: One policy implemented, higher  technological progress. (with low skill distribution)

Skill distribution: low                technological progress: fast
----------------------------------------------------------------------------------------------------------
pop_POLAND_COMBINED_POLICIES_TECHNOLOGY_IMPROVEMENT_and_MEDIUM_SKILL_UPGRADE.pop
Combined policies: higher technological progress and medium skill distribution

Skill distribution: medium                technological progress: fast
--------------------------------------------------------------------------------------------------------------------
pop_POLAND_COMBINED_POLICIES_TECHNOLOGY_IMPROVEMENT_and_HIGH_SKILL_UPGRADE.pop
Combined policies: higher technological progress and high skill distribution

Skill distribution: high                technological progress: fast





