#include "lwip/udp.h"
#include "lwip/ip_addr.h"
#include "udp_sender.h"
#include <string.h>

void udp_send_packet(const char *msg)
{
    struct udp_pcb *pcb = udp_new();
    struct pbuf *p;
    ip_addr_t dest_ip;

    if (!pcb || !msg) return;

    // Set destination IP (e.g., PC IP)
    IP4_ADDR(&dest_ip, 192, 168, 1, 35);  // Replace with your PC IP

    // Allocate buffer based on message length
    p = pbuf_alloc(PBUF_TRANSPORT, strlen(msg), PBUF_RAM);
    if (!p) {
        udp_remove(pcb);
        return;
    }

    memcpy(p->payload, msg, strlen(msg));
    udp_sendto(pcb, p, &dest_ip, 5005);  // Port 5005 — match PC side
    pbuf_free(p);
    udp_remove(pcb);
}
