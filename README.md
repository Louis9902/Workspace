# Zusammenfassungen für Vorlesungen

## Schreiben von Zusammenfassungen
Es wird empfohlen VSCode zu benutzen (OpenSource alternative VSCodium). Als Extension für den Editor sollten man TexLab verwenden (Tex LSP Implementation) und gegebenenfalls Code Spell Checker.

## Erstellen der Zusammenfassungen
Um die Zusammenfassungen zu erstellen wird eine installation von LaTeX benötigt. Zu dem ist empfohlen einen Dokumentengenerator zu benutzen, beispielsweiße `LaTeXmk`.

Auf Linux sollte eine Installation des TeXLive Schemas Small reichen, mit wenigen zusatz Paketen.

Fedora:
```bash
$ sudo dnf install -y texlive-scheme-small texlive-standalone latexmk make
$ git clone https://github.com/Louis9902/Zusammenfassungen.git && cd Zusammenfassungen
$ make artifacts
```

Im Anschluss sollten alle Zusammenfassungen in einem Ordner Target zu finden sein. Sollte das nicht klappen gibt es alle Zusammenfassengen auch noch einmal auf GitHub unter `Actions` > `Build LaTeX` dann den neusten Eintrag auswählen und dann das `Zusammenfassungen` Archive herunterladen.
