---
layout: default
course_number: CS330
title: "Lab - Reliable Data Transfer Review"
---

# Lab - Reliable Data Transfer   

###  Problem 1.
Visit the Chapter 3 - _Go-Back-N Protocol_ Java applet at the companion [Web site](https://media.pearsoncmg.com/ph/esm/ecs_kurose_compnetwork_8/cw/content/interactiveanimations/go-back-n-protocol/index.html). Please read the instructions carefully before proceeding. 

1. Experiment with Five Packets:
   - Have the source send five packets.
   - Pause the animation before any of the packets reach the destination.
   - Eliminate the first packet and then resume the animation.
   - Describe what happens.
<code>
Sender will eventually retransmit all 5 packets 
</code>

2. Experiment with Acknowledgments:
   - Repeat the experiment, allowing all packets to reach the destination.
   - Kill the first acknowledgment.
   - Describe the outcome.
<code>
Since Go-Back-N follows cumulative acknowledgement, next acknowledgement will confirm the receipt of the previous packet.
</code>

1. Experiment with the Second Packet:
   - Send five packets from the source again.
   - Pause the animation before any packets arrive at the destination.
   - Eliminate the second packet and resume the animation.
   - Describe what happens.
<code>
Sender will eventually retransmit packets 2, 3, 4 and 5.
</code>

2. Experiment with Six Packets:
   - Increase the number of packets sent to six.
   - Describe the outcome.

<code>
Cannot send 6 packets. Windows is size 5. 
</code>

### Problem 2.
- Repeat Problem 1 (all questions), but now with [Selective Repeat Protocol](https://media.pearsoncmg.com/ph/esm/ecs_kurose_compnetwork_8/cw/content/interactiveanimations/selective-repeat-protocol/index.html).

<code> 
Eventually the first packet gets retransmitted
</code>

<code> 
Eventually the first packet gets retransmitted
</code>

<code> 
Eventually the second packet gets retransmitted
</code>

### Problem 3.
- List Key Differences Between Selective Repeat and Go-Back-N?

### Grading
Post your report including source in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus.
