#include <iostream>
#include <vector>
#include <conio.h>
#include "colors.hpp"

using namespace std;

#define UP_KEY 72
#define DOWN_KEY 80
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

    int getHP()
    {
        return HP;
    }

    int getStamina()
    {
        return Stamina;
    }

    int getLevel()
    {
        return level;
    }

    

};


class Player : public Character {

protected:
    int budget;
    string selectedWeapon;
    vector<Weapon> backpack;
    int warmWeaponSkill;

public:
    Player(string name, int age, string gender) : Character(name, age, gender) {}

    void setBudget(int budget) {
        this->budget = budget;
    }

    void addToBackpack(Weapon weapon) {
        backpack.push_back(weapon);
    }

    void showBackpack() {

        cout << "your weapons:\n";

        for (int i = 1; i <= backpack.size(); i++)
        {
            cout << "["+to_string(i)+"]. " << backpack[i-1].name << "    ";
        }
        
    }

    void chooseWeapon() {
        string n;
        cout << "choose your weapon\nEnter name\n";
        for (int i = 1; i <= backpack.size(); i++)
        {
            cout << "["+to_string(i)+"]. " << backpack[i-1].name << "    ";
        }
        cout << endl;
        cin >> n;
        selectedWeapon = n;
    }

    bool canAfford(int price) {
        return budget >= price;
    }

    void decreaseBudget(int price) {
        budget -= price;
    }

    ~Player() {}
};

class humanEnemy {

protected:
    int HP;

public:
    // humanEnemy()
};

class enemyView {

public:
    // void displayEnemyDettails()
};

class enemyController {

};

void fight(Player& character, humanEnemy& enemy) {
    
}

class Shop {
public:
    vector<Weapon> weapons;
    void addWeapon(Weapon weapon) {
        weapons.push_back(weapon);
    }
    int ch, SelectedOption = 0;
    void buyWeapon(Player& character) {
        while (true)
        {
            cout << "choose weapon with up and down key to buy:" << endl;
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
        cout << "What do you want to buy? (enter number)" << endl << " [1]. Cold_warm_weapon    [2]. Consumings    [3]. Throwings  \n";
        cin >> choose;

        system("cls");

        if(choose == 1) {
            shop.buyWeapon(character1);
            system("cls");
            character1.chooseWeapon();
        }
        // else
        // {
        // }
        
    } else {
        exit(0);
    }

    return 0;
}