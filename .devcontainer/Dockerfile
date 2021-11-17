FROM riot/riotbuild:latest

ENV DEBIAN_FRONTEND=noninteractive
ENV LC_ALL=C.UTF-8

# Update all packages
RUN apt-get -q -y update && apt-get -q -y upgrade && rm -rf /var/lib/apt/lists/*

# Download most up to date RIOT
RUN cd /data/riotbuild && git clone git://github.com/RIOT-OS/RIOT.git
ENV RIOTBASE=/data/riotbuild/RIOT

# Patch RIOT buildsystem to allow for external packages
# https://github.com/RIOT-OS/RIOT/pull/17211
RUN cd $RIOTBASE \
    && git fetch origin pull/17211/head:buildsystem-add-EXTERNAL_PKG_DIRS \
    && git checkout buildsystem-add-EXTERNAL_PKG_DIRS

# Install riotgen
RUN pip3 install riotgen --no-cache-dir
