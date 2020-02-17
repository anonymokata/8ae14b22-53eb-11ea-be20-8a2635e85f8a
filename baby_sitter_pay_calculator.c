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


static size_t calculatePay(size_t hours, size_t rate)
{
	/* Round to the nearest hour. */
	hours = ((hours % 100) ? hours + 100 : hours);
	return ((hours / 100) * rate);
}


size_t calculateBabySitterPay(char const familyName, size_t startTime, size_t stopTime)
{
	size_t sitterPay = 0;
	familyRateInfo const* familyRates;
	size_t idx, adjustedStart, adjustedStop;

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
						sitterPay += calculatePay(familyRates->rates[idx].stopTime - adjustedStart,
							familyRates->rates[idx].hourlyRate);

						/* Set the new start to be the end of the current period so the
						   next subtraction will not double count hours. */
						adjustedStart = familyRates->rates[idx].stopTime;
					}
				}
				else
				{
					sitterPay += calculatePay(adjustedStop - adjustedStart,
						familyRates->rates[idx].hourlyRate);
					break;
				}
			}
		}
	}

	return sitterPay;
}