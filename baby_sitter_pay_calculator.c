#include <stdio.h>
#include <stdlib.h>
#include "baby_sitter_pay_calculator.h"
#include "baby_sitter_family_info.h"


/* Start and stop times for a standard 24 hour clock. */
#define EARLIEST_START_TIME				(1700)
#define LATEST_STOP_TIME				(400)
#define EARLIEST_TIME					(0)
#define LATEST_TIME						(2359)


static inline convertTo12HourBasedTime(size_t hour)
{
	/* This function normalizes the times so we can make sure the stop
	   time is after the start time. */
	return ((hour >= 1200) ? (hour - 1200) : (hour + 1200));
}


static size_t validateBabySittingTimes(size_t start_time, size_t stop_time)
{
	size_t validTimes = 0;

	if ((start_time != stop_time) &&
		(((start_time >= EARLIEST_START_TIME) && (start_time <= LATEST_TIME)) ||
			((start_time >= EARLIEST_TIME) && (start_time < LATEST_STOP_TIME))) &&
		(((stop_time > EARLIEST_START_TIME) && (stop_time <= LATEST_TIME)) ||
			((stop_time >= EARLIEST_TIME) && (stop_time <= LATEST_STOP_TIME))) &&
		(convertTo12HourBasedTime(start_time) < convertTo12HourBasedTime(stop_time)))
	{
		validTimes = 1;
	}

	return validTimes;
}


size_t calculateBabySitterPay(char const family_name, size_t start_time, size_t stop_time)
{
	size_t sitterPay = 0;
	family_rate_info const* familyRates;

	if ((sitterPay = validateBabySittingTimes(start_time, stop_time)) == 1)
	{
		if ((familyRates = getFamilyRates(family_name)) != NULL)
		{
			sitterPay = 1;
		}
		else
		{
			sitterPay = 0;
		}
	}

	printf("%s - sP: %u\n", __func__, sitterPay);
	return sitterPay;
}