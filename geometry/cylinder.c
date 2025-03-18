#include <stdio.h>
#include <math.h>
#include <unistd.h>

#define PI 3.1415926

// Structure to represent a cylinder
typedef struct {
    double radius;
    double height;
    double mass;
    double angular_velocity; // in radians per second
} Cylinder;

// Function to calculate moment of inertia
double moment_of_inertia(Cylinder c) {
    return 0.5 * c.mass * c.radius * c.radius;
}

// Function to calculate kinetic energy
double kinetic_energy(Cylinder c) {
    double I = moment_of_inertia(c);
    return 0.5 * I * c.angular_velocity * c.angular_velocity;
}

// Function to visualize spinning cylinder
void visualize_cylinder(Cylinder c, int frame) {
    int width = 20;
    int height = 10;
    char display[height][width];
    
    // Clear display
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            display[i][j] = ' ';
        }
    }
    
    // Draw cylinder outline
    for (int i = 0; i < height; i++) {
        display[i][0] = '|';
        display[i][width-1] = '|';
    }
    
    // Draw spinning line
    int line_pos = (int)(frame * c.angular_velocity * width / (2 * PI)) % width;
    for (int i = 0; i < height; i++) {
        display[i][line_pos] = '*';
    }
    
    // Print display
    printf("\033[2J\033[H"); // Clear screen and move cursor to top-left
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", display[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Cylinder c = {1.0, 2.0, 5.0, PI}; // radius 
    
    int frame = 0;
    while (1) {
        visualize_cylinder(c, frame);
        frame++;
        usleep(100000); // Sleep for 100ms
    }
    return 0;
}
