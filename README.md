
# 🔍 Simple Multithreaded Port Scanner (C++)

A lightweight TCP port scanner written in **C++** using raw Linux sockets and multithreading.

This project was built as part of my cybersecurity homelab and systems programming practice to better understand how tools like Nmap work internally.

---

## 🚀 Features

- TCP connect() port scanning
- Multithreaded for faster performance
- Custom IP target
- Custom port range
- Socket timeout handling
- Service name detection (/etc/services)
- Colored terminal output
- Built with Makefile
- Linux compatible

---

## 🛠️ Technologies Used

- C++17
- POSIX sockets
- std::thread
- Linux networking APIs
- Make

---

## 📦 Build

Clone the repository:

```bash
git clone git@github.com:JeycobSec/port-scanner.git
cd port-scanner
```

Compile:

```bash
make
```

---

## ▶️ Usage

```bash
./scanner <ip> <start_port> <end_port>
```

### Example

```bash
./scanner 127.0.0.1 1 1024
```

---

## 🖥️ Example Output

```
Scanning 127.0.0.1 from port 1 to 1024...

[OPEN] Port 22 (ssh)
[OPEN] Port 80 (http)
[OPEN] Port 631 (ipp)

Scan complete.
```

---

## 🧠 What I Learned

This project helped me practice:

- Low-level socket programming
- TCP handshake behavior
- Multithreading in C++
- Handling timeouts
- CLI tool design
- Makefile builds
- Git/GitHub workflows
- How real scanners like Nmap work internally

---

## ⚠️ Disclaimer

This tool is for **educational and lab use only**.  
Only scan systems you own or have permission to test.

---

## 📌 Author

Jeycob  
Cybersecurity | Homelab | Systems Programming
