---
layout: default
course_number: CS330
title: "Wireshark UDP"
---

# Wireshark Lab: Analyzing UDP Packets

## Overview

In this lab, you will explore the structure and behavior of the **User Datagram Protocol (UDP)** by using **Wireshark** to capture and analyze packets. You'll use the command: `nslookup ycp.edu` This command sends a DNS query over UDP. You'll analyze the request and its response using Wireshark.

---

## Lab Objectives

- Capture UDP packets using Wireshark
- Identify fields in the UDP header
- Understand DNS over UDP
- Examine port numbers and protocol values

---

## Instructions

1. Open **Wireshark** and start a new capture.
2. In a terminal or command prompt, enter:
```
nslookup ycp.edu
```
3. Stop the capture after the response is received.
4. Use the **display filter** `udp` to isolate UDP packets.

---

## Questions

### 1. First UDP Segment

- Identify the **first UDP segment** in your capture.
- **Make sure this packet is the DNS query for `ycp.edu`.**
- What is the **packet number** of this segment in the trace file?
- What **application-layer protocol** or payload does this segment contain?
- How many **fields** are present in the UDP header? *(Use Wireshark, not the textbook.)*
- What are the **names** of these fields?

---

### 2. Length of UDP Header Fields

Using Wireshark:

- What is the **length (in bytes)** of each field in the UDP header?
- List each field along with its size.

---

### 3. UDP Length Field

- What does the **Length** field in the UDP header represent?
- Verify this by comparing the value in the Length field with the actual size of the UDP header and payload.
- Show your calculation.

---

### 4. Maximum UDP Payload Size

- Based on your answer to Question 2:
- What is the **maximum number of bytes** that can be included in a UDP payload?
- Show how you arrived at this answer.

> *Hint: Consider the total size of the Length field and subtract the header size.*

---

### 5. Maximum Source Port Number

- What is the **maximum possible source port number**?
- Explain how the size of the port number field leads to this answer.

---

### 6. UDP Protocol Number in IP Header

- What is the **protocol number** used to indicate UDP in the **IP header**?
- Locate and report this number in **decimal** format.
- Use Wireshark to find this in the **IP header** of a packet.

---

### 7. UDP Query and Response Pair

Find the UDP **request** sent from your machine and the corresponding **response** from the server.

For the **first packet (the request)**:

- What is the **packet number**?
- What is the **Source Port**?
- What is the **Destination Port**?

For the **second packet (the response)**:

- What is the **packet number**?
- What is the **Source Port**?
- What is the **Destination Port**?

> **Explain the relationship** between the port numbers in the request and the response. Why are they arranged this way?

---

> **Note:** Be sure to save your packet capture file (`.pcapng`) for submission or reference.

## Grading
Submit your lab report, including the **packet capture file** and **screenshots**, via [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date listed in the syllabus.

> **Note:** Label your answers clearly using the question numbers above.

### How to Save Your Packet Capture

1. After stopping the capture in Wireshark, go to the **File** menu.
2. Select **Save As…** or **Save**.
3. Choose a location on your computer to save the capture file.
4. Ensure the file extension is `.pcap` or `.pcapng`.
5. Click **Save**.
   
> **Note:** All answers should be derived directly from your Wireshark analysis.
