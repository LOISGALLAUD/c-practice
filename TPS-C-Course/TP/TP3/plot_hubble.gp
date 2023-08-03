set xlabel "distance (Mpc)"     # titre pour les abscisses
set ylabel "Velocity (km/s)"    # titre pour les ordonnées
set title "Hubble diagramm"     # titre de la figure
set key top left	        # position de la legend haut à gauche

plot "hubble.dat" using 1:2 with points title 'galaxies', \
     "hubble.dat" using 1:3 with lines title  'linear regression'
