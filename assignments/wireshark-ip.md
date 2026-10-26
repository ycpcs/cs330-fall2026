---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Analyzing IP Traffic with Wireshark

## Due: See syllabus

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Objective

In this exercise, you will use Wireshark to analyze IPv4 and IPv6 traffic. You will look at IP headers in traceroute packets, see how IPv4 fragmentation works, and examine an IPv6 DNS request and response.

By the end of this lab, you should be able to:

- identify important fields in IPv4 and IPv6 headers
- explain how traceroute uses the TTL field
- recognize IPv4 fragments in a packet capture
- and connect IP packet details to the data carried by the packet

---

## Part 1: Capture Traceroute Traffic

In this part, you will send traceroute traffic to `gaia.cs.umass.edu`. The commands for generating the trace depend on your operating system.

### macOS or Linux

1. Open **Wireshark** and start a capture on your active network interface.
2. Open a terminal and send two traceroute commands to `gaia.cs.umass.edu`, first with a packet length of 56 bytes and then with a packet length of 3000 bytes:

```bash
traceroute gaia.cs.umass.edu 56
traceroute gaia.cs.umass.edu 3000
```

3. Wait for both commands to finish, then stop the capture.

### WSL on Windows

Capture the traffic inside WSL with `tcpdump`, then open the saved capture in Windows Wireshark. Do not use Windows Command Prompt or PowerShell's `tracert`; this lab requires the Linux `traceroute` utility and its UDP packets.

1. In WSL, install `tcpdump` if needed (on Ubuntu, run `sudo apt install tcpdump`).
2. Start a capture in a WSL terminal:

```bash
sudo tcpdump -i any -w traceroute.pcap
```

3. Leave that terminal running. In a second WSL terminal, run the two traceroute commands shown above.
4. After both commands finish, stop `tcpdump` with **Ctrl+C**.
5. From the WSL directory containing `traceroute.pcap`, run `explorer.exe .` and open the capture file in Wireshark.

If `traceroute` is not available in your Linux or WSL environment, install it using that distribution's package manager.

### Filter the Capture

In the Wireshark display filter bar, enter:

```text
udp || icmp
```

`traceroute` normally sends UDP packets and routers return ICMP messages. Your capture may also include unrelated traffic, so check the source, destination, and packet details before answering.

---

## Part 2: Analyze IPv4 Headers

Find the first UDP traceroute packet sent from your computer to `gaia.cs.umass.edu`. Expand the **Internet Protocol Version 4** section in the packet details.

### 1. First IPv4 Datagram

1. What is the packet number of the first traceroute packet sent by your computer?
2. What is your computer's IP address?
3. What is the destination IP address?
4. What is the value of the **Time to Live (TTL)** field?
5. What is the value of the **Protocol** field? Give the value in both decimal and protocol name.
6. How many bytes are in the IPv4 header?
7. How many bytes are in the IP payload? Show how you calculated this from the header fields.
8. Has this datagram been fragmented? What fields did you use to decide?

### 2. Traceroute Packet Sequence

Find the sequence of traceroute packets sent from your computer to `gaia.cs.umass.edu`. You can use a filter like the following, replacing `your_IP` and `destination_IP` with the addresses from your capture:

```text
ip.src == your_IP && ip.dst == destination_IP && !icmp
```

9. Which IPv4 header fields change from one outgoing traceroute packet to the next? Why do they change?
10. Which IPv4 header fields stay the same across these packets? Why?
11. What pattern do you see in the **Identification** field values?
12. What happens to the TTL values as traceroute sends packets toward routers farther from your computer?

Now find the ICMP messages returned by the routers. Use a filter like the following, replacing `your_IP` with your computer's address:

```text
ip.dst == your_IP && icmp
```

13. What protocol value appears in the IPv4 header of the packets returned by the routers?
14. Do the **Identification** field values follow a pattern similar to the outgoing packets? Explain what you see.
15. Are the TTL values the same across all of the returned packets? Explain your answer.

---

## Part 3: IPv4 Fragmentation

This part uses the traceroute packets with a length of 3000 bytes.

In the packet list, find an outgoing IPv4 datagram containing a large traceroute packet. In the sample trace, the first fragmented packet is near the beginning of the large-packet traceroute sequence. Use the source address, destination address, time, and **Identification** field to find the other fragments that belong to the same original datagram.

