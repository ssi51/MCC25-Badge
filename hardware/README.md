# 🛠️ MCC25 Badge Hardware Design

This directory contains the Open Source Hardware (OSHW) design files for the **MCC25 Badge**. The PCB was designed using **KiCad** (Version 7.0+).

## 📂 File Descriptions

| File Name | Description |
| :--- | :--- |
| `mcc25_badge.kicad_pro` | Main KiCad Project file. Open this to start editing. |
| `mcc25_badge.kicad_sch` | **Schematic**: Shows how the ESP32-C3 connects to the OLED, LEDs, and buttons. |
| `mcc25_badge.kicad_pcb` | **PCB Layout**: The physical board routing, layers, and footprints. |
| `gerber.zip` | **Production Files**: The exact manufacturing files needed to order this board from a fab house. |

## 📐 Technical Specifications
* **Layers:** 2-Layer PCB
* **Dimensions:** 100mm x 60mm
* **Thickness:** 1.6mm (Standard)
* **Signal Voltage:** 3.3V Logic

## 🏭 How to Order This Board (Fabrication)

You don't need to install KiCad if you just want to manufacture the PCB.

1.  **Download the Gerbers**: Download the file `gerber.zip` from this folder.
2.  **Visit a Manufacturer**: Go to a PCB fabrication website (e.g., JLCPCB, PCBWay, AiPCBA).
3.  **Upload**: Drag and drop the `gerber.zip` file into their "Quote" tool.
4.  **Select Settings**: The defaults are usually fine, but ensure the following:
    * **Layers**: 2
    * **Thickness**: 1.6mm
    * **PCB Color**: Black (Matches the MCC aesthetic)
    * **Surface Finish**: HASL (Cheaper) or ENIG (Better for gold pads)
5.  **Order**: Add to cart and ship!

## ✏️ How to Modify the Design

If you want to change the logo, move buttons, or add sensors:

1.  Install **KiCad** (Free & Open Source) from [kicad.org](https://www.kicad.org/).
2.  Clone this repository to your computer.
3.  Double-click `mcc25_badge.kicad_pro` to open the project manager.
4.  Open the **Schematic Editor** to change connections or the **PCB Editor** to change the physical layout.

## ⚠️ Assembly Note
This board uses **SMD (Surface Mount Device)** components for the ESP32-C3 and LEDs.
* If ordering **PCB Assembly (PCBA)** services, you will need to provide them with the `BOM` (Bill of Materials) and `CPL` (Component Placement List).
* If assembling by hand, ensure you have a hot air station or a fine-tip soldering iron.
