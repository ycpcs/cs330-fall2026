---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330 Lab: Wireshark Explorer

## Due: Thursday, Sep 03, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Purpose

This is your first packet capture. The goal is to become comfortable with Wireshark's interface and learn how to find information in a packet. You do not need to understand TCP or memorize protocol headers for this lab. Follow the steps, record what you observe, and ask questions when something looks unfamiliar.

By the end of the lab, you should be able to:

- Start and stop a packet capture.
- Recognize the packet list, packet details, and packet bytes panes.
- Use a simple display filter.
- Find basic information such as time, protocol, addresses, and packet length.
- Expand a packet to discover information hidden inside it.

## Part 1: Start a Capture

1. Open **Wireshark**.
2. Look at the list of network interfaces. Choose the interface whose packet count is increasing. On most computers this will be **Wi-Fi** or **Ethernet**.
3. If you are unsure, open a browser tab and load a simple webpage. The interface with visible activity is usually the correct choice.
4. Start the capture by double-clicking the active interface.
5. Immediately visit [the HTTP test page](http://gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html), then stop the capture using the red square button after the page loads.
   1. Use `http` exactly as shown in the link. Do not change it to `https`.
        2. If your browser does not allow the `http` page to load, leave Wireshark capturing and run `curl http://gaia.cs.umass.edu/wireshark-labs/INTRO-wireshark-file1.html` in a terminal or command prompt. This creates the HTTP request needed for the rest of the lab.
6. Save the capture as `wireshark-first-capture.pcapng`.

> **Privacy reminder:** Capture only the short activity requested for this lab. Do not browse personal email, banking, medical, or private accounts while capturing.

After the command finishes, stop and save the capture. Use only the HTTP test page or the HTTP `curl` command. Do not substitute an HTTPS webpage, because the questions in this lab require visible HTTP information.

## Part 2: Learn the Three Panes

Click any packet in the top packet list. Wireshark normally displays three areas:

1. **Packet List:** one row for each captured packet.
2. **Packet Details:** expandable rows describing the selected packet.
3. **Packet Bytes:** the raw bytes that make up the selected packet.

Click a few different packets and watch how all three areas change. Then select the packet that has `HTTP` in the **Protocol** column. If you do not see `HTTP` immediately, scroll through the packet list. You can also type `http` in the display filter bar and press **Enter** to show only HTTP traffic.

Answer these warm-up questions:

1. What information does the packet list show in the **Time**, **Source**, **Destination**, and **Protocol** columns?
2. What happens when you click the small arrow beside a row in the Packet Details pane?
3. Which pane shows hexadecimal values and readable text?

## Part 3: Packet Scavenger Hunt

Use the packet that contains the HTTP request. Answer the following by clicking and expanding rows. You are reporting what Wireshark displays; you are not expected to explain every field yet.

As you work, take screenshots for your submission. Your screenshots should show the Wireshark window, the selected packet, and the relevant details pane. Do not submit screenshots of unrelated or private traffic.

### 1. Find the Packet

- What is the packet number of your selected packet?
- What protocol is shown in the **Protocol** column?
- What is the value in the **Length** column?

### 2. Find the Addresses

In the Packet Details pane, expand the **Internet Protocol Version 4** section. Look for the fields labeled **Source** and **Destination**. These are the addresses for this packet.

- What is the source address?
- What is the destination address?
- Which address belongs to your computer? Explain how you decided.

### 3. Find a Time Difference

Wireshark can display time in several ways. For this question, use the default time shown in the packet list.

- What time is shown for your selected packet?
- Select the packet immediately before it. What time is shown?
- Which packet came first, and how can you tell?

### 4. Explore the Details

Expand two different sections in the Packet Details pane. For example, you might see sections labeled **Frame**, **Internet Protocol**, **Transmission Control Protocol**, or **Hypertext Transfer Protocol**.

- What are the names of the two sections you expanded?
- Record one field name and value from each section.
- Choose one field you do not recognize. Make a reasonable guess about what it might describe based only on its name. You may revise this guess later in the course.

### 5. Look at the Bytes

Select a packet showing `200 OK  (text/html)`. With the same packet selected, look at the Packet Bytes pane.

- Do you see any readable text?
- Does the readable text match anything shown in the Packet Details pane?
- Why might some packet information be easier to read in the Details pane than in the raw bytes pane?

### 6. HTTP Hunt

Find the request packet by looking for `GET` in the **Info** column. In the Packet Details pane, look for a request line similar to `GET /... HTTP/1.1`, then examine the **Hypertext Transfer Protocol** section.

- Find the request line. What HTTP method was used, and what resource was requested?
- Find the server's response packet. Look for a packet showing `... 200 OK ...` and, if visible, `Content-Type: text/html`. What status code and short status phrase does it contain?

You do not need to explain what the method or status code means yet. Copy the values exactly as Wireshark displays them and include both packet numbers.

## Part 4: Narrow the Search

The display filter bar is above the packet list. This time, use a more specific filter. Enter `http.request` and press **Enter**.

- How did the number of visible packets change compared with the `http` filter?
- What kind of packets does `http.request` keep?
- Clear the filter using the **X** at the right side of the filter bar. Then enter `http.response` and press **Enter**.
- What kind of packets does `http.response` keep? Can you find the `200 OK` response again?

If no packets appear after using either filter, check that you used the HTTP test page or the HTTP `curl` command while Wireshark was capturing. Record which filters you used in your report.

## Part 5: Reflection

In a short paragraph, answer both questions:

- What was the most useful thing you learned about finding information in Wireshark?
- What is one question about packets or networks that you would like to investigate in a future lab?

## Optional Challenge

Try the display filter `dns` or `tcp` and compare the result with your `http` view. You do not need to understand the protocol yet. Simply report which filter displayed more packets and one visible difference between the two results.

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

> **Note:** Save `wireshark-first-capture.pcapng` for submission. Use only the HTTP test page or the HTTP `curl` command.

### How to Save Your Packet Capture

1. After stopping the capture, open the **File** menu.
2. Select **Save As...** or **Save**.
3. Choose a location on your computer.
4. Name the file `wireshark-first-capture.pcapng`.
5. Click **Save**.

> **Note:** Do not worry if some fields are unfamiliar. Record what you can observe, and bring confusing fields to class for discussion.

## Grading

Submit your short lab report, the packet capture file, and these screenshots via [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date listed in the syllabus:

- A screenshot of the HTTP request packet with the **Hypertext Transfer Protocol** section expanded.
- A screenshot of the HTTP response packet showing `200 OK` and the relevant details.
- A screenshot showing one of your display filters, such as `http.request` or `http.response`, in the filter bar.

Label your answers with the section and question numbers above. Make sure each screenshot is clear enough to read the packet number and relevant fields.
