#include <gmp.h>
#include <stdio.h>
#include <assert.h>


void gcd(mpz_t * output, mpz_t a, mpz_t b)
{
	mpz_t comp;
	mpz_init(comp);
	if (mpz_cmp_ui(b, 0) == 0)
	{
		mpz_set(*output, a);
	}
	
	else
	{
		mpz_mod(comp, a, b);
		gcd(output, b, comp);
	}
}

void xgcd(mpz_t * output, mpz_t a, mpz_t b)
{
	mpz_t aa0;
	mpz_t aa1;
	mpz_t bb0;
	mpz_t bb1;
	mpz_t product1;
	mpz_t product2;
	mpz_t q;
	mpz_t r;
	
	mpz_init(aa0);
	mpz_init(aa1);
	mpz_init(bb0);
	mpz_init(bb1);
	mpz_init(product1);
	mpz_init(product2);
	mpz_init(q);
	mpz_init(r);

	mpz_add_ui(aa0, aa0, 1);
	mpz_add_ui(bb1, bb1, 1);
	while(1)
	{	
		mpz_div(q, a, b);
		mpz_mod(a, a,b);
		mpz_mul(product1, q, aa1);
		mpz_mul(product2, q, bb1);
		mpz_sub(aa0, aa0, product1);
		mpz_sub(bb0, bb0, product2);
		if(mpz_cmp_si(a, 0) == 0)
		{
			mpz_set(*output, bb1);
			break;
		}
		mpz_div(q, b, a);
		mpz_mod(b, b, a);
		mpz_mul(product1, q, aa0);
		mpz_mul(product2, q, bb0);
		mpz_sub(aa1, aa1, product1);
		mpz_sub(bb1, bb1, product2);
		if(mpz_cmp_si(b, 0) == 0)
 		{
			mpz_set(*output, bb0);
			break;
		}
			
	}	
	


	mpz_clear(aa0);
	mpz_clear(aa1);
	mpz_clear(bb0);
	mpz_clear(bb1);
	mpz_clear(q);
	mpz_clear(r);
	mpz_clear(product1);
	mpz_clear(product2);
}
int main(){
	
	char firstPrime[1024];
	char secondPrime[1024];

	
	printf("Enter your first large prime: ");
	scanf("%1023s" , firstPrime);
	printf("Enter your second large prime: ");
	scanf("%1023s" , secondPrime);
	
	mpz_t p;	//first prime
	mpz_t q;	//second prime
	mpz_t N;	//large prime with only two factors
	mpz_t subtractp;
	mpz_t subtractq;
	mpz_t totient;
	mpz_t out;
	gmp_randstate_t state;
	gmp_randinit_default(state);
	mpz_t mult;
	mpz_t add;
	mpz_t modulo;
	mpz_t range;
	mpz_t encryption;
	mpz_t decryption;
	mpz_t k;
	mpz_t result;

	mpz_t random;

	mpz_t mod;

	mpz_t largeval;
	mpz_t temp;
	
	mpz_init(random);
	mpz_init(p);
	mpz_init(q);
	mpz_init(N);
	mpz_init(subtractp);
	mpz_init(subtractq);
	mpz_init(totient);
	mpz_init(mod);
	mpz_init(out);
	mpz_init(range);
	mpz_init(add);
	mpz_init(mult);
	mpz_init(modulo);
	mpz_init(encryption);
	mpz_init(decryption);
	mpz_init(largeval);
	mpz_init(k);
	mpz_init(result);
	mpz_init(temp);

	mpz_add_ui(k, k, 1);

	mpz_set_str(p, firstPrime, 10);
	mpz_set_str(q, secondPrime, 10);
	mpz_mul(N, p, q);
	
	mpz_sub_ui(subtractp, p, 1);
	mpz_sub_ui(subtractq, q, 1);
	mpz_mul(totient, subtractp, subtractq);

	mpz_mod(mod, p, q);

	gcd(&out, p, q);
	
	printf("first prime: \n");
	mpz_out_str(stdout, 10, p);
	printf("\n");

	printf("second prime: \n");
	mpz_out_str(stdout, 10, q);
	printf("\n");

	printf("N: \n");
	mpz_out_str(stdout, 10, N);
	printf("\n");
	
	printf("first prime minus 1: \n");
	mpz_out_str(stdout, 10, subtractp);
	printf("\n");

	printf("second prime minus 1: \n");
	mpz_out_str(stdout, 10, subtractq);
	printf("\n");

	printf("modulus: \n");
	mpz_out_str(stdout, 10, mod);
	printf("\n");
	
	printf("totient: \n");
	mpz_out_str(stdout, 10, totient);
	printf("\n");

	printf("gcd: \n");
	mpz_out_str(stdout, 10, out);
	printf("\n");

	//for encryption key
	mpz_sub_ui(range, totient, 2);

	mpz_urandomm(random, state, range);
	mpz_add_ui(random, random, 2);
	printf("random number: \n");
	mpz_out_str(stdout, 10, random);
	printf("\n");

	while(1)
	{
		gcd(&out, random, totient);
		if (mpz_cmp_si(out, 1) == 0)
		{
			mpz_add_ui(encryption, random, 0);
			break;
		}
		else
		{
			mpz_urandomm(random, state, range);
			mpz_add_ui(random, random, 2);
		}
	}

	printf("encryption key: \n");
	mpz_out_str(stdout, 10, encryption);
	printf("\n");

	mpz_set(temp, totient);
	xgcd(&result, temp, encryption);
	if(mpz_cmp_si(result, 0) < 0)
	{
		mpz_add(result, result, totient);
	}
	printf("decryption key2: \n");
	mpz_out_str(stdout, 10, result);
	printf("\n");
	
	mpz_clear(p);
	mpz_clear(q);
	mpz_clear(N);
	mpz_clear(mod);
	mpz_clear(subtractp);
	mpz_clear(subtractq);
	mpz_clear(totient);
	mpz_clear(out);
	gmp_randclear(state);
	mpz_clear(largeval);
	mpz_clear(random);
	mpz_clear(range);
	mpz_clear(encryption);
	mpz_clear(decryption);
	mpz_clear(add);
	mpz_clear(mult);
	mpz_clear(modulo);
	mpz_clear(k);
	mpz_clear(result);
	mpz_clear(temp);
}


	
