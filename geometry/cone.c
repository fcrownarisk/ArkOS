#include <stdio.h>
#include <math.h>

#define C 299792458 
// Speed of light in m/s

// Structure to represent a point in spacetime
typedef struct {
    double t; // Time coordinate (in seconds)
    double x, y, z; // Spatial coordinates (in meters)
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
            
            if (isInsideCone(p, cone)) {
                printf("C");
            } else if (isInsideLightCone(p)) {
                printf("L");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    printf("Cone within Light Cone Visualization\n");
    printf("====================================\n\n");

    Cone cone = {M_PI / 6, 1.0}; // 30 degree apex angle, 1 second height

    printf("Light Cone and Physical Cone Visualization:\n");
    printf("C: Physical Cone, L: Light Cone\n");
    printf("(vertical axis is time, horizontal is radial distance)\n\n");
    visualizeCones(20, cone);

    printf("\nChecking specific points:\n");
    SpacetimePoint p1 = {0.1, 0.2, 0, 0};
    SpacetimePoint p2 = {0.3, 0.4, 0, 0};
    SpacetimePoint p3 = {0.5, 0.6, 0, 0};

    printf("Point (%.1f, %.1f, 0, 0):\n", p1.t, p1.x);
    printf("  In Light Cone: %s\n", isInsideLightCone(p1) ? "Yes" : "No");
    printf("  In Physical Cone: %s\n\n", isInsideCone(p1, cone) ? "Yes" : "No");

    printf("Point (%.1f, %.1f, 0, 0):\n", p2.t, p2.x);
    printf("  In Light Cone: %s\n", isInsideLightCone(p2) ? "Yes" : "No");
    printf("  In Physical Cone: %s\n\n", isInsideCone(p2, cone) ? "Yes" : "No");

    printf("Point (%.1f, %.1f, 0, 0):\n", p3.t, p3.x);
    printf("  In Light Cone: %s\n", isInsideLightCone(p3) ? "Yes" : "No");
    printf("  In Physical Cone: %s\n", isInsideCone(p3, cone) ? "Yes" : "No");

    return 0;
}
