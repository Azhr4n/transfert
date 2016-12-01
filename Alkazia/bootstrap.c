
#include <zlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <curl/curl.h>
#include <openssl/md5.h>

#include "bootstrap.h"

size_t	writeData(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
	return (fwrite(ptr, size, nmemb, stream));
}

int		getFileFromURL(char *url, char *name)
{
	CURL		*curl;
	
	if ((curl = curl_easy_init()))
	{
		FILE		*fp;
		CURLcode	res;

		fp = fopen(name, "w+");
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
		if ((res = curl_easy_perform(curl)) == CURLE_OK)
		{
			curl_easy_cleanup(curl);
			fclose(fp);
			return (1);
		}
		curl_easy_cleanup(curl);
		fclose(fp);
	}
	return (0);
}

int		setDirectory(char *path)
{
	if (path != NULL)
	{
		if (chdir(path) != -1)
		{
			if (access(SERVER_DIRECTORY, F_OK) == -1)
			{
				if (mkdir(SERVER_DIRECTORY, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) == -1)
				{
					printf("Failed to create directory.\n");
					return (0);
				}
			}
			if (chdir(SERVER_DIRECTORY) != -1)
				return (1);
			else
				printf("Error.\n");
		}
		else
			printf("Error.\n");
	}
	else
		printf("Home not found.\n");
	return (0);
}



int		checkVersion(char *path)
{
	MD5_CTX			mdContext;
	FILE			*fp;
	char			hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
	unsigned char	hash[MD5_DIGEST_LENGTH];
	char			r_hash[MD5_DIGEST_LENGTH * 2 + 1];
	char			buff[BUFFSIZE];
	char			*ptr;
	int				ret;
	int				i;

	if ((fp = fopen(path, "rb")) == NULL)
		return (0);
	MD5_Init(&mdContext);
	while ((ret = fread(buff, 1, BUFFSIZE, fp)) > 0)
	{
		if (ret < -1)
		{
			fclose(fp);
			return (0);
		}
		MD5_Update(&mdContext, buff, ret);
	}
	MD5_Final(hash, &mdContext);
	for(i = 0; i < MD5_DIGEST_LENGTH; i++)
	{
		r_hash[i * 2] = hex[hash[i] / 16];
		r_hash[i * 2 + 1] = hex[hash[i] % 16];
	}
	r_hash[MD5_DIGEST_LENGTH * 2] = 0;
	fclose(fp);
	if ((fp = fopen("md5.txt", "rb")) == NULL)
		return (0);
	ret = fread(buff, 1, BUFFSIZE, fp);
	if (ret < 0)
	{
		fclose(fp);
		return (0);
	}
	ptr = strchr(buff, ':');
	if (strncmp(ptr, r_hash, 32) == 0)
		return (1);
	return (0);
}
/*
int		unzip(char *path)
{
	unzFile				*zipfile;
	unz_global_info		global_info;
	unz_file_info		file_info;
	char				buff[BUFFSIZE + 1];
	char				filename[MAX_FILENAME];
	size_t 				filename_length;
	unsigned long int	i;
	int					ret;
	int					fd;

	if ((zipfile = unzOpen(path)) == NULL)
	{
		printf("Zip file not found.\n");
		return (0);
	}
	if (unzGetGlobalInfo(zipfile, &global_info) != UNZ_OK)
	{
		printf("Could not read file global info\n");
		unzClose(zipfile);
		return (0);
	}
	for (i = 0; i < global_info.number_entry; ++i)
	{
		if (unzGetCurrentFileInfo(zipfile, &file_info, filename, MAX_FILENAME, NULL, 0, NULL, 0) != UNZ_OK)
		{
			printf("Could not read file info.\n");
			unzClose(zipfile);
			return (0);
		}
	}
	filename_length = strlen(filename);
	if (filename[filename_length - 1] == DIR_DELIMITER)
		mkdir(filename, S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	else
	{
		if (unzOpenCurrentFile(zipfile) != UNZ_OK)
		{
			printf("Could not open current file.\n");
			unzClose(zipfile);
			return (0);
		}
		if ((fd = open(filename, O_RDWR)) == -1)
		{
			printf("Could not open destination file.\n");
			unzCloseCurrentFile(zipfile);
			unzClose(zipfile);
			return (0);
		}
		do 
		{
			ret = unzReadCurrentFile(zipfile, buff, BUFFSIZE);
			buff[ret] = 0;
			if (ret < 0)
			{
				printf("Error reading current file.\n");
				unzCloseCurrentFile(zipfile);
				unzClose(zipfile);
			}
			else if (ret > 0)
			{
				if (write(fd, buff, BUFFSIZE) < 1)
				{
					printf("Failed to write in file.\n");
					unzCloseCurrentFile(zipfile);
					unzClose(zipfile);
					return (0);
				}
			}
		} while (ret > 0);
		close(fd);
		unzCloseCurrentFile(zipfile);
		if (i + 1 < global_info.number_entry)
		{
			if (unzGoToNextFile(zipfile) != UNZ_OK)
			{
				printf("Could not acces next file.\n");
				unzClose(zipfile);
				return (0);
			}
		}
	}
	unzClose(zipfile);
	return (1);
}*/

int		installJRE(void)
{
	if (system("Java -version") != 0)
	{
		#ifdef _WIN32
		# define FILE_NAME "jre_windows_86_tmp.zip"
		# define FILE_URL "http://launcher.alkazia.net/launcher_era/jre_windows_86_tmp.zip"
		#endif
		#ifdef _WIN64
		# define FILE_NAME "jre_windows_64_tmp.zip"
		# define FILE_URL "http://launcher.alkazia.net/launcher_era/jre_windows_64_tmp.zip"
		#endif
		#ifdef __unix__
		# define FILE_NAME "jre_linux_86_tmp.zip"
		# define FILE_URL "http://launcher.alkazia.net/launcher_era/jre_linux_86_tmp.zip"
		#endif
		if (!getFileFromURL(FILE_URL, FILE_NAME))
			return (0);
		unzip(FILE_NAME);
		return (1);
	}
	return (0);
}

void	install(char *path)
{
	if (setDirectory(path))
	{
		if (access("md5.txt", R_OK == -1))
		{
			if (!getFileFromURL("http://launcher.alkazia.net/launcher_era/md5.txt", "md5.txt"))
			{
				printf("Can't get files needed.\n");
				return ;
			}
		}
		if (access(LAUNCHER_NAME, R_OK) == -1 || !checkVersion(LAUNCHER_NAME))
		{
			if (!getFileFromURL("http://launcher.alkazia.net/launcher_era/launcher_alkazia.jar", LAUNCHER_NAME))
			{
				printf("Can't get files needed.\n");
				return ;
			}
		}
		if (!installJRE())
			printf("Error installing java.\n");
	}
}

int		main(void)
{	
	char	*path;

	#ifdef _WIN32
		path = getenv("APPDATA");
	#endif
	#ifdef __unix__
		path = getenv("HOME");
	#endif
	//Mac missing
	install(path);
	return (0);
}
