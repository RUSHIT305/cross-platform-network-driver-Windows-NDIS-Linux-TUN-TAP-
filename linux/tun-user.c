// Simple TUN/TAP user-space example for Linux (Ubuntu 22.04+).
// Creates a TUN device and echoes read packets to stdout.
// Build: make (in linux/) or: gcc -o tun-user tun-user.c
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/if.h>
#include <linux/if_tun.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/select.h>

int tun_alloc(char *dev) {
    struct ifreq ifr;
    int fd, err;
    if ((fd = open("/dev/net/tun", O_RDWR)) < 0) {
        perror("open /dev/net/tun");
        return -1;
    }
    memset(&ifr, 0, sizeof(ifr));
    ifr.ifr_flags = IFF_TUN | IFF_NO_PI;
    if (*dev)
        strncpy(ifr.ifr_name, dev, IFNAMSIZ);
    if ((err = ioctl(fd, TUNSETIFF, (void *)&ifr)) < 0) {
        perror("ioctl TUNSETIFF");
        close(fd);
        return -1;
    }
    strcpy(dev, ifr.ifr_name);
    return fd;
}

int main(int argc, char **argv) {
    char tun_name[IFNAMSIZ] = "tun0";
    if (argc >= 2) {
        strncpy(tun_name, argv[1], IFNAMSIZ-1);
        tun_name[IFNAMSIZ-1] = '\0';
    }
    int tun_fd = tun_alloc(tun_name);
    if (tun_fd < 0) {
        fprintf(stderr, "Failed to allocate tun device\n");
        return 1;
    }
    printf("Allocated tun device: %s\n", tun_name);
    fflush(stdout);

    // Simple loop: read packets and print summary to stdout
    unsigned char buffer[2000];
    while (1) {
        ssize_t n = read(tun_fd, buffer, sizeof(buffer));
        if (n < 0) {
            if (errno == EINTR) continue;
            perror("read");
            break;
        }
        printf("Read packet: %zd bytes\n", n);
        // Dump first 32 bytes hex
        size_t dump = (n < 32) ? n : 32;
        for (size_t i = 0; i < dump; ++i) {
            printf("%02x ", buffer[i]);
        }
        printf("\n");
        fflush(stdout);
    }
    close(tun_fd);
    return 0;
}
