FROM kayess/ubuntu-updated:latest
MAINTAINER Kirit Saelensminde

WORKDIR /src

RUN \
    apt-get install -y lsb-release wget \
        g++ clang libboost-all-dev uuid-dev libbz2-dev libssl-dev && \
    apt-get clean

ADD fost-build /usr/local/bin/fost-build
