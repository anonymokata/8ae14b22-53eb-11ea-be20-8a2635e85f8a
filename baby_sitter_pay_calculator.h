#ifndef _BABY_SITTER_PAY_CALCULATOR_H
#define _BABY_SITTER_PAY_CALCULATOR_H


/*	@brief				Calculates the baby sitter's pay for a night of work.

	@param start_time	The time the baby sitter is to start as	entered
						on a 24 hour clock format.  For instance,
						5AM would be 500 and 7:30PM would be 1930.
						Acceptable values are >= 1700 and <= 2359,
						and >= 0000 and <= 359.  Midnight is represented as 0.

	@param stop_time	The time the baby sitter is to stop as entered
						on a 24 hour clock format.  For instance,
						5AM would be 500 and 7:30PM would be 1930.
						Acceptable values are >= 1701 and <= 2359,
						and >= 0000 and <= 400.  Midnight is represented as 0.

	@return				The amount of pay the baby sitter will receive upon
						completion or 0 if the request is invalid.
*/
size_t calculateBabySitterPay(size_t start_time, size_t stop_time);


#endif