FROM kayess/minit-restart:precise
MAINTAINER Kirit Saelensminde

RUN \
    apt-get install -y python-software-properties postgresql-client && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get dist-upgrade -y \
    apt-get clean
