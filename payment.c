#include <stdio.h>

typedef struct
{
	char number [16];
	int exp_minth, exp_year, type, pin;
	account_t *account;
}
card_t;

typedef struct
{
	char name[200];
	int balance;
	card_t cards[4];
}
account_t;

double deposit(double how, account_t *acc);

int main()
{
	account_t account={"Kuci", 20000};
}

double deposit(double how, account_t *acc)
{
	acc->balance+=
}
