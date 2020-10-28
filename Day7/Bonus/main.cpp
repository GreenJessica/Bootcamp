#include <iostream>
extern "C" {
    #include <pcap.h>
}

void print_packet_info(const u_char *packet, struct pcap_pkthdr packet_header);

int main() {
    char *device;
    char error_buffer[PCAP_ERRBUF_SIZE];
    pcap_t *handle;
    const u_char *packet;
    extern pcap_pkthdr packet_header;
    int packet_count_limit = 1;
    int timeout_limit = 10000;
    

    device = pcap_lookupdev(error_buffer);
    if (device == NULL){
        std::cout << "Error finding device " << error_buffer  << std::endl;
        return 1;
    }

    handle = pcap_open_live(device, BUFSIZ, packet_count_limit, timeout_limit, error_buffer);

    packet = pcap_next(handle, &packet_header);
    if (packet == NULL){
        std::cout << "Error finding device " << error_buffer  << std::endl;
        return 2;
    }

    print_packet_info(packet, packet_header);

    return 0;
}