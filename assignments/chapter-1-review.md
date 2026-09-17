---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330 Homework: Chapter 1

## Due: Tuesday, Sep 15, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Network Transmission Scenario (15 pts)
Consider a single router transmitting packets, each of size **_L_ bits**, over a single link to another router. The link has a transmission rate of **_R_ Mbps**.

**Given:**
- Packet size: _L_ = **16,000 bits**
- Link transmission rate: _R_ = **400 Mbps**

### Questions:

1. **Compute the one-hop transmission delay.**  
   - Express your answer in **seconds**, rounded to **two decimal places after leading zeros**.
  <br/>
  <code>
    Transmission delay = L / R = 16,000 / (400 × 10^6) = 0.00004 sec
  </code>

2. **Determine the maximum number of packets per second** that can be transmitted over this link.
  <br/>
  <code>
    Packets/sec = R / L = (400 × 10^6) / 16,000 = 25,000 packets/sec
  </code>

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
  
  <br/>
  <code>
    Link 1 transmission delay = L/R = 4000 bits / (10 Mbps *10^6) = 0.0004 seconds<br/>
    Link 1 propagation delay = d/s = (3 Km * 1000) / 3*10^8 m/sec = 0.00001 seconds<br/>
    Link 1 total delay = 0.0004 seconds + 0.00001 seconds = 0.00041 seconds<br/>
    <br/>
    Link 2 transmission delay = L/R = 4000 bits / (100 Mbps  *10^6) = 0.00004 seconds<br/>
    Link 2 propagation delay = d/s = (1000 Km * 1000) / 3*10^8 m/sec = 0.00333 seconds<br/>
    Link 2 total delay = 0.00004 seconds + 0.00333 seconds = 0.0034 seconds<br/>
    <br/>
    Link 3 transmission delay = L/R = 4000 bits / (1000 Mbps * 10^6) = 0.000004 seconds<br/>
    Link 3 propagation delay = d/s = (1 Km * 1000) / 3*10^8 m/sec = 0.00000333 seconds<br/>
    Link 3 total delay = 0.000004 seconds + 0.00000333 seconds = 0.00000733 seconds<br/>
    <br/>
    The total delay = 0.00041 seconds + 0.0034 seconds + 0.00000733 seconds = 0.0038 seconds
  </code>

##  End-to-End Packet Delay Analysis (10 pts)
Consider sending a packet from a **source host** to a **destination host** over a fixed network route.

### Questions:

1. **List and briefly describe the major components** of the **end-to-end delay** experienced by the packet.
  <br/>
  <code>
    The delay components are processing delays, transmission delays, propagation delays, and queuing delays.
  </code>

2. **Classify each delay component** as either **constant** or **variable**, and explain why.
  <br/>
  <code>
    All of these delays are fixed, except for the queuing delays, which are variable.
  </code>

## Circuit vs. Packet Switching Scenario(45 pts)
Consider the two scenarios below:

- A **circuit-switching** scenario in which _N<sub>cs</sub>_ users, each requiring a bandwidth of **10 Mbps**, must share a link of capacity **150 Mbps**.
- A **packet-switching** scenario with _N<sub>ps</sub>_ users sharing the same **150 Mbps** link, where each user again requires **10 Mbps** when transmitting, but only needs to transmit **20%** of the time.

Round all your answers to **two decimal places after leading zeros**.

### Questions:
1. **When circuit switching is used**, what is the **maximum number of users** that can be supported?
  <br/>
  <code>
    Max Users: 150 Mbps / 10 Mbps = 15 Users
  </code>

2. **Suppose packet switching is used**, if there are **29 users**, can this many users be supported under circuit-switching? Why?
  <br/>
  <code>
  No. 29 Users * 10 Mbps = 290 Mbps, which is greater than 150 Mbps of link capacity available
</code>

3. If there are **29 packet-switching users**, what is the **probability that a given (specific) user is transmitting**, and the remaining users are not transmitting?
  <br/>
  <code>
    p = 0.20
    <br/>
    𝑝 ∗ (1 − 𝑝)<sup>(29 − 1)</sup> = (0.20) * (0.80)<sup>28</sup> ~ 0.00038685 ~ 0.00039
</code>

4. What is the **probability that one user (any one among the 29)** is transmitting, and the remaining users are not transmitting?  
   _(Assume packet switching is used.)_
  <br/>
  <code>
   29 ∗ 𝑝 ∗ (1 − 𝑝)<sup>(29 − 1)</sup> = 29 * 0.20 * (0.80)<sup>28</sup> ~ 0.01121 ~ 0.011
  </code>

5. **When one user is transmitting**, what **fraction of the link capacity** is used by this user?  
   Write your answer as a **decimal number**.  _(Assume packet switching is used.)_
  <br/>
  <code>
  10 Mbps over the 150 Mbps link, or 10 Mbps / 150 Mbps = 6.7% of the link's capacity when busy.
  </code>

6. When packet switching is used, what is the **probability that any 16 users** (of the total 29 users) are transmitting and the remaining users are not transmitting?
  <br/>
  <code>
  (29 choose 16) * 𝑝<sup>16</sup> ∗ (1 − 𝑝)<sup>(29-16)</sup> = (29 choose 16) * 0.20<sup>16</sup> * 0.80<sup>(29-16)</sup> ~ 0.000024450 ~ 0.0000245
  </code>
  <br/>
  <a href="https://www.wolframalpha.com/input?i=%2829+choose+16%29+*+0.2%5E16+*+0.8%5E%2829-16%29">Wolfram Alpha</a>


7. When packet switching is used, what is the **probability that more than 15 users** are transmitting?
  <br/>
  <code>
   Sum{(29 choose n) * p <sup>n</sup> * (1 - p)<sup>(29 - n)</sup>}, for n = 16 to 29 => sum{(29 choose n) * 0.20<sup>n</sup> * 0.80<sup>(29-n)</sup>}, for n = 16 to 29 => 0.000030032 ~ 0.00003
  </code>
  <br/>
  <a href="https://www.wolframalpha.com/input?i=sum%7B%2829+choose+n%29+*+0.20%5En+*+0.80%5E%2829-n%29%7D%2C+for+n+%3D+16+to+29">Wolfram Alpha</a>

## TCP/IP Stack Concept Check (5 pts)
Which layer of the **TCP/IP protocol stack** is responsible for **handling messages from various network applications**?
  <br/>
  <code>
    Application layer
  </code>

### Submit

Post your solutions in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

