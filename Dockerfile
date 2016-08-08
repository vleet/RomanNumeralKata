FROM ubuntu:14.04

RUN apt-get update && apt-get install -y \
    build-essential \
    check \
    git \
    nano \
    pkg-config

#RUN git clone https://github.com/ddaugher/roman.numeral.calculator.C.git /tmp

CMD ["/bin/bash"]
