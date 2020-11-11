FROM madduci/docker-alpine-cpp:gcc-6

WORKDIR /app/

COPY . .
RUN rm *.o
RUN ls
RUN make

FROM alpine:3.12.0
WORKDIR /app/
COPY --from=0 /app/a.out .

RUN apk update && apk add --no-cache \ 
    libstdc++

EXPOSE 8080

ENTRYPOINT [ "./a.out" ]