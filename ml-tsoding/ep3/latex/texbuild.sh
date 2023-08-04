#!/bin/bash

# Compile le fichier .tex en .pdf
pdflatex gradient.tex

# Ouvre le fichier .pdf dans MuPDF pour la visualisation
mupdf -I gradient.pdf

# Nettoie les fichiers intermédiaires
rm gradient.aux gradient.log
