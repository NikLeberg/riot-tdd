FROM riot/riotbuild:latest

ENV DEBIAN_FRONTEND=noninteractive
ENV LC_ALL=C.UTF-8

# Update all packages
RUN apt-get -q -y update && apt-get -q -y upgrade && rm -rf /var/lib/apt/lists/*

# Download most up to date RIOT
RUN cd /data/riotbuild && git clone git://github.com/RIOT-OS/RIOT.git
ENV RIOTBASE=/data/riotbuild/RIOT

# Patch RIOT buildsystem to allow for external packages
COPY 0001-buildsystem-add-EXTERNAL_PKG_DIRS-functionality.patch /tmp/
RUN cd $RIOTBASE \
    && git apply /tmp/0001-buildsystem-add-EXTERNAL_PKG_DIRS-functionality.patch \
    && rm /tmp/0001-buildsystem-add-EXTERNAL_PKG_DIRS-functionality.patch

# Install riotgen
RUN pip3 install riotgen --no-cache-dir
