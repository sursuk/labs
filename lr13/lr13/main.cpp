//Создайте класс Time с операциями + (int), +=(int), =, == , != , > , < , >= , <= , ++, --. (int)-секунды.

#include<iostream>
#include<ctime>

class Time
{
private:
	int sec;
public:
	Time(int second) { sec = second; }
	friend std::ostream& operator<< (std::ostream& out, const Time& time);
	friend std::istream& operator>> (std::istream& in, Time& time);

	int operator+ (int val) { return sec + val; }
	int operator+= (int val) { return sec += val; }
	int operator= (int val) { return sec = val; }

	bool operator== (int val) { return sec == val; }
	bool operator!= (int val) { return sec != val; }
	bool operator> (int val) { return sec > val; }
	bool operator< (int val) { return sec < val; }
	bool operator>= (int val) { return sec >= val; }
	bool operator<= (int val) { return sec <= val; }

	Time operator++ (int val)
	{
		sec++;
		return *this;
	}
	Time operator-- (int val)
	{
		sec--;
		return *this;
	}
};

	std::ostream& operator<< (std::ostream& out, const Time& time)
	{
		out << "sec = " << time.sec << std::endl;
		return out;
	}
	std::istream& operator>> (std::istream& in, Time& time)
	{
		in >> time.sec;
		return in;
	}

int main()
{
	srand(time(0));
	int randnum = rand();
	std::cout << "---constructor test---" << std::endl;
	Time time = Time(randnum);
	std::cout << "input number" << randnum << std::endl;
	std::cout << time << std::endl;

	std::cout << "---operator + test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " + " << randnum << " = " << time + randnum << std::endl;
	std::cout << time << std::endl;

	std::cout << "---operator += test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " += " << randnum << std::endl;
	time += randnum;
	std::cout << time << std::endl;

	std::cout << "---operator = test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " = " << randnum << std::endl;
	time = randnum;
	std::cout << time << std::endl;

	std::cout << "---operator == test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " == " << randnum << "|";
	if (time == randnum)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << time << std::endl;

	std::cout << "---operator != test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " != " << randnum << "|";
	if (time != randnum)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << time << std::endl;

	std::cout << "---operator > test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " > " << randnum << "|";
	if (time > randnum)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << time << std::endl;

	std::cout << "---operator < test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " < " << randnum << "|";
	if (time < randnum)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << time << std::endl;
	
	std::cout << "---operator >= test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " >= " << randnum << "|";
	if (time >= randnum)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << time << std::endl;

	std::cout << "---operator <= test---" << std::endl;
	randnum = rand();
	std::cout << "input number: " << randnum << std::endl;
	std::cout << time << " <= " << randnum << "|";
	if (time <= randnum)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	std::cout << time << std::endl;

	std::cout << "---operator ++ test---" << std::endl;
	std::cout << time << "++" << std::endl;
	time++;
	std::cout << time << std::endl;

	std::cout << "---operator -- test---" << std::endl;
	std::cout << time << "--" << std::endl;
	time--;
	std::cout << time << std::endl;

	return 0;
}
