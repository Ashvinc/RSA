#include <gmp.h>
#include <stdio.h>
#include <assert.h>

#define MAX_MESSAGE_SIZE 100000
int main(){
	
	char a[MAX_MESSAGE_SIZE];
	char b[100000];
	char c[100000];
	char d[100000];
	int length;
	int length2;
	int ascii;
	int k;
	int nsize;
	size_t n;
	
	printf("Enter your message : \n");
	fgets(a, MAX_MESSAGE_SIZE, stdin);
	/*
	for(length = 0; a[length] != '\0'; ++length);
	//printf("length of message: %d\n", length); 
	ascii = (int)a[0];
	snprintf(d, 100000, "%d", ascii);
	//printf("ascii of a[0]: %d\n", ascii);
	*/
	printf("Enter P*Q: \n");
	scanf("%99999s", b);
	for(nsize = 0; b[nsize] != '\0'; ++nsize);

	printf("Enter Encryption Key: \n");
	scanf("%99999s", c);

	mpz_t message;
	mpz_t ptq;
	mpz_t key;
	mpz_t mult;

	
	mpz_init(message);
	mpz_init(ptq);
	mpz_init(key);
	mpz_init(mult);
	printf("Your ciphertext is: \n");	
	for(length = 0; a[length] != '\n'; ++length){
	//printf("length of message: %d\n", length); 
	ascii = (int)a[length];
	snprintf(d, 100000, "%d", ascii);
	mpz_set_str(message, d, 10 );
	//mpz_out_str(stdout, 10, message);
	mpz_set_str(ptq, b, 10);
	mpz_set_str(key, c, 10);
	
	mpz_powm(mult, message, key, ptq);
/*
	for(length2 = 0; d[length2] != '\0'; ++length2)
	{
		if(length < nsize)
		{	
			printf("%d", 0);
		}
			
	}
*/	

	//printf("Your ciphertext is: \n");
	gmp_printf("%0*Zd", nsize, mult);
	//mpz_out_str(stdout, 10, mult);
	//printf("\n");
	}
	printf("\n");
	mpz_clear(mult);
	mpz_clear(message);
	mpz_clear(key);
	mpz_clear(mult);
	
}	
