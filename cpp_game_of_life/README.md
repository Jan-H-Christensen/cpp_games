# Raylib Game of Life

Ein interaktives "Conways Spiel des Lebens" (Game of Life) geschrieben in C++ unter Verwendung der [raylib](https://www.raylib.com/) Grafikbibliothek.

## ✨ Features

* **Toroidales Spielfeld (Weltkugel-Effekt):** Zellen wandern nahtlos über die Bildschirmränder hinweg (Pac-Man-Effekt).
* **Pause-Funktion:** Über die `Leertaste` lässt sich die Evolution jederzeit einfrieren, um den aktuellen Zustand zu analysieren.
* **Interaktiver Sandkasten (Maus-Steuerung):** * `Linksklick gedrückt halten`: Zellen direkt auf das Spielfeld zeichnen (lebendig setzen).
  * `Rechtsklick gedrückt halten`: Zellen wieder vom Spielfeld löschen (tot setzen).
* **Optimierte Simulationsgeschwindigkeit:** Das Spielfeld rendert flüssig mit 60 FPS, während die Evolution kontrolliert mit einer angenehmen Geschwindigkeit (z. B. 10 Generationen pro Sekunde) abläuft.

## 🛠️ Voraussetzungen

Das Projekt ist für Linux-Systeme konfiguriert und setzt voraus:
* Ein installierter C++ Compiler (`clang++` oder `g++`)
* Eine installierte `raylib` Bibliothek
* `make` für den Build-Prozess

*Hinweis: Die Pfade im Makefile und in den `compile_flags.txt` sind auf das Verzeichnis `/home/j_c/...` eingestellt.*

## 🚀 Projekt starten

1. **Kompilieren:**
   Erstelle das ausführbare Programm mit dem Makefile:
   ```bash
   make
