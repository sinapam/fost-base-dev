FROM racker/precise-with-updates
MAINTAINER Kirit Saelensminde

ENV INITRD No
ENV DEBIAN_FRONTEND noninteractive

RUN \
    rm /etc/apt/apt.conf.d/no-http-cache && \
    echo 'Acquire::http::Proxy "http://172.17.42.1:3142/";' > /etc/apt/apt.conf.d/cache && \
    apt-get update && \
    apt-get install -y libboost-system1.46.1 libboost-filesystem1.46.1 libboost-regex1.46.1 libboost-thread1.46.1 libboost-date-time1.46.1 && \
    apt-get clean
