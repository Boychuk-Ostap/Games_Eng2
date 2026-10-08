Lab3 Report
Name: Ostap Boychuk
Student ID: C00301627

I set up Lab 3 in visual Studio as an x64 Debug console project. Google test was not installed, so i installed it 
with vcpkg and ran vcpkg integrate install so VS could find the headerts and libraries.

I opened lab3.slnx and added files to it. I set Additional Include Directories to $(ProjectDir)../src and added gtest.lib and
gtest_main.lib to te linker. 
The firs build failed with c1083 error. The inlcude used calculation.hpp and a path outside the Lab3 folder, 
so Calucator was undefined. I changed it to #include"src/calculator.hpp". Then replaced the four unfinished tests with EXPECT_EQ
check for negative addition, subtraction, equal inputs and adding zero.

GoogleTest scales better than a hand-written pass/fail counter. Each behaviour is its own test. 
FAIl of the test show the name of the case and the expected and actual values as new cases can be added without changing the runner. 