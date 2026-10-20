FROM debian:latest

# Installation du compilateur, de Make et de la bibliothèque OpenSSL
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

# Définition du répertoire de travail dans le conteneur
WORKDIR /app

# Copie de l'intégralité de ton dossier racine (rappel_c) vers /app dans le conteneur
COPY . /app

# On ouvre un terminal Bash par défaut pour te permettre de tester manuellement
CMD ["/bin/bash"]