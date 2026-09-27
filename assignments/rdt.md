---
layout: default
course_number: CS330
title: "Network Applications and Protocols"
---

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## CS 330: Reliable Data Transfer and Flow Control

## Due: Tuesday, Oct 08, 2026 by 11:59 PM

--- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---

## Objective

In this exercise, you will use the Chapter 3 interactive protocol animations to explore how reliable data transfer works in practice. You will compare the behavior of **Go-Back-N** and **Selective Repeat** under packet loss and acknowledgment loss, and you will explain how the protocol design affects reliability, efficiency, and complexity.

By the end of this assignment, you should be able to:

- explain how loss and corruption are handled in reliable transport protocols,
- compare sliding-window behavior in Go-Back-N and Selective Repeat,
- identify the effects of dropped packets and dropped acknowledgements,
- and summarize the key tradeoffs between the two protocols.

---

## Part 1: Go-Back-N Protocol

Visit the Chapter 3 **Go-Back-N Protocol** applet at the companion website:

[Go-Back-N Protocol](https://media.pearsoncmg.com/ph/esm/ecs_kurose_compnetwork_8/cw/content/interactiveanimations/go-back-n-protocol/index.html)

Please read the instructions carefully before proceeding.

### Problem 1. Packet Loss and Retransmission Behavior (30 pts)

1. Experiment with five packets.
   - Have the source send five packets.
   - Pause the animation before any packet reaches the destination.
   - Delete (Kill) the first packet and then resume the animation.
   - Describe what happens and explain why the sender behaves this way.

2. Experiment with acknowledgements.
   - Repeat the experiment, allowing all packets to reach the destination.
   - Delete (Kill) the first acknowledgement.
   - Describe the outcome and explain how the protocol recovers from this loss.

3. Experiment with the second packet.
   - Send five packets again.
   - Pause the animation before the packets arrive at the destination.
   - Delete the second packet and resume the animation.
   - Describe what happens and compare this outcome to the first scenario.

4. Experiment with six packets.
   - Increase the number of packets sent to six.
   - Describe the behavior of the sender and receiver. What is different from the five-packet case?

---

## Part 2: Selective Repeat Protocol

Visit the Chapter 3 **Selective Repeat Protocol** applet:

[Selective Repeat Protocol](https://media.pearsoncmg.com/ph/esm/ecs_kurose_compnetwork_8/cw/content/interactiveanimations/selective-repeat-protocol/index.html)

### Problem 2. Repeat the Experiments (30 pts)

Repeat all parts of Problem 1 using the **Selective Repeat Protocol**. For each scenario, describe what happens and compare the observed behavior with the Go-Back-N case.

Be sure to explain:

- how packet losses are detected,
- how the receiver handles out-of-order packets,
- and how the sender decides which packets to retransmit.

---

## Part 3: Compare the Protocols

### Problem 3. Key Differences (15 pts)

List several important differences between **Selective Repeat** and **Go-Back-N**. Your answer should include at least a few of the following ideas:

- how packets are retransmitted,
- whether the receiver discards out-of-order packets,
- how much buffering is required,
- and the tradeoff between simplicity and efficiency.

---

## Submission Instructions

Post your answers in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.

Please submit:

- your written answers to all questions,
- a brief explanation of what you observed in each protocol experiment,
- and a comparison of Go-Back-N and Selective Repeat.

> Be sure to clearly label your answers by question and scenario.

---

## Notes

- This assignment is intended to help you reason about how reliable transport protocols handle loss and recovery.
- Use the animations to observe the actual protocol behavior rather than relying only on the textbook description.
