FROM alpine as build
RUN apk add --no-cache build-base
WORKDIR /app
COPY ./memory_hold.c /app/memory_hold.c
RUN gcc -static -o memory_hold memory_hold.c

FROM scratch
COPY --from=build /app/memory_hold /memory_hold
ENTRYPOINT ["/memory_hold"]