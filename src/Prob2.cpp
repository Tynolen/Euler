#include <iostream>

int main()
{
	std::cout<<"Calulating sum of even Fibonacci numbers less than 4 million\n";
	int total=0;
	int prev=1;
	int fib=1;
	while(fib<4000000)
	{
		int temp=fib;
		if(fib%2==0) total+=fib;
		fib+=prev;
		prev=temp;
	}
	std::cout<<total<<'\n';
}
