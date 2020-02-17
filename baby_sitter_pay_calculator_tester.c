#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "baby_sitter_pay_calculator.h"


static void whenBabySitterCalculatorIsPassedInvalidTimesItReturnsZero(void)
{
	/* Start and stop are the same */
	assert(calculateBabySitterPay('A', 1701, 1701) == 0);

	/* Start is too late and midnight is 0, not 2400 */
	assert(calculateBabySitterPay('B', 2400, 400) == 0);
	assert(calculateBabySitterPay('C', 400, 400) == 0);

	/* Stop is too late and midnight is 0, not 2400 */
	assert(calculateBabySitterPay('A', 1700, 2400) == 0);
	assert(calculateBabySitterPay('B', 1700, 401) == 0);

	/* Start is earlier than the minimum */
	assert(calculateBabySitterPay('C', 1659, 2359) == 0);
	assert(calculateBabySitterPay('A', 400, 2359) == 0);
	assert(calculateBabySitterPay('B', 1200, 2359) == 0);

	/* Stop is later than the maximum */
	assert(calculateBabySitterPay('C', 359, 401) == 0);
	assert(calculateBabySitterPay('A', 1700, 1700) == 0);
	assert(calculateBabySitterPay('B', 0, 1200) == 0);

	/* Make sure the start time is before the end time */
	assert(calculateBabySitterPay('C', 200, 2359) == 0);
	assert(calculateBabySitterPay('A', 100, 1) == 0);
}


static void whenBabySitterCalculatorIsPassedAnInvalidFamilyNameItReturnsZero(void)
{
	assert(calculateBabySitterPay((char const)NULL, 1700, 2359) == 0);
	assert(calculateBabySitterPay('D', 1700, 2359) == 0);
	assert(calculateBabySitterPay('F', 1700, 2359) == 0);
	assert(calculateBabySitterPay('G', 1700, 2359) == 0);
}


static void whenBabySitterCalculatorIsPassedOneHourItReturnsTheRateXOne(void)
{
	assert(calculateBabySitterPay('A', 1700, 1800) == 15);
	assert(calculateBabySitterPay('B', 1700, 1800) == 12);
	assert(calculateBabySitterPay('C', 1700, 1800) == 21);
}


static void whenBabySitterCalculatorIsPassedMultipleHoursInOneRate(void)
{
	assert(calculateBabySitterPay('A', 1800, 2300) == 75);
	assert(calculateBabySitterPay('A', 2300, 300) == 80);

	assert(calculateBabySitterPay('B', 1900, 2200) == 36);
	assert(calculateBabySitterPay('B', 2300, 0) == 8);
	assert(calculateBabySitterPay('B', 100, 300) == 32);

	assert(calculateBabySitterPay('C', 1700, 2000) == 63);
	assert(calculateBabySitterPay('C', 2200, 200) == 60);
}


static void whenBabySitterCalculatorIsPassedTimesThatSpanRates(void)
{
	assert(calculateBabySitterPay('A', 2200, 0) == 35);
	assert(calculateBabySitterPay('A', 1800, 200) == 135);
	assert(calculateBabySitterPay('A', 1700, 400) == 190);

	assert(calculateBabySitterPay('B', 2100, 2300) == 20);
	assert(calculateBabySitterPay('B', 2300, 100) == 24);
	assert(calculateBabySitterPay('B', 1700, 400) == 140);

	assert(calculateBabySitterPay('C', 2000, 2200) == 36);
	assert(calculateBabySitterPay('C', 1700, 0) == 129);
	assert(calculateBabySitterPay('C', 1700, 400) == 189);
}


static void whenBabySitterCalculatorIsPassedFractionalHoursItShouldRoundToFullHoursSingleRate(void)
{
	assert(calculateBabySitterPay('A', 30, 145) == 40);
	assert(calculateBabySitterPay('A', 1700, 1701) == 15);

	assert(calculateBabySitterPay('B', 1700, 2104) == 60);
	assert(calculateBabySitterPay('B', 2222, 2323) == 16);
	assert(calculateBabySitterPay('B', 201, 300) == 16);

	assert(calculateBabySitterPay('C', 1910, 2011) == 42);
	assert(calculateBabySitterPay('C', 2206, 2307) == 30);
}


static void whenBabySitterCalculatorIsPassedFractionalHoursItShouldRoundToFullHoursMultipleRateSpan(void)
{
	assert(calculateBabySitterPay('A', 2230, 2301) == 35);
	assert(calculateBabySitterPay('A', 1701, 359) == 190);

	assert(calculateBabySitterPay('B', 1829, 2245) == 56);
	assert(calculateBabySitterPay('B', 2222, 159) == 48);
	assert(calculateBabySitterPay('B', 1745, 352) == 140);

	assert(calculateBabySitterPay('C', 2015, 15) == 81);
	assert(calculateBabySitterPay('C', 1759, 301) == 189);
}


int main(void)
{
	whenBabySitterCalculatorIsPassedInvalidTimesItReturnsZero();
	whenBabySitterCalculatorIsPassedAnInvalidFamilyNameItReturnsZero();
	whenBabySitterCalculatorIsPassedOneHourItReturnsTheRateXOne();
	whenBabySitterCalculatorIsPassedMultipleHoursInOneRate();
	whenBabySitterCalculatorIsPassedTimesThatSpanRates();
	whenBabySitterCalculatorIsPassedFractionalHoursItShouldRoundToFullHoursSingleRate();
	whenBabySitterCalculatorIsPassedFractionalHoursItShouldRoundToFullHoursMultipleRateSpan();

	printf("All Baby Sitter Calculator Tests Passed!\n");
	return 0;
}