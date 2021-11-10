#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>
#include <string.h>
#include <stdio.h>

static const char *const evval[2] = {
	"RELEASED",
	"PRESSED"
};

int main() {
	const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	struct input_event ev;
	ssize_t n;
	int fd;
	FILE *fp;

	fd = open(dev, O_RDONLY);
		
	if (fd == -1) {
		fp = fopen("ex2.txt", "w");
		fprintf(fp, "cannot open %s: %s\n", dev, strerror(errno));
		fclose(fp);
		return EXIT_FAILURE;
	}

	while (1) {
		fp = fopen("ex2.txt", "a");
		n = read(fd, &ev, sizeof ev);
		if (n == (ssize_t)-1) {
			if (errno == EINTR)
				continue;
			else
				break;
		} else {
			if (n != sizeof ev) {
				errno = EIO;
				break;
			}
		}
		if (ev.type == EV_KEY && ev.value >= 0 && ev.value <= 1)
			fprintf(fp, "%s 0x%04x (%d)\n", evval[ev.value], (int)ev.code, (int)ev.code);
		fclose(fp);
	}
	fp = fopen("ex2.txt", "w");
	fprintf(fp, "%s\n", strerror(errno));
	fclose(fp);
	return EXIT_FAILURE;
}


