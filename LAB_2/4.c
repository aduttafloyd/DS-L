#include <stdio.h>
#include <stdlib.h>

struct Account {
    int accNumber;
    float balance;
};

void addAccount(struct Account** acc, int* size) {
    struct Account* temp = (struct Account*)realloc(*acc, (*size + 1) * sizeof(struct Account));
    if(temp == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    *acc = temp;
    
    printf("Enter new account number: ");
    scanf("%d", &(*acc)[*size].accNumber);
    (*acc)[*size].balance = 0.0;
    (*size)++;
    printf("Account added successfully!\n");
}

void deposit(struct Account* acc, int size) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    for(int i = 0; i < size; i++) {
        if(acc[i].accNumber == accNum) {
            acc[i].balance += amount;
            printf("Balance updated successfully\n");
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw(struct Account* acc, int size) {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    for(int i = 0; i < size; i++) {
        if(acc[i].accNumber == accNum) {
            if(acc[i].balance >= amount) {
                acc[i].balance -= amount;
                printf("Balance updated successfully\n");
            } else {
                printf("Insufficient balance!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void balanceEnquiry(struct Account* acc, int size) {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    
    for(int i = 0; i < size; i++) {
        if(acc[i].accNumber == accNum) {
            printf("Balance: %.2f\n", acc[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

int main() {
    int size;
    printf("Enter number of accounts: ");
    scanf("%d", &size);
    
    struct Account* accounts = (struct Account*)malloc(size * sizeof(struct Account));
    if(accounts == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for(int i = 0; i < size; i++) {
        accounts[i].accNumber = i + 1000; 
        accounts[i].balance = 0.0;
    }

    int choice;
    while(1) {
        printf("\n1. Deposit\n2. Withdraw\n3. Balance Enquiry\n4. Add Account\n0. Exit\nChoice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: deposit(accounts, size); break;
            case 2: withdraw(accounts, size); break;
            case 3: balanceEnquiry(accounts, size); break;
            case 4: addAccount(&accounts, &size); break;
            case 0: free(accounts); return 0;
            default: printf("Invalid choice!\n");
        }
    }
}