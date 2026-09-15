---
layout: default
course_number: CS330
title: Network Applications and Protocols
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Exam 1

## Date: Sept 22, 2026

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

Chapters 1 - 2
-----------------------

This exam is really a check on whether you understand how the Internet works at a high level, not just whether you can memorize definitions. If you can explain the ideas in plain English and work through a few calculations, you will be in good shape.

## What to focus on

### 1. How networks are built and how data moves
- Be comfortable comparing **circuit switching** and **packet switching**.
- Know why packet switching is more flexible and why it can suffer from congestion.
- Understand the difference between a **dedicated link** and a **shared link**, and how each affects performance and reliability.

### 2. Delay, loss, and throughput
- Know the four types of delay:
  - **Processing delay**
  - **Queuing delay**
  - **Transmission delay**
  - **Propagation delay**
- Be able to explain what each one means in words, and be ready to calculate **total end-to-end** delay.
- Understand why **packet loss** happens and how it relates to congestion, queue overflow, and network reliability.

### 3. The network stack and the devices in it
- Review the **TCP/IP model** and know the purpose of each layer.
- Be able to say which layers are involved for:
  - **Switches**
  - **Routers**
  - **End hosts**
- This is one of those topics where a quick sketch of the stack can save you a lot of confusion during the exam.

### 4. Network architecture and applications
- Compare **client-server** and **peer-to-peer (P2P)** systems.
- Know the trade-offs in cost, scalability, simplicity, and maintenance.
- Be able to explain why one architecture might be a better fit than the other in a specific scenario.

### 5. Sockets and transport protocols
- Understand what a **socket** is and why it matters for communication between processes.
- Compare **TCP** and **UDP** in terms of reliability, ordering, connection setup, overhead, and use cases.
- Be ready to give examples of when TCP is preferred and when UDP is a better choice.

### 6. HTTP and cookies
- Know what **cookies** do in HTTP and why they matter for session tracking, personalization, and user-specific behavior.
- Be comfortable explaining how cookies support user state across HTTP requests.

### 7. DNS
- Review the basics of **DNS** and the difference between centralized and distributed DNS designs.
- Be aware of the trade-offs in performance, fault tolerance, and scalability.
- Understand why DNS is important for translating names into addresses and how that affects application behavior.

### 8. Security basics
- You do not need to memorize every attack type, but you should know the general idea of common threats and malware types.
- Focus on the big concept: networks are vulnerable to attacks, and security measures aim to protect confidentiality, integrity, and availability.

### 9. Common protocols and ports
Know the default ports for the following protocols:

| Protocol | Port(s) | Secure Version     | Notes                   |
| -------- | ------- | ------------------ | ----------------------- |
| HTTP     | 80      | HTTPS (443)        | Web traffic             |
| DNS      | 53      | DNS over TLS (853) | Name resolution         |
| FTP      | 20, 21  | SFTP (989/990)     | 20 = Data, 21 = Control |
| SMTP     | 25      | SMTPS (465)        | Email sending           |
| POP3     | 110     | POP3S (995)        | Email retrieval         |
| IMAP     | 143     | IMAPS (993)        | Email retrieval         |

A good rule for this part: if you recognize the port, you should also know what kind of traffic it usually carries.

---

## Quick self-check questions

If you can answer these without looking at notes, you are in a strong position:

- Why is packet switching more efficient than circuit switching in many networks?
- What is the difference between processing delay and transmission delay?
- How does a router contribute to end-to-end delay?
- Why does packet loss occur, and what usually causes it?
- What problem does TCP solve that UDP does not?
- Why do we use sockets when building network applications?
- What is the relationship between DNS and HTTP in a typical web request?
- Which layers do switches, routers, and hosts operate at?
- Why might a client-server architecture be easier to manage than a P2P architecture?

---

## Exam Guidelines

- **Format:** Open-book.
- **Duration:** Entire class period.
- **Content:** May include a programming component and a Wireshark portion.
- **Number of Exams:** 4 total.
- **Make-Up Policy:** Make-up exams require prior approval unless due to a documented emergency or illness.

---

## Best ways to study

- Work through a few delay and packet loss problems by hand so you are not just memorizing formulas.
- Draw the TCP/IP stack and trace a message from one host to another.
- Review Wireshark examples and ask yourself what protocol is being used and what behavior you should expect.
- Practice explaining the ideas out loud as if you were teaching a classmate.
- Focus on understanding the "why" behind the concepts, not just the vocabulary.

The exam is not meant to trick you with obscure terminology. It is mostly checking whether you understand the fundamentals of how networks communicate, how protocols are layered, and how data flow is affected by delay, loss, and design choices.

Good luck with your exam prep!
