# 🔋 RFID-Based EV Charging System

RFID-based Electric Vehicle (EV) charging system using **ATmega328 (Arduino UNO)** for secure user authentication and automated charging control.

---

## 📌 Project Description

This project demonstrates an **RFID-based Electric Vehicle (EV) Charging System** using a microcontroller.

The system ensures **secure and authorized EV charging** by allowing only valid RFID card/tag holders to access the charging station. Once authentication is successful, the charging process is automatically controlled using a **relay module**.

This project reflects a **real-world EV charging use case** with a focus on security, automation, and reliability.

---

## 🧠 Key Features

* Secure user authentication using RFID
* Automated EV charging control
* Relay-based power switching
* Microcontroller-based control logic
* Simple, reliable, and cost-effective design

---

## 🧩 Block Diagram

![Block Diagram](diagrams/block_diagram.png)

---

## 🔄 Flow Chart

![Flow Chart](diagrams/flow_chart.png)

---

## 🧰 Hardware Components Used

* Arduino UNO (ATmega328)
* RFID Reader (EM-18 / MFRC522)
* RFID Cards / Tags
* Relay Module
* EV Charging Load (Demo)
* Power Supply
* Connecting Wires

---

## 💻 Software & Tools

* Arduino IDE
* Embedded C / Arduino Programming
* Serial Monitor

---

## ⚙️ Working Principle

1. User scans RFID card/tag
2. RFID reader sends data to ATmega328
3. Microcontroller verifies authorized ID
4. If valid, relay is activated
5. EV charging starts automatically
6. Charging stops when access is removed or timed out

---

## 📘 Project Report

The complete project documentation including objectives, circuit diagram, working principle, components, results, and future scope is available below:

📥 **[Download Project Report (PDF)](report/RFID_REPORT.pdf)**
⚠️ *GitHub may not preview this PDF correctly. Please download to view.*

---

## 📂 Repository Structure

```
RFID-Based-EV-Charging-System/
│
├── code/                   # Arduino source code
├── diagrams/
│   ├── block_diagram.png
│   └── flow_chart.png
├── report/
│   └── RFID_REPORT.pdf
└── README.md
```

---

## 🚀 Future Scope

* Mobile application integration for monitoring
* Automated billing & payment gateway integration
* Multi-user EV charging station support
* IoT-enabled smart EV charging infrastructure
* Cloud-based data logging and analytics

---

## 👤 Author

**Ganesh S**
Electronics & Communication Engineering
Aspiring Embedded Systems & IoT Engineer

---

## ⭐ Acknowledgements

* Arduino Community
* Embedded Systems Learning Resources

---

> ⭐ If you find this project useful, feel free to star the repository!