### 1. First Fragment

16. What is the packet number of the first fragment?
17. Has the original IP datagram been fragmented? Which IPv4 header fields show this?
18. What indicates that this is the first fragment?
19. How many bytes are in this IP datagram, including its header and payload?

### 2. Other Fragments

20. What is the packet number of the second fragment?
21. What indicates that this is not the first fragment?
22. Which IPv4 header fields change between the first and second fragments?
23. What is the packet number of the last fragment?
24. Which header field indicates that this is the last fragment?
25. How many fragments make up the original datagram?

---

## Part 4: Take a Look at IPv6

Capture your own IPv6 DNS lookup for the AAAA record for `youtube.com`. The `-6` option makes `dig` use IPv6 to contact the DNS server; requesting an AAAA record by itself does not ensure that the DNS traffic uses IPv6.

On macOS or Linux, start a Wireshark capture on your active network interface. On WSL, capture inside WSL with `tcpdump` and open the saved capture in Windows Wireshark:

```bash
sudo tcpdump -i any -w ipv6-dns.pcap 'ip6 and port 53'
```

While the capture is running, open a terminal (or a second WSL terminal) and run:

```bash
dig -6 @2606:4700:4700::1111 AAAA youtube.com
```

If `dig` is not installed, on Ubuntu or WSL install it with `sudo apt install dnsutils`. macOS usually includes `dig`; on other Linux distributions, install the package that provides `dig` using that distribution's package manager.

Stop the Wireshark capture or stop `tcpdump` with **Ctrl+C**. If you used WSL, open the directory containing `ipv6-dns.pcap` with `explorer.exe .` and open the file in Wireshark. Use the display filter `ipv6 && dns` to find the request and its matching response. This requires IPv6 connectivity to the DNS server; if the lookup fails, try a network with IPv6 connectivity.

If WSL reports `network unreachable`, it does not have a route to the IPv6 DNS server. If Windows itself has IPv6 connectivity, capture on the active Windows interface in Wireshark and run this in PowerShell instead:

```powershell
Resolve-DnsName -Name youtube.com -Type AAAA -Server "2606:4700:4700::1111"
```

If that command also fails, use a network with IPv6 connectivity before continuing.

Expand the **Internet Protocol Version 6** and **Domain Name System** sections in the packet details.

### 1. IPv6 DNS Request

26. What is the packet number of the DNS AAAA request?
27. What is the IPv6 source address? Copy it exactly as Wireshark displays it.
28. What is the IPv6 destination address? Copy it exactly as Wireshark displays it.
29. What is the value of the **Flow Label**?
30. How many bytes of payload data are carried in this IPv6 packet?
31. What is the value and name of the **Next Header** protocol?

### 2. IPv6 DNS Response

Find the DNS response that matches the AAAA request.

32. What is the packet number of the response?
33. How many IPv6 addresses are returned for `youtube.com`?
34. What is the first IPv6 address in the response? Copy it exactly as Wireshark displays it.

---

## What to Look For in Wireshark

When you examine the packets, pay attention to:

- source and destination IP addresses,
- the TTL and Protocol fields in IPv4 headers,
- the Identification, Flags, and Fragment Offset fields in IPv4 fragments,
- the IPv6 Flow Label and Next Header fields,
- and how the IP payload carries UDP, ICMP, or DNS data.

Use the packet details to support your answers. Do not assume that your packet numbers or IP addresses will match the sample trace.

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit the following:

- your answers to all questions,
- a copy of your packet capture file (`.pcap` or `.pcapng`) for Part 1,
- a copy of your IPv6 DNS capture file (`.pcap` or `.pcapng`) for Part 4,
- a screenshot of the first traceroute packet with its IPv4 header expanded,
- a screenshot showing the IPv4 fragments and their header details,
- and a screenshot of the IPv6 DNS request or response with the IPv6 header expanded.

If you used a course-provided trace file for Part 3, include screenshots from that trace.

> Double-check that your screenshots clearly show packet details and are legible.

---

## Notes

- All answers should come directly from your Wireshark analysis.
- Your packet numbers and IP addresses may differ from the examples in this lab.
- Save your capture file before you finish in case you need to revisit the packet details later.
