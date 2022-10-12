FROM debian:11-slim

RUN apt update && apt -y upgrade
RUN apt-get install -y cmake make python3 g++ gdb git

RUN mkdir /tmp/2022-10-24/

WORKDIR /root/