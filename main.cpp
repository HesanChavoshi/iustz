#include <iostream>
#include <vector>
#include <conio.h>
#include "colors.hpp"
#include <cstdlib>

using namespace std;

#define UP_KEY 72
#define DOWN_KEY 80
#define ENTER_KEY 13

class Item {
public:
    string name;
    int price;

    Item(string n, int p) : name(n), price(p) {}
};

class Weapon : public Item {
public:
    Weapon(string n, int p) : Item(n, p) {}
};

class Consumable : public Item {
public:
  Consumable(string n, int p) : Item(n, p) {}
};

class Throwing : public Item {
public:
  Throwing(string n, int p) : Item(n, p) {}
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
    vector<Weapon> weapons;
    vector<Throwing> throwings;
    vector<Consumable> consumables;
    int warmWeaponSkill;
    int coldWeaponSkill;

public:
    Player(string name, int age, string gender) : Character(name, age, gender) {}

    string getSelectedWeapon() {
        return selectedWeapon;
    }

    int getWarmWeaponSkill() {
        return warmWeaponSkill;
    }

    int getBudget() {
        return budget;
    }

    int getColdWeaponSkill() {
        return coldWeaponSkill;
    }

    void setBudget(int budget) {
        this->budget = budget;
    }

    // void addToBackpack(Item weapon) {
    //     backpack.push_back(weapon);
    // }

    // void showBackpack() {

    //     cout << "your items:\n";

    //     for (int i = 1; i <= backpack.size(); i++)
    //     {
    //         cout << "["+to_string(i)+"]. " << backpack[i-1].name << "    ";
    //     }
        
    // }

    void chooseWeapon() {
        string n;
        cout << "choose your weapon\nEnter name\n";
        for (int i = 1; i <= weapons.size(); i++)
        {
            cout << "["+to_string(i)+"]. " << weapons[i-1].name << "    ";
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
    int budget;
    string selectedWeapon;
    vector<Weapon> backpack;

public:

    humanEnemy(int HP, int budget) : HP(HP), budget(budget) {}

    string getSelectedWeapon() {
        return selectedWeapon;
    }

    void setHP(int HP)
    {
        this->HP = HP;
    }

    int getHP()
    {
        return HP;
    }

    int getBudget() {
        return budget;
    }

    void addToBackpack(Weapon weapon) {
        backpack.push_back(weapon);
    }

    void chooseWeapon() {
        srand(time(0));

        int random = rand() % 5;

        if (random == 0)
        {
            selectedWeapon = "shotgun";
        }

        else if (random == 1)
        {
            selectedWeapon = "snipe";
        }

        else if (random == 2)
        {
            selectedWeapon = "gun";
        }
        
        else if (random == 3)
        {
            selectedWeapon = "sword";
        }
        
        else if (random == 4)
        {
            selectedWeapon = "knife1";
        }
        
    }
};

// class enemyView {

// public:
//     void displayEnemyDettails()
// };

// class enemyController {

// };

class Game {

    static int calculatePlayerDamage(Player& character) {

        if (character.getSelectedWeapon() == "shotgun") {
            return 20 + character.getWarmWeaponSkill() * 2;
        } 
        
        else if (character.getSelectedWeapon() == "snipe") {
            return 30 + character.getWarmWeaponSkill() * 3;
        } 
        
        else if (character.getSelectedWeapon() == "gun") {
            return 15 + character.getWarmWeaponSkill();
        }

        else if (character.getSelectedWeapon() == "sword") {
            return 15 + character.getColdWeaponSkill() * 2;
        }

        else if (character.getSelectedWeapon() == "knife1") {
            return 10 + character.getColdWeaponSkill();
        }

        else if (character.getSelectedWeapon() == "knife2") {
            return 10 + character.getColdWeaponSkill();
        }
    }
        
    static int calculateEnemyDamage(humanEnemy& enemy, Player& character) {

        if (enemy.getSelectedWeapon() == "shotgun") {
            return 20 + character.getLevel() * 2;
        } 
        
        else if (character.getSelectedWeapon() == "snipe") {
            return 30 + character.getLevel() * 3;
        } 
        
        else if (character.getSelectedWeapon() == "gun") {
            return 15 + character.getLevel();
        }

        else if (character.getSelectedWeapon() == "sword") {
            return 15 + character.getLevel() * 2;
        }

        else if (character.getSelectedWeapon() == "knife1") {
            return 10 + character.getLevel();
        }

        else if (character.getSelectedWeapon() == "knife2") {
            return 10 + character.getLevel();
        }
    }
        
    static void fight(Player& character) {

        humanEnemy enemy(50, 100);

        while (true)
        {
            int choice;
            cout << "Your turn: \nchoose to what happen";
            cout << "[1]. choose weapon [2]. attack [3]. upgrade your character\n";
            cin >> choice;

            if (choice == 1)
            {
                character.chooseWeapon();
            }
            else if (choice == 2)
            {
                cout << "Do you want to use throwing weapon?(y/n)\n";
                char a;
                cin >> a;

                if (a == 'y')
                {
                    
                }

                else
                {
                    int damage = calculatePlayerDamage(character);
                    enemy.setHP(enemy.getHP() - damage);
                    cout << "You dealt " << damage << " damage to the enemy." << endl;
                }
            }
            

            if (enemy.getHP() <= 0) {
                cout << "Congratulations! You defeated the enemy!" << endl;
                character.setBudget(character.getBudget() + enemy.getBudget());
                character.setlevel(character.getLevel() + 1);
                break;
            }

            cout << "Enemy's turn:" << endl;
            enemy.chooseWeapon();
            int damage = calculateEnemyDamage(enemy, character);
            character.setHP(character.getHP() - damage);

            if (character.getHP() <= 0) {
                cout << "Game over! You were defeated by the enemy." << endl;
                break;
            }

            cout << "Your HP: " << character.getHP() << endl;
            cout << "Enemy HP: " << enemy.getHP() << endl;
        }
        
    }
};



class Shop {
public:
    vector<Weapon> weapons;
    void addWeapon(Weapon weapon) {
        weapons.push_back(weapon);
    }

    vector<Consumable> consumables;
    void addConsumable(Consumable consumable) {
        consumables.push_back(consumable);
    }

    vector<Throwing> throwings;
    void addThrowing(Throwing throwing) {
        throwings.push_back(throwing);
    }

    void buyWeapon(Player& character) {
        int ch, SelectedOption = 0;
        while (true)
        {
            cout << "choose item with up and down key to buy:" << endl;
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
            ch = _getch();
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
                    character.decreaseBudget(bought.price);
                    character.addToBackpack(weapons[SelectedOption]);
                    weapons.erase(weapons.begin() + SelectedOption);
                    cout << "You bought a " << bought.name << " for " << bought.price << " dollars." << endl;

                    break;
                }
                else
                {
                        
                    cout << color::rize("not enough money" , "Light Yellow") << endl;
                    continue;
                }
                    
                
            }
            system("cls");
        }
        
    }

