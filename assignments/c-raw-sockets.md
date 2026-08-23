---
layout: default
course_number: CS330
title: "Programming Assignment: Ping and Traceroute using C raw sockets"
---
### Background
- ICMP is used by hosts and routers to communicate network-layer information. The most common use of ICMP is to send error messages and operational information indicating, for example, that a requested service is unavailable or that a host or router could not be reached.
- ICMP differs from transport protocols such as TCP and UDP in that it is not typically used to exchange user data between systems, with the exception of diagnostic tools like *ping* and *traceroute*.
- ICMP is often considered part of IP, but architecturally it lies just above IP. ICMP messages are carried inside IP datagrams—meaning they are transmitted as IP payload just like TCP or UDP segments.

### Objective
- The goal of this assignment is to become familiar with low-level network programming by implementing two widely used network diagnostic utilities: **ping** and **traceroute**.
- These tools require the use of **raw sockets**, so you must run your program with **root privileges**.
- All code must be **well-documented**. Points will be deducted for insufficient documentation. Add comments explaining the functionality of each function, variable, and significant block of code.

---

### Ping
- Your program should send **10 ICMP Echo Request** messages to a target server (specified as an IP address or hostname).
- For each ping:
  - Wait for the corresponding ICMP Echo Reply.
  - Calculate and display the **Round-Trip Time (RTT)** in milliseconds.

#### Handling Packet Loss
- Networks may drop packets, so your program should not wait indefinitely for a reply.
- Set a **2-second timeout** for each response.
- If no reply is received in that time, assume the packet was lost and print an appropriate timeout message.

---

### Traceroute
- Extend your ping program to implement **traceroute**.

#### How Traceroute Works
- Traceroute sends packets with increasing **TTL (Time-to-Live)** values starting at 1, incrementing by 1 after each hop.
- When a packet’s TTL expires at a router:
  - The router discards the packet.
  - It sends an **ICMP Time Exceeded** message (type 11, code 0) back to the source.
  - This message includes the IP address and sometimes the hostname of the router.

#### What Your Program Should Do
- Upon receiving an ICMP message, your program should:
  - Compute the **RTT** using timestamps.
  - Extract the router’s **IP address** and (if available) **hostname**.

#### Stopping Criteria
- Continue increasing the TTL until the destination host responds with:
  - **ICMP Echo Reply** (type 0, code 0)
- Once received, the destination has been reached and the traceroute ends.

---

### Code Snippets
- [checksum.c](files/checksum.c)
- [get_host.c](files/get_host.c)
- [ping-skeleton.c](files/ping-skeleton.c)

---

### References
- [RFC 792](http://tools.ietf.org/html/rfc792)
- Linux manual pages: 
  - [socket](https://linux.die.net/man/2/socket) 
  - [ip](https://www.man7.org/linux/man-pages/man7/ip.7.html)
  - [sendto](https://linux.die.net/man/3/sendto)
  - [recvfrom](https://linux.die.net/man/3/recvfrom)
  - [gethostbyname](https://www.man7.org/linux/man-pages/man3/gethostbyname.3.html)
  - [getnameinfo](https://www.man7.org/linux/man-pages/man3/getnameinfo.3.html)
  - [setsockopt](https://linux.die.net/man/3/setsockopt)
- Example of setting TTL:
```c
setsockopt(sock, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
```

--- 

### Discussion Questions

1. **ICMP and Packet Behavior**
   - What is the purpose of ICMP in the network stack, and how does it differ from TCP and UDP?
   - Why must ping and *traceroute* use raw sockets instead of standard socket types?
   - What fields in the ICMP Echo Request and Echo Reply messages does your program need to set or parse?
   - Why does *traceroute* rely on TTL expiration to discover intermediate routers?

2. **Timing and Measurements**
   - How did you measure the Round-Trip Time (RTT)? What functions or system calls did you use?
   - What factors can cause RTT values to fluctuate between pings?
   - How accurate do you believe your RTT calculations are? What might introduce error?

3. **Packet Loss and Timeouts**
   - What conditions might cause a *ping* request to time out even on a healthy network?
   - How did you implement the 2-second timeout (e.g., `select()`, `setsockopt()`, etc.)?
   - What differences did you observe between packet loss in *ping* and missing responses during *traceroute*?

4. **Traceroute Behavior**
   - Did any routers along the path fail to respond with Time Exceeded messages? Why might some hops not respond?
   - Did you observe any hops where the hostname could not be resolved? What does that indicate about DNS configuration?
   - What determines the maximum number of hops needed before *traceroute* terminates?

5. **Implementation Details**
   - What challenges did you face when constructing raw ICMP packets?
   - How did you verify that your checksum implementation was correct?
   - Did you encounter permission issues when using raw sockets? How did you address them?

6. **Testing and Wireshark Analysis**
   - How did Wireshark help you verify your program’s correctness?
   - Did the packets captured by Wireshark match your expected ICMP packet structure?
   - What differences did you notice between how Linux and other operating systems generate ICMP packets (if applicable)?

7. **Reflection and Extensions**
   - If the *ping* utility were extended to IPv6, how would the implementation change?
   - How could *traceroute* be redesigned using UDP or TCP instead of ICMP?
   - What additional features could improve your diagnostic tools?

--- 

### Extra Credit
- In addition to displaying the Round-Trip Time (RTT) for each individual ping, your program should also compute and display the following statistics at the end of the test:
  - **Minimum RTT:** The shortest round-trip time recorded.
  - **Maximum RTT:** The longest round-trip time recorded.
  - **Average RTT:** The average round-trip time for all successful ping replies.
- **Packet Loss Calculation:**
  - Your program should calculate and display the packet loss rate as a percentage, based on the number of successful replies compared to the total number of packets sent.
- **Ping Rate:**
  - The standard `ping` utility sends one request per second. Modify your program to follow this behavior by introducing a **1-second delay** between each ping request.
  - **Important:** Do *not* send the next ping immediately after receiving a reply; always wait a full second between transmissions.

---

### Testing
- Use **Wireshark** to capture and analyze packets sent and received by your program.
- Verify that:
  - ICMP Echo Requests and Echo Replies are formed correctly.
  - TTL values increment properly for the traceroute.
  - Routers respond with **ICMP Time Exceeded** messages as expected.
  - Timing and RTT values match what you observe in packet captures.

---

### Grading and Submission

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

#### 1. Code Submission
- Submit the complete source code for your ping and traceroute implementations.
- All required files should be included (e.g., `ping.c`, `traceroute.c`, helper modules, headers, etc.).
- Code must compile and run without modification.

#### 2. Wireshark Packet Capture
- Submit a Wireshark packet capture showing your program sending and receiving ICMP Echo Requests, Echo Replies, and (for traceroute) ICMP Time Exceeded messages.
- Ensure your capture clearly includes:
  - ICMP Echo Request and Echo Reply packets for ping.
  - TTL-limited probes and the corresponding Time Exceeded responses for traceroute.
- Save the capture in **`.pcapng`** format.

#### 3. Questions / Observations
- Provide answers to any discussion questions as well as a brief write-up containing:
  - Observations you made during development and testing.
  - Any issues or bugs you encountered and how you resolved them.
  - Any assumptions or constraints applied during your implementation (e.g., testing only on `localhost`, running as root, OS-specific behavior, etc.).
- Include screenshots where relevant, ensuring they are **clear, readable, and show packet details**.


> **Note:** Double-check that any screenshots clearly show packet details and are legible.

