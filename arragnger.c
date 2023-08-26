void execute_external(char **args, t_redr *envpp) {
    char *cmd_path;
    pid_t pid;
    int fd[2];
    int status;

    if (pipe(fd) == -1) {
        perror("Pipe creation error");
        return;
    }

    pid = fork();
    if (pid == -1) {
        perror("Fork error");
        return;
    }

    if (pid == 0) {
        // Child process code
        close(fd[0]); // Close read end of the pipe

        // Redirect standard output to the write end of the pipe
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]); // Close duplicated file descriptor

        cmd_path = get_path_cmd(args[0], envpp->env);
        if (!cmd_path) {
            perror("Command path not found");
            exit(EXIT_FAILURE);
        }

        execve(cmd_path, args, envpp->env);
        perror("Execve error");
        exit(EXIT_FAILURE);
    } else {
        // Parent process code
        close(fd[1]); // Close write end of the pipe

        // Redirect standard input to the read end of the pipe
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]); // Close duplicated file descriptor

        waitpid(pid, &status, 0);
    }
}
