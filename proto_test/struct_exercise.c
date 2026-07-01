#include <stdio.h>

// 1. Here is our struct definition. It groups our variables together.
struct Player {
    char name[50];
    int health;
    int score;
};

// void    displayStats(struct Player);
// // TODO: Step 1
// // Write the function prototype here. 
// // It should return 'void', be named 'displayStats', and take a 'struct Player' as its parameter.


// int main() {
//     // We create a player and give them some starting stats
//     struct Player myPlayer = {"Alex", 100, 500};

//     // TODO: Step 2
//     // Call your 'displayStats' function here and pass 'myPlayer' into it.
//     displayStats(myPlayer);

//     return 0;
// }

// // TODO: Step 3
// // Write the actual 'displayStats' function down here.
// // Inside the function, use printf() to print the player's name, health, and score.
// // Hint: You access variables inside a struct using the dot (.) operator!

// void displayStats(struct Player player)
// {
//     printf("player_name = %s, health = %d, score = %d", player.name, player.health, player.score);
// }

// 1. The function takes a POINTER to a struct (notice the *)
void takeDamage(struct Player *player) {
    // 2. We use the arrow operator (->) to access and modify the original data
    player->health -= 100; 
    printf("%s took damage! Health is now %d\n", player->name, player->health);
}

int main() {
    struct Player myPlayer = {"Walid", 100, 500};
    
    // 3. We pass the MEMORY ADDRESS of myPlayer (notice the &)
    takeDamage(&myPlayer); 
    
    return 0;
}