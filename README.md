# BabySitterKata

This is a C implementation of the Baby Sitter Kata as described in the following link:
https://github.com/PillarTechnology/kata-babysitter

It was built with Microsoft Visual Studio Community 2019, Version 16.4.5.

# Execution Instructions for the Microsoft Visual Studio 2019 GUI:
    Open Microsoft Visual Studio 2019 and select 'Clone or check out code'.
    Enter 'https://github.com/luapsitnam/BabySitterKata' as the Repository location and select 'Clone'.
    Right click on the BabySitterKata.sln file in the Solution Explorer and select Clean.
    Right click on the BabySitterKata.sln file in the Solution Explorer and select Build.
    Right click on the BabySitterKata.vcxproj file in the Solution Explorer and select Debug.
    
# Execution Instruction for the Microsoft Visual Studio 19 Developer Command Prompt:
    Open Microsoft Visual Studio 2019 and select 'Clone or check out code'.
    Enter 'https://github.com/luapsitnam/BabySitterKata' as the Repository location and select 'Clone'.
    Open a developer command prompt.
    In the prompt window, navigate to the location where the BabySitterKata.vcxproj file is located.
    Type msbuild BabySitterKata.vcxproj and you should see a "Build succeeded" message with build information above it.
    Type 'cd Debug'.
    Type 'BabySitterKata'.
   
After executing, there should be no assertions and the following text "All Baby Sitter Calculator Tests Passed!" is printed.

# Implementation Assumptions:
    Any fractional hour was rounded up to an hour of pay.
        For instance if 1 minute was worked, it was rounded up to 1 hour of that rate plan.
    Times must be entered as a 24 clock with 0 being midnight and not 2400.
    Entered times must not include beginning zeros but must include appending zeros.
        For instance, 12:30AM is 30 and 12:01 is 1.  6:00PM is 1800 and 11:36PM is 2336.
    
The test cases live in baby_sitter_pay_calculator_tester.c.
