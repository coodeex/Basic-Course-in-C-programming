#ifndef AALTO_TCPHEADER_H
#define AALTO_TCPHEADER_H

int getSourcePort(const unsigned char *tcp_hdr);
int getDestinationPort(const unsigned char *tcp_hdr);
void setSourcePort(unsigned char *tcp_hdr, int port);
void setDestinationPort(unsigned char *tcp_hdr, int port);
int getAckFlag(const unsigned char *tcp_hdr);
void setAckFlag(unsigned char *tcp_hdr, int flag);
int getDataOffset(const unsigned char *tcp_hdr);
void setDataOffset(unsigned char *tcp_hdr, int offset);

#endif