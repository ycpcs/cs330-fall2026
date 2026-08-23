---
layout: default
course_number: CS330
title: Resources
---

This page contains links and tools to help you throughout the course.

## Development Environment

- [Visual Studio Code](https://code.visualstudio.com/) – A lightweight code editor with debugging tools.
- [GCC](https://gcc.gnu.org/) – GNU Compiler Collection for C/C++ and more.
- [GDB](https://www.gnu.org/software/gdb/) – Debugger for programs written in C, C++, etc.
- [Microsoft Visual Studio](https://visualstudio.microsoft.com/) – Full-featured IDE for many languages.
- [Apache NetBeans](https://netbeans.apache.org/) – IDE supporting C/C++, Java, PHP, etc.

## Packet Capture & Network Analysis

### Passive Capture

- [Wireshark](https://www.wireshark.org/) – Industry-standard for passive packet capture.
- [TCPDump](https://www.tcpdump.org/) & `libpcap` – Command-line network analyzer.
- [NetworkMiner](https://www.netresec.com/?page=NetworkMiner) – Forensic analysis tool.
- [tcpflow](https://github.com/simsong/tcpflow) – Captures and reconstructs TCP flows.
- `tcptrace` – Graphical tool for analyzing TCP dump files.
- **Note:** [Microsoft Message Analyzer](https://techcommunity.microsoft.com) (retired 2019)

---
### Netwox Suite (no longer actively maintained)

- [`netwox`](https://linux.die.net/man/1/netwox) – Toolbox for network testing.
  - `netwib` – Library used by netwox.
  - `netwag` – GUI front-end for netwox.
  
---
## Active Capture / Interception

- [Suricata](https://suricata.io/) – IDS/IPS engine with full packet logging capabilities.
- [Arkime](https://arkime.com/) (formerly Moloch) – Scalable full-packet-capture and search platform.
- [Mallory](https://github.com/IntrepidusGroup/Mallory) – MITM gateway proxy.
- [Ettercap](https://www.ettercap-project.org/) – Advanced MITM tool for LANs.

---
## Connectivity & Port Scanning

- [Nmap](https://nmap.org/) – Network mapping and port scanning.
- [Masscan](https://github.com/robertdavidgraham/masscan) – Fast port scanner.
- [netcat](https://nc110.sourceforge.io/) – Send and receive data over arbitrary TCP/UDP ports.
- [Hping](http://www.hping.org/) – Network tool for security auditing.
- [curl](https://curl.se/) / [wget](https://www.gnu.org/software/wget/) – CLI tools for data transfer.
- [HTTPie](https://httpie.io/) – User-friendly HTTP client.
- [netdiscover](https://github.com/netdiscover-scanner/netdiscover) – Discover live hosts on a network.

---
## Web Testing / Proxies

- [Burp Suite](https://portswigger.net/burp) – Web app security testing tool.
- [OWASP ZAP](https://www.zaproxy.org/) – Open-source web app scanner.
- [mitmproxy](https://mitmproxy.org/) – SSL-capable HTTP proxy.
- [Charles Proxy](https://www.charlesproxy.com/) – GUI HTTP proxy.
- [w3af](https://github.com/andresriancho/w3af) – Web app attack and audit framework.
- [HTTrack](https://www.httrack.com/) – Website copier tool.
  
---
## Network Spoofing
- [Ettercap](https://www.ettercap-project.org/) – MITM tool for network traffic manipulation.
- [arpspoof](https://linux.die.net/man/8/arpspoof) – Simple ARP spoofer.
- [DNSMasq](http://www.thekelleys.org.uk/dnsmasq/doc.html) – Lightweight DNS/DHCP server.
  
---
## System Utilities

- [Sysinternals Suite](https://learn.microsoft.com/en-us/sysinternals/) – Windows system utilities.
- [NirSoft](https://www.nirsoft.net/) – Small Windows utilities, including password tools.

---
## API Development

- [Postman](https://www.postman.com/) – API testing and development.
- [Fiddler](https://www.telerik.com/fiddler) – HTTP debugging proxy.
- [RESTful Tutorial](https://restfulapi.net/) – Concepts of REST APIs.

---
## Supplemental Material

### Interactive Learning
- [Interactive Exercises](http://gaia.cs.umass.edu/kurose_ross/interactive/) – Companion to the Kurose & Ross textbook with quizzes and animations.
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/html) – A hands-on guide to socket programming in C.
- [High Performance Browser Networking](https://hpbn.co/) – What every web developer should know about networking and web performance.
- [Eloquent JavaScript](https://eloquentjavascript.net/) – A book about JavaScript, programming, and digital concepts.
- [Principles of Chaos Engineering](https://principlesofchaos.org/) – Understand how resilience is tested in distributed systems.
- [Programmable Web](https://www.programmableweb.com/) – (Retired) Formerly a hub for APIs and mashups.

---
### Code Repositories
- [BIND 9 GitLab Repository](https://gitlab.isc.org/isc-projects/bind9) – Source code and issue tracker for the BIND DNS server.

---
### Key References
- [Root Servers Map](https://root-servers.org/) – Overview of global DNS root server infrastructure.
- [IANA – Internet Assigned Numbers Authority](https://www.iana.org/)
- [Service Name & Port Number Registry](https://www.iana.org/assignments/service-names-port-numbers/service-names-port-numbers.xhtml)
- [CERN WorldWideWeb Rebuild (2019)](https://worldwideweb.cern.ch/browser/) – Interactive historical browser demo.
- [The CERT Division – Carnegie Mellon](https://www.sei.cmu.edu/about/divisions/cert/index.cfm)
- [Assigned Internet Protocol Numbers](https://www.iana.org/assignments/protocol-numbers/protocol-numbers.xhtml)
- [IEEE 802.3 Ethernet Working Group](http://www.ieee802.org/3/)
- [ICANN – Internet Corporation for Assigned Names and Numbers](http://www.icann.org/)
- [The Wayback Machine](https://web.archive.org/)

---
## Key References & RFCs

See the [RFC Index](https://datatracker.ietf.org/doc/) for official protocol specs. Notable examples:

- **HTTP:** RFC 7230–7235, RFC 7540 (HTTP/2), draft for HTTP/3.
- **DNS:** RFC 1034, RFC 1035, RFC 8484 (DoH).
- **TCP:** RFC 793, RFC 1122, RFC 5681.
- **UDP:** RFC 768, RFC 8085.
- **IP:** RFC 791, RFC 2460 (IPv6), RFC 1958.
- **SMTP/IMAP/POP3:** RFC 5321, RFC 3501, RFC 1939.
- **DHCP:** RFC 2131, RFC 3046.
- **BGP/OSPF/ARP:** RFC 1771, RFC 2328, RFC 826.
