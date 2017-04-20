/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/


#include<iostream>
#include<string>

using namespace std;

bool isPrime(int a);

int rotate(string number);

bool isCircular(int a);

int main()
{
	int total = 1;
	for (int i = 3; i < 1000000; i += 2)
	{
		if (isCircular(i))
		{
			total++;
		}
	}
	cout << total << endl;
	system("pause");
	return 0;
}

//Checks to see if a number is prime
bool isPrime(int a)
{
	if (a <= 1)
	{
		return false;
	}
	else if (a == 2)
	{
		return true;
	}
	else if (a % 2 == 0)
	{
		return false;
	}
	else
	{
		bool prime = true;
		int divisor = 3;
		double num_d = static_cast<double>(a);
		int upperLimit = static_cast<int>(sqrt(num_d) + 1);
		while (divisor <= upperLimit)
		{
			if (a % divisor == 0)
			{
				prime = false;
				break;
			}
			divisor += 2;
		}
		return prime;
	}
}


//Wraps around the current prime number
int rotate(string number)
{
	char temp = number[number.size() - 1];

	for (int i = number.size() - 2; i >= 0; i--)
	{
		number[i + 1] = number[i];
	}

	number[0] = temp;
	int num = 0;
	for (int i = 0; i < number.size(); i++)
	{
		num *= 10;
		num += (number[i] - '0');
	}
	return num;
}

//Checks to see if the number is a circular prime
bool isCircular(int a)
{
	string number = to_string(a);
	int counter = number.size() - 1;
	if (number.size() == 1 && isPrime(a))
	{
		return true;
	}
	else
	{
		while (counter >= 0)
		{
			if (isPrime(a))
			{
				a = rotate(number);
				number = to_string(a);
				counter--;
			}
			else
			{
				return false;
			}
			
		}
		return true;
	}
}