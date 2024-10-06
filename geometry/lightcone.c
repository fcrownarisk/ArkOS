#include <stdio.h>
#include <math.h>

#define C 299792458 // Speed of light in m/s

// Structure to represent an event in spacetime
typedef struct {
    double t; // Time coordinate (in seconds)
    double x, y, z; // Spatial coordinates (in meters)
} SpacetimeEvent;

// Function to calculate the spacetime interval between two events
double spacetimeInterval(SpacetimeEvent e1, SpacetimeEvent e2) {
    double dt = e2.t - e1.t;
    double dx = e2.x - e1.x;
    double dy = e2.y - e1.y;
    double dz = e2.z - e1.z;
    
    return -C*C*dt*dt + dx*dx + dy*dy + dz*dz;
}

// Function to determine the nature of the interval
const char* intervalNature(double interval) {
    if (interval < 0) return "Timelike";
    if (interval > 0) return "Spacelike";
    return "Lightlike";
}

// Function to visualize a 2D slice of the light cone
void visualizeLightCone(int size) {
    for (int y = -size/2; y < size/2; y++) {
        for (int x = -size/2; x < size/2; x++) {
            SpacetimeEvent origin = {0, 0, 0, 0};
            SpacetimeEvent event = {y, x, 0, 0}; // Using y for time to match visual orientation
            double interval = spacetimeInterval(origin, event);
            
            if (fabs(interval) < 0.5) printf("*"); // Light cone
            else if (interval < 0) printf("."); // Inside light cone
            else printf(" "); // Outside light cone
        }
        printf("\n");
    }
}

int main() {
    printf("Light Cone in Spacetime\n");
    printf("=======================\n\n");

    SpacetimeEvent origin = {0, 0, 0, 0};
    SpacetimeEvent event1 = {1, C*0.5, 0, 0}; // Timelike event
    SpacetimeEvent event2 = {1, C*2, 0, 0};   // Spacelike event
    SpacetimeEvent event3 = {1, C, 0, 0};     // Lightlike event

    printf("Spacetime intervals from origin (0,0,0,0):\n");
    printf("Event1 (1s, %.2fm, 0, 0): %.2f - %s\n", 
           C*0.5, spacetimeInterval(origin, event1), intervalNature(spacetimeInterval(origin, event1)));
    printf("Event2 (1s, %.2fm, 0, 0): %.2f - %s\n", 
           C*2, spacetimeInterval(origin, event2), intervalNature(spacetimeInterval(origin, event2)));
    printf("Event3 (1s, %.2fm, 0, 0): %.2f - %s\n\n", 
           C, spacetimeInterval(origin, event3), intervalNature(spacetimeInterval(origin, event3)));

    printf("2D Visualization of Light Cone:\n");
    printf("(vertical axis is time, horizontal is one spatial dimension)\n");
    visualizeLightCone(21);

    return 0;
}