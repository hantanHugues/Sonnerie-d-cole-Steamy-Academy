# Sonnerie-d-cole-Steamy-Academy

## Présentation du Matériel à Utiliser

### 1.ESP32

Description : L'ESP32 est un microcontrôleur puissant et polyvalent qui intègre des fonctionnalités Wi-Fi et Bluetooth. Il est largement utilisé dans les projets IoT en raison de sa capacité à se connecter à Internet et à interagir avec divers capteurs et dispositifs.
Utilisation dans le projet : Dans ce projet, l'ESP32 sera utilisé pour récupérer l'heure via un serveur NTP, contrôler l'affichage sur un écran LCD et activer une sonnerie ou un buzzer à des heures spécifiques.

### 2. Écran LCD I2C (16x2)

Description : L'écran LCD I2C 16x2 est un affichage à cristaux liquides qui peut afficher 16 caractères sur 2 lignes. Il utilise le protocole I2C pour la communication, ce qui simplifie le câblage en nécessitant seulement deux fils pour la communication (SDA et SCL).
Caractéristiques :
Affiche des caractères ASCII.
Dispose d'un rétroéclairage LED.
Utilise un module I2C basé sur un chip PCF8574 pour faciliter la connexion.

### 3. Buzzer ou Sonnerie

Description : Un buzzer ou une sonnerie sera utilisé pour émettre des sons aux heures programmées. Cela permettra d'annoncer le début et la fin des cours, ainsi que les récréations.
Utilisation dans le projet : Le buzzer sera contrôlé par l'ESP32 pour se déclencher aux heures définies dans le code.

### 4. Breadboard et Câbles de Raccordement

