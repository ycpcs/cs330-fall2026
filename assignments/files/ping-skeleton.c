#define _GNU_SOURCE

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <limits.h>

void main(int argc, char *argv[])
{
    char ip[100];
    memset(ip, 0x00, sizeof(ip));
    get_host(argv[1], ip);

    int number_pings = atoi(argv[2]);

    int sock = socket(PF_INET, SOCK_RAW, IPPROTO_ICMP);

    // TODO: build the address
    struct sockaddr_in dest;

    // TODO - id and sequence
    char packet[64 * sizeof(char)];
    memset(packet, 0x00, sizeof(packet));
    struct icmphdr *hdr = (struct icmphdr *)packet;
    hdr->type = ICMP_ECHO;
    hdr->code = 0;
    hdr->checksum = 0;
    hdr->un.echo.id = 0;
    hdr->un.echo.sequence = 0;
    hdr->checksum = checksum((unsigned short *)hdr, sizeof(packet));

    // get start time
    struct timeval start;
    gettimeofday(&start, NULL);

    sendto(sock, packet, sizeof(packet), 0, (struct sockaddr *)&dest, sizeof(dest));

    struct sockaddr_in resp_addr;
    socklen_t addr_len = sizeof(resp_addr);

    char recv[4096];
    recvfrom(sock, recv, sizeof(recv), 0, (struct sockaddr *)&resp_addr, &addr_len);

    // TODO: Calculate time diff

    close(sock);
}
