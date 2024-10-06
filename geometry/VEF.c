#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Structure to represent a polyhedron
typedef struct {
    int vertices;
    int edges;
    int faces;
} Polyhedron;

// Function to create a polyhedron
Polyhedron createPolyhedron(int v, int e, int f) {
    Polyhedron p = {v, e, f};
    return p;
}

// Function to verify Euler's equation
bool verifyEulerEquation(Polyhedron p) {
    return (p.vertices - p.edges + p.faces == 2);
}

// Function to print polyhedron details
void printPolyhedron(Polyhedron p, const char* name) {
    printf("%s:\n", name);
    printf("  Vertices (V): %d\n", p.vertices);
    printf("  Edges (E): %d\n", p.edges);
    printf("  Faces (F): %d\n", p.faces);
    printf("  V - E + F = %d\n", p.vertices - p.edges + p.faces);
    printf("  Satisfies Euler's equation: %s\n\n", 
           verifyEulerEquation(p) ? "Yes" : "No");
}
int main() {
    printf("Euler's Polyhedron Equation: V - E + F = 2\n");
    printf("==========================================\n\n");

    // Create and verify various polyhedra
    Polyhedron tetrahedron = createPolyhedron(4, 6, 4);
    Polyhedron cube = createPolyhedron(8, 12, 6);
    Polyhedron octahedron = createPolyhedron(6, 12, 8);
    Polyhedron dodecahedron = createPolyhedron(20, 30, 12);
    Polyhedron icosahedron = createPolyhedron(12, 30, 20);

    // Non-polyhedron example (torus)
    Polyhedron torus = createPolyhedron(16, 32, 16);

    printPolyhedron(tetrahedron, "Tetrahedron");
    printPolyhedron(cube, "Cube");
    printPolyhedron(octahedron, "Octahedron");
    printPolyhedron(dodecahedron, "Dodecahedron");
    printPolyhedron(icosahedron, "Icosahedron");
    printPolyhedron(torus, "Torus (non-polyhedron)");

    return 0;
}