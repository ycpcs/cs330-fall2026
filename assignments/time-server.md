---
layout: default
course_number: CS330
title: "Time Server"
---

# Programming Lab: Networked TCP Time Server & Client

## Objective

The goal of this lab is to help students understand the basic concepts of networking in C by converting a simple time server into a networked TCP server. Students will then implement a basic TCP client that connects to the server to retrieve the current date and time.

## Setup 
- You are provided with a simple C program that returns the current time as a string. Your task is to network this program by implementing a TCP server that will listen on port `8013`. When a client connects, the server will send the current time, and then close the connection.

- Use the following simple datetime program as a base for the server:

```c
#include <stdio.h>
#include <time.h>

int main() {
    time_t rawtime;
    struct tm *timeinfo;
    char time_string[100];

    // Get the current time
    time(&rawtime);
    
    // Convert the time to local time
    timeinfo = localtime(&rawtime);
    
    // Format the time as string
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", timeinfo);

    printf("Current time: %s\n", time_string);

    return 0;
}
```
- Use the [TCP server](tcp\server.c) developed during class as a reference or starting point for your implementation.

---

## Server Task 

### 1. TCP Time Server Implementation
- Create a simple TCP server that listens on port `8013` for incoming client connections.
- When a client connects, the server should:
  - Send the current time to the client.
  - Print the time sent to the client and the client’s connection information (IP address, port, etc.).
  - Close the connection after sending the time.
- Use the code provided as a starting point and integrate it into a TCP server by using `socket()`, `bind()`, `listen()`, `accept()`, `send()`, and `close()`.

### 2. Display Client Information
- Display details such as the client’s IP address and port number each time a new client connects.
- The server should handle one connection at a time (for simplicity).

### 3. Expected Output (Server)
The server will output information about the connected client and the time sent to the client.

---

## Client Task

### 1. TCP Client Implementation
- Create a simple TCP client that connects to the server (on `localhost` or the server’s IP address) at port `8013`.
- Once the client connects, the client should receive the current time from the server and print it to the console.

### 2. Expected Output (Client)
The client will print the time it receives from the server.

---

## Extra Credit 

### 1. Time Zone Support
- Modify the server to accept an optional time zone argument from the client. If the client sends a specific time zone (e.g., `"GMT"`, `"UTC"`, `"PST"`, etc.), the server should convert the current time to that time zone and send it to the client.
- For example, the server could send the time in multiple time zones (like UTC or PST) if the client requests a specific one.

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

### 1. Code Submission
- Submit the source code for both the server and client (`server.c`, `client.c`).

### 2. Wireshark Packet Capture
- Capture and submit the packets exchanged between the server and client using Wireshark.
- Ensure the packet capture includes the initial connection handshake and the transmission of the time data from the server to the client.
- Save the packet capture in `.pcapng` format.

### 3. Answer Questions/Observations
- Include any questions, observations, or issues you encountered during the implementation.
- Describe any challenges faced and how you overcame them.
- Discuss any assumptions made during the project (e.g., using `localhost` for testing).


> **Note:** Double-check that any screenshots clearly show packet details and are legible.
