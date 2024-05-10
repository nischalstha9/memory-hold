FROM ubuntu as build

ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
    apt-get -y install gcc mono-mcs && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY ./memory_hold.c /app/memory_hold.c
RUN gcc -static -o memory_hold memory_hold.c

FROM scratch
COPY --from=build /app/memory_hold /memory_hold
ENTRYPOINT ["/memory_hold"]