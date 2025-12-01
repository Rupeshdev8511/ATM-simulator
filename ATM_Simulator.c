#include <stdio.h>
#include <stdlib.h>

// FUNCTION PROTOTYPES
void displayMenu();
void checkBalance(float balance);
float depositMoney(float balance);
float withdrawMoney(float balance);

int main() {
    // VARIABLE DECLARATIONS
    int choice;
    float balance = 5000000.00; 
    int continueTransaction = 1;
    int pin = 1234; 
    int enteredPin;
    int pinAttempts = 0;
    
    printf("=== WELCOME TO SIMPLE ATM SIMULATOR ===\n\n");

    // PIN VERIFICATION SYSTEM
    while (pinAttempts < 3) {
        printf("Please enter your 4-digit PIN: ");
        scanf("%d", &enteredPin);
        
        if (enteredPin == pin) {
            printf("\nPIN verified successfully!\n");
            break;
        } else {
            pinAttempts++;
            printf("Invalid PIN! Attempts remaining: %d\n\n", 3 - pinAttempts);
        }
    }
    
    // SECURITY BLOCK AFTER 3 FAILED ATTEMPTS
    if (pinAttempts == 3) {
        printf("\nToo many incorrect attempts. Your card is blocked.\n");
        return 0;
    }
    
    // MAIN TRANSACTION LOOP
    while (continueTransaction) {
        displayMenu();
        printf("\nPlease select an option (1-4): ");
        scanf("%d", &choice);
        
        // MENU OPTION HANDLING
        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
                
            case 2:
                balance = depositMoney(balance);
                break;
                
            case 3:
                balance = withdrawMoney(balance);
                break;
                
            case 4:
                printf("\nThank you for using our ATM service!\n");
                printf("Please take your card.\n");
                continueTransaction = 0;
                break;
                
            default:
                printf("\nInvalid option! Please try again.\n");
                break;
        }
        
        // CONTINUE TRANSACTION PROMPT
        if (continueTransaction) {
            printf("\nDo you want to perform another transaction?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            printf("Enter your choice: ");
            scanf("%d", &continueTransaction);
            continueTransaction = (continueTransaction == 1) ? 1 : 0;
        }
    }
    
    return 0;
}

// FUNCTION TO DISPLAY MAIN MENU
void displayMenu() {
    printf("\n== ATM MAIN MENU ==\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

// FUNCTION TO CHECK ACCOUNT BALANCE
void checkBalance(float balance) {
    printf("\n== BALANCE INQUIRY ==\n");
    printf("Your current balance is: $%.2f\n", balance);
}

// FUNCTION TO HANDLE MONEY DEPOSITS
float depositMoney(float balance) {
    float amount;
    
    printf("\n== DEPOSIT MONEY ==\n");
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);
    
    if (amount > 0) {
        balance += amount;
        printf("Deposit successful!\n");
        printf("New balance: $%.2f\n", balance);
    } else {
        printf("Invalid amount! Please enter a positive value.\n");
    }
    return balance;
}

// FUNCTION TO HANDLE MONEY WITHDRAWALS
float withdrawMoney(float balance) {
    float amount;
    
    printf("\n=== WITHDRAW MONEY ===\n");
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
    } else if (amount > balance) {
        printf("Insufficient funds! Your balance is $%.2f\n", balance);
    } else {
        balance -= amount;
        printf("Withdrawal successful!\n");
        printf("Please take your cash: $%.2f\n", amount);
        printf("Remaining balance: $%.2f\n", balance);
    }
    return balance;
}