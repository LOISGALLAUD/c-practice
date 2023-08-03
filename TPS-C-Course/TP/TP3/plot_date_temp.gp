set yrange [13:15]       # plage pour ordonnees  (auto pour abscisses)
set xlabel "annees"     # titre pour les abscisses
set ylabel "temperature"    # titre pour les ordonnées
set title "Evolution mondiale de la temperature"     # titre de la figure
set key top left	        # position de la legend haut à gauche

plot "date_temperature.txt" using 1:2 with linespoints title 't°'
