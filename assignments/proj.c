#include <stdio.h>
#include <string.h>

#define MAX_BUSES 10
#define SAFETY_THRESHOLD 12

struct Bus {
    int bus_id;
    char from_city[30];
    char to_city[30];
    int dep_hour, dep_min;
    int arr_hour, arr_min;
    int risk_level;   // 0 (safe) to 10 (unsafe)
};

int calculateDuration(struct Bus b) {
    int dep = b.dep_hour * 60 + b.dep_min;
    int arr = b.arr_hour * 60 + b.arr_min;
    return arr - dep;
}

int main() {
    struct Bus buses[MAX_BUSES] = {
        {101, "Pune", "Mumbai", 6, 30, 10, 30, 3},
        {102, "Pune", "Mumbai", 9, 0, 13, 30, 6},
        {103, "Pune", "Nashik", 7, 0, 11, 0, 4},
        {104, "Nashik", "Mumbai", 12, 0, 16, 0, 5},
        {105, "Pune", "Satara", 8, 0, 11, 0, 2},
        {106, "Satara", "Mumbai", 12, 0, 17, 0, 7}
    };

    int bus_count = 6;
    char source[30], destination[30];
    int found = 0;
    int safestRisk = 100, safestIndex = -1;

    printf("\n--- Smart Bus Route Finder & Safety Advisor ---\n");
    printf("Enter source city: ");
    scanf("%s", source);
    printf("Enter destination city: ");
    scanf("%s", destination);

    printf("\nAvailable Direct Buses:\n");
    printf("---------------------------------------------------------------\n");
    printf("ID   From     To       Departure Arrival Duration Risk\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < bus_count; i++) {
        if (strcmp(buses[i].from_city, source) == 0 &&
            strcmp(buses[i].to_city, destination) == 0) {

            int duration = calculateDuration(buses[i]);

            printf("%d  %-8s %-8s %02d:%02d     %02d:%02d     %3d min   %d\n",
                   buses[i].bus_id,
                   buses[i].from_city,
                   buses[i].to_city,
                   buses[i].dep_hour, buses[i].dep_min,
                   buses[i].arr_hour, buses[i].arr_min,
                   duration,
                   buses[i].risk_level);

            found = 1;

            if (buses[i].risk_level < safestRisk) {
                safestRisk = buses[i].risk_level;
                safestIndex = i;
            }
        }
    }

    if (found) {
        printf("\n✅ Safest Direct Option:\n");
        printf("Bus %d (%s → %s) | Risk Level: %d\n",
               buses[safestIndex].bus_id,
               buses[safestIndex].from_city,
               buses[safestIndex].to_city,
               buses[safestIndex].risk_level);

        if (safestRisk > 7)
            printf("⚠ Warning: Route has high safety risk.\n");
    } else {
        printf("\n❌ No direct bus found.\n");
        printf("Checking for safest 2-hop routes...\n");

        int bestTotalRisk = 100;
        int hop1 = -1, hop2 = -1;

        for (int i = 0; i < bus_count; i++) {
            if (strcmp(buses[i].from_city, source) == 0) {
                for (int j = 0; j < bus_count; j++) {
                    if (strcmp(buses[i].to_city, buses[j].from_city) == 0 &&
                        strcmp(buses[j].to_city, destination) == 0) {

                        int totalRisk = buses[i].risk_level + buses[j].risk_level;

                        if (totalRisk < bestTotalRisk) {
                            bestTotalRisk = totalRisk;
                            hop1 = i;
                            hop2 = j;
                        }
                    }
                }
            }
        }

        if (hop1 != -1 && hop2 != -1) {
            printf("\n🔁 Best 2-Hop Route Found:\n");
            printf("Bus %d: %s → %s (Risk %d)\n",
                   buses[hop1].bus_id,
                   buses[hop1].from_city,
                   buses[hop1].to_city,
                   buses[hop1].risk_level);

            printf("Bus %d: %s → %s (Risk %d)\n",
                   buses[hop2].bus_id,
                   buses[hop2].from_city,
                   buses[hop2].to_city,
                   buses[hop2].risk_level);

            printf("Total Route Risk: %d\n", bestTotalRisk);

            if (bestTotalRisk > SAFETY_THRESHOLD)
                printf("⚠ Travel not advised due to high safety risk.\n");
        } else {
            printf("❌ No safe multi-hop route available.\n");
        }
    }

    printf("\nThank you for using the system. Stay safe! 🚍\n");
    return 0;
}