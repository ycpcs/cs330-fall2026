---
layout: default
course_number: CS330
title: "Exam 1 - Study Guide"
---

Exam 1 - Sept 22, 2026
-----------------------

## Topics to Review

### 1. Circuit Switching vs. Packet Switching
- Understand the **key differences** between circuit and packet switching.
- Compare their **advantages and disadvantages**, such as:
  - Resource reservation
  - Latency
  - Efficiency
  - Scalability

### 2. Router Delays
- Identify and explain the four types of router delays:
  - **Processing delay**
  - **Queuing delay**
  - **Transmission delay**
  - **Propagation delay**
- Be able to **calculate end-to-end delay** using these components.

### 3. Packet Loss
- Understand how and why **packet loss** occurs.
- Discuss the role of **congestion**, **queue overflow**, and **network reliability**.

### 4. TCP/IP Model & Devices
- Identify the **TCP/IP model layers**.
- Know which layers are used by:
  - **Switches**
  - **Routers**
  - **End hosts (computers)**

### 5. Links to ISPs
- Differentiate between:
  - **Dedicated links**
  - **Shared links**
- Understand how each type affects:
  - Bandwidth
  - Performance
  - Reliability

### 6. Security Threats
- Be familiar with common **network attacks** and **malware types**
  
### 7. Network Architectures
- Compare:
  - **Client-server architecture**
  - **Peer-to-peer (P2P) architecture**
- Understand pros and cons related to:
  - Cost
  - Scalability
  - Maintenance

### 8. Sockets
- Understand what a **socket** is in networking.
- Explain its role in enabling **communication between processes** over a network.

### 9. TCP vs. UDP
- Compare the **services provided** by:
  - **TCP**: Reliable, ordered, connection-oriented.
  - **UDP**: Unreliable, unordered, connectionless, lower overhead.
- Know when each is appropriate to use.

### 10. Cookies
- Understand the function of **cookies** in HTTP.
- Know how cookies are used for:
  - Session management
  - Personalization
  - Tracking

### 11. DNS Server Types
- Compare **centralized** vs. **distributed DNS** architectures.
- Understand the trade-offs in:
  - Performance
  - Fault tolerance
  - Scalability

### 12. Common Protocols and Ports
Know the default ports for the following protocols:

| Protocol    | Port(s) | Secure Version     | Notes                   |
| ----------- | ------- | ------------------ | ----------------------- |
| HTTP        | 80      | HTTPS (443)        | Web traffic             |
| DNS         | 53      | DNS over TLS (853) | Name resolution         |
| FTP         | 20, 21  | SFTP (989/990)     | 20 = Data, 21 = Control |
| SMTP        | 25      | SMTPS (465)        | Email sending           |
| POP3        | 110     | POP3S (995)        | Email retrieval         |
| IMAP        | 143     | IMAPS (993)        | Email retrieval         |

---

## Exam Guidelines

- **Format:** Open-book, open-notes.
- **Duration:** Entire class period.
- **Content:** May include a **programming component**.
- **Post-Exam Time:** Any remaining class time may be used for **lecture or lab**.
- **Number of Exams:** 4 total. The **lowest score will be dropped**.
- **Make-Up Policy:**
  - Make-up exams require **prior approval** unless due to **documented emergency or illness**.

---

## Study Tips

- Use **practice problems** to prepare for delay and port-based questions.
- **Sketch diagrams** of the TCP/IP stack and data flow.
- Review **Wireshark traces** to understand protocol behavior.

---

Good luck with your exam prep!
