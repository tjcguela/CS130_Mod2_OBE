#include "player.h"

Player::Player() : health(100) {}

void Player::takeDamage(int damage) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "\t\033[31m" << "Attacking!!!\n\n"; 
    health -= damage;
    if (health < 0) health = 0;
}

void Player::heal(int heal) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "\t\033[32m" << "Healing...\n\n";
    //health += heal;
    if (health > 0)
    {
        health += heal;
    }
}

void Player::collectItem() {
    std::cout << "\t\033[33m"<< "Collecting item...";

    std::lock_guard<std::mutex> lock(mtx);
    static std::vector<std::string> items = { "POTION", "SWORD", "SHIELD", "ARMOR", "DRAGON SWORD"};
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<int> dis(0, items.size() - 1);
    inventory.push_back(items[dis(gen)]);
    
    std::cout << "item collected: " << items[dis(gen)] <<"\n";
    
    int goblin_num = dis(gen);

    if (inventory.size() > 0 && dis(gen) == goblin_num) // randomly lose items thru random num generator
    {
        std::cout << "\t\033[36m" << "Say bye to your items. The ITEM GOBLINS have stolen them...\n\n";
        inventory.clear();
    }

    
}

void Player::displayStatus() {
    std::cout << "\033[37m" << "\nCurrent Status: \n";

    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Health: " << health << "\nInventory: ";
    for (int iteration = 0; iteration < inventory.size(); iteration++)
    {
        if (iteration < inventory.size()-1)
        {
            std::cout << inventory[iteration] << ", ";
        }
        else
        {
            std::cout << inventory[iteration] <<".";
        }
    }

    /*for (const auto& item : inventory) {
        std::cout << item << ", ";
    }*/
    std::cout << "\n\n";
}

bool Player::isAlive() {
    std::lock_guard<std::mutex> lock(mtx);
    return health > 0;
}