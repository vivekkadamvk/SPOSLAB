def findWaitingTime(processes, n, bt, wt, at):
    # The first process does not need to wait
    wt[0] = 0

    # Calculate waiting time for remaining processes
    for i in range(1, n):
        wt[i] = bt[i - 1] + wt[i - 1] - at[i]

        # If the waiting time is negative, set it to 0
        if wt[i] < 0:
            wt[i] = 0


def findTurnaroundTime(processes, n, bt, wt, tat):
    # Calculate turnaround time by adding burst time and waiting time
    for i in range(n):
        tat[i] = bt[i] + wt[i]


def findAverageTime(processes, n, bt, at):
    wt = [0] * n
    tat = [0] * n

    # Find waiting time of all processes
    findWaitingTime(processes, n, bt, wt, at)

    # Find turnaround time for all processes
    findTurnaroundTime(processes, n, bt, wt, tat)

    # Display process details and average times
    print("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time")
    total_wt = 0
    total_tat = 0
    for i in range(n):
        total_wt += wt[i]
        total_tat += tat[i]
        print(f"{i + 1}\t\t{bt[i]}\t\t{at[i]}\t\t{wt[i]}\t\t{tat[i]}")

    avg_wt = total_wt / n
    avg_tat = total_tat / n
    print(f"\nAverage Waiting Time: {avg_wt}")
    print(f"Average Turnaround Time: {avg_tat}")


# Example usage
if __name__ == "__main__":
    # Process details - Customize as needed
    processes = [1, 2, 3, 4, 5]
    n = len(processes)
    burst_time = [10, 5, 8, 12, 3]
    arrival_time = [0, 2, 4, 5, 6]

    findAverageTime(processes, n, burst_time, arrival_time)
