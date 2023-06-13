#include <stdio.h>

void fcfs(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n];

    waiting_time[0] = 0;
    turnaround_time[0] = burst_time[0];

    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i - 1] + waiting_time[i - 1];
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
}

void sjf(int processes[], int n, int burst_time[]) {
    int waiting_time[n], turnaround_time[n];
    int temp, total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst_time[i] > burst_time[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }

        waiting_time[i] = total;
        total += burst_time[i];
        turnaround_time[i] = total;
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
}


void priority(int processes[], int n, int burst_time[], int priority[]) {
    int waiting_time[n], turnaround_time[n];
    int temp, total = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;

                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }

        waiting_time[i] = total;
        total += burst_time[i];
        turnaround_time[i] = total;
    }

    printf("Process\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], priority[i], waiting_time[i], turnaround_time[i]);
    }
}


void round_robin(int processes[], int n, int burst_time[], int time_quantum) {
    int remaining_burst_time[n];
    int waiting_time[n], turnaround_time[n];
    int total_waiting_time = 0, total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    int time = 0;
    while (1) {
        int all_processes_done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                all_processes_done = 0;

                if (remaining_burst_time[i] > time_quantum) {
                    time += time_quantum;
                    remaining_burst_time[i] -= time_quantum;
                } else {
                    time += remaining_burst_time[i];
                    waiting_time[i] = time - burst_time[i];
                    remaining_burst_time[i] = 0;
                }
            }
        }

        if (all_processes_done)
            break;
    }

    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("Average waiting time: %.2f\n", (float)total_waiting_time / n);
    printf("Average turnaround time: %.2f\n", (float)total_turnaround_time / n);
}



int main() {
    int processes[] = {1, 2, 3, 4};
    int burst_time[] = {10, 5, 8, 12};
    int priority1[] = {2, 1, 4, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int time_quantum = 2;

    

    fcfs(processes, n, burst_time);
    sjf(processes, n, burst_time);
    priority(processes, n, burst_time, priority1);
    round_robin(processes, n, burst_time, time_quantum);

    return 0;
}