Description : Une breadboard (plaque d'essai) est utilisée pour réaliser les connexions sans soudure entre les composants. Les câbles de raccordement sont nécessaires pour établir les connexions entre l'ESP32, l'écran LCD et le buzzer.
Utilisation dans le projet : La breadboard facilitera l'assemblage des composants et permettra d'effectuer des modifications facilement.
Conclusion

Ce matériel constitue la base du projet de sonnerie d'école programmable. L'ESP32, associé à l'écran LCD I2C et au buzzer, permettra de créer un système efficace pour gérer les horaires scolaires tout en offrant une interface utilisateur conviviale grâce à l'affichage en temps réel de l'heure. Les composants sont faciles à assembler et à programmer, ce qui en fait un excellent choix pour un projet éducatif.

## Présentation du Projet

Dans le cadre de ce cours, nous allons réaliser un projet passionnant : la création d'une sonnerie d'école programmable à l'aide d'un microcontrôleur ESP32.

Ce système permettra d'automatiser les sonneries annonçant les différents événements de la journée scolaire, tels que le début et la fin des cours, les récréations, etc.L'ESP32 est un microcontrôleur très performant qui combine connectivité Wi-Fi et Bluetooth.

Grâce à ses nombreuses entrées/sorties, il sera en mesure de piloter une sonnerie et d'afficher l'heure sur un écran LCD. Mais le cœur du projet résidera dans la programmation de l'ESP32 pour qu'il déclenche la sonnerie aux heures prédéfinies.

Pour cela, nous utiliserons une connexion Wi-Fi pour synchroniser l'heure de l'ESP32 avec un serveur NTP (Network Time Protocol). Ainsi, nous garantirons une heure précise et fiable, indispensable pour le bon fonctionnement du système de sonnerie.L'écran LCD I2C permettra quant à lui d'afficher l'heure en temps réel, facilitant le réglage et la vérification du bon fonctionnement du système.

Enfin, un buzzer ou une sonnerie sera activé aux heures programmées pour annoncer les différents événements de la journée.Ce projet combinera donc des aspects hardware (câblage des composants) et software (programmation de l'ESP32). Il vous permettra de vous familiariser avec les microcontrôleurs, la synchronisation horaire, la programmation d'événements, tout en réalisant un objet concret et utile pour votre école.

Tout au long du cours, vous serez guidés pas à pas pour mener à bien ce projet, depuis la configuration de l'environnement de développement jusqu'à l'assemblage final du système. Vous pourrez même aller plus loin en personnalisant votre sonnerie ou en l'intégrant à d'autres systèmes de votre école.

Alors, prêts à créer votre propre sonnerie d'école programmable ? Suivez le guide et laissez libre cours à votre créativité !


## Qu'est-ce qu'un Serveur NTP ?

Le Network Time Protocol (NTP) est un protocole utilisé pour synchroniser les horloges des ordinateurs et d'autres dispositifs sur un réseau. Dans le cadre de notre projet de sonnerie d'école programmable, le serveur NTP joue un rôle crucial en garantissant que notre système fonctionne avec une heure précise.

# Objectifs du Serveur NTP

Synchronisation Horaire : L'objectif principal d'un serveur NTP est de fournir une heure précise et fiable à tous les dispositifs connectés. Pour notre sonnerie d'école, cela signifie que les heures de déclenchement des sonneries seront exactes, évitant ainsi toute confusion dans la gestion des horaires scolaires.
Horodatage : Le NTP permet d'horodater les événements de manière précise, ce qui est important pour notre système afin de s'assurer que les sonneries se déclenchent aux moments appropriés.

# Fonctionnement du Serveur NTP

Architecture Hiérarchique :
Le système NTP est organisé en strates. Les serveurs de strate 0 sont des sources de temps très précises (comme des horloges atomiques ou GPS). Les serveurs de strate 1 se synchronisent directement avec ces sources, tandis que notre projet peut utiliser un serveur de strate 2 pour récupérer l'heure.
Modes de Communication :
Dans notre projet, nous utiliserons le mode client/serveur, où notre ESP32 agira comme un client qui envoie une requête à un serveur NTP pour obtenir l'heure actuelle.
Protocoles Utilisés :
NTP utilise le protocole UDP sur le port 123 pour la communication. Cela permet une transmission rapide et efficace des données horaires, essentielle pour le bon fonctionnement de notre sonnerie.

# Avantages du NTP

Précision : Le NTP peut atteindre une précision allant jusqu'à quelques millisecondes sur Internet, ce qui est suffisant pour notre application scolaire.
Fiabilité : Grâce à sa structure hiérarchique et à ses mécanismes de redondance, le NTP peut maintenir une synchronisation horaire même en cas de défaillance d'un ou plusieurs serveurs, assurant ainsi que notre sonnerie fonctionne toujours correctement.
Facilité d'Utilisation : Le protocole est largement supporté par la plupart des systèmes d'exploitation modernes, ce qui facilite son intégration dans notre projet avec l'ESP32.

# Applications du NTP dans notre Projet

Gestion des Horaires Scolaires : En utilisant un serveur NTP pour synchroniser l'heure de l'ESP32, nous garantissons que les sonneries annonçant les périodes de classe et les récréations se déclenchent à des heures précises.
Optimisation du Système : La synchronisation horaire permet également d'éviter les retards et les interruptions dans le déroulement des activités scolaires, contribuant ainsi à une meilleure organisation dans l'établissement.

# Sécurité du NTP

Bien que le NTP soit un protocole robuste, il est important d'utiliser un serveur NTP fiable et sécurisé pour éviter tout risque potentiel. Dans notre projet, il est recommandé d'utiliser un serveur NTP local ou bien connu pour garantir la sécurité et la précision des données horaires.

# Conclusion

Dans le cadre de notre projet de sonnerie d'école programmable avec un ESP32, le serveur NTP est essentiel pour assurer une synchronisation horaire précise et fiable. En intégrant cette technologie dans notre système, nous pouvons garantir que les sonneries se déclenchent aux moments appropriés, améliorant ainsi la gestion des horaires scolaires et contribuant à une expérience éducative fluide.


## Intégration des différents fonctionnalités du projet

Voici un guide détaillé et structuré étape par étape pour chaque fonctionnalité du code, en incluant des détails supplémentaires pour chaque partie, pour  le développement d'une sonnerie d'école.

 Développer une sonerie Connectée avec ESP8266

# Introduction

Cette dernière partie vous guide à travers la création d'une sonnerie d'école connectée utilisant un ESP8266.

# Partie 1 : Connexion au Réseau Wi-Fi

# Objectif

Établir une connexion au réseau Wi-Fi pour permettre à l'ESP8266 d'accéder à Internet et de synchroniser l'heure.

# Étape 1 : Déclaration des Variables de Connexion

Avant de commencer la connexion Wi-Fi, nous devons définir les informations nécessaires pour se connecter au réseau.

   
  
    #define ssid "SSID" // Remplacez par votre SSID 
    #define password "PASS" // Remplacez par votre mot de passe
ssid : Nom du réseau Wi-Fi auquel vous souhaitez vous connecter.
password : Mot de passe du réseau Wi-Fi.

# Étape 2 : Fonction de Connexion au Wi-Fi

La fonction connectToWiFi() initialise la connexion au réseau Wi-Fi et attend jusqu'à ce que la connexion soit établie.

    void connectToWiFi() { 
        Serial.print("Connexion à "); 
        Serial.println(ssid); 
        WiFi.begin(ssid, password); // Démarrer la connexion au réseau 
        
        while (WiFi.status() != WL_CONNECTED) { // Attendre la connexion 
            delay(500); 
            Serial.print("."); 
        } 
        
        Serial.println(""); 
        Serial.println("Connexion établie !"); 
        Serial.print("Adresse IP : "); 
        Serial.println(WiFi.localIP()); // Afficher l'adresse IP obtenue 
    }
WiFi.begin(ssid, password) : Lance la tentative de connexion au réseau Wi-Fi avec les informations fournies.
Boucle while (WiFi.status() != WL_CONNECTED) : Vérifie si la connexion est réussie en attendant que l'état de connexion soit WL_CONNECTED.
WiFi.localIP() : Affiche l'adresse IP attribuée à l'ESP8266.

# Partie 2 : Connexion au Serveur NTP

# Objectif

Obtenir l'heure actuelle depuis un serveur NTP pour afficher l'heure et la date précises sur l'écran LCD.

# Étape 1 : Déclaration et Initialisation de NTP

Pour obtenir l'heure actuelle, nous avons besoin d'un client NTP (Network Time Protocol).

    #include <NTPClient.h> 
    #include <WiFiUDP.h> 
    
    WiFiUDP ntpUDP; 
    NTPClient timeClient(ntpUDP, "pool.ntp.org");
WiFiUDP ntpUDP : Crée un objet pour la communication UDP nécessaire au client NTP.
NTPClient timeClient(ntpUDP, "pool.ntp.org") : Crée un client NTP en utilisant l'objet UDP et un serveur NTP public.

# Étape 2 : Initialisation de NTP dans la Fonction setup()

Initialisez le client NTP et définissez l'offset pour ajuster l'heure selon votre fuseau horaire.

    void setup() { 
        // Code pour LCD et Wi-Fi 
        timeClient.begin(); 
        timeClient.setTimeOffset(3600); // Réglez l'offset pour votre fuseau horaire 
    }
timeClient.begin() : Initialise le client NTP pour commencer à recevoir les données de temps.
timeClient.setTimeOffset(3600) : Ajuste l'heure en fonction du décalage horaire (3600 secondes = 1 heure pour GMT+1).

# Partie 3 : Récupérer l'Heure et la Date

Objectif

Obtenir l'heure et la date actuelles depuis le serveur NTP pour les afficher sur l'écran LCD.

# Étape 1 : Mise à Jour et Récupération de l'Heure

Mettez à jour le client NTP et récupérez l'heure sous différents formats.

    void loop() { 
        timeClient.update(); 
        time_t epochTime = timeClient.getEpochTime(); 
        String formattedTime = timeClient.getFormattedTime();
    }
timeClient.update() : Met à jour l'heure en obtenant les dernières données du serveur NTP.
timeClient.getEpochTime() : Récupère l'heure actuelle en temps epoch (nombre de secondes depuis 1970).
timeClient.getFormattedTime() : Obtient l'heure formatée sous forme de chaîne (HH:MM


).

# Étape 2 : Extraction des Composants de Temps

Extrayez les heures, minutes, secondes, ainsi que la date (jour, mois, année).

    int currentHour = timeClient.getHours(); 
    int currentMinute = timeClient.getMinutes(); 
    int currentSecond = timeClient.getSeconds(); 
    
    struct tm *ptm = gmtime((time_t *)&epochTime); 
    int monthDay = ptm->tm_mday; 
    int currentMonth = ptm->tm_mon + 1; 
    int currentYear = ptm->tm_year + 1900;
timeClient.getHours(), getMinutes(), getSeconds() : Obtenez respectivement les heures, minutes et secondes.
gmtime() : Convertit le temps epoch en une structure de temps UTC, permettant d'extraire le jour, le mois, et l'année.

# Partie 4 : Affichage sur l'Écran LCD

Objectif

Afficher l'heure et la date sur un écran LCD pour une lecture facile.

# Étape 1 : Initialisation de l'Écran LCD

Configurez l'écran LCD pour l'affichage.

LiquidCrystal_I2C lcd(0x27
    #include <LiquidCrystal_I2C.h> 
    LiquidCrystal_I2C lcd(0x27, 16, 2);
, 16, 2) : Crée un objet pour l'écran LCD avec l'adresse I2C 0x27, 16 colonnes et 2 lignes.

# Étape 2 : Affichage des Données

Affichez l'heure et la date sur l'écran LCD.

    lcd.setCursor(0, 0); 
    lcd.print(formattedTime); 
    lcd.setCursor(0, 1); 
    lcd.print("Date: "); 
    lcd.print(monthDay); 
    lcd.print("/"); 
    lcd.print(currentMonth); 
    lcd.print("/"); 
    lcd.print(currentYear);
lcd.setCursor() : Positionne le curseur à la ligne et colonne spécifiées.
lcd.print() : Affiche les données (heure et date) sur l'écran LCD.

# Partie 5 : Ajouter une Fonctionnalité de Buzzer

# Objectif

Faire sonner un buzzer à des heures spécifiques, comme l'heure de la récréation et l'heure de rentrée.

# Étape 1 : Déclaration du Buzzer

Définissez les heures spécifiques pour le buzzer et configurez la broche du buzzer.

    #define RECREATION_HOUR 10 
    #define RECREATION_MINUTE 15 
    #define RETURN_HOUR 15 
    #define RETURN_MINUTE 30 
    #define BUZZER_PIN D5 // Définir la broche du buzzer
RECREATION_HOUR, RECREATION_MINUTE : Heure et minute pour l'heure de récréation.
RETURN_HOUR, RETURN_MINUTE : Heure et minute pour l'heure de rentrée.
BUZZER_PIN : Broche à laquelle le buzzer est connecté.

# Étape 2 : Configuration du Buzzer

Configurez la broche du buzzer comme sortie dans la fonction setup().

    void setup() { 
        // Code pour LCD et Wi-Fi 
        pinMode(BUZZER_PIN, OUTPUT); // Configurez la broche du buzzer comme sortie 
    }
pinMode(BUZZER_PIN, OUTPUT) : Configure la broche du buzzer comme une sortie numérique.

# Étape 3 : Activation du Buzzer

Implémentez la logique pour activer le buzzer à des heures spécifiques.

    if ((currentHour == RECREATION_HOUR && currentMinute == RECREATION_MINUTE) || 
        (currentHour == RETURN_HOUR && currentMinute == RETURN_MINUTE)) { 
        digitalWrite(BUZZER_PIN, HIGH); // Allumez le buzzer 
        delay(1000); // Faites sonner le buzzer pendant 1 seconde 
        digitalWrite(BUZZER_PIN, LOW); // Éteignez le buzzer 
    }
digitalWrite(BUZZER_PIN, HIGH) : Allume le buzzer.
delay(1000) : Maintient le buzzer allumé pendant 1 seconde.
digitalWrite(BUZZER_PIN, LOW) : Éteint le buzzer.

# Conclusion

Ce guide vous a montré comment créer une horloge connectée avec l'ESP8266. Vous avez appris à :

Connecter l'ESP8266 au Wi-Fi.
Obtenir l'heure via NTP.
Afficher l'heure et la date sur un écran LCD.
Ajouter une fonctionnalité de buzzer pour des alertes à des heures spécifiques.

Chaque étape a été détaillée pour vous aider à comprendre et à implémenter les fonctionnalités de manière efficace. Vous pouvez personnaliser les horaires et ajuster les paramètres en fonction de vos besoins
