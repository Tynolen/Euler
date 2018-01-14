#include <iostream>
#include <gmpxx.h>	//large number library
										//compile with g++ Prob3.cpp -lgmpxx -lgmp

class sieve
{
	private:
		mpz_t table;
		unsigned int size;

	public:
		sieve();
		int isPrime(mpz_class r);
		~sieve();
};

sieve::sieve()
{
	mpz_init(table);
	size=2;
}

int sieve::isPrime(mpz_class r)
{
	unsigned int rul = mpz_get_ui(r.get_mpz_t());

	if(size >= rul)
	{
		return !mpz_tstbit(table,rul);
	}
	else
	{
		unsigned int oldsize = size;
		size*=2;
		
		unsigned int i;
		for(i=2; i<=size; i++)
		{
			if(!mpz_tstbit(table,i))
			{
				unsigned int j;
				for(j=i*2; j<=size; j+=i)
				{
					mpz_setbit(table,j);
				}
			}
		}
		return !mpz_tstbit(table,rul);
	}
}

sieve::~sieve()
{
	mpz_clear(table);
}

int main()
{
	std::cout<<"Finding largest prime factor of 600851475143\n";

	sieve s;

	mpz_class value=600851475143;
	mpz_class value_sqrt;
	mpz_sqrt(value_sqrt.get_mpz_t(), value.get_mpz_t());

	unsigned long int i = mpz_get_ui(value_sqrt.get_mpz_t());
	for(i; i>0; i--)
	{
		mpz_class temp;
		mpz_set_ui(temp.get_mpz_t(), i);
		if(s.isPrime(temp))
		{
			if(mpz_fdiv_ui(value.get_mpz_t(), i)==0) std::cout<<temp<<'\n';
		}
	}

	//std::cout<<value<<"square root\t"<<value_sqrt<<"\n";

	return 0;
}
