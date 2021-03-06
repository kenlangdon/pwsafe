#!/bin/bash
# Silly script to setup the development pre-requisites for
# building PasswordSafe on Debian-based distros.
# Meant to be run as root or sudo'd
# Much room for improvement, error checking, reporting stuff, etc.
# Running this after cloning the git repo (or unpacking the sources)
# and you should be all set.

# Ubuntu 20 decided to rename the following
#LIBWXDEV="ibwxgtk3.0-gtk3-dev"
#The rest of the Debiverse should use
LIBWXDEV="ibwxgtk3.0-dev"
# Two internet points for writing the correct if statement to handle the above...

apt-get install cmake fakeroot g++ gettext git libgtest-dev \
        libcurl4-openssl-dev libqrencode-dev  libssl-dev libuuid1 \
        $LIBWXDEV libxerces-c-dev libxt-dev libxtst-dev \
        libykpers-1-dev libyubikey-dev make pkg-config uuid-dev zip \
        libmagic-dev

cd /usr/src/gtest
mkdir build
cd build
cmake ..
make
