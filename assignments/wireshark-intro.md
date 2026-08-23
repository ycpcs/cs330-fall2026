---
layout: default
course_number: CS330
title: "Wireshark Intro"
---

# Wireshark Lab: HTTP and Protocol Analysis

## Lab Setup

1. Start the **Wireshark** software.
2. To begin packet capture:
   - On **Windows**: Go to the **Capture** pull-down menu and select **Interfaces**.
   - On **Mac**: Choose **Options** from the Capture menu.
3. You will see a list of network interfaces on your computer along with a live packet count.
   - How to Pick the Right Interface:
     - Look for the interface that is actively showing an **increasing packet count** — this is typically your main network adapter.
     - If you're on Wi-Fi, it will usually be labeled something like `Wi-Fi`, `wlan0`, or `en0`.
     - If you're using Ethernet, look for `Ethernet`, `eth0`, or a similar name.
     - If you're unsure, open your browser and **start loading a webpage** — then see which interface shows packet activity.
     - **Tip:** Avoid loopback interfaces unless you're capturing local traffic like `localhost`.
4. On **Windows**, click **Start** next to the interface on which you want to begin capture.
5. ~~While Wireshark is running, open your browser and go to: <a href="https://ycpcs.github.io/cs330-fall2025/assignments/fingerprint.html" target="_blank">https://ycpcs.github.io/cs330-fall2025/assignments/fingerprint.html</a>~~
6. While Wireshark is running, open your browser and go to: <a href="http://gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html" target="_blank">http://gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html</a>
   1. Make sure you use ```http``` and not ```https```

---

## Lab Questions

### 1. Protocol Identification

Which of the following protocols appear in the **Protocol** column in your Wireshark trace file?

- [ ] TCP  
- [ ] QUIC  
- [ ] HTTP  
- [ ] DNS  
- [ ] UDP  
- [ ] TLSv1.2  

---

### 2. HTTP Response Timing

How long did it take from when the **HTTP GET** message was sent until the **HTTP OK** reply was received?

**Tip**:  
> The **Time** column in Wireshark shows the time (in seconds) since capture began.  
> To change this to time-of-day format:  
> `View → Time Display Format → Time-of-day`

---

### 3. IP Address Lookup

- What is the **IP address** of ```http://gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html```?
- What is the **IP address of your computer**?

---

### 4. Browser Identification

Expand the HTTP GET request in the **Details of selected packet** window.

- What is the **User-Agent** value?
- What type of **Web browser** issued the HTTP request?

---

### 5. Destination Port Number

Expand the **Transmission Control Protocol (TCP)** section of the HTTP request packet.

- What is the **destination port number** for the HTTP request?
- What is the **source port number** for the HTTP request?

---

### 6. Packet Size Analysis  
- What is the size (in bytes) of the HTTP GET request packet?  
- What is the size of the HTTP OK response packet?  
- How do the sizes compare? Why might the response be larger or smaller?
  
---

### 7. Print HTTP Messages

Print the two HTTP messages (GET and OK) referred to in **Question 2**.

**Steps**:

1. Select the desired packet in the list.
2. Go to **File → Print**
3. Choose:
- **Selected Packet Only**
- **Print as displayed**
4. Click **OK** to print.

---

> **Note:** Be sure to save your packet capture file (`.pcapng`) for submission or reference.

## Grading
Submit your lab report, including the **packet capture file** and **screenshots**, via [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date listed in the syllabus.

### How to Save Your Packet Capture

1. After stopping the capture in Wireshark, go to the **File** menu.
2. Select **Save As…** or **Save**.
3. Choose a location on your computer to save the capture file.
4. Ensure the file extension is `.pcap` or `.pcapng`.
5. Click **Save**.
   
> **Note:** All answers should be derived directly from your Wireshark analysis.