#include <stdio.h>
#include "tcpheader.h"


int getSourcePort(const unsigned char *tcp_hdr)
{
    int i = (tcp_hdr[0] << 8) | tcp_hdr[1];
    return i;
}

int getDestinationPort(const unsigned char *tcp_hdr)
{
    int i = (tcp_hdr[2] << 8) | tcp_hdr[3];
    return i;
}

void setSourcePort(unsigned char *tcp_hdr, int port)
{
   tcp_hdr[1] = (char) (port & 0xFF);
   tcp_hdr[0] = (char) ((port >> 8) & 0xFF);
}

void setDestinationPort(unsigned char *tcp_hdr, int port)
{
   tcp_hdr[3] = (char) (port & 0xFF);
   tcp_hdr[2] = (char) ((port >> 8) & 0xFF);
}

int getAckFlag(const unsigned char *tcp_hdr)
{
    if(tcp_hdr[13] & (1<<4)){
        return 1;
    }
    else {
        return 0;
    }
}

void setAckFlag(unsigned char *tcp_hdr, int flag)
{
    /*int mask = 1 << 4; 
    (tcp_hdr[13] & ~mask) | ((flag << 4) & mask);*/
    
    if(flag){
        tcp_hdr[13] |= 1 << 4;
    }
    else if(!flag){
        tcp_hdr[13] &= ~(1 << 4);
    }
}

int getDataOffset(const unsigned char *tcp_hdr)
{
    int a;
    a = tcp_hdr[12] >> 4;
    return a;
}

void setDataOffset(unsigned char *tcp_hdr, int offset)
{
    //int bit1, bit2, bit3, bit4;
    //for(int i = 0; i<4;i++){
        tcp_hdr[12]=(tcp_hdr[12]<<4);
        tcp_hdr[12]=(tcp_hdr[12]>>4);
        tcp_hdr[12]=(tcp_hdr[12] | (offset<<4));
        /*if((offset >> (0+i)) & 1){
            tcp_hdr[12] |= (1 << (4 + i));
        }else {
            tcp_hdr[12] &= ~(0 << (4 + 1));
        }*/
    //}

}
int main()
{
    /* Feel free to modify this function to test different things */

    unsigned char bytes[] = {
        0x12,0x34,0x45,0x67,0xaa,0xbb,0xcc,0xdd,
        0xee,0xff,0xaa,0xbb,0xb1,0x5c,0x08,0x00,
        0x12,0x34,0x00,0x00 };
    
    printf("Source port: %d\n", getSourcePort(bytes));
    printf("Destination port: %d\n", getDestinationPort(bytes));
    printf("ACK flag: %d\n", getAckFlag(bytes));
    printf("Data Offset: %d\n", getDataOffset(bytes));    
}
