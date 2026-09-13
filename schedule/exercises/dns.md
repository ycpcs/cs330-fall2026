---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Exploring DNS Using `nslookup` and Wireshark

## ## Due: Tuesday, Sep 22, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Objective

In this exercise, you will:

- Use `ipconfig` and `nslookup` to explore DNS functionality on your system.
- Capture and analyze DNS traffic using **Wireshark**.
- Understand how DNS queries and responses work at both the command-line and packet levels.
- Compare DNS results across different tools and servers.

---

## Part 1: Identify Your DNS Server

1. Open a terminal or Command Prompt.
2. Run the following command:

```bash 
ipconfig /all
```

### Answer:

- What is the IP address of the **DNS server(s)** configured on your system? If more than one is listed, record the one your computer is currently using or note the full set of configured servers.

---

## Part 2: Capture DNS Traffic in Wireshark

### Step 1: Start Wireshark Capture

1. Open **Wireshark**.
2. Select your **active network interface** (e.g., Ethernet or Wi-Fi).
3. Click **Start** to begin capturing packets.

---

### Step 2: Run DNS Queries While Capturing

While Wireshark is capturing, open your terminal and run the following commands one at a time:

```bash 
nslookup -type=A google.com
nslookup -type=NS google.com
nslookup -type=MX gmail.com  
```

Wait a few seconds between each command to ensure the traffic is captured.

1. Once finished, return to Wireshark and click **Stop** to end the capture.

---

### Step 3: Apply DNS Filter

In the Wireshark display filter bar, enter:

```plaintext
dns
```

This will isolate DNS query and response packets.

---

### Questions:

1. What **transport layer protocol** is used for DNS queries and responses — UDP or TCP? Why?  
2. What **port number** is used for DNS traffic?  
3. What is the **IP address** of the DNS server your computer queried?

> Note: Most DNS lookups use **UDP** because the queries are small and fast. DNS may use **TCP** for larger responses, zone transfers, or when a UDP response exceeds the size limit.

### What to Look for in Wireshark

When you inspect packets, pay attention to:

- **Source and destination IP addresses**
- **Source and destination ports**
- Whether the packet is a **query** or a **response**
- The **DNS record type** (for example, `A`, `NS`, or `MX`)
- The **answer section** and returned values

---

## Part 3: Analyze DNS Packets in Wireshark

### Step 1: Follow a DNS Conversation

1. In the packet list, locate a DNS **query packet**.
2. Right-click on it and choose **Follow → UDP Stream**.

#### Answer:

4. Which **domain name** was queried?  
5. Was the response **successful**?  
6. What **IP address** was returned?  
7. What **transport layer protocol** and **port** were used for this DNS exchange?

---

### Step 2: Analyze an MX Record Response

1. Find a DNS **MX response** packet.
2. Click on it, and in the **Packet Details Pane**, expand the **“Answers”** section.

#### Answer:

8. What is the **mail server domain name** listed in the response?  
9. What is its **priority value**?  
10. Was the response **authoritative**? How can you tell?

---

## Discussion Questions

11. What are the differences between **A**, **NS**, and **MX** records?  
12. How is **DNS resolution affected by caching**?  
13. Why is it important for **security tools to monitor DNS traffic**?

---

## Compare DNS Results Across Different Sources

In this part, compare the DNS results you observed earlier with information from other tools and servers. Choose at least two of the following methods and record the results for the same domain(s):

### Option 1: Use an online DNS checker

Go to [https://dnschecker.org/](https://dnschecker.org/) and look up a domain such as `google.com`.

### Option 2: Query a public DNS server

Use a public resolver such as Cloudflare:

```bash 
nslookup -type=A google.com 1.1.1.1
```

### Option 3: Inspect browser DNS requests

Open the **Developer Tools** in your browser, go to the **Network** tab, and reload a page. Look for DNS requests and note what domain names and IP addresses appear.

### What to record:

For each source, note:

- the domain name queried,
- the returned IP address (if any),
- whether the result matched the result from your earlier `nslookup` and Wireshark analysis,
- any differences in timing, server used, or record type shown.

#### Questions:

14. How consistent were the DNS responses across:
- Command line (`nslookup`)
- Wireshark capture
- Online DNS tools
- Browser Developer Tools

15. Why might DNS responses differ across tools or servers?

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit the following:

- **Answers** to all questions (including analysis and discussion).  
- A copy of your **Wireshark packet capture file** (`.pcapng`).  
- A **screenshot** of a DNS query in the UDP stream.  
- A **screenshot** showing a DNS MX record with details expanded.  
- Summary of observations from online DNS tools.

> Double-check that your screenshots clearly show packet details and are legible. 