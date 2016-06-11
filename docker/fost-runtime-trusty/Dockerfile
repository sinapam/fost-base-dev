FROM kayess/minit-restart:trusty
MAINTAINER Kirit Saelensminde

RUN \
    apt-get install -y software-properties-common postgresql-client && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get dist-upgrade -y && \
    apt-get clean

