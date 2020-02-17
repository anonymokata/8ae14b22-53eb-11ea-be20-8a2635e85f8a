# BabySitterKata

This is a C implementation of the Baby Sitter Kata as described in the following link:
https://github.com/PillarTechnology/kata-babysitter

It was built with Microsoft Visual Studio Community 2019, Version 16.4.5.

To run the program, download or clone the solution into Microsoft Visual Studio 2019.
    Right click on the BabySitterKata.sln file in the Solution Explorer and select Clean.
    Right click on the BabySitterKata.sln file in the Solution Explorer and select Build.
    Right click on the BabySitterKata.vcxproj file in the Solution Explorer and select Debug.

After executing, there should be no assertions and the following text "All Baby Sitter Calculator Tests Passed!" is printed.

There were some assumptions I made to implement this:
    Any fractional hour was rounded up to an hour of pay.
        For instance if 1 minute was worked, it was rounded up to 1 hour of that rate plan.
    Times must be entered as a 24 clock with 0 being midnight and not 2400.
    Entered times must not include beginning zeros but must include appending zeros.
        For instance, 12:30AM is 30 and 12:01 is 1.  6:00PM is 1800 and 11:36PM is 2336.
    
The test cases live in baby_sitter_pay_calculator_tester.c.
