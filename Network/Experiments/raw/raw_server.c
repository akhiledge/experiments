
/**
 * File              : raw_server.c
 * Author            : Vepuri Vinay Kumar <vk.vepuri@globaledgesoft.com>
 * Date              : 27.09.2018
 * Last Modified Date: 27.09.2018
 * Last Modified By  : Vepuri Vinay Kumar <vk.vepuri@globaledgesoft.com>
 */
#include "head.h"
int
main(void)
{
	int     s_raw;
	s_raw = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
	perror("socket");

	unsigned char *buffer = (unsigned char *)malloc(sizeof(char) * 65536);	//to receive data
	memset(buffer, 0, 65536);
	struct sockaddr saddr;
	int     saddr_len = sizeof(saddr);

	//Receive a network packet and copy in to buffer

	int     buflen =
			recvfrom(s_raw, buffer, 65536, 0, &saddr,
			(socklen_t *) & saddr_len);
	if (buflen < 0) {
		perror("recvfrom");
		return -1;
	}

	struct ethhdr *eth = (struct ethhdr *)(buffer);

	printf("\nEthernet Header\n");
	printf("\t|-Source Address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",
			eth->h_source[0], eth->h_source[1], eth->h_source[2],
			eth->h_source[3], eth->h_source[4], eth->h_source[5]);
	printf("\t|-Destination Address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",
			eth->h_dest[0], eth->h_dest[1], eth->h_dest[2], eth->h_dest[3],
			eth->h_dest[4], eth->h_dest[5]);
	printf("\t|-Protocol : %d\n", eth->h_proto);

	unsigned short iphdrlen;

	struct iphdr *ip = (struct iphdr *)(buffer + sizeof(struct ethhdr));

	struct sockaddr_in source;
	struct sockaddr_in dest;

	memset(&source, 0, sizeof(source));
	source.sin_addr.s_addr = ip->saddr;

	memset(&dest, 0, sizeof(dest));
	dest.sin_addr.s_addr = ip->daddr;

	printf("\t|-Version : %d\n", (unsigned int)ip->version);

	printf("\t|-Internet Header Length : %d WORDS or %d Bytes\n",
			(unsigned int)ip->ihl, ((unsigned int)(ip->ihl)) * 4);

	printf("\t|-Type Of Service : %d\n", (unsigned int)ip->tos);

	printf("\t|-Total Length : %d Bytes\n", ntohs(ip->tot_len));

	printf("\t|-Identification : %d\n", ntohs(ip->id));

	printf("\t|-Time To Live : %d\n", (unsigned int)ip->ttl);

	printf("\t|-Protocol : %d\n", (unsigned int)ip->protocol);

	printf("\t|-Header Checksum : %d\n", ntohs(ip->check));

	printf("\t|-Source IP : %s\n", inet_ntoa(source.sin_addr));

	printf("\t|-Destination IP : %s\n", inet_ntoa(dest.sin_addr));

	iphdrlen = (ip->ihl) * 4;
	/* getting pointer to udp header */
	struct udphdr *udp =
			(struct udphdr *)(buffer + iphdrlen + sizeof(struct ethhdr));

	printf(" \t|-Source Port : %d\n", ntohs(udp->source));
	printf(" \t|-Destination Port : %d\n", ntohs(udp->dest));
	printf(" \t|-UDP Length : %d\n", ntohs(udp->len));
	printf(" \t|-UDP Checksum : %d\n", ntohs(udp->check));

	struct tcphdr *tcp =
			(struct tcphdr *)(buffer + iphdrlen + sizeof(struct ethhdr));

	printf(" \t|-Source Port : %d\n", ntohs(tcp->source));
	printf(" \t|-Destination Port : %d\n", ntohs(tcp->dest));
	printf(" \t|-sequence number  : %d\n", ntohs(tcp->seq));
	printf(" \t|-acknowledge number : %d\n", ntohs(tcp->ack_seq));

	/*
	   printf(" \t|-data offset : %d\n", ntohs(tcp->doff));
	   printf(" \t|-fin : %d\n", ntohs(tcp->fin));
	   printf(" \t|-syn offset : %d\n", ntohs(tcp->syn));
	   printf(" \t|-rst offset : %d\n", ntohs(tcp->rst));
	   printf(" \t|-psh offset : %d\n", ntohs(tcp->psh));
	   printf(" \t|-ack offset : %d\n", ntohs(tcp->ack));
	   printf(" \t|-urg offset : %d\n", ntohs(tcp->urg));
	   printf(" \t|-ece offset : %d\n", ntohs(tcp->ece));
	   printf(" \t|-cwr : %d\n", ntohs(tcp->cwr));
	 */
	printf(" \t|-data offset : %d\n", ntohs(tcp->doff));
	printf(" \t|-fin : %d\n", (tcp->fin));
	printf(" \t|-syn offset : %d\n", (tcp->syn));
	printf(" \t|-rst offset : %d\n", (tcp->rst));
	printf(" \t|-psh offset : %d\n", (tcp->psh));
	printf(" \t|-ack offset : %d\n", (tcp->ack));
	printf(" \t|-urg offset : %d\n", (tcp->urg));
	printf(" \t|-ece offset : %d\n", (tcp->ece));
	printf(" \t|-cwr : %d\n", (tcp->cwr));

	printf(" \t|-window : %d\n", ntohs(tcp->window));
	printf(" \t|-check : %d\n", ntohs(tcp->check));
	printf(" \t|-urg_ptr : %d\n", ntohs(tcp->urg_ptr));

	return 0;

}
