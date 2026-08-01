/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmuhaise <mmuhaise@student.42beirut.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:22:54 by mmuhaise          #+#    #+#             */
/*   Updated: 2025/01/31 13:33:59 by mmuhaise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void    ft_putstr_fd2(char *str, char *arg)
{
    while (*str)
        write(2, str++, 1);
    if (arg)
        while (*arg)
            write(2, arg++, 1);
    write(2, "\n", 1);
}

void    ft_exec(char **av, int i, int temp_fd, char **env)
{
    av[i] = NULL;
    dup2(temp_fd, STDIN_FILENO);
    close(temp_fd);
    execve(av[0], av, env);
    ft_putstr_fd2("error: cannot execute ", av[0]);
    exit(1);
}

int main(int ac, char **av, char **env)
{
    int i = 0;
    int fd[2];
    int temp_fd = dup(STDIN_FILENO);
    
    (void)ac;
    while (av[i] && av[i + 1])
    {
        av = &av[i + 1];
        i = 0;

        while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
            i++;
        if (!strcmp(av[0], "cd"))
        {
            if (i != 2)
                ft_putstr_fd2("error: cd: bad arguments", NULL);
            else if (chdir(av[1]) != 0)
                ft_putstr_fd2("error: cd: cannot change directory to ", av[1]);
        }
        else if (i != 0 && (av[i] == NULL || !strcmp(av[i], ";")))
        {
            if (fork() == 0)
                ft_exec(av, i, temp_fd, env);
            else
            {
                close(temp_fd);
                while(waitpid(-1, NULL, WUNTRACED) != -1);
                temp_fd = dup(STDIN_FILENO);
            }
        }
        else if (i != 0 && !strcmp(av[i], "|"))
        {
            pipe(fd);
            if (fork() == 0)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);
                ft_exec(av, i, temp_fd, env);
            }
            else
            {
                close(fd[1]);
                close(temp_fd);
                temp_fd = fd[0];
            }
        }
        
    }
    close(temp_fd);
    return (0);
    
}
