---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Analyzing UDP Traffic with Wireshark

## Due: Tuesday, Oct 06, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Objective

In this exercise, you will use Wireshark to capture and analyze a simple UDP exchange. You will see how UDP works in practice, identify the fields in the UDP header, and relate packet-level behavior to the higher-level DNS application that depends on it.

By the end of this lab, you should be able to:

- capture UDP packets in Wireshark,
- identify the fields in a UDP header,
- explain how UDP differs from TCP,
- and connect the packet details to the DNS query used in the exercise.

---

## Part 1: Capture UDP Traffic

### Step 1: Start Wireshark

1. Open **Wireshark**.
2. Start a new packet capture on your active network interface.
3. Make sure your machine is connected to the network.

---

### Step 2: Generate UDP Traffic

While Wireshark is running, open a terminal or command prompt and enter:

```bash
nslookup ycp.edu
```

This command sends a DNS request to a resolver. DNS commonly uses **UDP** for small queries.

---

### Step 3: Stop the Capture

Once the lookup completes, return to Wireshark and click **Stop** to end the capture.

---

### Step 4: Filter for UDP Traffic

In the Wireshark display bar, enter:

```text
udp
```

This will isolate the UDP packets in your trace. You may need to look at the DNS packets as well to confirm that the exchange is a DNS query and response.

---

## Part 2: Analyze the First UDP Segment

Find the first UDP packet in your capture and make sure it matches the DNS query for `ycp.edu`.

### 1. First UDP Segment

1. What is the **packet number** of the first UDP segment in your capture?
2. What **application-layer protocol** or payload is carried in this packet?
3. How many **fields** are present in the UDP header? Use Wireshark to inspect the packet rather than relying on memory.
4. What are the **names** of the fields in the UDP header?

---

### 2. UDP Header Field Lengths

Using Wireshark, inspect the UDP header and answer the following:

5. What is the **length in bytes** of each field in the UDP header?
6. List each field and its corresponding size.

---

### 3. UDP Length Field

7. What does the **Length** field in the UDP header represent?
8. Verify your answer by comparing the UDP Length field to the actual size of the UDP header and payload. Show the calculation that supports your answer.

---

### 4. Maximum UDP Payload Size

9. Based on your answer to Question 5, what is the **maximum number of bytes** that can be included in a UDP payload?
10. Show how you arrived at this value.

> Hint: The UDP Length field includes the header and the payload. Subtract the header size to determine the payload capacity.

---

### 5. Maximum Source Port Number

11. What is the **maximum possible source port number**?
12. Explain how the size of the port number field leads to this answer.

---

### 6. UDP Protocol Value in the IP Header

13. What is the **protocol number** used to indicate UDP in the **IP header**?
14. Report the number in **decimal** format and explain where you found it in Wireshark.

---

### 7. DNS Query and Response Pair

Find the UDP request sent from your machine and the matching response from the server.

For the **request packet**:

15. What is the **packet number**?
16. What is the **source port**?
17. What is the **destination port**?

For the **response packet**:

18. What is the **packet number**?
19. What is the **source port**?
20. What is the **destination port**?

21. Explain the relationship between the port numbers in the request and the response. Why are they arranged this way?

---

### 8. UDP Checksum

22. In the DNS request packet, what UDP checksum value does Wireshark show, and does Wireshark report it as valid? 

---

## What to Look For in Wireshark

When you examine the packets, pay attention to:

- source and destination IP addresses,
- source and destination ports,
- whether the packet is a request or a response,
- the UDP length and checksum values,
- and the way the DNS query is carried inside the UDP payload.

This will help you connect the protocol fields to the behavior of the network application.

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit the following:

- your answers to all questions,
- a copy of your **packet capture file** (`.pcap` or `.pcapng`),
- a screenshot of the **DNS query packet** in Wireshark,
- and a screenshot showing the **UDP packet details** with the header fields expanded.

> Double-check that your screenshots clearly show packet details and are legible.

---

## Notes

- All answers should come directly from your Wireshark analysis.
- You should not rely on a textbook answer when the packet trace itself provides the needed information.
- Save the capture file before you finish in case you need to revisit the packet details later.
