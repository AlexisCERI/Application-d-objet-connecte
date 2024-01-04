# Application-d-objet-connecte
Rendu du projet de la matière "application d'objet connecté" dans le cadre d'un master 2 SICOM.

Pour la mise en place du projet rapidement, veuillez-suivre ces étapes :

- Faire le montage du simulateur
- Intégrer dans l'arduino uno le programme ecg_generator.ino
- Intégrer dans l'arduino Leonardo le programme prog_reception_ecg.ino
- s'assurer de configurer le programme prog_reception_ecg.ino pour la configuration de la plateforme TTN et le relais LORA
- Installer postgresql sur la raspberry pi et le serveur distant
- créer une base de données sur chaque instance de psql (ecg)
- créer deux tables sur chaque base de données de chaque instance (avgecg et ecg)
- Installer node-red (si pas installé) sur le serveur distant et la raspberry pi
- Installer les différents modules pour que les noeuds soient disponibles sur node-red: serial, dashboard, postgresql, rate-avg, function
- Upload le fichier flow_rpi.json dans l'instance node-red de la raspberry pi
- Upload le fichier flow_serveur_distant.json dans l'instance node-red dans le serveur distant
- Lancez les deux flows sur les deux instances node-red
