#include <stdio.h>
struct Process {
    int id;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int RT;
};
void calculateTimes(struct Process processes[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].AT) {
            current_time = processes[i].AT;
        }
        processes[i].CT = current_time + processes[i].BT;
        processes[i].TAT = processes[i].CT - processes[i].AT;
        processes[i].WT = processes[i].TAT - processes[i].BT;
        processes[i].RT = current_time - processes[i].AT;
        current_time += processes[i].BT;
    }
}
void displayResults(struct Process processes[], int n) {
    printf("\nProcess ID | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time | Response Time\n");
    for (int i = 0; i < n; i++) {
        printf("    %d      |     %d       |     %d     |       %d        |       %d        |      %d      |      %d\n",
            processes[i].id,
            processes[i].AT,
            processes[i].BT,
            processes[i].CT,
            processes[i].TAT,
            processes[i].WT,
            processes[i].RT);
    }
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].AT, &processes[i].BT);
    }
    calculateTimes(processes, n);
    displayResults(processes, n);
    return 0;
}
