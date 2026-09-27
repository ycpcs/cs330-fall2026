---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Analyzing TCP Traffic with Wireshark

## Due: Tuesday, Oct 13, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Objective

In this exercise, you will use Wireshark to analyze a TCP connection during a file upload. You will examine the three-way handshake, observe how HTTP data is carried over TCP, and study the timing and flow-control behavior that make reliable transport work.

By the end of this lab, you should be able to:

- identify the client and server endpoints in a TCP connection,
- interpret the TCP handshake and segment fields,
- analyze round-trip time and acknowledgment behavior,
- and connect packet-level behavior to the larger idea of reliable end-to-end delivery.

---

## Part 1: Prepare the Upload

1. Open a terminal and confirm that you are using **HTTP** rather than HTTPS by downloading the sample file with:

```bash
curl -O http://gaia.cs.umass.edu/wireshark-labs/alice.txt
```

   This should save the file as `alice.txt` on your local computer.

2. Open the following URL in a browser:
   [http://gaia.cs.umass.edu/wireshark-labs/TCP-wireshark-file1.html](http://gaia.cs.umass.edu/wireshark-labs/TCP-wireshark-file1.html)

3. Use the **Browse** button to select the `alice.txt` file you downloaded.

4. Do not upload yet.

5. Open **Wireshark** and start a packet capture.

6. Return to the browser and click the **Upload alice.txt file** button.

7. Wait for the upload to complete and then stop the capture.

> Important: Use the **HTTP** version of the site and avoid HTTPS. The lab is designed to capture clear-text HTTP traffic over TCP.

---

## Part 2: Find the TCP Connection

In Wireshark, locate the **HTTP POST** request and then filter the view to show only **TCP** packets. The body of the HTTP message contains the contents of `alice.txt`, which gives you a realistic example of application data being carried over a TCP connection.

---

## Questions

### 1. Client IP and Port

1. What is the **IP address** and **TCP port number** used by the **client computer** that sends the upload to `gaia.cs.umass.edu`?
2. Hint: Select the packet containing the **HTTP POST** message and inspect its **TCP header**.

---

### 2. Server IP and Port

3. What is the **IP address** of `gaia.cs.umass.edu`?
4. On what **port number** is it sending and receiving TCP segments for this connection?

---

### 3. TCP SYN Segment

5. What is the **sequence number** of the **TCP SYN** segment that initiates the connection?
6. What field in the segment identifies it as a **SYN** segment?
7. Does the TCP receiver in this session support **Selective Acknowledgments**?

---

### 4. TCP SYN-ACK Segment

8. What is the **sequence number** of the **SYN-ACK** segment from `gaia.cs.umass.edu`?
9. What field marks this as a **SYN-ACK** segment?
10. What is the **acknowledgement number** in this segment?
11. How did the server determine this value?

---

### 5. TCP Segment with HTTP POST

12. What is the **sequence number** of the TCP segment containing the **HTTP POST** command?
13. How many **bytes of data** are in the payload of this segment?
14. Did the entire `alice.txt` file fit into this single TCP segment?

---

### 6. TCP Timing and RTT

For the segment containing the **HTTP POST**:

15. At what **time** was the segment sent?
16. At what **time** was the **ACK** for this segment received?
17. What is the **RTT** for this segment?

For the **second data-carrying** segment:

18. What is the **RTT** for the second segment and its ACK?

#### Estimated RTT

19. Calculate the **EstimatedRTT** after receiving the second ACK using:

```text
EstimatedRTT = (1 - α) * EstimatedRTT + α * SampleRTT
```

Use `α = 0.125`, and let the initial EstimatedRTT equal the RTT of the first segment.

> Tip: Use **Statistics → TCP Stream Graph → Round Trip Time Graph** in Wireshark for visual RTT inspection.

---

### 7. Segment Lengths

20. What is the **length (header + payload)** of the **first four** data-carrying TCP segments?
21. What is the **maximum segment size (MSS)** of the stream?

---

### 8. Receiver Buffer Space (Window Size)

22. What is the **minimum advertised window size** (buffer space) from the server among the first four data segments?
23. Does the **lack of buffer space** ever throttle the sender during these first four segments?

---

### 9. Retransmissions

24. Are there any **retransmitted segments** in the trace?
25. What did you look for to determine this?

---

### 10. Acknowledgment Behavior

26. How much **data** does the receiver typically acknowledge in each ACK among the **first ten** data-carrying segments?
27. Can you find any instances where the receiver **ACKs every other segment**?

---

### 11. TCP Throughput

28. What is the **throughput** (in bytes per second) of the TCP connection?
29. Show your calculation using the total bytes transferred and the total transfer time.

---

## Discussion Questions

30. Why is the **three-way handshake** necessary before data transfer begins?
31. How do **sequence numbers** and **acknowledgement numbers** help TCP provide reliable delivery?
32. Why does TCP use a **window size** and acknowledgements instead of simply sending data as fast as possible?
33. What do the packet timings and RTT values suggest about the behavior of congestion control and network delay in this connection?

---

## Bonus: Time-Sequence Graph (Stevens)

To visualize how data was sent over time:

1. Select a TCP segment sent from the client.
2. Go to **Statistics → TCP Stream Graph → Time-Sequence Graph (Stevens)**.
3. Observe the shape of the graph.

### Questions

34. Is the graph mostly linear, or are there visible gaps or irregularities?
35. Do you observe any retransmissions or pauses in data flow?
36. What does the graph suggest about packet timing and congestion behavior during the transfer?

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit the following:

- your answers to all questions,
- a copy of your **packet capture file** (`.pcap` or `.pcapng`),
- a screenshot of the **HTTP POST** packet and TCP header details,
- a screenshot of the **TCP handshake** or stream details,
- and any relevant Wireshark graphs used for your analysis.

> Double-check that your screenshots clearly show packet details and are legible.

---

## Notes

- All answers should be derived directly from your Wireshark analysis.
- Save the capture file before you finish in case you need to revisit the packet details later.
- You should use the packet trace itself to justify your conclusions rather than relying on a textbook summary alone.
