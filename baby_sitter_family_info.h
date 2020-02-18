#ifndef _BABY_SITTER_FAMILY_INFO_H
#define _BABY_SITTER_FAMILY_INFO_H


/* This will make it easier to subtract times that span over night.
   It will make the later time greater than the earlier time. */
#define CONVERT_TO_12_HOUR(hour) ((hour >= 1200) ? (hour - 1200) : (hour + 1200))


/* The maximum number of different rates allowed per family.  */
#define MAX_RATE_PLANS	(3)


/* The different rates that a family can have.  A family has to have at
   least one of these and can have multiple. */
typedef struct
{
	size_t hourlyRate;
	size_t startTime;
	size_t stopTime;
} rateInfo;


/* The family rate information which consists of a name along with an array
   of rate information. */
typedef struct
{
	char const name;
	rateInfo rates[MAX_RATE_PLANS];
} familyRateInfo;


/*	@brief				Finds the family rate information given a family name.

	@param familyName	The name of the family that is requesting the
						baby sitter.

	@return				A pointer to the familyRateInfo structure.
*/
familyRateInfo const* getFamilyRates(char const familyName);


#endif