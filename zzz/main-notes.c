
#include <unistd.h>
#include <fcntl.h>

//	valgrind --leak-check=full --track-fds=yes --trace-children=yes -s ./a.out
//	lsof -c a.out

void	child_process(int fd, char* cmd, char **args)
{
//proteger si dup2 < 0
//dup2 cierra stdin y fd se vuelve en luevo input
close(tuberia[0]);//SIEMPRE cerrar el extremo de tubería que no este en uso, si permanece abierto
					//se quedará esperando una entrada y el proceso no terminará
dup2(fd, STDIN_FILENO);
close(fd);
dup2(tuberia[1], STDOUT_FILENO); //asignamos el output de este proceso al out de tubería
close(tuberia[1])
//access(cmd, F_OK) == -1 si falla el archivo no existe
//access(cmd, X_OK) == -1 si falla el archivo no tiene permisos de ejecucion
//error y exit(1);

//ls -la
//execve("/usr/bin/ls", {"ls", "-la"}, envp)
if (execve(cmd, args, envp) == -1)
	mensaje de error;
}

void	child_process_2(int fd, char* cmd)
{
//proteger si dup2 < 0
//dup2 cierra stdin y fd se vuelve en luevo input
close(tuberia[1]);//SIEMPRE cerrar el extremo de tubería que no este en uso, si permanece abierto
					//se quedará esperando una entrada y el proceso no terminará
dup2(tuberia[0], STDOUT_FILENO); //asignamos el output de este proceso al out de tubería
close(tuberia[0])
dup2(fd, STDOUT_FILENO);
close(fd);
//access(cmd, F_OK) == -1 si falla el archivo no existe
//access(cmd, X_OK) == -1 si falla el archivo no tiene permisos de ejecucion
//error y exit(1);

//ls -la
//execve("/usr/bin/ls", {"ls", "-la"}, envp)
if (execve(cmd, args, envp) == -1)
	mensaje de error;
}
//	  P            H1               			H2			
//|------|		|------|					|------|
//0      1		0	   1					0	   1

pipe(P)

1º fork			P[0]						P[1]
P[1]			dup2(P[1], STDOUT_FILENO)	dup2(P[0], STDIN_FILENO)
2º fork			close[P[1]]					close[O[0]]
P[0]


void	pipex(int input, int output, char *cmd, char *cmd2, char **envp)
{
	int	tuberia[2];
	pid_t	padre;
	int		status;

	pipe(tuberia);
	padre = fork();
	if (padre < 0)
	{
		close(tuberia[0]);
		close(tuberia[1]);
		close(input);
		close(output);
		return (perror("Fork: "));
	}
	if (!padre) //si fork retorna 0, estamos en el proceso hijo
		child_process(input, cmd1, args);
	else
	{
		close(input);
		close(tuberia[0]);
		waitpid(padre, &status, 0);
	}
	padre = fork();
	if (padre < 0)
	{
		close(tuberia[1]);
		close(input);
		return (perror("Fork: "));
	}
	if (!padre) //si fork retorna 0, estamos en el proceso hijo
		child_process_2(output, cmd2, args);
	else
	{
		close(output);
		close(tuberia[0]);
		waitpid(padre, &status, 0);
	}
}

int	main(int argc, char** argv, char **envp)
{
	//parseo
	int input;
	int output;
	input = open(ruta, filename, O_WRONLY, 0777);
	if (input == -1)
	{
		if (errno == EACCES)
			error de permisos
		else
			error de archivo
	}
	pipex(inpout, output);
	free(cosas);
	while(1);
	return (0);
}