FROM ubuntu:20.04 as builder

RUN apt update \
    && apt upgrade -y \
    && apt autoremove -y \
    && apt install -y \
        gcc \
        make

WORKDIR /var/src/vm
COPY . .

RUN make -j clean 
RUN make
