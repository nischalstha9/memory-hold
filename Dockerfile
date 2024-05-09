FROM alpine as build
RUN apk add --no-cache build-base
WORKDIR /app
COPY ./mem.c /app/mem.c
RUN gcc -o mem.c hold_memory

FROM scratch
COPY --from=build-env /app/hold_memory /app/hold_memory
WORKDIR /app
ENTRYPOINT ["/app/hold_memory"]