---
layout: default
course_number: CS330
title: Network Applications and Protocols
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Exam 3

## Date: Nov 10, 2026

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

Chapters 4 - 5
-----------------------

This exam is a check on whether you understand IP addressing, how packets move through a network, and how routers choose where to send them. Focus on explaining how the pieces fit together and working through subnetting, routing, and forwarding examples, rather than memorizing isolated terms.

## What to focus on

### 1. How routers process packets
- Understand the roles of the **routing processor**, **switch fabric**, and **input and output ports**.
- Know that the routing processor handles control-plane tasks, including routing protocols and route updates.
- Compare **memory-based**, **bus-based**, and **crossbar-based** switch fabrics, and understand how their designs affect throughput.
- Review the work performed at input and output ports, including forwarding-table lookups, buffering, scheduling, and transmission.
- Understand **Head-of-Line (HOL) blocking** and how input buffering can contribute to it.

### 2. IP addressing and subnetting
- Understand how an IP address is divided into a **subnet portion** and a **host portion**.
- Know how **CIDR prefix notation** (such as `/24`) identifies the number of bits in the subnet portion.
- Be able to identify subnet addresses from host addresses and a given prefix length.
- Practice recognizing which addresses belong to the same subnet, including prefixes that are not `/24`.

### 3. Forwarding tables
- Be able to construct and read a forwarding table with destination prefixes, next hops, and metrics or costs.
- Understand how routers use forwarding information to send packets toward their destinations.
- Keep the distinction between **routing** (choosing paths) and **forwarding** (moving packets from an input to an output) clear.

### 4. IPv4 fragmentation
- Understand why fragmentation occurs when a packet is larger than the outgoing link's **Maximum Transmission Unit (MTU)**.
- Know the purpose of the IPv4 **Identification**, **Flags** (DF and MF), and **Fragment Offset** fields.
- Be ready to explain how fragments are identified and reassembled.
- Remember that reassembly happens at the **destination**, and that fragmentation can increase inefficiency and the impact of packet loss.

### 5. IPv6
- Know that IPv6 uses **128-bit addresses** and was introduced in part to address the exhaustion of IPv4's 32-bit address space.
- Review the main IPv6 header fields, including **Payload Length**, **Next Header**, **Hop Limit**, **Traffic Class**, and **Flow Label**.
- Understand key differences from the IPv4 header: IPv6 has no header checksum, options are handled through extension headers, and routers do not fragment IPv6 packets.
- Understand how **tunneling** carries an IPv6 packet inside an IPv4 packet to support networks with both IPv4 and IPv6 routers.

### 6. Intra-AS and inter-AS routing
- Compare **intra-AS routing**, which routes within one Autonomous System, with **inter-AS routing**, which routes between Autonomous Systems.
- Know that protocols such as **OSPF** and **RIP** are used for intra-AS routing, while **BGP** is used for inter-AS routing.
- Be able to explain why both types are needed to support scalable global routing.

### 7. Traceroute and ICMP
- Understand how **Traceroute** discovers a path by sending probes with increasing **TTL** values.
- Know how routers use **ICMP Time Exceeded** messages and how the destination may respond.
- Be prepared to describe the purpose of each step and how the results reveal the route toward a destination.

### 8. Link-state routing
- Review how **Dijkstra's algorithm** computes shortest paths and builds a shortest-path tree.
- Understand the role of the **Link-State Database (LSDB)**.
- Know how routers distribute topology information using **Link-State Advertisements (LSAs)**.
- Practice following the algorithm on a small network graph.

### 9. Distance-vector routing
- Review how the **Bellman-Ford algorithm** updates distance vectors using information from neighboring routers.
- Understand how routers share information and how the routing process converges.
- Be ready to explain limitations such as the **count-to-infinity problem**.
- Practice calculating updated costs and next hops from a small distance-vector table.

---

## Quick self-check questions

If you can answer these without looking at your notes, you are in a strong position:

- What is the difference between routing and forwarding?
- What does each of the routing processor, switch fabric, input ports, and output ports do?
- How do memory-based, bus-based, and crossbar-based switch fabrics differ?
- What is Head-of-Line blocking?
- Given an IP address and a CIDR prefix, how can you identify its subnet address?
- What do the subnet and host portions of an IP address represent?
- Which IPv4 header fields are used for fragmentation, and where are fragments reassembled?
- How does IPv6 addressing differ from IPv4, and what are some important IPv6 header differences?
- What is IPv6 tunneling, and why is it used during the transition from IPv4?
- How does a router use a forwarding table to choose an output?
- What is the difference between intra-AS and inter-AS routing, and why do networks need both?
- How does Traceroute use TTL and ICMP messages to discover a path?
- How does Dijkstra's algorithm use link-state information to find shortest paths?
- How does distance-vector routing update route costs, and what is count-to-infinity?

---

## Resources

- [Dijkstra's Algorithm](../slides/dijkstra_algorithm.pdf)
- [CS360: Bellman-Ford Algorithm](https://ycpcs.github.io/cs360-spring2019/lectures/lecture21.html)
- [CS360: Dijkstra's Algorithm](https://ycpcs.github.io/cs360-spring2019/lectures/lecture22.html)

---

## Exam Guidelines

- **Format:** Open-book, open-notes.
- **Duration:** Entire class period.
- **Content:** May include a programming component and a Wireshark portion.
- **Number of Exams:** 4 total.
- **Make-Up Policy:** Make-up exams require prior approval unless due to a documented emergency or illness.

---

## Best ways to study

- Work through a small forwarding-table example and trace how a packet is sent to its next hop.
- Practice finding subnet addresses from IP addresses and CIDR prefixes, including a prefix such as `/23`.
- Practice fragmenting an IPv4 packet and interpreting the relevant header fields.
- Compare IPv4 and IPv6 headers, and review how tunneling carries IPv6 traffic across IPv4 networks.
- Draw a small network graph and work through Dijkstra's algorithm by hand.
- Use a small distance-vector table to practice updating costs and identifying next hops.
- Review Traceroute examples and explain what each TTL and ICMP response tells you.
- Focus on explaining why each mechanism exists and how it contributes to packet delivery.

The exam is not meant to trick you with obscure terminology. It is mostly checking whether you understand IP addressing, how routers move packets, how routing information is used to choose paths, and how the network layer handles challenges such as packet size, address space, and changing routes.

Good luck with your exam prep!
