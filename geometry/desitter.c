#include <stdio.h>
#include <math.h>

#define C 299792458 // Speed of light in m/s
#define H 2.25e-18 // Hubble constant in s^-1 (approximation)

// Structure to represent a point in de Sitter space
typedef struct {
    double t; // Time coordinate
    double x, y, z; // Spatial coordinates
} DeSitterPoint;

// Function to calculate the de Sitter metric
double deSitterMetric(DeSitterPoint p) {
    double r2 = p.x*p.x + p.y*p.y + p.z*p.z;
    return -C*C*p.t*p.t + exp(2*H*p.t) * r2;
}

// Function to visualize space-time curvature
void visualizeCurvature(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            DeSitterPoint p = {i*0.1, j*0.1, 0, 0};
            double curvature = fabs(deSitterMetric(p));
            if (curvature < 1) printf(".");
            else if (curvature < 10) printf("o");
            else printf("O");
        }
        printf("\n");
    }
}

int main() {
    printf("De Sitter Space Representation\n");
    // Calculate metric for a specific point
    DeSitterPoint p = {1.0, 1.0, 1.0, 1.0};
    printf("De Sitter metric at point (%.1f, %.1f, %.1f, %.1f): %e\n\n\n\n", 
           p.t, p.x, p.y, p.z, deSitterMetric(p));

    // Visualize space-time curvature
    printf("Space-time curvature visualization:\n");
    visualizeCurvature(20);

    return 0;
