FROM ubuntu
RUN apt-get update
RUN apt-get install figlet
CMD figlet -f script hello

ENTRYPOINT ["figlet", "-f", "script"]
CMD hello world

COPY hello.c /
RUN make hello
CMD /hello
