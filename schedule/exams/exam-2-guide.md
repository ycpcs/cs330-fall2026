---
layout: default
course_number: CS330
title: "Exam 2 - Study Guide"
---

Exam 2 - Oct 20, 2026
-----------------------

## Topics to Review

### 1. **Multiplexing and Demultiplexing**
   - **Understand** how multiple applications share the same network connection.
   - **Study** how **port numbers** are used to identify different data streams (source and destination ports).
   - **Make sure you can explain** the difference between **multiplexing** and **demultiplexing**.

### 2. **TCP and UDP Overview**
   - **Understand** the differences between **TCP** and **UDP**.
   - **Study** the **use cases** where TCP is preferred versus UDP.
   - **Make sure you can explain** the trade-offs.

### 3. **TCP Services**
   - **Understand** the following key features of TCP:
     - Reliable delivery.
     - Flow control.
     - Stream-oriented nature (continuous data flow).
   - **Make sure you can explain** how TCP handles data delivery and **congestion**.

### 4. **Connection Management (TCP)**
   - **Understand** the **three-way handshake** process.
   - **Study** the process for **connection termination**.
   - **Ensure you can articulate** how a TCP connection is established and terminated, including the roles of sequence numbers and acknowledgments.

### 5. **Error Detection**
   - **Understand** how **checksums** are used in both TCP and UDP to detect errors.
   - **Examine** the difference between error detection in TCP (reliable) vs. UDP (optional but essential in IPv6).
   - **Make sure you can explain** how checksum fields in both protocols help ensure data integrity.

### 6. **Reliable Data Transfer (TCP)**
   - **Understand** the **finite state machine** of TCP (review slides).
   - **Be ready to define** how TCP handles retransmissions and ensures data is delivered in order, without loss.

### 7. **Round-Trip Time (RTT) and Timeouts**
   - **Review** the concept of **RTT** (time for a round trip between sender and receiver).
   - **Study** how **RTT** is used to dynamically adjust **timeouts** in TCP for retransmissions.
   - **Make sure you can explain** how RTT is measured and why accurate RTT estimation is critical for TCP performance.

### 8. **Congestion Control**
   - **Understand** the phases of TCP congestion control:
     - **Slow Start**: Gradually increase the window size to avoid overwhelming the network.
     - **Congestion Avoidance**: When the network gets congested, slow down the transmission rate.
     - **Fast Retransmit/Fast Recovery**: Recover from lost packets more efficiently.
   - **Master** the **AIMD** (Additive Increase, Multiplicative Decrease) algorithm used in congestion control.
   - **Know how to convey** the different congestion control algorithms and how they avoid network congestion.

### 9. **UDP**
   - **Understand** the characteristics of UDP     
   - **Study** the **UDP header** format and how it differs from TCP.
   - **Make sure you can explain** the trade-offs of using UDP over TCP, including the lack of error recovery and flow control.

### 10. **Sockets and Socket Types**
   - **Understand** the types of sockets:
     - **SOCK_STREAM**: Used for TCP (stream-oriented).
     - **SOCK_DGRAM**: Used for UDP (datagram-oriented).
   - **Be capable of demonstrating** the differences in socket types and how each is used in application development.

### 11. **Programming Component**
   - **Understand** how to create basic **TCP and UDP socket programs**.
   - **Review** how to create sockets in `C` and how they are used to establish connections or send data.
   - **Study** how data is sent and received over sockets, including the **client-server model**.
   - **Have a firm grasp of** how to write simple socket-based programs for both TCP (reliable) and UDP (faster, no connection).
     - Review code examples in Python or C.

---

## Additional Study Tips:

- **Finite State Machine for TCP**: Review **state transitions** from the slides. Understand how TCP ensures reliable delivery using these states.
- **Interactive RTT Tool**: Use the [TCP RTT Simulator](https://gaia.cs.umass.edu/kurose_ross/interactive/TCP_RTT.php) to understand how RTT affects TCP performance and retransmissions.

---

## Exam Guidelines

- **Format:** Open-book, open-notes.
- **Duration:** Entire class period.
- **Content:** May include a **programming component**.
- **Number of Exams:** 4 total. The **lowest score will be dropped**.
- **Make-Up Policy:**
  - Make-up exams require **prior approval** unless due to **documented emergency or illness**.

---

Good luck with your exam prep!
