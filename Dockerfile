FROM gcc:latest

WORKDIR /usr/src/app

COPY . .

RUN mkdir -p build

RUN g++ -o build/app src/app.cpp

WORKDIR /usr/src/app/build

CMD ["./app"]
