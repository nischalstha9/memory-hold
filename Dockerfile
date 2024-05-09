FROM alpine as build
RUN apk add --no-cache build-base
WORKDIR /app
COPY ./mem.c /app/mem.c
RUN gcc -o hold_memory mem.c

FROM scratch
RUN mkdir -p /app
WORKDIR /app
COPY --from=build /app/hold_memory /app/hold_memory
ENTRYPOINT ["/app/hold_memory"]