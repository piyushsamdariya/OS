#include <stdio.h>
#define MAX 10
struct Process {
    int pid,burst_time,remaining_time,arrival_time,waiting_time,turnaround_time,completion_time;
};
void sortByBurstTime(struct Process proc[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].burst_time > proc[j].burst_time) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}
void calculateNonPreemptiveSJF(struct Process proc[], int n) {
    int total_burst_time = 0;
    proc[0].waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_burst_time += proc[i].burst_time;
    }
    for (int i = 1; i < n; i++) {
        proc[i].waiting_time = proc[i - 1].waiting_time + proc[i - 1].burst_time;
        proc[i].turnaround_time = proc[i].waiting_time + proc[i].burst_time;
    }
}
void calculatePreemptiveSJF(struct Process proc[], int n) {
    int total_time = 0;
    int completed = 0;
    int current_time = 0;
    int min_remaining_time;
    int shortest = -1;
    for (int i = 0; i < n; i++) {
        proc[i].remaining_time = proc[i].burst_time;
    }
    while (completed < n) {
        min_remaining_time = 999999;
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (proc[i].arrival_time <= current_time && proc[i].remaining_time > 0 && proc[i].remaining_time < min_remaining_time) {
                min_remaining_time = proc[i].remaining_time;
                shortest = i;
            }
        }
        if (shortest == -1) {
            current_time++;
            continue;
        }
        proc[shortest].remaining_time--;
        current_time++;
        if (proc[shortest].remaining_time == 0) {
            proc[shortest].completion_time = current_time;
            proc[shortest].turnaround_time = proc[shortest].completion_time - proc[shortest].arrival_time;
            proc[shortest].waiting_time = proc[shortest].turnaround_time - proc[shortest].burst_time;
            completed++;
        }
    }
}
void displayResults(struct Process proc[], int n) {
    printf("\nProcess ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].burst_time, proc[i].arrival_time, proc[i].waiting_time, proc[i].turnaround_time);
    }
}
float calculateAverageWaitingTime(struct Process proc[], int n) {
    int total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += proc[i].waiting_time;
    }
    return (float)total_waiting_time / n;
}
float calculateAverageTurnaroundTime(struct Process proc[], int n) {
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += proc[i].turnaround_time;
    }
    return (float)total_turnaround_time / n;
}
int main() {
    int n;
    int choice;
    struct Process proc[MAX];

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for Process %d:\n", i + 1);
        proc[i].pid = i + 1;
        printf("Burst Time: ");
        scanf("%d", &proc[i].burst_time);
        printf("Arrival Time: ");
        scanf("%d", &proc[i].arrival_time);
    }
    printf("\nChoose the type of SJF scheduling:\n");
    printf("1. Non-Preemptive SJF\n");
    printf("2. Preemptive SJF\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        sortByBurstTime(proc, n);
        calculateNonPreemptiveSJF(proc, n);
        displayResults(proc, n);
        printf("\nAverage Waiting Time: %.2f", calculateAverageWaitingTime(proc, n));
        printf("\nAverage Turnaround Time: %.2f", calculateAverageTurnaroundTime(proc, n));
    } else if (choice == 2) {
        calculatePreemptiveSJF(proc, n);
        displayResults(proc, n);
        printf("\nAverage Waiting Time: %.2f", calculateAverageWaitingTime(proc, n));
        printf("\nAverage Turnaround Time: %.2f", calculateAverageTurnaroundTime(proc, n));
    } else {
        printf("\nInvalid choice!\n");
    }

    return 0;
}


