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
