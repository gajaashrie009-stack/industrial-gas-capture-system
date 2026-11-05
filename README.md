# Industrial Gas Capture & Utilization (IGCU) System

> Transforming Toxic Industrial Emissions into Valuable Resources & Economic Assets.

## 📌 Project Overview
This project presents an engineering concept and digital platform for **Industrial Gas Capture & Utilization (IGCU)**. Rather than releasing harmful gaseous pollutants into the atmosphere or venting them through conventional smokestacks, this system captures emissions at the source, purifies them, and transforms them into revenue-generating commodities such as synthetic fuels, chemical feedstocks, and mineralized concrete.

---

## 🎯 Target Gases & Applications
- **CO₂ (Carbon Dioxide):** Converted into green methanol, chemical intermediates, and mineralized concrete.
- **NOₓ (Nitrogen Oxides):** Processed into nitric acid and agricultural fertilizers.
- **SOₓ (Sulfur Oxides):** Desulfurized into industrial sulfuric acid and synthetic gypsum.
- **CO (Carbon Monoxide):** Purified into syngas for fuel and acetic acid synthesis.
- **VOCs (Volatile Organics):** Recondensed and recycled as reusable industrial solvents.

---

## 🔄 The 7-Stage Recovery Cycle
1. **Industrial Process:** Point-source generation from kilns, furnaces, and smokestacks.
2. **Emission Capture:** Electrostatic collection and thermal ducted hoods.
3. **Gas Separation:** Polymer/ceramic membranes and cryogenic fractionators.
4. **Purification:** Catalytic and molecular sieve adsorption beds.
5. **Safe Storage:** Pressure-rated ASME-compliant containment vessels.
6. **Chemical Conversion:** Catalytic hydrogenation and mineralization reactors.
7. **Useful Products:** Clean chemicals, fuels, fertilizers, and building materials.

---

## 💻 Tech Stack & Project Files
- `index.html` — Interactive web dashboard with animated recovery flows, gas cards, and a yield simulator.
- `website_generator.c` — C program that structures project data and generates `index.html`.
- `server.c` — Standalone HTTP web server written in C using Windows Sockets (`winsock2.h`).
- `open_website.bat` — Simple Windows batch launcher to view the site instantly.

---

## 🚀 Quick Start
### 1. Direct Browser View
Double click `open_website.bat` or open `index.html` in any modern web browser.

### 2. Compile via C (Optional)
```bash
# To generate the website via C:
gcc website_generator.c -o website_generator.exe
./website_generator.exe

# To run the local C Web Server:
gcc server.c -o server.exe -lws2_32
./server.exe
# Open http://localhost:8080 in your browser
```
