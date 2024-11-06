FROM ubuntu
RUN apt update && apt install gcc make vim check valgrind g++ snapd libgtest-dev cmake -y
RUN cd /usr/src/googletest && cmake CMakeLists.txt && make
WORKDIR /home
COPY . /home

ENTRYPOINT ["sh", "valgrisha.sh"]