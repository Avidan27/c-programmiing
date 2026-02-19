#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>  // for night detection

#define MAX_BUSES 10

struct Bus {
    int bus_id;
    char from_city[30];
    char to_city[30];
    char dep_time[10];      
    char arr_time[10];      
    char driver[30];
    int driver_rating;      
    int route_safety;       
    char current_route[50];
};

int getHourFromTime(char* time_str) {
    int hour;
    sscanf(time_str, "%d", &hour);
    return hour;
}

int isNightTravel(char* dep_time, char* arr_time) {
    int dep_hour = getHourFromTime(dep_time);
    int arr_hour = getHourFromTime(arr_time);
    
    // Night travel if departure >20 OR arrival >20
    return (dep_hour >= 20 || arr_hour >= 20);
}

int calculateAdjustedSafety(struct Bus b) {
    int base_safety = b.driver_rating + b.route_safety;
    
    if (isNightTravel(b.dep_time, b.arr_time)) {
        return base_safety - 2;  // Night penalty
    }
    return base_safety;
}

void emergencySOS(int bus_id, char* current_location) {
    printf("\n🚨 EMERGENCY SOS ACTIVATED! 🚨\n");
    printf("========================================\n");
    printf("📱 ALERT SENT TO EMERGENCY CONTACTS\n");
    printf("🚌 Bus ID: %d\n", bus_id);
    printf("📍 Current Location: %s\n", current_location);
    printf("⏰ Time: %s IST\n", __TIME__);
    printf("========================================\n");
    printf("✅ SOS Message Sent Successfully!\n");
    printf("   Help is on the way! Stay safe.\n");
    printf("📲 'EMERGENCY! Bus %d at %s. Send help!'\n", bus_id, current_location);
}

int main() {
    struct Bus buses[MAX_BUSES] = {
        {101, "Pune", "Mumbai", "06:30", "10:30", "Raj", 4, 4, "Pune-NH48-Khandala"},
        {102, "Pune", "Mumbai", "09:00", "13:30", "Anil", 3, 2, "Pune-NH48-Lonavala"},
        {103, "Pune", "Nashik", "07:00", "11:00", "Vijay", 5, 4, "Pune-Sangamner-Nashik"},
        {104, "Mumbai", "Pune", "21:00", "01:00", "Suresh", 4, 4, "Mumbai-NH48-Panvel"},  // NIGHT
        {105, "Pune", "Kolhapur", "08:00", "12:00", "Kiran", 3, 3, "Pune-Satara-Kolhapur"},
        {106, "Nashik", "Pune", "22:00", "02:00", "Ramesh", 4, 3, "Nashik-Sangamner-Pune"}, // NIGHT
        {107, "Pune", "Mumbai", "14:00", "18:00", "Mahesh", 4, 4, "Pune-NH48-Khopoli"},
        {108, "Pune", "Nashik", "15:00", "19:00", "Sunil", 3, 3, "Pune-Shirdi-Nashik"},
        {109, "Mumbai", "Nashik", "10:00", "15:00", "Ajay", 2, 2, "Mumbai-NashikRd-Igatpuri"},
        {110, "Kolhapur", "Pune", "16:00", "20:00", "Prakash", 4, 3, "Kolhapur-Satara-Pune"}
    };

    int choice, selected_bus = -1;
    char source[30], destination[30];
    int found_count = 0;
    int best_safety = 0, best_index = -1;

    printf("=== SMART BUS FINDER & NIGHT SAFETY SYSTEM ===\n");

    while(1) {
        printf("\n1. Find bus BETWEEN cities\n");
        printf("2. Show ALL routes FROM city\n");
        printf("3. 🚨 EMERGENCY SOS\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        if (choice == 3) {
            printf("Enter your Bus ID: ");
            scanf("%d", &selected_bus);
            
            int bus_found = 0;
            for (int i = 0; i < MAX_BUSES; i++) {
                if (buses[i].bus_id == selected_bus) {
                    emergencySOS(buses[i].bus_id, buses[i].current_route);
                    bus_found = 1;
                    break;
                }
            }
            if (!bus_found) printf("❌ Bus ID not found!\n");
            continue;
        }

        printf("Enter source city: ");
        scanf("%s", source);

        if (choice == 1) {
            printf("Enter destination city: ");
            scanf("%s", destination);

            printf("\n%s → %s:\n", source, destination);
            printf("ID  Driver     Time       Safety  Status\n");
            printf("---------------------------------------\n");

            for (int i = 0; i < MAX_BUSES; i++) {
                if (strcmp(buses[i].from_city, source) == 0 && 
                    strcmp(buses[i].to_city, destination) == 0) {
                    
                    int safety = calculateAdjustedSafety(buses[i]);
                    char status[20] = "Day";
                    
                    if (isNightTravel(buses[i].dep_time, buses[i].arr_time)) {
                        strcpy(status, "🌙 NIGHT");
                    }
                    
                    printf("%-3d %-9s %-11s %2d/10   %s\n",
                           buses[i].bus_id, buses[i].driver,
                           buses[i].dep_time, safety, status);

                    found_count++;
                    if (safety > best_safety) {
                        best_safety = safety;
                        best_index = i;
                    }
                }
            }

            if (found_count > 0 && best_index != -1) {
                printf("\n✓ BEST CHOICE: Bus %d\n", buses[best_index].bus_id);
                char night_status[20] = "";
                if (isNightTravel(buses[best_index].dep_time, buses[best_index].arr_time)) {
                    strcpy(night_status, " (NIGHT TRAVEL -2)");
                }
                printf("   Driver: %s | Safety: %d/10%s\n", 
                       buses[best_index].driver, best_safety, night_status);
                selected_bus = buses[best_index].bus_id;
            } else {
                printf("\n❌ No direct buses found.\n");
            }

        } else if (choice == 2) {
            printf("\nRoutes FROM %s:\n", source);
            printf("--------------------------------\n");

            int mumbai_cnt=0, nashik_cnt=0, kolhapur_cnt=0;
            int best_mumbai=-1, best_nashik=-1, best_kolhapur=-1;

            for (int i = 0; i < MAX_BUSES; i++) {
                if (strcmp(buses[i].from_city, source) == 0) {
                    int safety = calculateAdjustedSafety(buses[i]);
                    
                    if (strcmp(buses[i].to_city, "Mumbai") == 0) {
                        mumbai_cnt++; if (safety > best_mumbai) best_mumbai = safety;
                    }
                    if (strcmp(buses[i].to_city, "Nashik") == 0) {
                        nashik_cnt++; if (safety > best_nashik) best_nashik = safety;
                    }
                    if (strcmp(buses[i].to_city, "Kolhapur") == 0) {
                        kolhapur_cnt++; if (safety > best_kolhapur) best_kolhapur = safety;
                    }
                }
            }

            if (mumbai_cnt > 0) printf("→ Mumbai: %d buses (Best %d/10)\n", mumbai_cnt, best_mumbai);
            if (nashik_cnt > 0) printf("→ Nashik: %d buses (Best %d/10)\n", nashik_cnt, best_nashik);
            if (kolhapur_cnt > 0) printf("→ Kolhapur: %d buses (Best %d/10)\n", kolhapur_cnt, best_kolhapur);
        }
    }

    printf("\nThank you! Drive Safe 🚍✨\n");
    return 0;
}