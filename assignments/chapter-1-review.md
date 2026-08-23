---
layout: default
course_number: CS330
title: "Homework: Chapter 1 Review"
---

# Chapter 1 Homework

## Network Transmission Scenario (15 pts)
Consider a single router transmitting packets, each of size **_L_ bits**, over a single link to another router. The link has a transmission rate of **_R_ Mbps**.

**Given:**
- Packet size: _L_ = **12,000 bits**
- Link transmission rate: _R_ = **600 Mbps**

### Questions:

1. **Compute the one-hop transmission delay.**  
   - Express your answer in **seconds**, rounded to **two decimal places after leading zeros**.
  <br/>
  <code>
    Transmission delay = L / R = 12,000 / (600 × 10^6) = 0.00002 sec
  </code>

2. **Determine the maximum number of packets per second** that can be transmitted over this link.
  <br/>
  <code>
    Packets/sec = R / L = (600 × 10^6) / 12,000 = 50,000 packets/sec
  </code>

## Multi-Link Network Delay Calculation (25 pts)
Consider a network with three links, each with the specified transmission rate and link length:

- **Link 1**: Transmission rate = _200 Mbps_, Length = _10 Km_
- **Link 2**: Transmission rate = _50 Mbps_, Length = _3000 Km_
- **Link 3**: Transmission rate = _150 Mbps_, Length = _2 Km_

The packet being transmitted is **9,000 bits** in size.  
Assume the speed of light is **3 × 10⁸ m/sec**.

### Questions:

1. **Calculate the transmission and propagation delays** for each of the three links.
   - Express all answers in **seconds**, rounded to **two decimal places after leading zeros**.
  <br/>
  <code>
    Link 1 Transmission delay: 9000 / (200 × 10^6) = 0.000045 sec <br/>
    Link 1 Propagation delay: 10,000 / (3 × 10^8) = 0.000033 sec <br/>
    Link 2 Transmission delay: 9000 / (50 × 10^6) = 0.00018 sec <br/>
    Link 2 Propagation delay: 3,000,000 / (3 × 10^8) = 0.01 sec <br/>
    Link 3 Transmission delay: 9000 / (150 × 10^6) = 0.00006 sec <br/>
    Link 3 Propagation delay: 2,000 / (3 × 10^8) = 0.0000067 sec <br/>
  </code>

1. **Compute the total end-to-end delay** for transmitting the packet from the source to the destination across all three links.

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

- A **circuit-switching** scenario in which _N<sub>cs</sub>_ users, each requiring a bandwidth of **30 Mbps**, must share a link of capacity **180 Mbps**.
- A **packet-switching** scenario with _N<sub>ps</sub>_ users sharing the same **180 Mbps** link, where each user again requires **30 Mbps** when transmitting, but only needs to transmit **25%** of the time.

Round all your answers to **two decimal places after leading zeros**.

### Questions:

1. **When circuit switching is used**, what is the **maximum number of users** that can be supported?
  <br/>
  <code>
    Max Users: 180 Mbps / 30 Mbps = 6 Users  
  </code>

2. **When packet switching is used**, if there are **13 users**, can this many users be supported under circuit-switching?
  <br/>
  <code>
    No. 13 Users * 30 Mbps = 390 Mbps, which is greater than 180 Mbps
  </code>

3. If there are **13 packet-switching users**, what is the **probability that a given user is transmitting**, and the remaining users are not transmitting?
  <br/>
  <code>
    p = 0.25
    <br/>
    𝑝 ∗ (1 − 𝑝)<sup>(13 − 1)</sup> = (0.25) × (0.75)^12 ~ 0.007919 ~ 0.0079
  </code>

4. What is the **probability that one user (any one among the 13)** is transmitting, and the remaining users are not transmitting?  
  _(Assume packet switching is used.)_
  <br/>
  <code>
    13 ∗ 𝑝 ∗ (1 − 𝑝)<sup>(13 − 1)</sup> = 13 * (0.25) × (0.75)^12 ~ 0.1029 ~ 0.10
  </code>

5. **When one user is transmitting**, what **fraction of the link capacity** is used by this user?  
   Write your answer as a **decimal number**.
  <br/>
  <code>
    30 Mbps over the 180 Mbps link or 16.66% of the link’s capacity when busy
  </code>

6. When packet switching is used, what is the **probability that exactly 7 users** (of the total 13) are transmitting and the remaining users are not transmitting?
  <br/>
  <code>
    (13 choose 7) * 𝑝<sup>7</sup> ∗ (1 − 𝑝)<sup>(13-7)</sup> = (13 choose 7) * 0.25<sup>7</sup> * 0.75<sup>(13-7)</sup> ~ 0.01864 ~ 0.019
  </code>
  <br/>
  <a href="https://www.wolframalpha.com/input?i=%2813+choose+7%29+*+0.25+%5E+7+*+0.75+%5E+%2813-7%29">Wolfram Alpha</a>

7. When packet switching is used, what is the **probability that more than 7 users** are transmitting?
  <br/>
  <code>
    Sum{(13 choose n) * p <sup>n</sup> * (1 - p)<sup>(13 - n)</sup>}, for n = 8 to 13 => sum{(13 choose n) * 0.25<sup>n</sup> * 0.75<sup>(13-n)</sup>}, for n = 8 to 13 => 0.0056493282318115234375 ~ 0.0056
  </code>
  <br/>
  <a href="https://www.wolframalpha.com/input?i=sum%7B%2813+choose+n%29+*+0.25+%5E+n+*+0.75+%5E+%2813-n%29%7D%2C+for+n+%3D+8+to+13">Wolfram Alpha</a>

## TCP/IP Stack Concept Check (5 pts)
Which layer of the **TCP/IP protocol stack** is responsible for **handling messages from various network applications**?
  <br/>
  <code>
    Application layer
  </code>

### Submit

Post your solutions in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.
