#include <stdio.h>

// Structure to represent a 3D position
typedef struct {
    int x;  // left/right
    int y;  // front/back
    int z;  // up/down
} Position;

// Function to move forward
void moveForward(Position *pos) {
    pos->y++;
}
// Function to move backward
void moveBackward(Position *pos) {
    pos->y--;
}
// Function to move left
void moveLeft(Position *pos) {
    pos->x--;
}
// Function to move right
void moveRight(Position *pos) {
    pos->x++;
}
// Function to move up
void moveUp(Position *pos) {
    pos->z++;
}
// Function to move down
void moveDown(Position *pos) {
    pos->z--;
}
// Function to print current position
void printPosition(Position pos) {
    printf("Current position: (%d, %d, %d)\n", pos.x, pos.y, pos.z);
}
// Function to visualize movement
void visualizeMovement(Position pos) {
    printf("Top-down view (x-y plane):\n");
    for (int i = -5; i <= 5; i++) {
        for (int j = -5; j <= 5; j++) {
            if (i == pos.x && j == pos.y) {
                printf("O");
            } else if (i == 0 && j == 0) {
                printf("+");
            } else if (i == 0) {
                printf("|");
            } else if (j == 0) {
                printf("-");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("Z-axis position: %d\n\n", pos.z);
}

int main() {
    Position currentPos = {0, 0, 0};  // Start at origin
    
    printPosition(currentPos);
    visualizeMovement(currentPos);

    // Demonstrate movements
    moveForward(&currentPos);
    moveBackward(&currentPos);
    printf("After moving forward:\n");
    printPosition(currentPos);
    visualizeMovement(currentPos);
    
    moveLeft(&currentPos);
    moveRight(&currentPos);
    printf("After moving right and up:\n");
    printPosition(currentPos);
    visualizeMovement(currentPos);
    
    moveUp(&currentPos);
    moveDown(&currentPos);
    printf("After moving backward, left, and down:\n");
    printPosition(currentPos);
    visualizeMovement(currentPos);

    return 0;
}
