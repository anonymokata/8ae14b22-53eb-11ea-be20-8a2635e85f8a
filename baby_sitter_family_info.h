#ifndef _BABY_SITTER_FAMILY_INFO_H
#define _BABY_SITTER_FAMILY_INFO_H


/* The maximum number of different rates allowed per family.  */
#define MAX_RATE_PLANS	(3)


/* The different rates that a family can have.  A family has to have at
   least one of these and can have multiple. */
typedef struct
{
	size_t hourly_rate;
	size_t start_time;
	size_t stop_time;
} rate_info;


/* The family rate information which consists of a name along with an array
   of rate information. */
typedef struct
{
	char const name;
	rate_info rates[MAX_RATE_PLANS];
} family_rate_info;


/*	@brief				Finds the family rate information given a family name.

	@param family_name	The name of the family that is requesting the
						baby sitter.

	@return				A pointer to the family_rate_info structure.
*/
family_rate_info const* getFamilyRates(char const family_name);


#endif