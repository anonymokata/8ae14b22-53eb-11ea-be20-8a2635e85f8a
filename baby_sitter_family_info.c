#include <stdio.h>
#include <stdlib.h>
#include "baby_sitter_family_info.h"


/* The family rate table which describes the rates of each family. */
static familyRateInfo const familyRates[] =
{
	{ 'A',
		{
			{ 15,	CONVERT_TO_12_HOUR(1700),	CONVERT_TO_12_HOUR(2300) },
			{ 20,	CONVERT_TO_12_HOUR(2300),	CONVERT_TO_12_HOUR(400) }
		}
	},
	{ 'B',
		{
			{ 12,	CONVERT_TO_12_HOUR(1700),	CONVERT_TO_12_HOUR(2200) },
			{ 8,	CONVERT_TO_12_HOUR(2200),	CONVERT_TO_12_HOUR(0) },
			{ 16,	CONVERT_TO_12_HOUR(0),		CONVERT_TO_12_HOUR(400) }
		}
	},
	{ 'C',
		{
			{ 21,	CONVERT_TO_12_HOUR(1700),	CONVERT_TO_12_HOUR(2200) },
			{ 15,	CONVERT_TO_12_HOUR(2200),	CONVERT_TO_12_HOUR(400) }
		}
	}
};


familyRateInfo const* getFamilyRates(char const familyName)
{
	familyRateInfo const* familyInfo = NULL;
	size_t idx;

	for (idx = 0; idx < sizeof(familyRates) / sizeof(familyRates[0]); idx++)
	{ 
		if (familyRates[idx].name == familyName)
		{
			familyInfo = &familyRates[idx];
			break;
		}	
	}

	return familyInfo;
}