#include <stdio.h>
#include <stdbool.h>

// Structure to represent a polyhedron
typedef struct {
    int vertices;
    int edges;
    int faces;
    const char* name;
    const char* element;
} Polyhedron;

// Function to create a polyhedron
Polyhedron createPolyhedron(int v, int e, int f, const char* name, const char* element) {
    Polyhedron p = {v, e, f, name, element};
    return p;
}

// Function to verify Euler's equation
bool verifyEulerEquation(Polyhedron p) {
    return (p.vertices - p.edges + p.faces == 2);
}

// Function to print polyhedron details
void printPolyhedron(Polyhedron p) {
    printf("Element: %s (represented by %s)\n", p.element, p.name);
    printf("  Vertices (V): %d\n", p.vertices);
    printf("  Edges (E): %d\n", p.edges);
    printf("  Faces (F): %d\n", p.faces);
    printf("  V - E + F = %d\n", p.vertices - p.edges + p.faces);
    printf("  Satisfies Euler's equation: %s\n\n", 
           verifyEulerEquation(p) ? "Yes" : "No");
}

int main() {
    printf("Five Elements Represented by Polyhedra\n");
    printf("======================================\n\n");

    // Create polyhedra for each element
    Polyhedron stone = createPolyhedron(4, 6, 4, "Tetrahedron", "Stone");
    Polyhedron water = createPolyhedron(8, 12, 6, "Cube", "Water");
    Polyhedron metal = createPolyhedron(6, 12, 8, "Octahedron", "Metal");
    Polyhedron dirt = createPolyhedron(20, 30, 12, "Dodecahedron", "Dirt");
    Polyhedron wood = createPolyhedron(12, 30, 20, "Icosahedron", "Wood");

    // Print details and verify Euler's equation for each element
    printPolyhedron(stone);
    printPolyhedron(water);
    printPolyhedron(metal);
    printPolyhedron(dirt);
    printPolyhedron(wood);

    return 0;
}