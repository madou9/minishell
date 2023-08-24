void close_all_pipes(int pipes[][2], int num_pipes) {
    for (int i = 0; i < num_pipes; i++) {
        close(pipes[i][0]); // Close read end
        close(pipes[i][1]); // Close write end
    }
}

void close_unused_pipes(int pipes[][2], int num_pipes, int current_pipe) {
    // Close all read ends of pipes except the one being used
    for (int i = 0; i < num_pipes; i++) {
        if (i != current_pipe) {
            close(pipes[i][0]);
        }
    }
    // Close all write ends of pipes except the one being used
    for (int i = 0; i < num_pipes - 1; i++) {
        if (i != current_pipe - 1) {
            close(pipes[i][1]);
        }
    }
}


void execute_pipeline(char **commands, t_redr *envpp) {
    int num_commands = 0;
    while (commands[num_commands]) {
        num_commands++;
    }

    int pipes[num_commands - 1][2];
    for (int i = 0; i < num_commands - 1; i++) {
        pipe(pipes[i]);
    }

    for (int i = 0; i < num_commands; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            if (i != 0) {
                dup2(pipes[i - 1][0], STDIN_FILENO);
            }
            if (i != num_commands - 1) {
                dup2(pipes[i][1], STDOUT_FILENO);
            }
            close_unused_pipes(pipes, num_commands, i);
            
            if (is_builtin(&commands[i][0])) {
                execute_builtins(&commands[i], envpp);
            } else {
                execute_external(&commands[i], envpp);
            }
            exit(EXIT_SUCCESS);
        } else if (pid < 0) {
            perror("Fork error");
            exit(EXIT_FAILURE);
        }
    }

    close_all_pipes(pipes, num_commands);

    for (int i = 0; i < num_commands; i++) {
        wait(NULL);
    }
}

