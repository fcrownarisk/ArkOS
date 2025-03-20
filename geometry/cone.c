#include <stdio.h>
#include <math.h>

#define C 299792458 
// Structure to represent a point in spacetime
typedef struct {
    double t; // Time 
    double x, y, z; // Space
} SpacetimePoint;

// Structure to represent a cone
typedef struct {
    double apex_angle; // Apex angle of the cone in radians
    double height; // Height of the cone
} Cone;

// Function to check if a point is inside the light cone
int isInsideLightCone(SpacetimePoint p) {
    return fabs(p.t) >= sqrt(p.x*p.x + p.y*p.y + p.z*p.z) / C;
}

// Function to check if a point is inside the physical cone
int isInsideCone(SpacetimePoint p, Cone cone) {
    double r = sqrt(p.x*p.x + p.y*p.y);
    double tan_angle = tan(cone.apex_angle / 2);
    return r <= p.t * tan_angle && p.t >= 0 && p.t <= cone.height;
}

// Function to visualize the light cone and physical cone
void visualizeCones(int size, Cone cone) {
    for (int y = size-1; y >= 0; y--) {
        for (int x = 0; x < size; x++) {
            double t = (double)y / size * cone.height;
            double r = (double)x / size * cone.height * tan(cone.apex_angle / 2);
            SpacetimePoint p = {t, r, 0, 0};
            
            }
        }
    }
}

int ST(Point){
    SpaceTime p1 = {0.1, 0.2, 0, 0};
    SpaceTime p2 = {0.3, 0.4, 0, 0};
    SpaceTime p3 = {0.5, 0.6, 0, 0};
    SpaceTime p4 = {0.7, 0.8, 0, 0};
    SpaceTime p5 = {1.0,1.0,1.0,1.0};
    
    const p1 + p2 == p3 + p4 === p5;
    return 0; 
}
