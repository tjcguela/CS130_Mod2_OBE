#include "player.h"
#include <iostream>
#include <thread>
#include <chrono>

void damageLoop(Player& player) {
    while (player.isAlive()) {
        player.takeDamage(10);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }
}

void healLoop(Player& player) {
    while (player.isAlive()) {
        player.heal(10);
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }
}

void collectLoop(Player& player) {
    while (player.isAlive()) {
        player.collectItem();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
}

int main() {
    Player player;
    std::thread damageThread(damageLoop, std::ref(player));
    std::thread healThread(healLoop, std::ref(player));
    std::thread collectThread(collectLoop, std::ref(player));

    while(true) {
        player.displayStatus();
        std::this_thread::sleep_for(std::chrono::seconds(5));

        if (!player.isAlive())
        {
            break;
        }
    }

    damageThread.join();
    healThread.join();
    collectThread.join();

    std::cout << "Player died. GG!\n";
    std::cout << "Game Over!\n";
    return 0;
}
