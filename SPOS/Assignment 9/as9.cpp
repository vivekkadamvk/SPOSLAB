#include <iostream>
#include<bits/stdc++.h>
#include <unistd.h>
//#include <sys/wait.h>

int main() {
    // Forking a child process
    pid_t childPid = fork();

    if (childPid == -1) {
        // Fork failed
        std::cerr << "Fork failed." << std::endl;
        return 1;
    } else if (childPid == 0) {
        // Child process

        // Executing a new program using exec family system call
        execl("/bin/ps", "ps", "-ef", nullptr);

        // Exec will replace the current process, so this code will not be executed if successful
        std::cerr << "Exec failed." << std::endl;
        return 1;
    } else {
        // Parent process

        // Waiting for the child process to finish using wait system call
        int status;
        wait(&status);

        if (WIFEXITED(status)) {
            // Child process terminated normally
            int exitStatus = WEXITSTATUS(status);
            std::cout << "Child process exited with status: " << exitStatus << std::endl;
        } else if (WIFSIGNALED(status)) {
            // Child process terminated by a signal
            int signalNumber = WTERMSIG(status);
            std::cout << "Child process terminated by signal: " << signalNumber << std::endl;
        }
    }

    return 0;
}
