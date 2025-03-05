#include <stdio.h>
#include <string.h>
struct Process {
    int process_id;
    char process_name[50];
    int process_arrival_time;
    int process_completion_time;
    int process_execution_time;
};
void display_processes(struct Process processes[], int n) {
    printf("\nProcess Details:\n");
    printf("Process ID | Process Name | Arrival Time | Execution Time | Completion Time\n");
    for (int i = 0; i < n; i++) {
        printf("%10d | %-12s | %12d | %14d | %15d\n",
            processes[i].process_id,
            processes[i].process_name,
            processes[i].process_arrival_time,
            processes[i].process_execution_time,
            processes[i].process_completion_time);
    }
}
void search_process(struct Process processes[], int n, int search_id) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i].process_id == search_id) {
            printf("\nProcess Found:\n");
            printf("Process ID: %d\n", processes[i].process_id);
            printf("Process Name: %s\n", processes[i].process_name);
            printf("Arrival Time: %d\n", processes[i].process_arrival_time);
            printf("Execution Time: %d\n", processes[i].process_execution_time);
            printf("Completion Time: %d\n", processes[i].process_completion_time);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Process with ID %d not found.\n", search_id);
    }
}

int main() {
    int n;
    int choice;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d\n", i + 1);
        processes[i].process_id = i + 1;
        printf("Enter process name: ");
        scanf("%s", processes[i].process_name);
        printf("Enter arrival time: ");
        scanf("%d", &processes[i].process_arrival_time);
        printf("Enter execution time: ");
        scanf("%d", &processes[i].process_execution_time);
            processes[i].process_completion_time = processes[i].process_arrival_time + processes[i].process_execution_time;
    do {
        printf("\nMenu:\n");
        printf("1. Display all processes\n");
        printf("2. Search for a process by ID\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_processes(processes, n);
                break;
            case 2: {
                int search_id;
                printf("Enter the process ID to search: ");
                scanf("%d", &search_id);
                search_process(processes, n, search_id);
                break;
            }
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
