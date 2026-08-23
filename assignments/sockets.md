---
layout: default  
course_number: CS330  
title: "Introduction to Sockets"  
---

# Programming Lab - Introduction to Sockets

---

### Download and Compile Individually

Download and compile the following files:

- [tcp_client.c](sockets/tcp_client.c)  
- [udp_client.c](sockets/udp_client.c)  
- [tcp_server.c](sockets/tcp_server.c)  
- [udp_server.c](sockets/udp_server.c)

**Example:**  
Compile:  
```bash
gcc tcp_client.c -o tcp_client
```
Run with:  
```bash
./tcp_client
```

> Be sure to stop any running servers or clients and recompile after making changes.

---

## Lab Overview

We will use simple client/server applications to explore **TCP and UDP socket programming**:

- The client reads a line from standard input.
- It sends the line to the server over a socket.
- The server converts the line to **uppercase**.
- The server sends the modified line back to the client.
- The client prints the result to standard output.

---

## TCP vs UDP Quick Reference

| Protocol | Connection | Reliability | Ordering | Use Case        |
| -------- | ---------- | ----------- | -------- | --------------- |
| TCP      | Yes        | Yes         | Yes      | Web, FTP, Email |
| UDP      | No         | No          | No       | DNS, VoIP, TFTP |

---

## Questions

Answer the following in your lab report:

1. **Run `tcp_client` before starting `tcp_server`:**  
   - What happens?  
   - Why?

2. **Run `udp_client` before starting `udp_server`:**  
   - What happens?  
   - Why?

3. **UDP port mismatch:**  
   - Run both programs with different port numbers.  
   - What happens?  
   - Why?

4. **TCP port mismatch:**  
   - Run both programs with different port numbers.  
   - What happens?  
   - Why?

5. **UDP Buffer Test:**  
   - Start the `udp_server`.  
   - Launch `udp_client` and send a message.  
   - While the server is running, rerun `udp_client` and send a **shorter** message.  
     - What happens?  
     - Why?  
     - Fix it. Include your code fix in your submission.

6. **Send buffer limit (udp_client):**  
   - Modify `send_msg` in `udp_client` to allocate **5 bytes instead of 50**.  
   - Restart both client and server.  
   - Send a message longer than 5 bytes.  
     - What happens?  
     - Why?

7. **Receive buffer limit (udp_client):**  
   - Revert previous change and instead reduce `recv_msg` allocation to 5 bytes.  
   - Send a message longer than 5 bytes.  
     - What do you expect?  
     - What actually happened?  
     - Why?

---

## Programming Tasks

### 1. Accept user input for IP and port

Update all programs to prompt the user for:

- **Server IP address** (in client programs)  
- **Server and client port numbers**

**Example:**
```bash
Enter server IP: 127.0.0.1
Enter server port: 9000
```

---

### 2. Loop until QUIT

Update `tcp_client` and `udp_client` to:

- Continuously read input from the user
- Send the message to the server
- Exit the loop when the user types `QUIT`

> Note: Use standard input methods like `fgets()` or `scanf()`. Match `QUIT` exactly (case-sensitive).

---

## Extra Credit (Optional)

- Add multi-client support in `tcp_server`.
- Add logging features (client IP, timestamps, etc.)
- Add error recovery or retry logic in UDP.
- Feel free to experiment and go beyond the lab instructions! Surprise me!

---

## Helpful References

- [Linux socket interface (man 7 socket)](https://linux.die.net/man/7/socket)  
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html/)  
- [Debugging with GDB](https://ftp.gnu.org/old-gnu/Manuals/gdb/html_node/gdb_toc.html)

---

## Testing & Debugging Tools

- [Netcat](http://netcat.sourceforge.net/) – tool for sending and receiving data
- Check open ports:  
  - TCP: `netstat -antop`  
  - UDP: `netstat -anoup`
- Kill processes:  
  - By PID: `kill PID`  
  - By name: `pkill PATTERN`

---

## Grading

Submit your lab report, including answers to all questions, modified source code files and **screenshots**, via [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date listed in the syllabus.


