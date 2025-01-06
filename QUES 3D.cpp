#include <stdio.h>
#include <stdlib.h>

struct BankAccount {
    int balance;
};
void deposit(struct BankAccount* account, int amount) {
    account->balance += amount;
    printf("Deposited %d, New Balance: %d\n", amount, account->balance);
}
void withdraw(struct BankAccount* account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrew %d, New Balance: %d\n", amount, account->balance);
    } else {
        printf("Insufficient balance.\n");
    }
}

int main() {
    struct BankAccount account = {1000};

    deposit(&account, 500);
    withdraw(&account, 200);
    withdraw(&account, 1500);

    return 0;
}
