//
//  main.cpp
//  Laba1_4sem
//
//  Created by Роман Перепонов on 09.02.2024.
//
#include <iostream>
using namespace std;

class cashRegister {
private:
    int cashOnHand;

public:
    cashRegister() {
        cashOnHand = 500;
    }

    cashRegister(int cashInput) {
        cashOnHand = cashInput;
    }

    int getCurrentBalance() const {
        return cashOnHand;
    }

    void acceptAmount(int amountIn) {
        cashOnHand += amountIn;
    }
};

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType() {
        numberOfItems = 50;
        cost = 50;
    }

    dispenserType(int items, int costIn) {
        numberOfItems = items;
        cost = costIn;
    }

    int getNoOfItems() const {
        return numberOfItems;
    }

    int getCost() const {
        return cost;
    }

    void makeSale() {
        
        numberOfItems--;
            
    }
};


void showSelection() {
    cout << "Здравствуйте!\n";
    cout << "1. Конфеты\n";
    cout << "2. Чипсы\n";
    cout << "3. Жвачка\n";
    cout << "4. Печенье\n";
    cout << "Выберите продукт, введя его номер: ";
}

void sellProduct(dispenserType& productDispenser, cashRegister& cash) {
    int cost = productDispenser.getCost();
    int balance = cash.getCurrentBalance();
    int cashInput;
    if (productDispenser.getNoOfItems() > 0) {
        cout << "Стоимость продукта: " << cost << "₽. Пожалуйста, внесите деньги: ";
        cin >> cashInput;
        if (cashInput >= cost) {
            if (balance >= cashInput - cost) {
                productDispenser.makeSale();
                cash.acceptAmount(cost);
                cout << "Заберите ваш продукт!\n";
                cout << "Ваша сдача: " << cashInput - cost << "₽.\n";
            } else {
                cout << "В автомате нет сдачи :(\nВнесите меньшую сумму.\n";
            }
        } else {
            cout << "Недостаточно денег. Внесите большую сумму.\n";
        }
    } else {
        cout << "Продукт закончился :(\n";
    }
}

int main() {
    cashRegister cash(1000);
    dispenserType sweets(200, 29), chips(50, 120), bubbleGum(100, 35), bisquits(25, 50);

    int choice;
    showSelection();
    cin >> choice;

    switch (choice) {
        case 1:
            sellProduct(sweets, cash);
            break;
        case 2:
            sellProduct(chips, cash);
            break;
        case 3:
            sellProduct(bubbleGum, cash);
            break;
        case 4:
            sellProduct(bisquits, cash);
            break;
        default:
            cout << "Неправильный выбор.\n";
            break;
    }

    return 0;
}
