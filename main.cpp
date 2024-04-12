#include <iostream>
#include <vector>
#include <conio.h>
#include "colors.hpp"

using namespace std;

#define UP_KEY 72
#define DOWN_KEY 80
#define Right_KEY 77
#define LEFT_KEY 75
#define ENTER_KEY 13

class Weapon {
public:
    string name;
    int price;
    Weapon(string n, int p) : name(n), price(p) {}
};

class Character {

protected:
    string name;
    int age;
    string gender;
    int HP;
    int Stamina;
    int level;

public:
    Character(string name, int age, string gender) : name(name), age(age), gender(gender) {}

    void setHP(int HP)
    {
        this->HP = HP;
    }
    
    void setStamina(int Stamina)
    {
        this->Stamina = Stamina;
    }

    void setlevel(int level)
    {
        this->level = level;
    }

};


class Player : public Character {

protected:
    int budget;
    vector<Weapon> backpack;

public:
    Player(string name, int age, string gender) : Character(name, age, gender) {}

    void setBudget(int budget) {
        this->budget = budget;
    }

    void addToBackpack(Weapon weapon) {
        backpack.push_back(weapon);
    }

    void showBackpack() {

        for (Weapon a : backpack)
        {
            cout << a.name;
        }
        
        
    }

    bool canAfford(int price) {
        return budget >= price;
    }

    void decreaseBudget(int price) {
        budget -= price;
    }

    ~Player() {}
};

class Shop {
public:
    vector<Weapon> weapons;
    void addWeapon(Weapon weapon) {
        weapons.push_back(weapon);
    }
    int ch, SelectedOption = 0;
    // Weapon buyWeapon(string name, Player& character) {
    //     for(int i = 0; i < weapons.size(); i++) {
    //         if(weapons[i].name == name && character.canAfford(weapons[i].price)) {
    //             Weapon bought = weapons[i];
                // weapons.erase(weapons.begin() + i);
                // character.decreaseBudget(bought.price);
                // character.addToBackpack(weapons[i]);
                // cout << "You bought a " << bought.name << " for " << bought.price << " dollars." << endl;
    //             return bought;
    //         }
    //     }
    //     cout << "Sorry, you either don't have enough money or we don't have that weapon in stock." << endl;
    //     return Weapon("", 0);
    // }
    void buyWeapon(Player& character) {
        while (true)
        {
            for (int i = 0; i < weapons.size(); i++)
            {
                if (i == SelectedOption)
                {
                    cout << "-> "+weapons[i].name << "    "+to_string(weapons[i].price)+"$" << endl;
                }
                else
                {
                    cout << "   "+weapons[i].name << "    "+to_string(weapons[i].price)+"$" << endl;
                }
                
            }
            ch = getch();
            if(ch == UP_KEY)
            {
                if(SelectedOption == 0)
                {
                    SelectedOption = weapons.size()-1;
                }
                else
                {
                    SelectedOption--;
                }
    
            }
            else if(ch == DOWN_KEY)
            {
                if(SelectedOption == weapons.size()-1)
                {
                    SelectedOption = 0;
                }
                else
                {
                    SelectedOption++;
                }
                
                }
                else if(ch == ENTER_KEY)
                {
                    system("cls");
                    if (character.canAfford(weapons[SelectedOption].price))
                    {
                        Weapon bought = weapons[SelectedOption];
                        weapons.erase(weapons.begin() + SelectedOption);
                        character.decreaseBudget(bought.price);
                        character.addToBackpack(weapons[SelectedOption]);
                        cout << "You bought a " << bought.name << " for " << bought.price << " dollars." << endl;

                        break;
                    }
                    else
                    {
                        // cout << "not enough budget\n";
                        cout << color::rize("not enough budget" , "Light Yellow") << endl;
                        continue;
                    }
                    
                
            }
            system("cls");
        }
        
    }
};


int main() {
    string name;
    int age;
    string gender;
    char ch;
    int choose;
    int budget;


    cout << "Hi welcome to IUSTZ ! Let's go to customize your character. " << endl << "Enter your name : ";
    cin >> name;
    cout << "Enter your age : ";
    cin >> age;
    cout << "Enter your gender : ";
    cin >> gender;

    system("cls");

    Player character1(name, age, gender);

    character1.setBudget(100);
    
    Shop shop;
    shop.addWeapon(Weapon("shotgun", 100));
    shop.addWeapon(Weapon("snipe", 150));
    shop.addWeapon(Weapon("gun", 80));
    shop.addWeapon(Weapon("sword", 100));
    shop.addWeapon(Weapon("knife1", 50));
    shop.addWeapon(Weapon("knife2", 50));

    cout << "Do you want to go to store?(y or n)" << endl;
    cin >> ch;

    if(ch == 'y') {
        cout << "What do you want to buy?(enter number)" << endl << " 1.Cold_warm_weapon    2.Consumings    3. Throwings  ";
        cin >> choose;

        if(choose == 1) {
            // string weaponName;
            // cout << "choose your weapon " << endl << "1.shotgun(100 $)  2.snipe(150 $)  3.gun(80 $)  4.sword(100 $)  5.knife1(50 $)  6.knife2(50 $)";
            // cin >> weaponName;
            // shop.buyWeapon(weaponName, character1);
            shop.buyWeapon(character1);
        }
    } else {
        exit(0);
    }

    return 0;
}