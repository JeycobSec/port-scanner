#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <netdb.h>
// Terminal colors
#define GREEN  "\033[32m"
#define RED    "\033[31m"
#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/*
    Attempts to connect to a TCP port.
    Returns true if the port is open.
*/
bool scanPort(const char* ip, int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) return false;

    // ----- ADD TIMEOUT (1 second) -----
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));
    // ---------------------------------

    sockaddr_in target {};
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    int result = connect(sock, (sockaddr*)&target, sizeof(target));

    close(sock);

    return (result == 0);
}

std::string getServiceName(int port) {
    struct servent* service = getservbyport(htons(port), "tcp");

    if (service)
        return service->s_name;

    return "unknown";
}

int main(int argc, char* argv[]) {

    if (argc != 4) {
        std::cout << "Usage: ./scanner <ip> <start_port> <end_port>\n";
        return 1;
    }

    const char* ip = argv[1];
    int startPort = std::stoi(argv[2]);
    int endPort   = std::stoi(argv[3]);

    std::cout << YELLOW << "Scanning " << ip
              << " from port "
              << startPort << " to "
              << endPort << "...\n\n" << RESET;

    std::vector<std::thread> threads;

    for (int port = startPort; port <= endPort; port++) {
        threads.emplace_back([ip, port]() {
            if (scanPort(ip, port)) {
                std::cout << GREEN
          << "[OPEN] Port "
          << port
          << " (" << getServiceName(port) << ")"
          << RESET << "\n";


            }
        });
    }

    // Wait for all threads
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "\nScan complete.\n";
    return 0;
}

