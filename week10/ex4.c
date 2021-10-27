#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

void searchDIR(char *dir, int dep) {
	DIR *d;
	struct dirent *entry;
	struct stat stat;
	d = opendir(dir);
	chdir(dir);
	while ((entry = readdir(d)) != NULL) {
		lstat(entry->d_name, &stat);
		if (S_ISDIR(stat.st_mode)) {
			if (strcmp(".", entry->d_name) == 0 || (strcmp("..", entry->d_name) == 0 )) {
				continue;
			}
			printf("%*s%s/\n", dep, "", entry->d_name);
			searchDIR(entry->d_name, dep + 4);
		} else {
			if (stat.st_nlink >= 2) {
				printf("%*s%s\n", dep, "", entry->d_name);
			}
		}
	}
	chdir("../");
	closedir(d);
}
	
int main(){
	searchDIR("./tmp", 0);
	return 0;
}
