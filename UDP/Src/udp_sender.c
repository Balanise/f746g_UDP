#include "lwip/udp.h"
#include "lwip/ip_addr.h"
#include "udp_sender.h"
#include <string.h>

void udp_send_packet(const char *msg) {
    static ip_addr_t dest_ip;
    struct pbuf *p;

    if (!pcb) {
        pcb = udp_new();
        if (!pcb) return;
        IP4_ADDR(&dest_ip, 192, 168, 1, 35);
    }

    p = pbuf_alloc(PBUF_TRANSPORT, strlen(msg), PBUF_RAM);
    if (!p) return;

    memcpy(p->payload, msg, strlen(msg));
    udp_sendto(pcb, p, &dest_ip, 5005);
    pbuf_free(p);
}
