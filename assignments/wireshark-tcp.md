---
layout: default
course_number: CS330
title: "Wireshark TCP"
---

# Wireshark Lab: Analyzing TCP Segments 

## Overview

In this lab, you will use **Wireshark** to analyze a TCP connection established between your computer and the server at `gaia.cs.umass.edu` during the upload of a file. This lab focuses on HTTP over TCP, the TCP three-way handshake, data transmission, and segment-level behavior.

---

## Part 1: File Preparation and Upload

1. Open your web browser and download an ASCII version of **Alice in Wonderland** from: [http://gaia.cs.umass.edu/wireshark-labs/alice.txt](http://gaia.cs.umass.edu/wireshark-labs/alice.txt)

Save the file as `alice.txt` on your local computer.

2. Go to the following URL: [http://gaia.cs.umass.edu/wireshark-labs/TCP-wireshark-file1.html](http://gaia.cs.umass.edu/wireshark-labs/TCP-wireshark-file1.html)

3. Use the **Browse** button to select the `alice.txt` file you just downloaded.

4. **Do not upload yet!**

5. Open **Wireshark** and begin packet capture. (Use a filter like `http` or `tcp` if needed.)

6. Return to the browser and click the **"Upload alice.txt file"** button. A short "congratulations" message should appear once the upload is complete.

7. Stop the Wireshark capture.

---

## Part 2: HTTP POST and TCP Analysis

- Begin by locating the **HTTP POST** request in Wireshark. Expand the packet and look closely at the **TCP** and **HTTP** headers. Then, filter your Wireshark view by entering `tcp` into the display filter bar.

- The body of your application-layer HTTP POST message contains the contents of the file `alice.txt`, which is a large file.

---

## Questions

### 1. Client IP and Port

- What is the **IP address** and **TCP port number** used by the **client computer** (source) that transferred `alice.txt` to `gaia.cs.umass.edu`?
- Hint: Select the packet containing the HTTP POST message and examine its TCP header.

---

### 2. Server IP and Port

- What is the **IP address** of `gaia.cs.umass.edu`?
- On what **port number** is it sending and receiving TCP segments for this connection?

---

### 3. TCP SYN Segment (Client to Server)

- What is the **sequence number** of the **TCP SYN** segment that initiated the connection?
- What field in the segment identifies it as a **SYN** segment?
- Does the TCP receiver in this session support **Selective Acknowledgments**?

---

### 4. TCP SYN-ACK Segment (Server to Client)

- What is the **sequence number** of the **SYN-ACK** segment from `gaia.cs.umass.edu`?
- What field marks this as a **SYN-ACK** segment?
- What is the **Acknowledgement Number** in this segment?
- How did the server determine this value?

---

### 5. TCP Segment with HTTP POST

- What is the **sequence number** of the TCP segment containing the **HTTP POST** command?
- How many **bytes of data** are in the payload of this segment?
- Did the entire `alice.txt` file fit in this single TCP segment?

---

### 6. TCP Timing and RTT

For the segment containing the **HTTP POST**:

- At what **time** was the segment sent?
- At what **time** was the **ACK** for this segment received?
- What is the **RTT** for this segment?

For the **second data-carrying** segment:

- What is the **RTT** for the second segment and its ACK?

#### Estimated RTT

- Calculate the **EstimatedRTT** after receiving the second ACK using: `EstimatedRTT = (1 - α) * EstimatedRTT + α * SampleRTT`

Use `α = 0.125`, and let the initial EstimatedRTT equal the RTT of the first segment.

> 💡 Tip: Use **Statistics → TCP Stream Graph → Round Trip Time Graph** in Wireshark for visual RTT inspection.

---

### 7. Segment Lengths

- What is the **length (header + payload)** of the **first four** data-carrying TCP segments?
- What is the maximum segment size (MSS) of the stream?

---

### 8. Receiver Buffer Space (Window Size)

- What is the **minimum advertised window size** (buffer space) from the server (`gaia.cs.umass.edu`) among the first four data segments?
- Does the **lack of buffer space** ever throttle the sender during these first four segments?

---

### 9. Retransmissions

- Are there any **retransmitted segments** in the trace?
- What did you look for to determine this?

---

### 10. Acknowledgment Behavior

- How much **data** does the receiver typically acknowledge in each ACK among the **first ten** data-carrying segments?
- Can you find any instances where the receiver **ACKs every other segment**?

> Reference: See Table 3.2 in your textbook.

---

### 11. TCP Throughput

- What is the **throughput** (in bytes per second) of the TCP connection?

#### How to calculate: `Throughput = Total Bytes Transferred / Total Transfer Time`

- Show your calculation based on segment timestamps and byte counts.

---

## Bonus: Time-Sequence Graph (Stevens)

To visualize how data was sent over time:

1. Select a TCP segment sent from the client.
2. Go to: `Statistics → TCP Stream Graph → Time-Sequence Graph (Stevens)`

3. Observe and describe the shape of the graph:
- Is it linear?
- Are there gaps?
- Any retransmissions?

You may need to adjust axes or zoom in for clarity.

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