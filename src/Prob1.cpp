#include <iostream>

int main()
{
	std::cout<<"Calculating the sum of all multiples of 3 or 5 below 1000...\n";

	int total=0;
	for(int i=0;i<1000;i++)
	{
		if(i%3==0 || i%5==0) total+=i;	//brute force it by checking every number
	}
	std::cout<<total<<'\n';
	return 0;
}
