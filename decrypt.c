#include <gmp.h>
#include <stdio.h>
#include <assert.h>

#define ARRAY_LENGTH 100000
int main(){
	
	char a[ARRAY_LENGTH];
	char b[ARRAY_LENGTH];
	char c[ARRAY_LENGTH];
	char d[ARRAY_LENGTH];
	int count;
	int nsize;
	int pos = 0;
	int length;
	int count2 = 0;
	int nsize1;
	int ascii;
	char toPrint;

	printf("Enter your ciphertext : \n");
	scanf("%9999s" , a);
	for(nsize1 = 0; a[nsize1] != '\0'; ++nsize1);

	printf("Enter P*Q: \n");
	scanf("%9999s", b);
	for(nsize = 0; b[nsize] != '\0'; ++nsize);


	printf("Enter Decryption Key: \n");
	scanf("%9999s", c);

	mpz_t ciphertext;
	mpz_t ptq;
	mpz_t key;
	mpz_t mult;
	nsize1 = nsize1/nsize;
	mpz_init(ciphertext);
	mpz_init(ptq);
	mpz_init(key);
	mpz_init(mult);
	printf("Your message is: \n");
	
	for(length = 0; length < nsize1; length++){	
	for(count = 0; count < nsize; count++)
	{
		d[count] = a[pos];
		pos++;
	}
	
	mpz_set_str(ciphertext, d, 10);
	mpz_set_str(ptq, b, 10);
	mpz_set_str(key, c, 10);
	
	mpz_powm(mult, ciphertext, key, ptq);
	ascii = mpz_get_ui(mult);
//	printf("Your message is: \n");
//	mpz_out_str(stdout, 10, mult);
	toPrint = (char)(ascii);
	printf("%c", toPrint);
	count2++;
	}
	printf("\n");
	mpz_clear(mult);
	mpz_clear(ciphertext);
	mpz_clear(key);
	mpz_clear(mult);
	
}	
