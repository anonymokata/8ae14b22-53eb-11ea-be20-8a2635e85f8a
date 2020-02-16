#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "baby_sitter_pay_calculator.h"


static void whenBabySitterCalculatorIsPassedAnyTimeValuesItReturns1(void)
{
	assert(calculateBabySitterPay(1, 2) == 1);
}


int main(void)
{
	whenBabySitterCalculatorIsPassedAnyTimeValuesItReturns1();

	return 0;
}