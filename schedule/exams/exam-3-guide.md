---
layout: default
course_number: CS330
title: "Exam 3 - Study Guide"
---

# Exam 3 — Study Guide  
**Date: November 10, 2026**

---

## Network Layer

#### Routing Processor
- Executes routing protocols (OSPF, BGP, RIP, etc.).
- Maintains the routing table and forwarding information base (FIB).
- Handles control-plane tasks such as topology computation and route updates.

#### Switch Fabric
- Internal network that transfers packets from **input ports** to **output ports**.
- Types of switch fabrics:
  - **Memory-based**
  - **Bus-based**
  - **Crossbar-based**
- Understand how switch fabric design affects throughput and performance.

#### Input and Output Ports
- **Input Ports:**
  - Perform physical-layer and link-layer processing.
  - Carry out forwarding table lookups.
  - May include input buffering (susceptible to Head-of-Line (HOL) blocking).
- **Output Ports:**
  - Handle **scheduling**, buffering, and transmission onto the outgoing link.
  - Implement output queueing and packet scheduling algorithms.

#### IPv4 Fragmentation
- Fragmentation occurs when a packet exceeds the **Maximum Transmission Unit (MTU)** of the outgoing link.
- Relevant IPv4 header fields:
  - **Identification**
  - **Flags** (DF = Don’t Fragment, MF = More Fragments)
  - **Fragment Offset**
- Key concepts:
  - Fragmentation can be done by routers or hosts.
  - **Reassembly** happens **only at the destination**.
  - Fragmentation can cause inefficiency and increased packet loss impact.

### Intra-AS vs. Inter-AS Routing
- Understand the distinction between:
  - **Intra-AS routing** (Interior Gateway Protocols such as OSPF, RIP): routing **within** a single Autonomous System.
  - **Inter-AS routing** (Exterior Gateway Protocols such as BGP): routing **between** Autonomous Systems.
- Be able to explain **why both types are required** and how they support scalable global routing.

### Traceroute and ICMP
- Know how **Traceroute** discovers the path to a destination by manipulating TTL values.
- Understand how ICMP **Time Exceeded** and **Echo Reply** messages are used in the process.
- Be prepared to describe the purpose of each step in Traceroute’s operation.

### Routing / Forwarding Table Construction
- Understand how to construct a forwarding table, including:
  - Destination networks or prefixes  
  - Next-hop router  
  - Metrics or costs  
- Be familiar with how routers use this information to forward packets.

### Routing Algorithms

#### Link-State Routing (Dijkstra’s Algorithm)
- Know the key steps of **Dijkstra’s algorithm** for computing shortest-path trees.
- Understand the role of the **Link-State Database (LSDB)**.
- Know how routers exchange topology information using **Link-State Advertisements (LSAs)**.

#### Distance Vector Routing (Bellman-Ford Algorithm)
- Understand how the **Bellman-Ford algorithm** updates distance vectors and converges.
- Be prepared to explain:
  - How routers share distance vector information  
  - Convergence behavior  
  - Limitations such as the **count-to-infinity problem**

---

### Resources
- [Dijkstra's Algorithm](../slides/dijkstra_algorithm.pdf)  
- [CS360: Bellman–Ford Algorithm](https://ycpcs.github.io/cs360-spring2019/lectures/lecture21.html)  
- [CS360: Dijkstra’s Algorithm](https://ycpcs.github.io/cs360-spring2019/lectures/lecture22.html)

---

## Link Layer

### Services Provided by the Data Link Layer
Be able to list and explain key services:
- **Framing**  
- **Error detection** (e.g., checksums, CRC)  
- **Error correction** (e.g., forward error correction)  
- **Medium access control (MAC)** for shared channels  

---

# Exam Guidelines

- **Format:** Open-book, open-notes  
- **Duration:** Full class period  
- **Content:** May include a **programming component**  
- **Total Exams:** 4 (the **lowest score is dropped**)  
- **Make-Up Policy:**  
  - Requires **prior approval** unless due to a **documented emergency or illness**

---

Good luck with your exam prep!