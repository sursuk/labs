
#include<iostream>
#include<ctime>

class Rational
{
	private:
		int m_numinator;
		int m_denominator;
	public:
		//its constructor
		Rational(int numinator, int denominator)
		{
			set(numinator, denominator);
		}
		//its constuctor of copy
		Rational(const Rational &rational) 
		{
			set(rational.m_numinator, rational.m_denominator);
		}

		// its assignment operator
		Rational& operator= (const Rational& rational)
		{
			m_numinator = rational.m_numinator;
			m_denominator = rational.m_denominator;

			return *this;
		}

		// its destructor
		~Rational() { std::cout << "destructor" << std::endl; }

		void set(int numerator, int denominator)
		{
			if (denominator != 0)
			{
				m_numinator = numerator;
				m_denominator = denominator;
			}
			else
				std::cout << "denominator = 0"<<std::endl;
		}

		void get()
		{
			std::cout << m_numinator<<"/"<< m_denominator << std::endl;
		}

		void plus(int numinator, int denuminator)
		{
			if (m_denominator != denuminator)
			{
				m_numinator *= denuminator;
				numinator *= m_denominator;
				m_denominator *= denuminator;
				m_numinator += numinator;
			}
			else
			{
				m_numinator += numinator;
			}
		}

		void minus(int numinator, int denuminator)
		{
			if (m_denominator != denuminator)
			{
				m_numinator *= denuminator;
				numinator *= m_denominator;
				m_denominator *= denuminator;
				m_numinator -= numinator;
			}
			else
			{
				m_numinator -= numinator;
			}
		}

		void multiply(int numinator, int denuminator)
		{
			m_denominator *= denuminator;
			m_numinator *= numinator;
		}

		void divide(int numinator, int denuminator)
		{
			m_denominator *= numinator;
			m_numinator *= denuminator;			
		}
};

int main()
{
	srand(time(0));
	int a;
	int b;
	std::cout << "this is testing programm" << std::endl << "-------------------------------" << std::endl;
	std::cout << "constructor test" << std::endl << "-------------------------------" << std::endl;
	a = rand(); std::cout << a << std::endl;
	b = rand(); std::cout << b << std::endl;
	Rational drob = Rational(a, b);
	drob.get();

	std::cout << "-------------------------------" << std::endl << "copy construct test" << std::endl << "-------------------------------" << std::endl;
	drob.get();
	Rational new_drob = Rational(drob);
	new_drob.get();

	std::cout << "-------------------------------" << std::endl << "assignment operator test" << std::endl << "-------------------------------" << std::endl;
	a = rand(); std::cout << a << std::endl;
	b = rand(); std::cout << b << std::endl;
	drob.set(a, b);
	Rational new_drob1 = Rational(rand(), rand());
	new_drob1 = drob;
	new_drob1.get();

	std::cout << "-------------------------------" << std::endl << "set test" << std::endl << "-------------------------------" << std::endl;
	a = rand(); std::cout << a << std::endl;
	b = rand(); std::cout << b << std::endl;
	drob.set(a, b);
	drob.get();

	std::cout << "-------------------------------" << std::endl << "plus test" << std::endl << "-------------------------------" << std::endl;
	a = rand(); std::cout << a << std::endl;
	b = rand(); std::cout << b << std::endl;
	drob.plus(a, b);
	drob.get();

	std::cout << "-------------------------------" << std::endl << "minus test" << std::endl << "-------------------------------" << std::endl;
	a = rand(); std::cout << a << std::endl;
	b = rand(); std::cout << b << std::endl;
	drob.minus(a, b);
	drob.get();

	std::cout << "-------------------------------" << std::endl << "multiply test" << std::endl << "-------------------------------" << std::endl;
	a = rand(); std::cout << a << std::endl;
	b = rand(); std::cout << b << std::endl;
	drob.multiply(a, b);
	drob.get();

	std::cout << "-------------------------------" << std::endl << "divide test" << std::endl << "-------------------------------" << std::endl;
	a = rand(); std::cout << a << std::endl;
	b = rand(); std::cout << b << std::endl;
	drob.divide(rand(), rand());
	drob.get();
	std::cout << "-------------------------------" << std::endl << "in this place destructor is  working " << std::endl << "-------------------------------" << std::endl;
	return 0;
}