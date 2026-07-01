#include <stdio.h>

struct Player {
    char name[50];
    int level;
    int health;
};

// TODO: Step 1
// Write the function prototype for 'levelUp'. 
// It should return 'void' and take a POINTER to a 'struct Player'.

void levelUp(struct Player *player);

int main() {
    struct Player myPlayer = {"Alex", 1, 100};

    printf("Before: Level %d, Health %d\n", myPlayer.level, myPlayer.health);

    // TODO: Step 2
    // Call your 'levelUp' function here.
    // Remember to pass the memory address of 'myPlayer', not a copy!
    levelUp(&myPlayer);

    // If you did it right, this second printf will show Level 2 and Health 120
    printf("After: Level %d, Health %d\n", myPlayer.level, myPlayer.health);

    return 0;
}

void levelUp(struct Player *player)
{
    player->health += 20;
    player->level += 1;
}
// TODO: Step 3
// Write the actual 'levelUp' function down here.
// Inside, increase the player's level by 1 and health by 20.
// Hint: Because you have a pointer to the struct, the standard dot (.) operator won't work anymore!