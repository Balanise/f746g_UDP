#ifndef __UDP_SENDER_H__
#define __UDP_SENDER_H__

static struct udp_pcb *pcb = NULL;

void udp_send_packet(const char *msg);

#endif
