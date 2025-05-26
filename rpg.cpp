#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int health;
    int attack;
    int defense;
} Player;

void print_player(const Player* p) {
    printf("Player: %s\nHealth: %d\nAttack: %d\nDefense: %d\n",
           p->name, p->health, p->attack, p->defense);
}

void battle(Player* p1, Player* p2) {
    printf("%s attacks %s!\n", p1->name, p2->name);
    int damage = p1->attack - p2->defense;
    if(damage < 0) damage = 0;
    p2->health -= damage;
    printf("%s takes %d damage, health now %d\n", p2->name, damage, p2->health);
}

int main() {
    Player players[MAX_PLAYERS];
    int player_count = 0;

    // Initialize some players (expand later)
    strcpy(players[0].name, "Hero");
    players[0].health = 100;
    players[0].attack = 25;
    players[0].defense = 10;
    player_count++;

    strcpy(players[1].name, "Monster");
    players[1].health = 80;
    players[1].attack = 20;
    players[1].defense = 5;
    player_count++;

    print_player(&players[0]);
    print_player(&players[1]);

    battle(&players[0], &players[1]);

    return 0;
}

