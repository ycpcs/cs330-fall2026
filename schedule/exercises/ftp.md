---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Analyzing FTP Traffic with Wireshark

## Due: Tuesday, Sep 22, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Objective

In this exercise, you will use Wireshark to capture and analyze an FTP session. You will see how FTP works, identify information that is transmitted in clear text, and understand why using an unencrypted protocol can be risky.

---

## Step-by-Step Instructions

### 1. Start Wireshark

1. Open **Wireshark**.
2. Begin capturing on the active network interface (for example, Ethernet or Wi‑Fi).
3. Make sure your environment supports **FTP passive mode**.

---

### 2. Connect to the FTP Server

Open a terminal and enter the following commands one at a time:

```bash
ftp -p
open ftp.rfc-editor.org
Name: anonymous
Password: your-email-address
ls
cd in-notes
ls rfc959.txt
get rfc959.txt
ls
close
quit
```

- Replace `your-email-address` with your actual email address.
- Wait for each command to finish before moving on to the next one.

---

### 3. Stop the Capture

When the FTP session is complete, return to Wireshark and click **Stop** to end the capture.

---

### 4. Filter and Inspect the FTP Traffic

Use the Wireshark display filter to focus on the FTP traffic:

```text
ftp
```

You can also try filtering by port or by packet type:

```text
tcp.port == 21 || ftp-data
```

Look for the FTP commands and responses that match your actions in the terminal. Pay attention to:

- the control connection on port 21,
- the login sequence,
- commands such as `USER`, `PASS`, `LIST`, and `RETR`,
- and the data transfer that happens when the file is downloaded.

---

### 5. Export FTP Objects

In Wireshark, go to:

**File -> Export Objects -> FTP...**

A window should appear listing the files transferred during the capture.

---

## Questions

1. What files appear in the **Export Objects** window?
2. What information is visible in the FTP traffic that should not normally be exposed?
3. Where do you see the FTP login credentials in the packet capture?
4. What are the two ports used by FTP: one for the **control connection** and one for the **data connection**?
5. What is the difference between the **FTP control connection** and the **FTP data connection**?
6. What does the FTP traffic tell you about the use of **unencrypted file transfer** on public or shared networks?
7. Click **Save All** and save the exported file to your computer. What happened after you saved it? Were you able to open the file? What did it contain?
8. What are the security implications of being able to recover files from a packet capture in this way?

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit the following:

- Your answers to all questions.
- A copy of the **packet capture file**.
- A **screenshot** of the **TCP stream** showing the FTP login, including the username and password.
- A **screenshot** of the **Exported FTP Objects** window from Wireshark.
- Any files you saved from the FTP session (optional).

> Double-check that your screenshots clearly show packet details and are legible.