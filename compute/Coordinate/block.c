#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

// Structure to represent a point in spherical coordinates
typedef struct {
    double r;     // radial distance
    double theta; // polar angle (0 to π)
    double phi;   // azimuthal angle (0 to 2π)
} SphericalPoint;

// Structure to represent a point in Cartesian coordinates
typedef struct {
    double x, y, z;
} CartesianPoint;

// Function to convert spherical coordinates to Cartesian coordinates
CartesianPoint sphericalToCartesian(SphericalPoint sp) {
    CartesianPoint cp;
    cp.x = sp.r * sin(sp.theta) * cos(sp.phi);
    cp.y = sp.r * sin(sp.theta) * sin(sp.phi);
    cp.z = sp.r * cos(sp.theta);
    return cp;
}

// Function to create a fundamental block in spherical coordinates
void createSphericalBlock(SphericalPoint block[8], double r1, double r2, double theta1, double theta2, double phi1, double phi2) {
    block[0] = (SphericalPoint){r1, theta1, phi1};
    block[1] = (SphericalPoint){r2, theta1, phi1};
    block[2] = (SphericalPoint){r1, theta2, phi1};
    block[3] = (SphericalPoint){r2, theta2, phi1};
    block[4] = (SphericalPoint){r1, theta1, phi2};
    block[5] = (SphericalPoint){r2, theta1, phi2};
    block[6] = (SphericalPoint){r1, theta2, phi2};
    block[7] = (SphericalPoint){r2, theta2, phi2};
}

// Function to visualize the block (simple ASCII representation)
void visualizeBlock(SphericalPoint block[8]) {
    printf("Spherical Block Visualization (r-theta plane):\n");
    printf("  r2 +-----------------+\n");
    printf("     |                 |\n");
    printf("     |                 |\n");
    printf("  r1 +-----------------+\n");
    printf("     theta1           theta2\n\n");

    printf("Spherical Block Visualization (r-phi plane):\n");
    printf("  r2 +-----------------+\n");
    printf("     |                 |\n");
    printf("     |                 |\n");
    printf("  r1 +-----------------+\n");
    printf("     phi1             phi2\n");
}

int main() {
    printf("Fundamental Block in Spherical Coordinates\n");
    printf("=========================================\n\n");

    // Define the block parameters
    double r1 = 1.0, r2 = 2.0;
    double theta1 = PI/4, theta2 = PI/2;
    double phi1 = 0, phi2 = PI/2;

    // Create the block
    SphericalPoint block[8];
    createSphericalBlock(block, r1, r2, theta1, theta2, phi1, phi2);

    // Print block vertices
    printf("Block Vertices (Spherical Coordinates):\n");
    for (int i = 0; i < 8; i++) {
        printf("V%d: (r=%.2f, theta=%.2f, phi=%.2f)\n", i+1, block[i].r, block[i].theta, block[i].phi);
    }
    printf("\n");

    // Convert and print Cartesian coordinates
    printf("Block Vertices (Cartesian Coordinates):\n");
    for (int i = 0; i < 8; i++) {
        CartesianPoint cp = sphericalToCartesian(block[i]);
        printf("V%d: (x=%.2f, y=%.2f, z=%.2f)\n", i+1, cp.x, cp.y, cp.z);
    }
    printf("\n");

    // Visualize the block
    visualizeBlock(block);

    return 0;
}