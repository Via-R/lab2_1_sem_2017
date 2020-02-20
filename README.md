# Long arithmetic and primality tests
This labwork consists of two parts:

 - Long arithmetic class - allows to add, subtract and multiply long numbers that are too long to be stored in ordinary variables
 - Primality tests class - checks if the entered number (an ordinary one, without long arithmetic support) is prime

## Long arithmetic
This part implements a class called XLong, which stores possibly large integer numbers in vectors with a specific base - max number to be stored in a vector. This class has two methods to be used to multiply XLong numbers: 

 1. Simple column multiplication (SimpleMult class)
 2. Karatsuba multiplication (KaratsubaMult class)

## Primality tests
This part implements a class called PrimalTest that contains four methods to check if a number is primal:

 1. Miller-Rabin method
 2. Lehmann method
 3. Lucas-Lehmer method
 4. Solovay-Strassen method
 
All of those methods are implemented as separate classes with corresponding names.

## How to test
In order to test the labwork, you need MS Visual Studio C++ installed, then clone the repository using

`git clone https://github.com/Via-R/lab2_sem1_2017.git` 

Then open the .sln file with MS Visual Studio and launch the project. The main script will read two lines from `input.txt` - they contain two numbers to be multiplied. Then the third line is read, it contains the expected answer which will be printed out to compare it to the results the program got. After that, the first two numbers are multiplied using two different methods that were mentioned before, and then their difference is calculated and printed out. 
After the multiplication is done, one more line is read - it contains a number, which primality should be tested. Then it is passed to each of the implemented methods and they print out their answer - whether the mentioned number is prime or not.

