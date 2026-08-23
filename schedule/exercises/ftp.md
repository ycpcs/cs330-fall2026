---
layout: default
course_number: CS330
title: "FTP Traffic"
---

# Class Exercise: Analyzing FTP Traffic with Wireshark

## Objective
In this exercise, you will use Wireshark to capture and analyze an FTP session. You'll learn how FTP works, what information is transmitted in clear text, and the implications of using non-secure FTP protocols.

---

##  Step-by-Step Instructions

### 1. Start Wireshark
- Open **Wireshark**.
- Begin **capturing** on the appropriate network interface (e.g., Ethernet, Wi-Fi).
- Ensure your network supports **FTP passive mode**.

---

### 2. Initiate FTP Connection

Open a terminal that supports FTP, then enter the following commands:

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
- Replace ```your-email-address``` with your actual email address.
- Wait for each command to execute before proceeding to the next.

---

### 3. Stop Wireshark Capture
- Return to Wireshark and click Stop to end the capture.

---

### 4: Export FTP Objects

- In Wireshark, go to:  
  **File** → **Export Objects** → **FTP...**

- A window will appear listing all files transferred over FTP during your capture.

---

#### Answer the following:

8. **What do you see listed in the export window?**  
   - (Look for file names, sizes, types.)

9. Click **"Save All"** and choose a location on your system.  
   - What happens after saving the file?  
   - Were you able to open it? What did the file contain?

10. **Observations:**  
    - What are the implications of being able to extract files like this from a packet capture?
    - What does this tell you about using **unencrypted FTP** on public or shared networks?

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit the following:

- **Answers** to all **Analysis Tasks** and **Discussion Questions**.
- A copy of the **packet capture file**.
- A **screenshot** of the **TCP Stream** showing the FTP login (username and password).
- A **screenshot** of the **Exported FTP Objects** window from Wireshark.
- (Optional) Any **files** you saved from the FTP session (e.g., `rfc959.txt`).

> Double-check that your screenshots clearly show packet details and are legible.