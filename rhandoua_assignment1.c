#include <stdio.h>
#include <math.h>

/**
 * CS 374 Programming Assignment 1: Basic Formulas
 * Author: rhandouri (rhandoua)
 * Description: Calculates the surface area and volume of n spherical segments.
 */

int main(void) {
    // Variable Declarations [cite: 1337, 1358]
    int n, i;
    int valid_sets = 0;
    float R, ha, hb;
    double a, b, h;
    double top_area, bottom_area, lateral_area, total_area, volume;
    double total_area_sum = 0, volume_sum = 0;
    const double PI = 3.14159265359; // [cite: 1361]

    // 1. Request number of segments (n) [cite: 1338]
    // Loop repeats until n is between 2 and 10 [cite: 1339]
    do {
        printf("How many spherical segments you want to evaluate [2-10]?\n");
        scanf("%d", &n);
    } while (n < 2 || n > 10);

    // 2. Main loop to process n valid segments [cite: 1340, 1353]
    while (valid_sets < n) {
        printf("Obtaining data for spherical segment number %d\n", valid_sets + 1);
        
        // Input R, ha, hb in exact order [cite: 1341, 1342]
        printf("What is the radius of the sphere (R)?\n");
        scanf("%f", &R);
        printf("What is the height of the top area of the spherical segment (ha)?\n");
        scanf("%f", &ha);
        printf("What is the height of the bottom area of the spherical segment (hb)?\n");
        scanf("%f", &hb);

        // Echoing Input [cite: 1347, 1391]
        printf("Entered data: R=%.2f ha=%.2f hb=%.2f.\n", R, ha, hb);

        // 3. Validation [cite: 1349, 1350, 1351]
        if (R <= 0 || ha <= 0 || hb <= 0 || ha > R || hb > R || hb > ha) {
            printf("Invalid Input.\n"); // [cite: 1352]
            continue; // Re-request values for this set [cite: 1352]
        }

        // 4. Calculations [cite: 1332, 1333, 1334, 1335]
        a = sqrt((R * R) - (ha * ha)); // [cite: 1363, 1364]
        b = sqrt((R * R) - (hb * hb));
        h = ha - hb;
        
        top_area = PI * a * a;
        bottom_area = PI * b * b;
        lateral_area = 2 * PI * R * h;
        total_area = top_area + bottom_area + lateral_area;
        volume = (1.0/6.0) * PI * h * (3 * a * a + 3 * b * b + h * h);

        // 5. Output results for this segment [cite: 1356]
        printf("Total Surface Area=%.2f Volume=%.2f.\n", total_area, volume);

        // Accumulate sums for averages [cite: 1357]
        total_area_sum += total_area;
        volume_sum += volume;
        valid_sets++;
    }

    // 6. Report averages [cite: 1357, 1425]
    printf("Total average results:\n");
    printf("Average Surface Area=%.2f Average Volume=%.2f\n", 
            total_area_sum / n, volume_sum / n);

    return 0;
}