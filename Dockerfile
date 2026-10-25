FROM debian:latest

# Installation du compilateur, de Make et de la bibliothèque OpenSSL
RUN apt-get update && apt-get install -y \
    gcc \
    make \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY . /app

CMD ["/bin/bash"]