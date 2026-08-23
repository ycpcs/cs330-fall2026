#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>

void print_buffer(const char *buffer, int recv_length) {
    for (int i = 0; i < recv_length; i++) {
        char byte = buffer[i];
        if (byte > 31 && byte < 127) {
            printf("%c", byte);
        } else if (byte == 10 || byte == 13) {
            printf("\n");
        } else {
            printf(".");
        }
    }
    printf("\n---------------------------------------------------------\n");    
}

int main(void) {    
	struct sockaddr saddr;
	struct packet_mreq mr;
	socklen_t clientlen = sizeof(saddr);
	char buf[512];

	int sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

	mr.mr_type = PACKET_MR_PROMISC;
	setsockopt(sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &mr, sizeof(mr));

	int buf_len = sizeof(buf);

	while (1) {	
		bzero(buf, buf_len);

		int len = recvfrom(sock, buf, buf_len - 1, 0, (struct sockaddr*) & saddr, &clientlen);
		if (len > 0) {		
            print_buffer(buf, len);
		}
	}
	close(sock);
}