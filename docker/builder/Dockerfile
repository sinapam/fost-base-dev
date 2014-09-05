FROM kayess/fost-updated:latest
MAINTAINER Kirit Saelensminde

WORKDIR /src

RUN \
    apt-get install -y g++ libboost-all-dev uuid-dev libbz2-dev libssl-dev && \
    apt-get clean

ADD fost-build /usr/local/bin/fost-build
