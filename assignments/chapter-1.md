---
layout: default
course_number: CS330
title: "Homework: Chapter 1"
---

# Chapter 1 Homework

## Network Transmission Scenario (15 pts)
Consider a single router transmitting packets, each of size **_L_ bits**, over a single link to another router. The link has a transmission rate of **_R_ Mbps**.

**Given:**
- Packet size: _L_ = **16,000 bits**
- Link transmission rate: _R_ = **400 Mbps**

### Questions:

1. **Compute the one-hop transmission delay.**  
   - Express your answer in **seconds**, rounded to **two decimal places after leading zeros**.

2. **Determine the maximum number of packets per second** that can be transmitted over this link.

## Multi-Link Network Delay Calculation (25 pts)
Consider a network with three links, each with the specified transmission rate and link length:

- **Link 1**: Transmission rate = _10 Mbps_, Length = _3 Km_
- **Link 2**: Transmission rate = _100 Mbps_, Length = _1000 Km_
- **Link 3**: Transmission rate = _1000 Mbps_, Length = _1 Km_

The packet being transmitted is **4,000 bits** in size.  
Assume the speed of light is **3 × 10⁸ m/sec**.

### Questions:

1. **Calculate the transmission and propagation delays** for each of the three links.
   - Express all answers in **seconds**, rounded to **two decimal places after leading zeros**.

2. **Compute the total end-to-end delay** for transmitting the packet from the source to the destination across all three links.

##  End-to-End Packet Delay Analysis (10 pts)
Consider sending a packet from a **source host** to a **destination host** over a fixed network route.

### Questions:

1. **List and briefly describe the major components** of the **end-to-end delay** experienced by the packet.

2. **Classify each delay component** as either **constant** or **variable**, and explain why.

## Circuit vs. Packet Switching Scenario(45 pts)
Consider the two scenarios below:

- A **circuit-switching** scenario in which _N<sub>cs</sub>_ users, each requiring a bandwidth of **10 Mbps**, must share a link of capacity **150 Mbps**.
- A **packet-switching** scenario with _N<sub>ps</sub>_ users sharing the same **150 Mbps** link, where each user again requires **10 Mbps** when transmitting, but only needs to transmit **20%** of the time.

Round all your answers to **two decimal places after leading zeros**.

### Questions:

1. **When circuit switching is used**, what is the **maximum number of users** that can be supported?

2. **Suppose packet switching is used**, if there are **29 users**, can this many users be supported under circuit-switching? Why?

3. If there are **29 packet-switching users**, what is the **probability that a given (specific) user is transmitting**, and the remaining users are not transmitting?

4. What is the **probability that one user (any one among the 29)** is transmitting, and the remaining users are not transmitting?  
   _(Assume packet switching is used.)_

5. **When one user is transmitting**, what **fraction of the link capacity** is used by this user?  
   Write your answer as a **decimal number**.  _(Assume packet switching is used.)_

6. When packet switching is used, what is the **probability that any 16 users** (of the total 29 users) are transmitting and the remaining users are not transmitting?

7. When packet switching is used, what is the **probability that more than 15 users** are transmitting?

## TCP/IP Stack Concept Check (5 pts)
Which layer of the **TCP/IP protocol stack** is responsible for **handling messages from various network applications**?

### Submit

Post your solutions in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.
