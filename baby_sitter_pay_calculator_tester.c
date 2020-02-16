#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "baby_sitter_pay_calculator.h"


static void whenBabySitterCalculatorIsPassedAnInvalidTimesItReturnsZero(void)
{
	/* Start and stop are the same */
	assert(calculateBabySitterPay(1701, 1701) == 0);

	/* Start is too late and midnight is 0, not 2400 */
	assert(calculateBabySitterPay(2400, 400) == 0);
	assert(calculateBabySitterPay(400, 400) == 0);

	/* Stop is too late and midnight is 0, not 2400 */
	assert(calculateBabySitterPay(1700, 2400) == 0);
	assert(calculateBabySitterPay(1700, 401) == 0);

	/* Start is earlier than the minimum */
	assert(calculateBabySitterPay(1659, 2359) == 0);
	assert(calculateBabySitterPay(400, 2359) == 0);
	assert(calculateBabySitterPay(1200, 2359) == 0);

	/* Stop is later than the maximum */
	assert(calculateBabySitterPay(359, 401) == 0);
	assert(calculateBabySitterPay(1700, 1700) == 0);
	assert(calculateBabySitterPay(0, 1200) == 0);
}


int main(void)
{
	whenBabySitterCalculatorIsPassedAnInvalidTimesItReturnsZero();

	return 0;
}