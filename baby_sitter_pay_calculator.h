#ifndef _BABY_SITTER_PAY_CALCULATOR_H
#define _BABY_SITTER_PAY_CALCULATOR_H


/*	@brief				Calculates the baby sitter's pay for a night of work.

	@param familyName	The name of the family that is requesting the
						baby sitter.

	@param startTime	The time the baby sitter is to start as	entered
						on a 24 hour clock format.  For instance,
						3:30AM would be 330 and 7:30PM would be 1930.
						Acceptable values are >= 1700 and <= 2359,
						and >= 0 and <= 359.  Midnight is represented as 0.
						Do NOT prepend any 0's, only append them.

	@param stopTime		The time the baby sitter is to stop as entered
						on a 24 hour clock format.  For instance,
						3:30AM would be 330 and 7:30PM would be 1930.
						Acceptable values are >= 1701 and <= 2359,
						and >= 0 and <= 400.  Midnight is represented as 0.
						Do NOT prepend any 0's, only append them.

	@return				The amount of pay the baby sitter will receive upon
						completion or 0 if the request is invalid.
*/
size_t calculateBabySitterPay(char const familyName, size_t startTime,
	size_t stopTime);


#endif