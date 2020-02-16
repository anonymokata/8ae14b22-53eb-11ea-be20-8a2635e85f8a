#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "baby_sitter_pay_calculator.h"


static void whenBabySitterCalculatorIsPassedAnInvalidTimesItReturnsZero(void)
{
	/* Start and stop are the same */
	assert(calculateBabySitterPay('A', 1701, 1701) == 0);

	/* Start is too late and midnight is 0, not 2400 */
	assert(calculateBabySitterPay('A', 2400, 400) == 0);
	assert(calculateBabySitterPay('A', 400, 400) == 0);

	/* Stop is too late and midnight is 0, not 2400 */
	assert(calculateBabySitterPay('A', 1700, 2400) == 0);
	assert(calculateBabySitterPay('A', 1700, 401) == 0);

	/* Start is earlier than the minimum */
	assert(calculateBabySitterPay('A', 1659, 2359) == 0);
	assert(calculateBabySitterPay('A', 400, 2359) == 0);
	assert(calculateBabySitterPay('A', 1200, 2359) == 0);

	/* Stop is later than the maximum */
	assert(calculateBabySitterPay('A', 359, 401) == 0);
	assert(calculateBabySitterPay('A', 1700, 1700) == 0);
	assert(calculateBabySitterPay('A', 0, 1200) == 0);

	/* Make sure the start time is before the end time */
	assert(calculateBabySitterPay('A', 200, 2359) == 0);
	assert(calculateBabySitterPay('A', 100, 1) == 0);
}


static void whenBabySitterCalculatorIsPassedAnInvalidFamilyNameItReturnsZero(void)
{
	assert(calculateBabySitterPay((char const)NULL, 1700, 2359) == 0);
}

static void whenBabySitterCalculatorIsPassedValidParametersItReturnsOne(void)
{
	assert(calculateBabySitterPay('A', 1700, 2359) == 1);
	assert(calculateBabySitterPay('A', 1700, 400) == 1);
	assert(calculateBabySitterPay('A', 2359, 359) == 1);
	assert(calculateBabySitterPay('A', 1700, 1701) == 1);
	assert(calculateBabySitterPay('A', 359, 400) == 1);
}


int main(void)
{
	whenBabySitterCalculatorIsPassedAnInvalidTimesItReturnsZero();
	whenBabySitterCalculatorIsPassedAnInvalidFamilyNameItReturnsZero();
	whenBabySitterCalculatorIsPassedValidParametersItReturnsOne();

	return 0;
}