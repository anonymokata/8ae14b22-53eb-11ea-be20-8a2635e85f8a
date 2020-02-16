#include <stdio.h>
#include <stdlib.h>
#include "baby_sitter_family_info.h"


/* The family rate table which describes the rates of each family. */
static family_rate_info const family_rates[] =
{
	{ 'A',
		{
			{ 15, 1700, 2259 }, { 20, 2300, 400 }
		}
	},
	{ 'B',
		{
			{ 12, 1700, 2159 }, { 8, 2200, 2359 }, { 16, 0, 400 }
		}
	},
	{ 'C',
		{
			{ 21, 1700, 2159 }, { 15, 2200, 400 }
		}
	}
};


family_rate_info const* getFamilyRates(char const family_name)
{
	family_rate_info const* familyInfo = NULL;

	for (size_t idx = 0; idx < sizeof(family_rates) / sizeof(family_rates[0]); idx++)
	{ 
		if (family_rates[idx].name == family_name)
		{
			familyInfo = &family_rates[idx];
			break;
		}	
	}

	return familyInfo;
}