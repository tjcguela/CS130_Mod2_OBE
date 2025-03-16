#pragma once

#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <random>

class Player {
public:
    Player();
    void takeDamage(int damage);
    void heal(int heal);
    void collectItem();
    void displayStatus();
    bool isAlive();

private:
    int health;
    std::vector<std::string> inventory;
    std::mutex mtx;
};