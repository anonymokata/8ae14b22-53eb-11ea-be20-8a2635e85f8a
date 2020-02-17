#include <stdio.h>
#include <stdlib.h>
#include "baby_sitter_pay_calculator.h"
#include "baby_sitter_family_info.h"


/* Start and stop times for a standard 24 hour clock. */
#define EARLIEST_START_TIME				(1700)
#define LATEST_STOP_TIME				(400)
#define EARLIEST_TIME					(0)
#define LATEST_TIME						(2359)


static size_t validateBabySittingTimes(size_t startTime, size_t stopTime)
{
	size_t validTimes = 0;

	if ((startTime != stopTime) &&
		(((startTime >= EARLIEST_START_TIME) && (startTime <= LATEST_TIME)) ||
			((startTime >= EARLIEST_TIME) && (startTime < LATEST_STOP_TIME))) &&
		(((stopTime > EARLIEST_START_TIME) && (stopTime <= LATEST_TIME)) ||
			((stopTime >= EARLIEST_TIME) && (stopTime <= LATEST_STOP_TIME))) &&
		(CONVERT_TO_12_HOUR(startTime) < CONVERT_TO_12_HOUR(stopTime)))
	{
		validTimes = 1;
	}

	return validTimes;
}


size_t calculateBabySitterPay(char const familyName, size_t startTime, size_t stopTime)
{
	size_t sitterPay = 0;
	familyRateInfo const* familyRates;
	size_t idx, adjustedStart, adjustedStop, numHours;

	if ((validateBabySittingTimes(startTime, stopTime)) == 1)
	{
		if ((familyRates = getFamilyRates(familyName)) != NULL)
		{
			adjustedStart = CONVERT_TO_12_HOUR(startTime);
			adjustedStop = CONVERT_TO_12_HOUR(stopTime);

			for (idx = 0; idx < MAX_RATE_PLANS; idx++)
			{
				if (adjustedStop > familyRates->rates[idx].stopTime)
				{
					/* Make sure the start time falls into this bucket. */
					if (adjustedStart < familyRates->rates[idx].stopTime)
					{
						numHours = familyRates->rates[idx].stopTime - adjustedStart;

						/* Round any fractional hour to a full hour in the
						   same rate plan. */
						if (numHours % 100)
						{
							numHours += 100;
						}

						sitterPay += (numHours / 100 ) * familyRates->rates[idx].hourlyRate;

						/* Set the new start to be the end of the current period so we can subtract*/
						adjustedStart = familyRates->rates[idx].stopTime;
					}
				}
				else
				{
					numHours = adjustedStop - adjustedStart;

					/* Round any fractional hour to a full hour in the
					   same rate plan. */
					if (numHours % 100)
					{
						numHours += 100;
					}

					sitterPay += (numHours / 100) * familyRates->rates[idx].hourlyRate;
					break;
				}
			}
		}
	}

	printf("%s - sP: %u\n", __func__, sitterPay);
	return sitterPay;
}