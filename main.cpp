#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/*
    Attempts to connect to a TCP port.
    Returns true if the port is open.
*/
bool scanPort(const char* ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return false;

    sockaddr_in target {};
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    int result = connect(sock, (sockaddr*)&target, sizeof(target));

    close(sock);

    return (result == 0);
}

int main() {
    const char* ip = "127.0.0.1";

    std::cout << "Scanning " << ip << "...\n\n";

    for (int port = 1; port <= 1024; port++) {
        if (scanPort(ip, port)) {
            std::cout << "[OPEN] Port " << port << "\n";
        }
    }

    std::cout << "\nScan complete.\n";
    return 0;
}
