---
layout: default
course_number: CS330
title: "Exploring DNS"
---

# Class Exercise: Exploring DNS Using `nslookup` and Wireshark

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

- What is the IP address of your **DNS server**?

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

1. What **protocol** is used for DNS — UDP or TCP? Why?  
2. What **port number** is used for DNS traffic?  
3. What is the **IP address** of the DNS server your computer queried?

---

## Part 3: Analyze DNS Packets in Wireshark

### Step 1: Follow a DNS Conversation

1. In the packet list, locate a DNS **query packet**.
2. Right-click on it and choose **Follow → UDP Stream** (if available).

#### Answer:

4. Which **domain name** was queried?  
5. Was the response **successful?**  
6. What **IP address** was returned?

---

### Step 2: Analyze an MX Record Response

1. Find a DNS **MX response** packet.
2. Click on it, and in the **Packet Details Pane**, expand the **“Answers”** section.

#### Answer:

7. What is the **mail server domain name** listed in the response?  
8. What is its **priority value**?  
9. Was the response **authoritative**? How can you tell?

---

## Discussion Questions

10. What are the differences between **A**, **NS**, and **MX** records?  
11. How is **DNS resolution affected by caching**?  
12. Why is it important for **security tools to monitor DNS traffic**?

---

## Compare with Online Tools and Alternate DNS Servers

### Try the following:

- Go to: [https://dnschecker.org/](https://dnschecker.org/)  
- Or use a public DNS server like Cloudflare’s in the terminal:

```bash 
nslookup -type=A google.com 1.1.1.1
```

You may also open the **Developer Tools** in your browser, go to the **Network tab**, and observe DNS requests when you visit a domain.

#### Question:

13. How consistent are the DNS responses across:
- Command line (`nslookup`)
- Wireshark capture
- Online DNS tools
- Browser Developer Tools

14. Why might DNS responses differ across tools or servers?

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