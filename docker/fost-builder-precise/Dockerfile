FROM kayess/ubuntu-updated:precise
MAINTAINER Kirit Saelensminde

WORKDIR /src

RUN \
    apt-get install -y python-software-properties && \
    add-apt-repository ppa:ubuntu-toolchain-r/test && \
    add-apt-repository ppa:h-rayflood/gcc-upper && \
    add-apt-repository ppa:h-rayflood/llvm-upper && \
    apt-get update && \
    apt-get install -y lsb-release wget g++-6 clang++-3.6 \
        python-dev uuid-dev libbz2-dev libssl-dev libpq-dev && \
    apt-get clean && \
    cd /usr/bin && \
    rm gcc cpp && \
    ln -s gcc-6 gcc && \
    ln -s g++-6 g++ && \
    ln -s clang++-3.6 clang++ && \
    ln -s cpp-6 cpp

ADD fost-build /usr/local/bin/fost-build
