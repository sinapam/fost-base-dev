FROM racker/precise-with-updates
MAINTAINER Kirit Saelensminde

WORKDIR /src

ENV INITRD No
ENV DEBIAN_FRONTEND noninteractive

RUN \
    rm /etc/apt/apt.conf.d/no-http-cache && \
    echo 'Acquire::http::Proxy "http://172.17.42.1:3142/";' > /etc/apt/apt.conf.d/cache && \
    apt-get update && \
    apt-get install -y g++ libboost-all-dev uuid-dev libbz2-dev libssl-dev && \
    apt-get clean

ADD fost-build /usr/local/bin/fost-build
