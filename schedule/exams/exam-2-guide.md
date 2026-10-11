---
layout: default
course_number: CS330
title: Network Applications and Protocols
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Exam 2

## Date: Oct 20, 2026

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

Chapter 3
-----------------------

This exam is really a check on whether you understand how the transport layer makes communication work between applications. You do not need to memorize every detail in a vacuum; you need to understand what each mechanism is doing, why it exists, and how the pieces fit together.

## What to focus on

### 1. Why the transport layer matters
- Be comfortable explaining the job of the **transport layer**: it sits between application programs and the network, and it handles communication between processes.
- Know the difference between **multiplexing** and **demultiplexing**.
- Understand how **port numbers** are used to identify different application flows.
- Be able to explain how multiple applications can share the same host and network connection without mixing data together.

### 2. UDP: simple and lightweight
- Review the basic idea of **UDP** and when it is useful.
- Know that UDP is **connectionless**, **best-effort**, and does not provide retransmission, ordering, or flow control.
- Understand the purpose of the **UDP header**, including source and destination ports, length, and checksum.
- Be ready to compare **UDP vs. TCP** in terms of reliability, overhead, and use cases.

### 3. Reliable data transfer
- Know why reliable transfer matters and what problems it solves.
- Review the idea of **ACKs**, **sequence numbers**, **timeouts**, and **retransmissions**.
- Understand the difference between **stop-and-wait** and more advanced schemes, even if the exam will not require a full protocol design from scratch.
- Be able to explain what a **finite state machine (FSM)** is in the context of reliable transfer and why it matters for protocol behavior.

### 4. TCP services and design goals
- Understand the main features of **TCP**:
  - Reliable delivery
  - In-order delivery
  - Flow control
  - Congestion control
  - A byte-stream abstraction
- Know that TCP provides a **connection-oriented** service, even though it is still sending packets through an IP network.
- Be ready to explain how TCP turns a stream of bytes into packets and then reassembles them correctly at the receiver.

### 4a. Flow control
- Understand that **flow control** is different from **congestion control**.
- Know that flow control is about making sure the **receiver is not overwhelmed** by data it cannot process or buffer fast enough.
- Review the idea of the **receive window** and how the receiver tells the sender how much more data it is willing to accept.
- Be ready to explain how **advertised window size** helps match sender transmission to receiver capacity.
- Understand that flow control protects the receiver, while congestion control protects the network as a whole.
- If you can explain why a sender might need to slow down even when the network is fine, you are on the right track.

### 5. Connection management
- Review the **three-way handshake**: SYN, SYN/ACK, ACK.
- Understand why sequence numbers and acknowledgments are needed.
- Know how TCP establishes a connection and how it closes one cleanly.
- Be able to explain the difference between connection establishment and connection teardown, and why both are necessary.

### 6. RTT, timeout estimation, and loss recovery
- Know what **RTT** means and why it matters.
- Understand how TCP uses **RTT** to set timeouts and estimate when a packet may have been lost.
- Review the idea of **retransmission** and why a timeout that is too short or too long is a problem.
- Be comfortable explaining why accurate RTT estimation is important for good performance.

### 7. Congestion control
- This is one of the big ideas in Chapter 3.
- Know the basic phases of **TCP congestion control**:
  - **Slow Start**
  - **Congestion Avoidance**
  - **Fast Retransmit**
  - **Fast Recovery**
- Understand the idea of **AIMD**: additive increase, multiplicative decrease.
- Be ready to explain how TCP slows down when the network is congested and speeds up again when conditions improve.
- Make sure you understand the purpose of congestion control: keep the network stable without starving other traffic.

### 8. TCP vs. UDP in plain English
- Be able to compare them directly.
- **TCP** is better when you need reliability, ordering, and a controlled data stream.
- **UDP** is better when speed, simplicity, and low overhead matter more than guaranteed delivery.
- If you can explain the trade-off in a sentence, you are in good shape.

---

## Quick self-check questions

If you can answer these without looking at your notes, you are in a strong position:

- What is the difference between multiplexing and demultiplexing?
- Why do we use port numbers in transport-layer communication?
- What problem does TCP solve that UDP does not?
- Why do we need sequence numbers and acknowledgments?
- How does flow control prevent a fast sender from overwhelming a slow receiver?
- What happens during the TCP three-way handshake?
- Why does TCP need congestion control?
- What is the purpose of a timeout in reliable data transfer?
- How is UDP different from TCP in terms of reliability and overhead?
- Why are sockets important when building network applications?
- How does TCP deal with lost packets without completely collapsing performance?
- Review the **TCP FSM** from the slides and make sure you can describe the main states and transitions in words.
- 
---

## Exam Guidelines

- **Format:** Open-book, open-notes.
- **Duration:** Entire class period.
- **Content:** May include a programming component and\or a Wireshark portion.
- **Number of Exams:** 4 total.
- **Make-Up Policy:** Make-up exams require prior approval unless due to a documented emergency or illness.

---

This chapter is not about memorizing a bunch of isolated definitions. It is mostly about understanding how data gets from one application to another reliably, how loss and congestion are handled, and how the transport layer balances performance with correctness.

Good luck with your exam prep!
