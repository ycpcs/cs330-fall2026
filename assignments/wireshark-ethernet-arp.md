---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Analyzing Ethernet and ARP with Wireshark

## Due: Tuesday, Dec 01, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Objective

In this lab, you will capture traffic between your computer and its local network gateway. You will examine the Ethernet frame that carries an IP packet and observe how ARP discovers the link-layer address needed to send that packet.

By the end of the lab, you should be able to:

- identify source and destination addresses in an Ethernet II frame,
- distinguish Ethernet frames carrying ARP from frames carrying IPv4,
- interpret the key fields in an ARP request and reply,
- explain why an ARP request is broadcast on the local network, and
- relate the ARP cache to the frames seen in a capture.

## Part 1: Capture Traffic to Your Gateway

Use the active network interface connected to your local network. This lab uses IPv4 and your default gateway (often your home or campus router).

### Find the gateway and clear its cached entry

Clearing only the gateway's neighbor entry helps your computer send a new ARP request. If you do not have permission to clear it, skip that step and keep capturing until an ARP request and reply appear.

**Windows (PowerShell):**

1. Find the default gateway:

```powershell
Get-NetRoute -DestinationPrefix "0.0.0.0/0" |
  Sort-Object RouteMetric |
  Select-Object -First 1 NextHop, InterfaceAlias
```

2. In an elevated PowerShell window, replace `<gateway-ip>` with the `NextHop` address:

```powershell
arp -d <gateway-ip>
```

**macOS:**

1. Find the gateway with `route -n get default` and note the `gateway` address.
2. In a terminal, replace `<gateway-ip>` with that address:

```bash
sudo arp -d <gateway-ip>
```

**Linux:**

1. Run `ip route show default` and note the gateway address and interface after `via` and `dev`.
2. Replace `<gateway-ip>` and `<interface>` with those values:

```bash
sudo ip neigh del <gateway-ip> dev <interface>
```

### Start the capture

1. Open Wireshark and start a capture on the active Wi-Fi or Ethernet interface.
2. In a terminal or command prompt, ping the gateway address you found:

   **Windows:**

   ```powershell
   ping -n 4 <gateway-ip>
   ```

   **macOS or Linux:**

   ```bash
   ping -c 4 <gateway-ip>
   ```

3. Stop the capture after the ping finishes.
4. Save the capture as `wireshark-ethernet-arp.pcapng`.
5. Apply the display filter `arp` to find ARP requests and replies. Select an ARP request and its reply to the gateway. If there are several, compare their sender and target IP addresses to identify the matching pair.

> **Capture note:** The link-layer details Wireshark shows depend on your network adapter and capture mode. If you see IEEE 802.11 details instead of an Ethernet II header, try the adapter's ordinary Wi-Fi capture mode or use a wired Ethernet interface. Do not use monitor mode for this exercise.

> **Privacy reminder:** Capture only the short activity requested for this lab. Do not browse or capture personal accounts or unrelated private traffic.

## Part 2: Inspect Ethernet Frames

Select the ARP request and expand **Ethernet II** in the Packet Details pane. Then select one of the IPv4 ping packets and inspect its **Ethernet II** and **Internet Protocol Version 4** sections.

1. What is the packet number of the ARP request?
2. What are the source and destination MAC addresses in the Ethernet header of the request?
3. Is the request's destination MAC address a unicast address or the Ethernet broadcast address? What does that indicate about who can receive the frame on the local network?
4. What is the Ethernet **Type** value for the ARP request, in hexadecimal? Which protocol does it identify?
5. What is the Ethernet **Type** value for an IPv4 ping packet? How does it differ from the value in the ARP frame?
6. For an IPv4 ping packet sent to the gateway, what are the Ethernet source and destination MAC addresses? Is the destination MAC address the same kind of address as the IP destination address? Explain.

## Part 3: Examine the ARP Request and Reply

Expand **Address Resolution Protocol (request)** or **Address Resolution Protocol (reply)** in the Packet Details pane. Use the `arp` display filter to compare the matching request and reply.

### ARP request

7. What is the ARP **Opcode** value, and does Wireshark identify it as a request or a reply?
8. What sender IPv4 address is included in the request?
9. What target IPv4 address is the request trying to resolve?
10. Is the target MAC address in the request already known? What value is shown?
11. What are the request's sender MAC and target MAC addresses in the ARP details? Compare the sender MAC to the Ethernet source address.
12. Assuming an untagged Ethernet II frame (one without a VLAN tag), how many bytes from the start of the frame occur before the ARP Opcode field? Show how you used the Ethernet and ARP field lengths to determine the offset. (Do not count the Ethernet preamble.)

### ARP reply

13. What is the packet number of the matching ARP reply?
14. What is the reply's ARP **Opcode** value?
15. What IPv4-to-MAC mapping does the reply provide?
16. Compare the Ethernet destination address of the reply with the Ethernet destination address of the request. Why are they different?

## Part 4: Connect ARP to the Cache

Run `arp -a` in a terminal or command prompt after the ping completes. Find the entry for your default gateway.

17. What IPv4 address and MAC address are listed for the gateway?
18. Does the gateway's MAC address in the cache agree with the address learned from the ARP reply? If not, explain one possible reason.
19. In a sentence or two, explain what problem the ARP cache helps your computer avoid.
20. If your capture includes ARP requests from other devices, choose one and record its sender and target IPv4 addresses. Why might your computer see the request even though it did not send it?
21. Use the Ethernet source MAC address of the ARP request (your computer's interface, from Question 2) with [MAC Lookup](https://maclookup.app/) or another MAC address lookup service. What NIC manufacturer does it report? If the lookup cannot identify a manufacturer, or your interface uses a randomized MAC address, explain why.

If you could not clear the gateway entry and did not capture a new request, use another complete ARP request/reply pair in your trace for Questions 7-16. Clearly note that you used a different pair.

## What to Look For in Wireshark

Pay attention to:

- **Ethernet II** source, destination, and Type fields,
- the Ethernet broadcast destination used by an ARP request,
- ARP sender and target hardware/IP address fields,
- the request and reply Opcode values, and
- the relationship between the gateway's ARP mapping and the local neighbor cache.

The Ethernet destination for a packet sent to an off-network host is usually the local gateway's MAC address, not the remote host's MAC address. MAC addresses are used for delivery on a local link; IP addresses identify the endpoints across networks.

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit:

- your answers to all questions,
- the capture file (`.pcap` or `.pcapng`),
- a screenshot of the ARP request with its Ethernet II and ARP details expanded,
- a screenshot of the matching ARP reply with its details expanded, and
- a screenshot of an IPv4 ping frame showing its Ethernet II and IPv4 details.

Label your answers with the question numbers above. Make sure screenshots clearly show the packet number and relevant fields, and do not include unrelated or private traffic.

## Notes

- Addresses, packet numbers, and cache entries vary by computer and network.
- Use the values shown in your own capture; do not assume that another student's or an example trace will match.
- Save the capture before closing Wireshark so you can return to it while writing your answers.
