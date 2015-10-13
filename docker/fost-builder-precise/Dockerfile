FROM kayess/ubuntu-updated:precise
MAINTAINER Kirit Saelensminde

WORKDIR /src

RUN \
    apt-get install -y python-software-properties && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get install -y g++-4.9 lsb-release wget python-dev uuid-dev libbz2-dev libssl-dev && \
    apt-get clean && \
    cd /usr/bin && \
    rm gcc cpp && \
    ln -s gcc-4.9 gcc && \
    ln -s g++-4.9 g++ && \
    ln -s cpp-4.9 cpp

ADD fost-build /usr/local/bin/fost-build