    void buyConsumable(Player& character) {
        int ch, SelectedOption = 0;
        while (true)
        {
            cout << "choose item with up and down key to buy:" << endl;
            for (int i = 0; i < consumables.size(); i++)
            {
                if (i == SelectedOption)
                {
                    cout << "-> "+consumables[i].name << "    "+to_string(consumables[i].price)+"$" << endl;
                }
                else
                {
                    cout << "   "+consumables[i].name << "    "+to_string(consumables[i].price)+"$" << endl;
                }
                
            }
            ch = _getch();
            if(ch == UP_KEY)
            {
                if(SelectedOption == 0)
                {
                    SelectedOption = consumables.size()-1;
                }
                else
                {
                    SelectedOption--;
                }
    
            }
            else if(ch == DOWN_KEY)
            {
                if(SelectedOption == consumables.size()-1)
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
                if (character.canAfford(consumables[SelectedOption].price))
                {
                    Consumable bought = consumables[SelectedOption];
                    character.decreaseBudget(bought.price);
                    character.addToBackpack(consumables[SelectedOption]);
                    consumables.erase(consumables.begin() + SelectedOption);
                    cout << "You bought a " << bought.name << " for " << bought.price << " dollars." << endl;

                    break;
                }
                else
                {
                        
                    cout << color::rize("not enough money" , "Light Yellow") << endl;
                    continue;
                }
                    
                
            }
            system("cls");
        }
        
    }

    void buyThrowing(Player& character) {
        int ch, SelectedOption = 0;
        while (true)
        {
            cout << "choose item with up and down key to buy:" << endl;
            for (int i = 0; i < throwings.size(); i++)
            {
                if (i == SelectedOption)
                {
                    cout << "-> "+throwings[i].name << "    "+to_string(throwings[i].price)+"$" << endl;
                }
                else
                {
                    cout << "   "+throwings[i].name << "    "+to_string(throwings[i].price)+"$" << endl;
                }
                
            }
            ch = _getch();
            if(ch == UP_KEY)
            {
                if(SelectedOption == 0)
                {
                    SelectedOption = throwings.size()-1;
                }
                else
                {
                    SelectedOption--;
                }
    
            }
            else if(ch == DOWN_KEY)
            {
                if(SelectedOption == throwings.size()-1)
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
                if (character.canAfford(throwings[SelectedOption].price))
                {
                    Throwing bought = throwings[SelectedOption];
                    character.decreaseBudget(bought.price);
                    character.addToBackpack(throwings[SelectedOption]);
                    throwings.erase(throwings.begin() + SelectedOption);
                    cout << "You bought a " << bought.name << " for " << bought.price << " dollars." << endl;

                    break;
                }
                else
                {
                        
                    cout << color::rize("not enough money" , "Light Yellow") << endl;
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