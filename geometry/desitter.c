#include <stdio.h>
#include <math.h>
// Structure to represent a point in de Sitter space
typedef struct {
    double t; // Time coordinate
    double x, y, z; // Spatial coordinates
} DeSitterPoint;

double deSitterMetric(DeSitterPoint p) {
    double r2 = p.x*p.x + p.y*p.y + p.z*p.z;
    return -C*C*p.t*p.t + exp(2*H*p.t) * r2;
}

