#include <iostream>
#include <vector>
#include <thread>
#include "pi.h"

#ifndef MODE
    #define MODE 0 // 0 = single number  ——  1 = brute-force finding the number with the longest looping point
#else
    #define MODE 1
#endif // MODE

unsigned long firstPos(std::string str)
{
    for (unsigned long i {0}; i < PI.length(); ++i)
    {
		for (unsigned long j {0}, iTemp {i}; j < str.length(); ++j, ++iTemp)
			if (str[j] == PI[iTemp])
			{
				if (j == str.length() - 1)
					return i;
			}
			else
				break;
    }
    return 0;
}


unsigned long iterationsBeforeLoop(unsigned long number)
{
	std::vector<unsigned long> previousPos;
		
	for (int i {0}; true; ++i) {
		for (auto elt : previousPos)
			if (elt == number)
			{
				#if MODE == 0
					std::cout << "This number loops indefinitely after " << i << " iterations!" << std::endl;
				#endif // MODE
				return i;
			}
		previousPos.push_back(number);
		number = firstPos(std::to_string(number));
		#if MODE == 0
			std::cout << number << std::endl;
		#endif // MODE
	}
}


int main()
{
	#if MODE == 0
		unsigned long number;
		std::cout << "Enter the number to be checked: ";
		std::cin >> number;
		
		iterationsBeforeLoop(number);
	#endif // MODE
	
	
	#if MODE == 1
		unsigned long highestResitance = 0;
		for (int i {0}; i < 1'000'000; ++i)
		{
			unsigned long iBL = iterationsBeforeLoop(i);
			if (iBL > highestResitance)
			{
				std::cout << "Found new best!  " << i << " loops after " << iBL << " iterations!" << std::endl;
				highestResitance = iBL;
			}
		}
	#endif // MODE

    return 0;
}
