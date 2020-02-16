#include <stdio.h>
#include <stdlib.h>
#include "baby_sitter_pay_calculator.h"


/* Start and stop times for a standard 24 hour clock. */
#define EARLIEST_START_TIME				(1700)
#define LATEST_STOP_TIME				(400)
#define EARLIEST_TIME					(0)
#define LATEST_TIME						(2359)


static size_t validateInput(size_t start_time, size_t stop_time)
{
	size_t validRequest = 0;

	if ((start_time != stop_time) &&
		(((start_time >= EARLIEST_START_TIME) && (start_time <= LATEST_TIME)) ||
			((start_time >= EARLIEST_TIME) && (start_time < LATEST_STOP_TIME))) &&
		(((stop_time > EARLIEST_START_TIME) && (stop_time <= LATEST_TIME)) ||
			((stop_time >= EARLIEST_TIME) && (stop_time <= LATEST_STOP_TIME))))
	{
		validRequest = 1;
	}

	printf("%s - vR: %u\n", __func__, validRequest);
	return validRequest;
}


size_t calculateBabySitterPay(size_t start_time, size_t stop_time)
{
	return validateInput(start_time, stop_time);
}