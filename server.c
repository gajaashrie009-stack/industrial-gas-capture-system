/**
 * ============================================================================
 * Project: Industrial Gas Capture & Utilization (IGCU)
 * Program: server.c
 * Purpose: Standalone High-Performance C HTTP Web Server for Windows
 *          Serves the IGCU project website on http://localhost:8080
 *
 * Compilation (MinGW / GCC):
 *   gcc server.c -o server.exe -lws2_32
 *
 * Compilation (MSVC / Visual Studio Developer Prompt):
 *   cl server.c ws2_32.lib
 *
 * Run:
 *   server.exe
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
  #include <winsock2.h>
  #include <ws2tcpip.h>
  #pragma comment(lib, "ws2_32.lib")
  typedef int socklen_t;
#else
  #include <unistd.h>
  #include <arpa/inet.h>
  #include <sys/socket.h>
  #define closesocket close
  #define SOCKET int
  #define INVALID_SOCKET -1
  #define SOCKET_ERROR -1
#endif

#define DEFAULT_PORT 8080
#define BUFFER_SIZE 8192

/* Function to read entire file into dynamically allocated buffer */
char *read_file(const char *filename, long *out_size) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *buf = (char *)malloc(size + 1);
    if (!buf) {
        fclose(fp);
        return NULL;
    }

    fread(buf, 1, size, fp);
    buf[size] = '\0';
    fclose(fp);

    if (out_size) *out_size = size;
    return buf;
}

int main(int argc, char *argv[]) {
    int port = DEFAULT_PORT;
    if (argc > 1) {
        port = atoi(argv[1]);
        if (port <= 0 || port > 65535) port = DEFAULT_PORT;
    }

#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed.\n");
        return 1;
    }
#endif

    SOCKET server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == INVALID_SOCKET) {
        fprintf(stderr, "Failed to create socket.\n");
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (const char *)&opt, sizeof(opt));

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        fprintf(stderr, "Bind failed on port %d.\n", port);
        closesocket(server_fd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    if (listen(server_fd, 10) == SOCKET_ERROR) {
        fprintf(stderr, "Listen failed.\n");
        closesocket(server_fd);
#ifdef _WIN32
        WSACleanup();
#endif
        return 1;
    }

    printf("==============================================================\n");
    printf("   INDUSTRIAL GAS CAPTURE & UTILIZATION (IGCU) WEB SERVER    \n");
    printf("==============================================================\n");
    printf(" [✓] C HTTP Server listening on http://localhost:%d\n", port);
    printf(" [✓] Open your browser at: http://localhost:%d\n", port);
    printf(" [✓] Press Ctrl+C in this terminal to stop the server.\n");
    printf("==============================================================\n\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        SOCKET client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);

        if (client_fd == INVALID_SOCKET) {
            continue;
        }

        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_fd, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';

            char method[16], path[256], protocol[16];
            sscanf(buffer, "%s %s %s", method, path, protocol);
            printf("[REQUEST] %s %s (from %s)\n", method, path, inet_ntoa(client_addr.sin_addr));

            /* Route: API Endpoint */
            if (strcmp(path, "/api/status") == 0) {
                const char *json_body = "{\"status\":\"ONLINE\",\"system\":\"Industrial Gas Capture & Utilization\","
                                        "\"efficiency_pct\":88.5,\"captured_gases\":[\"CO2\",\"NOx\",\"SOx\",\"CO\",\"VOCs\"]}";
                char header[512];
                sprintf(header,
                        "HTTP/1.1 200 OK\r\n"
                        "Content-Type: application/json\r\n"
                        "Content-Length: %zu\r\n"
                        "Access-Control-Allow-Origin: *\r\n"
                        "Connection: close\r\n\r\n",
                        strlen(json_body));
                send(client_fd, header, (int)strlen(header), 0);
                send(client_fd, json_body, (int)strlen(json_body), 0);
            } 
            /* Route: Default Website (index.html) */
            else {
                long file_size = 0;
                char *file_content = read_file("index.html", &file_size);

                if (file_content) {
                    char header[512];
                    sprintf(header,
                            "HTTP/1.1 200 OK\r\n"
                            "Content-Type: text/html; charset=UTF-8\r\n"
                            "Content-Length: %ld\r\n"
                            "Connection: close\r\n\r\n",
                            file_size);
                    send(client_fd, header, (int)strlen(header), 0);
                    send(client_fd, file_content, (int)file_size, 0);
                    free(file_content);
                } else {
                    const char *not_found = "HTTP/1.1 404 Not Found\r\n"
                                            "Content-Type: text/plain\r\n"
                                            "Content-Length: 42\r\n"
                                            "Connection: close\r\n\r\n"
                                            "404 Not Found: index.html was not found.";
                    send(client_fd, not_found, (int)strlen(not_found), 0);
                }
            }
        }

        closesocket(client_fd);
    }

    closesocket(server_fd);
#ifdef _WIN32
    WSACleanup();
#endif
    return 0;
}
