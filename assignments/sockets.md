---
layout: default
course_number: CS330
title: "Introduction to Sockets"
---

# Programming Lab - Introduction to Sockets

---

## Overview

In this lab, you will work with a simple client/server program pair to explore how **TCP** and **UDP** sockets behave in practice. Each client sends a message to a server, the server converts the message to uppercase, and the client prints the result back to the screen.

The goal is to help you understand the difference between connection-oriented and connectionless communication, how ports work, and what happens when messages are too large for the buffer.

---

## Download and Compile the Programs

Download the following files and compile them individually:

- [tcp_client.c](sockets/tcp_client.c)
- [tcp_server.c](sockets/tcp_server.c)
- [udp_client.c](sockets/udp_client.c)
- [udp_server.c](sockets/udp_server.c)

Example:

```bash
gcc tcp_client.c -o tcp_client
```

Run the program with:

```bash
./tcp_client
```

> Before testing a new program, make sure no old server or client is still running. If your code changes, recompile before running it again.

---

## Recommended Order of Operations

For this lab, it is easiest to follow this order:

1. Compile the server program.
2. Start the server.
3. Compile and run the client.
4. Observe the behavior.
5. Repeat for UDP.

This helps you see the expected startup behavior and the difference between a connection-oriented protocol and a connectionless one.

---

## What the Programs Do

The client reads a line of text from the terminal and sends it to the server. The server then:

- receives the message,
- converts it to uppercase,
- sends it back to the client,
- and the client prints the result.

This is a simple example of how sockets can be used in real network applications.

---

## TCP vs UDP Quick Reference

| Protocol | Connection | Reliability | Ordering | Typical Use             |
| -------- | ---------- | ----------- | -------- | ----------------------- |
| TCP      | Yes        | Yes         | Yes      | Web traffic, FTP, email |
| UDP      | No         | No          | No       | DNS, VoIP, streaming    |

---

## Questions to Answer in Your Lab Report

Answer the following questions clearly and completely in your write-up. This assignment is worth a total of 125 points.

1. **Run the TCP client before starting the TCP server.** (10 points)
   - What happens?
   - Why does it happen?
   - Compile and run:
     ```bash
     gcc tcp_server.c -o tcp_server
     gcc tcp_client.c -o tcp_client
     ./tcp_server
     ./tcp_client
     ```

2. **Run the UDP client before starting the UDP server.** (10 points)
   - What happens?
   - Why does it happen?
   - Compile and run:
     ```bash
     gcc udp_server.c -o udp_server
     gcc udp_client.c -o udp_client
     ./udp_server
     ./udp_client
     ```

3. **UDP port mismatch.** (10 points)
   - Edit the source code to use different port numbers in the UDP client and UDP server.
   - Recompile and run both programs.
   - What happens?
   - Why?

4. **TCP port mismatch.** (10 points)
   - Edit the source code to use different port numbers in the TCP client and TCP server.
   - Recompile and run both programs.
   - What happens?
   - Why?

5. **UDP buffer test.** (20 points)
   - Edit the UDP server/client code to test how the program behaves when the message length changes.
   - Start the UDP server.
   - Run the UDP client and send a message.
   - While the server is still running, run the UDP client again and send a shorter message.
   - What happens?
   - Why?
   - Fix the issue in the code and include your code change in the submission.

6. **Send buffer limit in the UDP client.** (15 points)
   - Edit the UDP client source code to reduce the send buffer from 50 bytes to 5 bytes.
   - Recompile and restart both programs.
   - Send a message longer than 5 bytes.
   - What happens?
   - Why?

7. **Receive buffer limit in the UDP client.** (15 points)
   - Edit the UDP client source code to reduce the receive buffer from 50 bytes to 5 bytes.
   - Recompile and restart both programs.
   - Send a message longer than 5 bytes.
   - What do you expect to happen?
   - What actually happens?
   - Why?

### Question subtotal: 90 points

---

## Programming Tasks

### 1. Accept IP and Port Values as Command-Line Arguments (15 points)

Update the socket programs so that the server IP address and port number are passed as command-line arguments instead of being hard-coded or entered interactively.

- The **TCP client** and **UDP client** should accept the **server IP address** and **server port** as arguments.
- The **TCP server** and **UDP server** should accept the **listening port** as an argument.

Example commands:

```bash
./tcp_client 127.0.0.1 9000
./udp_client 127.0.0.1 9000
./tcp_server 9000
./udp_server 9000
```

Compile and test:

```bash
gcc tcp_client.c -o tcp_client
gcc tcp_server.c -o tcp_server
gcc udp_client.c -o udp_client
gcc udp_server.c -o udp_server
```

---

### 2. Keep Running Until the User Types QUIT (20 points)

Modify the TCP and UDP client programs so that they:

- keep reading input,
- send each message to the server,
- and exit the loop only when the user types `QUIT`.

> Use standard input functions such as `fgets()` or `scanf()`. Match the word `QUIT` exactly, including capitalization.

### Programming task subtotal: 35 points

---

## Extra Credit (Optional)

If you want to go beyond the basic lab, you can try any of the following:

- add multi-client support to the TCP server,
- include logging for client IP addresses and timestamps,
- add retry logic for UDP,
- or experiment with different buffer sizes and message lengths.

This is optional, but it is a good way to explore the behavior more deeply.

---

## Helpful References

- [Linux socket interface (man 7 socket)](https://linux.die.net/man/7/socket)
- [Debugging with GDB](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)

---

## Testing and Debugging Tools

Useful tools for this lab include:

- [Netcat](http://netcat.sourceforge.net/) – a simple tool for sending and receiving data
- Check open ports with:
  - TCP: `netstat -antop`
  - UDP: `netstat -anoup`
- Stop a process by PID:
  - `kill PID`
- Stop a process by name:
  - `pkill PATTERN`

---

## Grading

This assignment is worth a total of 125 points.

- Questions: 90 points
- Programming tasks: 35 points
- Total: 125 points

### What to Submit

Submit the following through [Marmoset](https://cs.ycp.edu/marmoset) by the due date listed in the syllabus:

- Your written answers to all numbered questions.
- Your modified source code for all four programs:
  - `tcp_client.c`
  - `tcp_server.c`
  - `udp_client.c`
  - `udp_server.c`
- Screenshots showing the key behaviors you tested, including:
  - successful TCP communication,
  - successful UDP communication,
  - a port mismatch case,
  - the buffer test result,
  - and the `QUIT` behavior.
- A brief summary of what changed in the code for the programming tasks.

> Make sure your screenshots are clear and readable, and that they show the relevant output or terminal behavior.


