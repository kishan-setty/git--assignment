import random
import time

class Player:
    def __init__(self, name, health=100, attack=20, defense=10):
        self.name = name
        self.health = health
        self.attack = attack
        self.defense = defense
    
    def is_alive(self):
        return self.health > 0
    
    def attack_enemy(self, enemy):
        damage = self.attack - enemy.defense
        if damage < 0:
            damage = 0
        enemy.health -= damage
        print(f"{self.name} attacks {enemy.name} for {damage} damage!")
        if enemy.health <= 0:
            print(f"{enemy.name} is defeated!")

def battle(player1, player2):
    while player1.is_alive() and player2.is_alive():
        player1.attack_enemy(player2)
        if not player2.is_alive():
            break
        player2.attack_enemy(player1)
        time.sleep(1)
    if player1.is_alive():
        print(f"{player1.name} wins!")
    else:
        print(f"{player2.name} wins!")

def main():
    hero = Player("Hero")
    monster = Player("Monster", health=80, attack=25, defense=5)
    battle(hero, monster)

if __name__ == "__main__":
    main()
