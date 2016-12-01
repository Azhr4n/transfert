
#ifndef BOOTSTRAP_H
# define BOOTSTRAP_H

# define SERVER_DIRECTORY ".Alkazia"
# define LAUNCHER_NAME "launcher_alkazia.jar"

# define BUFFSIZE 1024
# define MAX_FILENAME 512

# if defined(_WIN32) || defined(_WIN64)
#  define DIR_DELIMITER '\\'
# else
#  define DIR_DELIMITER '/'
# endif

#endif